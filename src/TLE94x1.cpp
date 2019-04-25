/*********************************************************************************************************************
 * Copyright (c) 2019, Infineon Technologies AG
 *
 * 
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * 
 *********************************************************************************************************************/


/****************************************************************************************************//**
 * @file         TLE94x1.c
 *
 * @brief        Implementation of main library functions
 *
 * @version     V1.0.0
 * @date        15. April 2019
 * @author      Markus Noll / markus.noll@infineon.com
 * @author      Yannek Micha Rixen / Yannek.Rixen@infineon.com
 ********************************************************************************************************/



/* ================================================================================ */
/* ============================   HEADER FILES     ================================ */
/* ================================================================================ */

#include "TLE94x1.h"
#include "util/SBC_TLE94x1.h"
#include <stdio.h>


/* ================================================================================ */
/* ==============================   Variables     ================================= */
/* ================================================================================ */


/* --------------------------------  ISR Handling --------------------------------- */

static    SBC_Func_Callback                 SBC_ISR_Callbacks[30];
static    uint32_t                          SBC_ISR_Vectors[30];
static    uint8_t                           SBC_ISR_ReadOutRegs[30];
static    uint8_t                           SBC_ISR_ReadOutVals[30];
static    uint8_t                           SBC_RegisteredCallbacks = 0;
static    uint8_t                           SBC_RegisteredRedoutRegs = 0;



/* ================================================================================ */
/* ===========================   Library Functions     ============================ */
/* ================================================================================ */


/* --------------------------------  Main Functions ------------------------------- */


SBC_ErrorCode SBC_WD_Trigger(void) {
    /* Read WD config out of SBC and write back to trigger WD */
    uint8_t WD_Data = (uint8_t)SBC_Read_Command(SBC_WD_CTRL);
    return SBC_Write_Reg(SBC_WD_CTRL, WD_Data, NULL);
}


uint16_t SBC_Read_Command(uint8_t SBC_Reg) {
    /* Read and return data - Bit[15:8] = Status Information Field - Bit [7:0] Register data */
    return  SBC_SPI_TRANSFER16(SBC_Read_Mask & SBC_Reg, 0x00U);
}


uint8_t SBC_Read_RegField(uint8_t SBC_Reg, uint8_t SBC_FieldMsk, uint8_t SBC_FieldPos) {
    uint8_t data = ((uint8_t)SBC_Read_Command(SBC_Reg)) & 0xFFU;
    return (data & SBC_FieldMsk) >> SBC_FieldPos;
}


SBC_ErrorCode SBC_Write_Reg(uint8_t SBC_Reg, uint8_t SBC_Val, uint16_t * returnval) {
    SBC_ErrorCode errCode;
    uint16_t returndata = SBC_SPI_TRANSFER16(SBC_Write_Bit | SBC_Reg, SBC_Val);
    if(returnval != NULL) {
        *returnval = returndata;
    }

    errCode.SBC_Register = SBC_Reg;
    errCode.flippedBitsMask = ((uint8_t)SBC_Read_Command(SBC_Reg)) ^ SBC_Val;
    errCode.expectedValue = SBC_Val;
    return errCode;
}


SBC_ErrorCode SBC_Write_RegField(uint8_t SBC_Reg, uint8_t SBC_FieldMsk, uint8_t SBC_FieldPos, uint8_t SBC_FieldVal, uint16_t * returnval) {
    SBC_ErrorCode errCode;

    /* Read data out of register to be manipulated */
    uint16_t returndata = SBC_Read_Command(SBC_Reg);
    if(returnval != NULL) {
        *returnval = returndata;
    }
    uint8_t data = (uint8_t)returndata; 

    /* Set the used bit field to all 0 */
    data &= ~(SBC_FieldMsk);

    /* Configure new data to bit field */
    data |= (SBC_FieldVal << SBC_FieldPos);

    (void)SBC_SPI_TRANSFER16(SBC_Write_Bit | SBC_Reg, data);

    errCode.SBC_Register = SBC_Reg;
    errCode.expectedValue = (SBC_FieldVal << SBC_FieldPos);
    uint8_t actualValue = ((uint8_t)SBC_Read_Command(SBC_Reg)) & SBC_FieldMsk;
    errCode.flippedBitsMask = errCode.expectedValue ^ actualValue;
    return errCode;
}


