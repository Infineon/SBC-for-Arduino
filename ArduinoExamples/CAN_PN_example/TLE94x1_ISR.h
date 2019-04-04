/*********************************************************************************************************************
 * Copyright (c) 2018, Infineon Technologies AG
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the 
 * following conditions are met:
 * 
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following 
 * disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following 
 * disclaimer in the documentation and/or other materials provided with the distribution.
 * 
 * Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote 
 * products derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************************************************************/


/****************************************************************************************************//**
 * @file        TLE94x1_ISR.h
 *
 * @brief       Declaration file for ISR-Vectors and ISR related functions
 * 
 * @version     V1.0.0
 * @date        26. March 2019
 * @author      Markus Noll / markus.noll@infineon.com
 *******************************************************************************************************/




#ifndef TLE94x1_ISR_H
#define TLE94x1_ISR_H







/* ================================================================================ */
/* ============================   HEADER FILES   ================================== */
/* ================================================================================ */ 

#include "TLE94x1_DEFINES.h"








/* ================================================================================ */
/* ================================   MACROS   ==================================== */
/* ================================================================================ */ 


/**
 * @def     SBC_ISR_VECTOR
 *
 * @brief   Vector defining the handling of interrupts.
 * 
 *          Vectors of this type have to be registered by the SBC_Register_Callback method.
 */
#define SBC_ISR_VECTOR(REG,MASK,POS,COMPARE)    ((((uint32_t)REG) << 24) | (((uint32_t)MASK) << 16) | (((uint32_t)POS) << 8) | ((uint32_t)COMPARE))






/* ================================================================================ */
/* =======================   General Interrupt Defines   ========================== */
/* ================================================================================ */ 