SBC_ErrorCode SBC_Init(void) {
    SBC_ErrorCode errCode;
    uint8_t WD_Checksum = CTRL_WD_CTRL;
    uint8_t WD_CTRL = CTRL_WD_CTRL;
    uint8_t SWK_ID3_CTRL, SWK_ID2_CTRL, SWK_ID1_CTRL, SWK_ID0_CTRL;
    uint8_t SWK_MASK_ID3_CTRL, SWK_MASK_ID2_CTRL, SWK_MASK_ID1_CTRL, SWK_MASK_ID0_CTRL;
    uint8_t SWK_CAN_FD_CTRL = CTRL_SWK_CAN_FD_CTRL;

    /* Calculate checksum */
    WD_Checksum = WD_Checksum ^ WD_Checksum >> 4;
    WD_Checksum = WD_Checksum ^ WD_Checksum >> 2;
    WD_Checksum = WD_Checksum ^ WD_Checksum >> 1;

    if(WD_Checksum > 0) {
        /* Set parity bit */
        WD_CTRL = CTRL_WD_CTRL | 0x80U;
    }

    /* Check if ID is configured to be extended */
    if((CTRL_SWK_ID0_CTRL & SBC_SWK_ID0_CTRL_IDE_Msk) == SBC_IDE_EXTENDED) {
        /* extended ID */
        uint32_t SWK_ID_CTRL = CTRL_SWK_IDx_CTRL << 3;
        uint32_t SWK_MASK_ID_CTRL = CTRL_SWK_MASK_IDx_CTRL << 3;

        SWK_ID3_CTRL = (uint8_t)(SWK_ID_CTRL >> 24);
        SWK_ID2_CTRL = (uint8_t)(SWK_ID_CTRL >> 16);
        SWK_ID1_CTRL = (uint8_t)(SWK_ID_CTRL >> 8);
        SWK_ID0_CTRL = (((uint8_t)(SWK_ID_CTRL >> 1)) & SBC_SWK_ID0_CTRL_ID4_0_Msk) | SBC_IDE_EXTENDED;
        SWK_MASK_ID3_CTRL = (uint8_t)(SWK_MASK_ID_CTRL >> 24);
        SWK_MASK_ID2_CTRL = (uint8_t)(SWK_MASK_ID_CTRL >> 16);
        SWK_MASK_ID1_CTRL = (uint8_t)(SWK_MASK_ID_CTRL >> 8);
        SWK_MASK_ID0_CTRL = (((uint8_t)(SWK_MASK_ID_CTRL >> 1)) & SBC_SWK_MASK_ID0_CTRL_MASK_ID4_0_Msk);
    } else {
        /* Standard length ID */
        uint16_t SWK_ID_CTRL = CTRL_SWK_IDx_CTRL;
        uint32_t SWK_MASK_ID_CTRL = CTRL_SWK_MASK_IDx_CTRL;

        SWK_ID3_CTRL = (uint8_t)(SWK_ID_CTRL >> 3);
        SWK_ID2_CTRL = (uint8_t)(SWK_ID_CTRL << 5);
        SWK_ID1_CTRL = 0x00U;
        SWK_ID0_CTRL = 0x00U;
        SWK_MASK_ID3_CTRL = (uint8_t)(SWK_MASK_ID_CTRL >> 3);
        SWK_MASK_ID2_CTRL = (uint8_t)(SWK_MASK_ID_CTRL << 5);
        SWK_MASK_ID1_CTRL = 0x00U;
        SWK_MASK_ID0_CTRL = 0x00U;
    }

    /* DIS_ERR_CNT is set only when FD Tolerance is set. */
    if((CTRL_SWK_CAN_FD_CTRL & SBC_SWK_CAN_FD_CTRL_CAN_FD_EN_Msk) == SBC_CAN_FD_EN_ENABLED) {
        SWK_CAN_FD_CTRL &= SBC_DIS_ERR_CNT_DISABLED << SBC_SWK_CAN_FD_CTRL_DIS_ERR_CNT_Pos;
    }

    /* Describes initialization sequence */
    uint8_t initSequence[39][2] = {
        {SBC_WD_CTRL, WD_CTRL},
        {SBC_M_S_CTRL, CTRL_M_S_CTRL},
        {SBC_HW_CTRL_0, CTRL_HW_CTRL_0},
        {SBC_HW_CTRL_3, CTRL_HW_CTRL_3},
        {SBC_BUS_CTRL_3, CTRL_BUS_CTRL_3},
        {SBC_WK_CTRL_0, CTRL_WK_CTRL_0},
        {SBC_WK_CTRL_1, CTRL_WK_CTRL_1},
        {SBC_WK_PUPD_CTRL, CTRL_WK_PUPD_CTRL},
        {SBC_TIMER_CTRL, CTRL_TIMER_CTRL},
        {SBC_PWM_FREQ_CTRL, CTRL_PWM_FREQ_CTRL}, /* The desired duty cycle should be set first before GPIO is enabled as PWM HS or PWM LS. */
        {SBC_PWM_CTRL, CTRL_PWM_CTRL},
        {SBC_GPIO_CTRL, CTRL_GPIO_CTRL},
        {SBC_HW_CTRL_1, CTRL_HW_CTRL_1}, /* May lock configuration (CFG_LOCK_0) */
        {SBC_HW_CTRL_2, CTRL_HW_CTRL_2}, /* May lock configuration (CFG_LOCK_1) */
        {SBC_BUS_CTRL_0, CTRL_BUS_CTRL_0},

        /* -------------------------- SELECTIVE WAKE REGISTERS --------------------------- */

        /* Configuring CDR */
        {SBC_SWK_CDR_CTRL2, CTRL_SWK_CDR_CTRL2},
        {SBC_SWK_BTL0_CTRL, CTRL_SWK_BTL0_CTRL},
        {SBC_SWK_CDR_LIMIT_HIGH_CTRL, CTRL_SWK_CDR_LIMIT_HIGH_CTRL},
        {SBC_SWK_CDR_LIMIT_LOW_CTRL, CTRL_SWK_CDR_LIMIT_LOW_CTRL},
        {SBC_SWK_CDR_CTRL1, (SBC_SEL_FILT_TC16 << SBC_SWK_CDR_CTRL1_SEL_FILT_Pos) | (SBC_CDR_EN_ENABLED << SBC_SWK_CDR_CTRL1_CDR_EN_Pos)},


        /* Set ID */
        {SBC_SWK_ID3_CTRL, SWK_ID3_CTRL},
        {SBC_SWK_ID2_CTRL, SWK_ID2_CTRL},
        {SBC_SWK_ID1_CTRL, SWK_ID1_CTRL},
        {SBC_SWK_ID0_CTRL, SWK_ID0_CTRL},

        /* Set Mask */
        {SBC_SWK_MASK_ID3_CTRL, SWK_MASK_ID3_CTRL},
        {SBC_SWK_MASK_ID2_CTRL, SWK_MASK_ID2_CTRL},
        {SBC_SWK_MASK_ID1_CTRL, SWK_MASK_ID1_CTRL},
        {SBC_SWK_MASK_ID0_CTRL, SWK_MASK_ID0_CTRL},

        /* Set Data */
        {SBC_SWK_DATA7_CTRL, (uint8_t)(CTRL_SWK_DATA_H_CTRL >> 24)},
        {SBC_SWK_DATA6_CTRL, (uint8_t)(CTRL_SWK_DATA_H_CTRL >> 16)},
        {SBC_SWK_DATA5_CTRL, (uint8_t)(CTRL_SWK_DATA_H_CTRL >> 8)},
        {SBC_SWK_DATA4_CTRL, (uint8_t)(CTRL_SWK_DATA_H_CTRL >> 0)},
        {SBC_SWK_DATA3_CTRL, (uint8_t)(CTRL_SWK_DATA_L_CTRL >> 24)},
        {SBC_SWK_DATA2_CTRL, (uint8_t)(CTRL_SWK_DATA_L_CTRL >> 16)},
        {SBC_SWK_DATA1_CTRL, (uint8_t)(CTRL_SWK_DATA_L_CTRL >> 8)},
        {SBC_SWK_DATA0_CTRL, (uint8_t)(CTRL_SWK_DATA_L_CTRL >> 0)},

         /* Set DLC */
        {SBC_SWK_DLC_CTRL, CTRL_SWK_DLC_CTRL},

        {SBC_SWK_CAN_FD_CTRL, SWK_CAN_FD_CTRL},

        /* End Configuration */
        {0x00U, 0x00U}
    };

    /* Call SPI Init */
    if(SBC_SPI_INIT() != 0) {
        errCode.SBC_Register = 0x00;
        errCode.flippedBitsMask = 0xFF;
        errCode.expectedValue = 0x00;
        return errCode;
    };

    uint8_t i = 0;

    /* Write all initialization items to Lite SBC */
    while(initSequence[i][0] != 0x00U || initSequence[i][1] != 0x00U) {
        errCode = SBC_Write_Reg(initSequence[i][0], initSequence[i][1], NULL);
        if(errCode.flippedBitsMask > 0) {
            return errCode;
        }
        i++;
    }

    errCode.SBC_Register = 0x00;
    errCode.flippedBitsMask = 0x00;
    errCode.expectedValue = 0x00;
    return errCode;
}



/* --------------------------------  ISR Functions -------------------------------- */


void SBC_Register_Callback(uint32_t ISR_Vector, void (*Callback_Handler)(uint8_t callbackHandler)) {
    /* Save callback */
    SBC_ISR_Callbacks[SBC_RegisteredCallbacks] = Callback_Handler;

    /* Save callback vector */
    SBC_ISR_Vectors[SBC_RegisteredCallbacks] = ISR_Vector;

    /* Check if the register will be readout already to avoid double-readout later */
    uint8_t RegFound = 0;
    for (uint8_t i = 0; i < SBC_RegisteredRedoutRegs; i++) {
        if (SBC_ISR_ReadOutRegs[i] == (ISR_Vector >> 24)) {
            RegFound = 1;
        }
    }

    /* If readout status-reg was not found, register in the readout list */
    if (RegFound == 0) {
        SBC_ISR_ReadOutRegs[SBC_RegisteredRedoutRegs] = (uint8_t)(ISR_Vector >> 24);
        SBC_RegisteredRedoutRegs++;
    }

    SBC_RegisteredCallbacks++;
}


SBC_ErrorCode SBC_ISR(void) {
    SBC_ErrorCode errCode;

    /* Readout all registered status-registers */
    for (uint8_t i = 0; i < SBC_RegisteredRedoutRegs; i++) {
        SBC_ISR_ReadOutVals[i] = (uint8_t) SBC_Read_Command(SBC_ISR_ReadOutRegs[i]);
    }

    /* Handle all interrupts */
    for (uint8_t i = 0; i < SBC_RegisteredCallbacks; i++) {
        /* Decode ISR Vector */
        uint8_t Compare = (uint8_t)SBC_ISR_Vectors[i];
        uint8_t FieldPos = (uint8_t)(SBC_ISR_Vectors[i] >> 8);
        uint8_t FieldMsk = (uint8_t)(SBC_ISR_Vectors[i] >> 16);
        uint8_t RegAddr = (uint8_t)(SBC_ISR_Vectors[i] >> 24);

        /* Readback of associated status-bit */
        uint8_t ReadBack = 0;
        for (uint8_t j = 0; j < SBC_RegisteredRedoutRegs; j++) {
            if (SBC_ISR_ReadOutRegs[j] == RegAddr) {
                ReadBack = SBC_ISR_ReadOutVals[j];
                break;
          }
        }

        /* If compare-values matched -> proceed callback and clear field */
        if (((ReadBack & FieldMsk) >> FieldPos) == Compare) {
            SBC_ISR_Callbacks[i](ReadBack);
        }
    }

    /* Clear all ISR related registers */
    for (uint8_t i = 0; i < SBC_RegisteredRedoutRegs; i++) {
        errCode = SBC_Write_Reg(SBC_ISR_ReadOutRegs[i], 0x00U, NULL);
        if(errCode.flippedBitsMask > 0) {
            return errCode;
        }
    }

    errCode.SBC_Register = 0x00U;
    errCode.flippedBitsMask = 0x00U;
    errCode.expectedValue = 0x00U;
    return errCode;
}