#define SBC_ISR_VS_UV                           SBC_ISR_VECTOR(SBC_SUP_STAT_1,      SBC_SUP_STAT_1_VS_UV_Msk,       SBC_SUP_STAT_1_VS_UV_Pos,       SBC_VS_UV_EVENT)
#define SBC_ISR_VS_OV                           SBC_ISR_VECTOR(SBC_SUP_STAT_1,      SBC_SUP_STAT_1_VS_OV_Msk,       SBC_SUP_STAT_1_VS_OV_Pos,       SBC_VS_OV_EVENT)
#define SBC_ISR_VCC1_OV                         SBC_ISR_VECTOR(SBC_SUP_STAT_1,      SBC_SUP_STAT_1_VCC1_OV_Msk,     SBC_SUP_STAT_1_VCC1_OV_Pos,     SBC_VCC1_OV_EVENT)
#define SBC_ISR_VCC1_UV_PREWARN                 SBC_ISR_VECTOR(SBC_SUP_STAT_1,      SBC_SUP_STAT_1_VCC1_WARN_Msk,   SBC_SUP_STAT_1_VCC1_WARN_Pos,   SBC_VCC1_UV_PREWARN_EVENT)
#define SBC_ISR_VCC2_OT                         SBC_ISR_VECTOR(SBC_SUP_STAT_0,      SBC_SUP_STAT_0_VCC2_OT_Msk,     SBC_SUP_STAT_0_VCC2_OT_Pos,     SBC_VCC2_OT_EVENT)
#define SBC_ISR_VCC2_UV                         SBC_ISR_VECTOR(SBC_SUP_STAT_0,      SBC_SUP_STAT_0_VCC2_UV_Msk,     SBC_SUP_STAT_0_VCC2_UV_Pos,     SBC_VCC2_UV_EVENT)
#define SBC_ISR_VCC1_UV                         SBC_ISR_VECTOR(SBC_SUP_STAT_0,      SBC_SUP_STAT_0_VCC1_UV_Msk,     SBC_SUP_STAT_0_VCC1_UV_Pos,     SBC_VCC1_UV_EVENT)
#define SBC_ISR_TSD2_SAFESTATE                  SBC_ISR_VECTOR(SBC_THERM_STAT,      SBC_THERM_STAT_TSD2_SAFE_Msk,   SBC_THERM_STAT_TSD2_SAFE_Pos,   SBC_TSD2_SAFE_SAFESTATE_DETECTED)
#define SBC_ISR_TSD1                            SBC_ISR_VECTOR(SBC_THERM_STAT,      SBC_THERM_STAT_TSD1_Msk,        SBC_THERM_STAT_TSD1_Pos,        SBC_TSD1_EVENT)
#define SBC_ISR_TPW                             SBC_ISR_VECTOR(SBC_THERM_STAT,      SBC_THERM_STAT_TPW_Msk,         SBC_THERM_STAT_TPW_Pos,         SBC_TPW_EVENT)
#define SBC_ISR_RESTART_DUE_FAIL                SBC_ISR_VECTOR(SBC_DEV_STAT,        SBC_DEV_STAT_DEV_STAT_Msk,      SBC_DEV_STAT_DEV_STAT_Pos,      SBC_DEV_STAT_RESTART_DUE_FAIL)
#define SBC_ISR_FROM_SLEEPMODE                  SBC_ISR_VECTOR(SBC_DEV_STAT,        SBC_DEV_STAT_DEV_STAT_Msk,      SBC_DEV_STAT_DEV_STAT_Pos,      SBC_DEV_STAT_SLEEP_MODE)
#define SBC_ISR_WD_FAIL                         SBC_ISR_VECTOR(SBC_DEV_STAT,        SBC_DEV_STAT_WD_FAIL_Msk,       SBC_DEV_STAT_WD_FAIL_Pos,       SBC_WD_FAIL_1_FAIL)
#define SBC_ISR_FAILURE                         SBC_ISR_VECTOR(SBC_DEV_STAT,        SBC_DEV_STAT_FAILURE_Msk,       SBC_DEV_STAT_FAILURE_Pos,       SBC_FAILURE_EVENT)
#define SBC_ISR_CAN_TSD                         SBC_ISR_VECTOR(SBC_BUS_STAT,        SBC_BUS_STAT_CAN_FAIL_Msk,      SBC_BUS_STAT_CAN_FAIL_Pos,      SBC_CAN_FAIL_TSD)
#define SBC_ISR_CAN_TXD_DOM_TO                  SBC_ISR_VECTOR(SBC_BUS_STAT,        SBC_BUS_STAT_CAN_FAIL_Msk,      SBC_BUS_STAT_CAN_FAIL_Pos,      SBC_CAN_FAIL_TXD_DOM_TO)
#define SBC_ISR_CAN_BUS_DOM_TO                  SBC_ISR_VECTOR(SBC_BUS_STAT,        SBC_BUS_STAT_CAN_FAIL_Msk,      SBC_BUS_STAT_CAN_FAIL_Pos,      SBC_CAN_FAIL_BUS_DOM_TO)
#define SBC_ISR_VCAN_UV                         SBC_ISR_VECTOR(SBC_BUS_STAT,        SBC_BUS_STAT_VCAN_UV_Msk,       SBC_BUS_STAT_VCAN_UV_Pos,       SBC_VCAN_UV_EVENT)
#define SBC_ISR_CAN_WU                          SBC_ISR_VECTOR(SBC_WK_STAT_0,       SBC_WK_STAT_0_CAN_WU_Msk,       SBC_WK_STAT_0_CAN_WU_Pos,       SBC_CAN_WU_EVENT)
#define SBC_ISR_TIMER_WU                        SBC_ISR_VECTOR(SBC_WK_STAT_0,       SBC_WK_STAT_0_TIMER_WU_Msk,     SBC_WK_STAT_0_TIMER_WU_Pos,     SBC_TIMER_WU_EVENT)
#define SBC_ISR_WK_WU                           SBC_ISR_VECTOR(SBC_WK_STAT_0,       SBC_WK_STAT_0_WK_WU_Msk,        SBC_WK_STAT_0_WK_WU_Pos,        SBC_WK_WU_EVENT)
#define SBC_ISR_GPIO_WK_WU                      SBC_ISR_VECTOR(SBC_WK_STAT_1,       SBC_WK_STAT_1_GPIO_WK_WU_Msk,   SBC_WK_STAT_1_GPIO_WK_WU_Pos,   SBC_GPIO_WK_WU_EVENT)
#define SBC_ISR_GPIO_OC                         SBC_ISR_VECTOR(SBC_GPIO_OC_STAT,    SBC_GPIO_OC_STAT_GPIO_OC_Msk,   SBC_GPIO_OC_STAT_GPIO_OC_Pos,   SBC_GPIO_OC_EVENT)
#define SBC_ISR_GPIO_OL                         SBC_ISR_VECTOR(SBC_GPIO_OL_STAT,    SBC_GPIO_OL_STAT_GPIO_OL_Msk,   SBC_GPIO_OL_STAT_GPIO_OL_Pos,   SBC_GPIO_OL_EVENT)
#define SBC_ISR_SWK_VALID_FRAME_RECEIVED        SBC_ISR_VECTOR(SBC_SWK_STAT,        SBC_SWK_STAT_SYNC_Msk,          SBC_SWK_STAT_SYNC_Pos,          SBC_SYNC_VALID_FRAME_RECEIVED)
#define SBC_ISR_SWL_CANSIL_EXCEEDED             SBC_ISR_VECTOR(SBC_SWK_STAT,        SBC_SWK_STAT_CANSIL_Msk,        SBC_SWK_STAT_CANSIL_Pos,        SBC_CANSIL_EXCEEDED)
#define SBC_ISR_SWK_ACTIVE                      SBC_ISR_VECTOR(SBC_SWK_STAT,        SBC_SWK_STAT_SWK_SET_Msk,       SBC_SWK_STAT_SWK_SET_Pos,       SBC_SWK_SET_SWK_ACTIVE)
#define SBC_ISR_SWK_WUP_DETECTED                SBC_ISR_VECTOR(SBC_SWK_STAT,        SBC_SWK_STAT_WUP_Msk,           SBC_SWK_STAT_WUP_Pos,           SBC_WUP_DETECTED)
#define SBC_ISR_SWK_WUF_DETECTED                SBC_ISR_VECTOR(SBC_SWK_STAT,        SBC_SWK_STAT_WUF_Msk,           SBC_SWK_STAT_WUF_Pos,           SBC_WUF_DETECTED)



#endif  /*TLE94x1_ISR_H*/