/* --------------------------------  API Calls  ----------------------------------- */

SBC_ErrorCode SBC_Mode_Normal(void) {
    return SBC_Write_RegField(SBC_M_S_CTRL, SBC_M_S_CTRL_MODE_Msk, SBC_M_S_CTRL_MODE_Pos, SBC_MODE_NORMAL, NULL);
}


SBC_ErrorCode SBC_Mode_Stop(void) {
    return SBC_Write_RegField(SBC_M_S_CTRL, SBC_M_S_CTRL_MODE_Msk, SBC_M_S_CTRL_MODE_Pos, SBC_MODE_STOP, NULL);
}


SBC_ErrorCode SBC_Mode_Sleep(void) {
    uint8_t registerReadOut;

    SBC_ErrorCode errCode;

    /* If CAN PN is configured */
    if(MATH_EN_PN != 0) {

        /* Reading value of SWK_STAT. */
        registerReadOut = (uint8_t)SBC_Read_Command(SBC_SWK_STAT);

        /* CAN Protocol Handler in sync? The selective wake routine should be aborted if sync is not set. Note: for SYNC to be set the transceiver must have been in Normal Mode and a valid CAN communication must have been sent on the bus by any node. */
        if((registerReadOut & SBC_SWK_STAT_SYNC_Msk) >> SBC_SWK_STAT_SYNC_Pos != SBC_SYNC_VALID_FRAME_RECEIVED) {
            errCode.SBC_Register = SBC_SWK_STAT;
            errCode.flippedBitsMask = SBC_SWK_STAT_SYNC_Msk;
            errCode.expectedValue = SBC_SYNC_VALID_FRAME_RECEIVED << SBC_SWK_STAT_SYNC_Pos;
            return errCode;
        }

        /* Set SWK Configuration valid */
        errCode = SBC_Write_RegField(SBC_SWK_CTRL, SBC_SWK_CTRL_CFG_VAL_Msk, SBC_SWK_CTRL_CFG_VAL_Pos, SBC_CFG_VAL_VALID, NULL);
        if(errCode.flippedBitsMask > 0) {
            return errCode;
        }
		
		
		/* Clear SYSERR bit */
        errCode = SBC_Write_RegField(SBC_BUS_STAT, SBC_BUS_STAT_SYSERR_Msk, SBC_BUS_STAT_SYSERR_Pos, 0x00, NULL);
        if(errCode.flippedBitsMask > 0) {
            return errCode;
        }	

        /* Set CAN Mode to off and once again to desired configuration */
        errCode = SBC_Write_Reg(SBC_BUS_CTRL_0, 0x03, NULL);
        if(errCode.flippedBitsMask > 0) {
            return errCode;
        }
		
        errCode = SBC_Write_Reg(SBC_BUS_CTRL_0, CTRL_BUS_CTRL_0, NULL);
        if(errCode.flippedBitsMask > 0) {
            return errCode;
        }

		 /* Check SWK_STAT for SYNC == 1 && SWK_SET == 1 && WUF == 0 && WUP == 0. Ignore CANSIL */
		registerReadOut = (uint8_t)SBC_Read_Command(SBC_SWK_STAT);
        if(        ((SBC_SWK_STAT_SYNC_Msk & registerReadOut) == SBC_SWK_STAT_SYNC_Msk)
            && ((SBC_SWK_STAT_SWK_SET_Msk & registerReadOut) == SBC_SWK_STAT_SWK_SET_Msk)
            && ((SBC_SWK_STAT_WUP_Msk & registerReadOut) != SBC_SWK_STAT_WUP_Msk)
            && ((SBC_SWK_STAT_WUF_Msk & registerReadOut) != SBC_SWK_STAT_WUF_Msk)) {
        /* Empty */
        } else {
            errCode.SBC_Register = SBC_SWK_STAT;
            errCode.expectedValue = 0b01000100U;
            errCode.flippedBitsMask = errCode.expectedValue ^ registerReadOut;
            return errCode;
        }
		
		
		
    }

	

    /* Clear Wake Status Registers, so that SBC can sleep. */
    errCode = SBC_Write_Reg(SBC_WK_STAT_0, 0x00, NULL);
    if(errCode.flippedBitsMask > 0) {
        return errCode;
    }
    errCode = SBC_Write_Reg(SBC_WK_STAT_1, 0x00, NULL);
    if(errCode.flippedBitsMask > 0) {
        return errCode;
    }
	
    /* Select sleep mode */
    (void)SBC_Write_RegField(SBC_M_S_CTRL, SBC_M_S_CTRL_MODE_Msk, SBC_M_S_CTRL_MODE_Pos, SBC_MODE_SLEEP, NULL);
    registerReadOut = (uint8_t)SBC_Read_Command(SBC_M_S_CTRL);

    /* This piece of code is ideally never reached as the microcontroller should be already turned off then */
    if(registerReadOut != 0) {
        errCode.SBC_Register = SBC_M_S_CTRL;
        errCode.flippedBitsMask = registerReadOut;
        errCode.expectedValue = 0x00U;
        return errCode;
    }

    errCode.SBC_Register = 0x00U;
    errCode.flippedBitsMask = 0x00U;
    errCode.expectedValue = 0x00U;
    return errCode;
}


SBC_ErrorCode SBC_Set_DutyCycle_PWM (uint8_t PWM_DC) {
    return SBC_Write_Reg(SBC_PWM_CTRL, PWM_DC, NULL);
}


SBC_ErrorCode SBC_Set_Timer_On (uint8_t OnTime) {
    return SBC_Write_RegField(SBC_TIMER_CTRL, SBC_TIMER_CTRL_TIMER_ON_Msk, SBC_TIMER_CTRL_TIMER_ON_Pos, OnTime, NULL);
}


SBC_ErrorCode SBC_Set_Timer_Period (uint8_t Period) {
    return SBC_Write_RegField(SBC_TIMER_CTRL, SBC_TIMER_CTRL_TIMER_PER_Msk, SBC_TIMER_CTRL_TIMER_PER_Pos, Period, NULL);
}


SBC_ErrorCode SBC_FO_Test_On(void) {
    return SBC_Write_RegField(SBC_HW_CTRL_0, SBC_HW_CTRL_0_FO_ON_Msk, SBC_HW_CTRL_0_FO_ON_Pos, SBC_FO_ON_ACTIVE, NULL);
}


SBC_ErrorCode SBC_FO_Test_Off(void) {
    return SBC_Write_RegField(SBC_HW_CTRL_0, SBC_HW_CTRL_0_FO_ON_Msk, SBC_HW_CTRL_0_FO_ON_Pos, SBC_FO_ON_NOT_ACTIVE, NULL);
}


SBC_ErrorCode SBC_CP_On(void) {
    return SBC_Write_RegField(SBC_HW_CTRL_0, SBC_HW_CTRL_0_CP_EN_Msk, SBC_HW_CTRL_0_CP_EN_Pos, SBC_CP_EN_ON, NULL);
}


SBC_ErrorCode SBC_CP_Off(void) {
    return SBC_Write_RegField(SBC_HW_CTRL_0, SBC_HW_CTRL_0_CP_EN_Msk, SBC_HW_CTRL_0_CP_EN_Pos, SBC_CP_EN_OFF, NULL);
}


SBC_ErrorCode SBC_WK_MEAS_On(void) {
    return SBC_Write_RegField(SBC_WK_CTRL_1, SBC_WK_CTRL_1_WK_MEAS_Msk, SBC_WK_CTRL_1_WK_MEAS_Pos, SBC_WK_MEAS_WK_AS_VOLTAGESENSING, NULL);
}


SBC_ErrorCode SBC_WK_MEAS_Off(void) {
    return SBC_Write_RegField(SBC_WK_CTRL_1, SBC_WK_CTRL_1_WK_MEAS_Msk, SBC_WK_CTRL_1_WK_MEAS_Pos, SBC_WK_MEAS_WK_AS_WAKEUP, NULL);
}


SBC_ErrorCode SBC_TIMER_WK_EN_On(void) {
    return SBC_Write_RegField(SBC_WK_CTRL_0, SBC_WK_CTRL_0_TIMER_WK_EN_Msk, SBC_WK_CTRL_0_TIMER_WK_EN_Pos, WK_CTRL_0_TIMER_WK_EN_WAKESOURCE, NULL);
}


SBC_ErrorCode SBC_TIMER_WK_EN_Off(void) {
    return SBC_Write_RegField(SBC_WK_CTRL_0, SBC_WK_CTRL_0_TIMER_WK_EN_Msk, SBC_WK_CTRL_0_TIMER_WK_EN_Pos, WK_CTRL_0_TIMER_WK_EN_WAKEUP_DISABLED, NULL);
}


uint16_t SBC_SYS_STAT_Read(void) {
    uint16_t systemStatus = 0;
    uint16_t returndata = SBC_Read_Command(SBC_SYS_STATUS_CTRL_0);
    systemStatus = returndata & 0x00FFU;
    systemStatus |= SBC_Read_Command(SBC_SYS_STATUS_CTRL_1) << 8;
    return systemStatus;
}


SBC_ErrorCode SBC_SYS_STAT_Write(uint16_t SystemStatus) {
    SBC_ErrorCode errCode;

    /* Write lower bits */
    errCode = SBC_Write_Reg(SBC_SYS_STATUS_CTRL_0, (uint8_t)SystemStatus, NULL);
    if(errCode.flippedBitsMask > 0) {
        return errCode;
    }

    /* Write higher bits */
    return SBC_Write_Reg(SBC_SYS_STATUS_CTRL_1, (uint8_t)(SystemStatus >> 8), NULL);
}


SBC_ErrorCode SBC_Lock_Configuration(void) {
    SBC_ErrorCode errCode;

    /* Lock CP_EN and GPIO cannot be modified */
    errCode = SBC_Write_RegField(SBC_HW_CTRL_1, SBC_HW_CTRL_1_CFG_LOCK_0_Msk, SBC_HW_CTRL_1_CFG_LOCK_0_Pos, SBC_CFG_LOCK_0_LOCKED, NULL);
    if(errCode.flippedBitsMask > 0) {
        return errCode;
    }

    /* Lock Bits with bit type ‘rwl’ (except CP_EN and GPIO) until next device power-up. */
    errCode = SBC_Write_RegField(SBC_HW_CTRL_2, SBC_HW_CTRL_2_CFG_LOCK_1_Msk, SBC_HW_CTRL_2_CFG_LOCK_1_Pos, SBC_CFG_LOCK_1_LOCKED, NULL);
    if(errCode.flippedBitsMask > 0) {
        return errCode;
    }

    errCode.SBC_Register = 0x00;
    errCode.flippedBitsMask = 0x00;
    errCode.expectedValue = 0x00;
    return errCode;
}


SBC_ErrorCode SBC_Unlock_Configuration(void) {
    SBC_ErrorCode errCode;

    /* Unlock CP_EN and GPIO configuration. */
    errCode = SBC_Write_RegField(SBC_HW_CTRL_1, SBC_HW_CTRL_1_CFG_LOCK_0_Msk, SBC_HW_CTRL_1_CFG_LOCK_0_Pos, SBC_CFG_LOCK_0_NOTLOCKED, NULL);
    if(errCode.flippedBitsMask > 0) {
        return errCode;
    }

    /* Unlock Bits with bit type ‘rwl’ (except CP_EN and GPIO). */
    errCode = SBC_Write_RegField(SBC_HW_CTRL_2, SBC_HW_CTRL_2_CFG_LOCK_1_Msk, SBC_HW_CTRL_2_CFG_LOCK_1_Pos, SBC_CFG_LOCK_1_NOTLOCKED, NULL);
    if(errCode.flippedBitsMask > 0) {
        return errCode;
    }

    errCode.SBC_Register = 0x00;
    errCode.flippedBitsMask = 0x00;
    errCode.expectedValue = 0x00;
    return errCode;
}

SBC_ErrorCode SBC_Clear_Wake_Status(void) {
    SBC_ErrorCode errCode = SBC_Write_Reg(SBC_WK_STAT_0, 0x00, NULL);
    if(errCode.flippedBitsMask != 0) {
        return errCode;
    }
    errCode = SBC_Write_Reg(SBC_WK_STAT_1, 0x00, NULL);
    if(errCode.flippedBitsMask != 0) {
        return errCode;
    }
    errCode.SBC_Register = 0x00;
    errCode.flippedBitsMask = 0x00;
    errCode.expectedValue = 0x00;
    return errCode;
}