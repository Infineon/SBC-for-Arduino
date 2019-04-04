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
 * @file        TLE94x1_DEFINES.h
 *
 * @brief       Main header declaration file for TLE94x1 SBC family device
 *
 * @version     V1.0.0
 * @date        26. March 2019
 * @author      Markus Noll / markus.noll@infineon.com
 *******************************************************************************************************/



#ifndef TLE94x1_DEFINES_H
#define TLE94x1_DEFINES_H






/* ================================================================================ */
/* ================           General Control Registers            ================ */
/* ================================================================================ */



/**
 * @def     SBC_M_S_CTRL
 * 
 * @brief   Control register address.
 */
#define SBC_M_S_CTRL                            (0b00000001U)

/**
 * @def     SBC_HW_CTRL_0
 * 
 * @brief   Control register address.
 */
#define SBC_HW_CTRL_0                           (0b00000010U)

/**
 * @def     SBC_WD_CTRL
 * 
 * @brief   Control register address.
 */
#define SBC_WD_CTRL                             (0b00000011U)

/**
 * @def     SBC_BUS_CTRL_0
 * 
 * @brief   Control register address.
 */
#define SBC_BUS_CTRL_0                          (0b00000100U)

/**
 * @def     SBC_WK_CTRL_0
 * 
 * @brief   Control register address.
 */
#define SBC_WK_CTRL_0                           (0b00000110U)

/**
 * @def     SBC_WK_CTRL_1
 * 
 * @brief   Control register address.
 */
#define SBC_WK_CTRL_1                           (0b00000111U)

/**
 * @def     SBC_WK_PUPD_CTRL
 * 
 * @brief   Control register address.
 */
#define SBC_WK_PUPD_CTRL                        (0b00001000U)

/**
 * @def     SBC_BUS_CTRL_3
 * 
 * @brief   Control register address.
 */
#define SBC_BUS_CTRL_3                          (0b00001011U)

/**
 * @def     SBC_TIMER_CTRL
 * 
 * @brief   Control register address.
 */
#define SBC_TIMER_CTRL                          (0b00001100U)

/**
 * @def     SBC_HW_CTRL_1
 * 
 * @brief   Control register address.
 */
#define SBC_HW_CTRL_1                           (0b00001110U)

/**
 * @def     SBC_HW_CTRL_2
 * 
 * @brief   Control register address.
 */
#define SBC_HW_CTRL_2                           (0b00001111U)

/**
 * @def     SBC_GPIO_CTRL
 * 
 * @brief   Control register address.
 */
#define SBC_GPIO_CTRL                           (0b00010111U)

/**
 * @def     SBC_PWM_CTRL
 * 
 * @brief   Control register address.
 */
#define SBC_PWM_CTRL                            (0b00011000U)

/**
 * @def     SBC_PWM_FREQ_CTRL
 * 
 * @brief   Control register address.
 */
#define SBC_PWM_FREQ_CTRL                       (0b00011100U)

/**
 * @def     SBC_HW_CTRL_3
 * 
 * @brief   Control register address.
 */
#define SBC_HW_CTRL_3                           (0b00011101U)

/**
 * @def     SBC_SYS_STATUS_CTRL_0
 * 
 * @brief   Control register address.
 */
#define SBC_SYS_STATUS_CTRL_0                   (0b00011110U)

/**
 * @def     SBC_SYS_STATUS_CTRL_1
 * 
 * @brief   Control register address.
 */
#define SBC_SYS_STATUS_CTRL_1                   (0b00011111U)






/* ================================================================================ */
/* ================        Selective Wake Control Registers        ================ */
/* ================================================================================ */



/**
 * @def     SBC_SWK_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_CTRL                            (0b00100000U)

/**
 * @def     SBC_SWK_BTL0_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_BTL0_CTRL                       (0b00100001U)

/**
 * @def     SBC_SWK_BTL1_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_BTL1_CTRL                       (0b00100010U)

/**
 * @def     SBC_SWK_ID3_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_ID3_CTRL                        (0b00100011U)

/**
 * @def     SBC_SWK_ID2_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_ID2_CTRL                        (0b00100100U)

/**
 * @def     SBC_SWK_ID1_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_ID1_CTRL                        (0b00100101U)

/**
 * @def     SBC_SWK_ID0_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_ID0_CTRL                        (0b00100110U)

/**
 * @def     SBC_SWK_MASK_ID3_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_MASK_ID3_CTRL                   (0b00100111U)

/**
 * @def     SBC_SWK_MASK_ID2_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_MASK_ID2_CTRL                   (0b00101000U)

/**
 * @def     SBC_SWK_MASK_ID1_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_MASK_ID1_CTRL                   (0b00101001U)

/**
 * @def     SBC_SWK_MASK_ID0_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_MASK_ID0_CTRL                   (0b00101010U)

/**
 * @def     SBC_SWK_DLC_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_DLC_CTRL                        (0b00101011U)

/**
 * @def     SBC_SWK_DATA7_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_DATA7_CTRL                      (0b00101100U)

/**
 * @def     SBC_SWK_DATA6_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_DATA6_CTRL                      (0b00101101U)

/**
 * @def     SBC_SWK_DATA5_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_DATA5_CTRL                      (0b00101110U)

/**
 * @def     SBC_SWK_DATA4_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_DATA4_CTRL                      (0b00101111U)

/**
 * @def     SBC_SWK_DATA3_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_DATA3_CTRL                      (0b00110000U)

/**
 * @def     SBC_SWK_DATA2_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_DATA2_CTRL                      (0b00110001U)

/**
 * @def     SBC_SWK_DATA1_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_DATA1_CTRL                      (0b00110010U)

/**
 * @def     SBC_SWK_DATA0_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_DATA0_CTRL                      (0b00110011U)

/**
 * @def     SBC_SWK_CAN_FD_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_CAN_FD_CTRL                     (0b00110100U)

/**
 * @def     SBC_SWK_OSC_TRIM_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_OSC_TRIM_CTRL                   (0b00111000U)

/**
 * @def     SBC_SWK_OPT_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_OPT_CTRL                        (0b00111001U)

/**
 * @def     SBC_SWK_OSC_CAL_H_STAT
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_OSC_CAL_H_STAT                  (0b00111010U)

/**
 * @def     SBC_SWK_OSC_CAL_L_STAT
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_OSC_CAL_L_STAT                  (0b00111011U)

/**
 * @def     SBC_SWK_CDR_CTRL1
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_CDR_CTRL1                       (0b00111100U)

/**
 * @def     SBC_SWK_CDR_CTRL2
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_CDR_CTRL2                       (0b00111101U)

/**
 * @def     SBC_SWK_CDR_LIMIT_HIGH_CTRL
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_CDR_LIMIT_HIGH_CTRL             (0b00111110U)

/**
 * @def     SBC_SWK_CDR_LIMIT_LOW_CTRL 
 * 
 * @brief   Selective wake register address.
 */
#define SBC_SWK_CDR_LIMIT_LOW_CTRL              (0b00111111U)






/* ================================================================================ */
/* ================            General Status Registers            ================ */
/* ================================================================================ */




/**
 * @def     SBC_SUP_STAT_1
 * 
 * @brief   Status register address.
 */
#define SBC_SUP_STAT_1                          (0b01000000U)

/**
 * @def     SBC_SUP_STAT_0
 * 
 * @brief   Status register address.
 */
#define SBC_SUP_STAT_0                          (0b01000001U)

/**
 * @def     SBC_THERM_STAT
 * 
 * @brief   Status register address.
 */
#define SBC_THERM_STAT                          (0b01000010U)

/**
 * @def     SBC_DEV_STAT
 * 
 * @brief   Status register address.
 */
#define SBC_DEV_STAT                            (0b01000011U)

/**
 * @def     SBC_BUS_STAT
 * 
 * @brief   Status register address.
 */
#define SBC_BUS_STAT                            (0b01000100U)

/**
 * @def     SBC_WK_STAT_0
 * 
 * @brief   Status register address.
 */
#define SBC_WK_STAT_0                           (0b01000110U)

/**
 * @def     SBC_WK_STAT_1
 * 
 * @brief   Status register address.
 */
#define SBC_WK_STAT_1                           (0b01000111U)

/**
 * @def     SBC_WK_LVL_STAT 
 * 
 * @brief   Status register address.
 */
#define SBC_WK_LVL_STAT                         (0b01001000U)

/**
 * @def     SBC_GPIO_OC_STAT
 * 
 * @brief   Status register address.
 */
#define SBC_GPIO_OC_STAT                        (0b01010100U)

/**
 * @def     SBC_GPIO_OL_STAT
 * 
 * @brief   Status register address.
 */
#define SBC_GPIO_OL_STAT                        (0b01010101U)






/* ================================================================================ */
/* ================        Selective Wake Status Registers         ================ */
/* ================================================================================ */




/**
 * @def     SBC_SWK_STAT
 * 
 * @brief   Selective wake status register address.
 */
#define SBC_SWK_STAT                            (0b01110000U)

/**
 * @def     SBC_SWK_ECNT_STAT
 * 
 * @brief   Selective wake status register address.
 */
#define SBC_SWK_ECNT_STAT                       (0b01110001U)

/**
 * @def     SBC_SWK_CDR_STAT1
 * 
 * @brief   Selective wake status register address.
 */
#define SBC_SWK_CDR_STAT1                       (0b01110010U)

/**
 * @def     SBC_SWK_CDR_STAT2
 * 
 * @brief   Selective wake status register address.
 */
#define SBC_SWK_CDR_STAT2                       (0b01110011U)

/**
 * @def     SBC_FAM_PROD_STAT
 * 
 * @brief   Selective wake status register address.
 */
#define SBC_FAM_PROD_STAT                       (0b01111110U)






/* ================================================================================ */
/* ============   General Control Registers Position & Mask        ================ */
/* ================================================================================ */



/* --------------------------------  M_S_CTRL  ------------------------------------ */

/**
 * @def     SBC_M_S_CTRL_MODE_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_M_S_CTRL_MODE_Pos                   (6U)
/**
 * @def     SBC_M_S_CTRL_MODE_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_M_S_CTRL_MODE_Msk                   (0b11000000U)
/**
 * @def     SBC_M_S_CTRL_VCC2_ON_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_M_S_CTRL_VCC2_ON_Pos                (3U)
/**
 * @def     SBC_M_S_CTRL_VCC2_ON_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_M_S_CTRL_VCC2_ON_Msk                (0b00011000U)
/**
 * @def     SBC_M_S_CTRL_VCC1_OV_RST_Pos 
 * 
 * @brief   Control register bit position.
 */
#define SBC_M_S_CTRL_VCC1_OV_RST_Pos            (2U)
/**
 * @def     SBC_M_S_CTRL_VCC1_OV_RST_Msk 
 * 
 * @brief   Control register bit mask.
 */
#define SBC_M_S_CTRL_VCC1_OV_RST_Msk            (0b00000100U)
/**
 * @def     SBC_M_S_CTRL_VCC1_RT_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_M_S_CTRL_VCC1_RT_Pos                (0U)
/**
 * @def     SBC_M_S_CTRL_VCC1_RT_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_M_S_CTRL_VCC1_RT_Msk                (0b00000011U)


/* --------------------------------  HW_CTRL_0  ----------------------------------- */


/**
 * @def     SBC_HW_CTRL_0_SOFT_RESET_RST_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_HW_CTRL_0_SOFT_RESET_RST_Pos        (6U)

/**
 * @def     SBC_HW_CTRL_0_SOFT_RESET_RST_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_HW_CTRL_0_SOFT_RESET_RST_Msk        (0b01000000U)

/**
 * @def     SBC_HW_CTRL_0_FO_ON_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_HW_CTRL_0_FO_ON_Pos                 (5U)

/**
 * @def     SBC_HW_CTRL_0_FO_ON_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_HW_CTRL_0_FO_ON_Msk                 (0b00100000U)

/**
 * @def     SBC_HW_CTRL_0_CP_EN_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_HW_CTRL_0_CP_EN_Pos                 (2U)

/**
 * @def     SBC_HW_CTRL_0_CP_EN_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_HW_CTRL_0_CP_EN_Msk                 (0b00000100U)

/**
 * @def     SBC_HW_CTRL_0_CFG1_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_HW_CTRL_0_CFG1_Pos                  (0U)

/**
 * @def     SBC_HW_CTRL_0_CFG1_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_HW_CTRL_0_CFG1_Msk                  (0b00000001U)


/* --------------------------------  WD_CTRL    ----------------------------------- */


/**
 * @def     SBC_WD_CTRL_CHECKSUM_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_WD_CTRL_CHECKSUM_Pos                (7U)

/**
 * @def     SBC_WD_CTRL_CHECKSUM_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_WD_CTRL_CHECKSUM_Msk                (0b10000000U)

/**
 * @def     SBC_WD_CTRL_WD_STM_EN_0_Pos 
 * 
 * @brief   Control register bit position.
 */
#define SBC_WD_CTRL_WD_STM_EN_0_Pos             (6U)

/**
 * @def     SBC_WD_CTRL_WD_STM_EN_0_Msk 
 * 
 * @brief   Control register bit mask.
 */
#define SBC_WD_CTRL_WD_STM_EN_0_Msk             (0b01000000U)

/**
 * @def     SBC_WD_CTRL_WD_WIN_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_WD_CTRL_WD_WIN_Pos                  (5U)

/**
 * @def     SBC_WD_CTRL_WD_WIN_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_WD_CTRL_WD_WIN_Msk                  (0b00100000U)

/**
 * @def     SBC_WD_CTRL_WD_EN_WK_BUS_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_WD_CTRL_WD_EN_WK_BUS_Pos            (4U)

/**
 * @def     SBC_WD_CTRL_WD_EN_WK_BUS_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_WD_CTRL_WD_EN_WK_BUS_Msk            (0b00010000U)

/**
 * @def     SBC_WD_CTRL_WD_TIMER_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_WD_CTRL_WD_TIMER_Pos                (0U)

/**
 * @def     SBC_WD_CTRL_WD_TIMER_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_WD_CTRL_WD_TIMER_Msk                (0b00000111U)


/* --------------------------------  BUS_CTRL_0  ---------------------------------- */

/**
 * @def     SBC_BUS_CTRL_0_CAN_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_BUS_CTRL_0_CAN_Pos                  (0U)

/**
 * @def     SBC_BUS_CTRL_0_CAN_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_BUS_CTRL_0_CAN_Msk                  (0b00000111U)


/* --------------------------------  WK_CTRL_0  ----------------------------------- */

/**
 * @def     SBC_WK_CTRL_0_TIMER_WK_EN_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_WK_CTRL_0_TIMER_WK_EN_Pos           (6U)

/**
 * @def     SBC_WK_CTRL_0_TIMER_WK_EN_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_WK_CTRL_0_TIMER_WK_EN_Msk           (0b01000000U)

/**
 * @def     SBC_WK_CTRL_0_WD_STM_EN_1_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_WK_CTRL_0_WD_STM_EN_1_Pos           (2U)

/**
 * @def     SBC_WK_CTRL_0_WD_STM_EN_1_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_WK_CTRL_0_WD_STM_EN_1_Msk           (0b00000100U)


/* --------------------------------  WK_CTRL_1  ----------------------------------- */


/**
 * @def     SBC_WK_CTRL_1_INT_GLOBAL_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_WK_CTRL_1_INT_GLOBAL_Pos            (7U)

/**
 * @def     SBC_WK_CTRL_1_INT_GLOBAL_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_WK_CTRL_1_INT_GLOBAL_Msk            (0b10000000U)

/**
 * @def     SBC_WK_CTRL_1_WK_MEAS_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_WK_CTRL_1_WK_MEAS_Pos               (5U)

/**
 * @def     SBC_WK_CTRL_1_WK_MEAS_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_WK_CTRL_1_WK_MEAS_Msk               (0b00100000U)

/**
 * @def     SBC_WK_CTRL_1_WK_EN_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_WK_CTRL_1_WK_EN_Pos                 (0U)

/**
 * @def     SBC_WK_CTRL_1_WK_EN_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_WK_CTRL_1_WK_EN_Msk                 (0b00000001U)


/* --------------------------------  WK_PUPD_CTRL  -------------------------------- */


/**
 * @def     SBC_WK_PUPD_CTRL_GPIO_WK_PUPD_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_WK_PUPD_CTRL_GPIO_WK_PUPD_Pos       (6U)

/**
 * @def     SBC_WK_PUPD_CTRL_GPIO_WK_PUPD_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_WK_PUPD_CTRL_GPIO_WK_PUPD_Msk       (0b11000000U)

/**
 * @def     SBC_WK_PUPD_CTRL_WK_PUPD_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_WK_PUPD_CTRL_WK_PUPD_Pos            (0U)

/**
 * @def     SBC_WK_PUPD_CTRL_WK_PUPD_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_WK_PUPD_CTRL_WK_PUPD_Msk            (0b00000011U)


/* -------------------------------   BUS_CTRL_3  ---------------------------------- */

/**
 * @def     SBC_BUS_CTRL_3_CAN_FLASH_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_BUS_CTRL_3_CAN_FLASH_Pos            (4U)

/**
 * @def     SBC_BUS_CTRL_3_CAN_FLASH_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_BUS_CTRL_3_CAN_FLASH_Msk            (0b00010000U)


/* -------------------------------   TIMER_CTRL  ---------------------------------- */


/**
 * @def     SBC_TIMER_CTRL_TIMER_ON_Pos 
 * 
 * @brief   Control register bit position.
 */
#define SBC_TIMER_CTRL_TIMER_ON_Pos             (4U)

/**
 * @def     SBC_TIMER_CTRL_TIMER_ON_Msk 
 * 
 * @brief   Control register bit mask.
 */
#define SBC_TIMER_CTRL_TIMER_ON_Msk             (0b01110000U)

/**
 * @def     SBC_TIMER_CTRL_TIMER_PER_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_TIMER_CTRL_TIMER_PER_Pos            (0U)

/**
 * @def     SBC_TIMER_CTRL_TIMER_PER_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_TIMER_CTRL_TIMER_PER_Msk            (0b00001111U)


/* --------------------------------  HW_CTRL_1  ----------------------------------- */


/**
 * @def     SBC_HW_CTRL_1_RSTN_HYS_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_HW_CTRL_1_RSTN_HYS_Pos              (7U)

/**
 * @def     SBC_HW_CTRL_1_RSTN_HYS_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_HW_CTRL_1_RSTN_HYS_Msk              (0b10000000U)

/**
 * @def     SBC_HW_CTRL_1_TSD2_DEL_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_HW_CTRL_1_TSD2_DEL_Pos              (5U)

/**
 * @def     SBC_HW_CTRL_1_TSD2_DEL_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_HW_CTRL_1_TSD2_DEL_Msk              (0b00100000U)

/**
 * @def     SBC_HW_CTRL_1_RSTN_DEL_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_HW_CTRL_1_RSTN_DEL_Pos              (4U)

/**
 * @def     SBC_HW_CTRL_1_RSTN_DEL_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_HW_CTRL_1_RSTN_DEL_Msk              (0b00010000U)

/**
 * @def     SBC_HW_CTRL_1_CFG_LOCK_0_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_HW_CTRL_1_CFG_LOCK_0_Pos            (3U)

/**
 * @def     SBC_HW_CTRL_1_CFG_LOCK_0_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_HW_CTRL_1_CFG_LOCK_0_Msk            (0b00001000U)


/* --------------------------------  HW_CTRL_2  ----------------------------------- */


/**
 * @def     SBC_HW_CTRL_2_2MHZ_FREQ_Pos 
 * 
 * @brief   Control register bit position.
 */
#define SBC_HW_CTRL_2_2MHZ_FREQ_Pos             (5U)

/**
 * @def     SBC_HW_CTRL_2_2MHZ_FREQ_Msk 
 * 
 * @brief   Control register bit mask.
 */
#define SBC_HW_CTRL_2_2MHZ_FREQ_Msk             (0b11100000U)

/**
 * @def     SBC_HW_CTRL_2_I_PEAK_TH_Pos 
 * 
 * @brief   Control register bit position.
 */
#define SBC_HW_CTRL_2_I_PEAK_TH_Pos             (4U)

/**
 * @def     SBC_HW_CTRL_2_I_PEAK_TH_Msk 
 * 
 * @brief   Control register bit mask.
 */
#define SBC_HW_CTRL_2_I_PEAK_TH_Msk             (0b00010000U)

/**
 * @def     SBC_HW_CTRL_2_SS_MOD_FR_Pos 
 * 
 * @brief   Control register bit position.
 */
#define SBC_HW_CTRL_2_SS_MOD_FR_Pos             (2U)

/**
 * @def     SBC_HW_CTRL_2_SS_MOD_FR_Msk 
 * 
 * @brief   Control register bit mask.
 */
#define SBC_HW_CTRL_2_SS_MOD_FR_Msk             (0b00001100U)

/**
 * @def     SBC_HW_CTRL_2_CFG_LOCK_1_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_HW_CTRL_2_CFG_LOCK_1_Pos            (0U)

/**
 * @def     SBC_HW_CTRL_2_CFG_LOCK_1_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_HW_CTRL_2_CFG_LOCK_1_Msk            (0b00000001U)


/* --------------------------------  GPIO_CTRL  ----------------------------------- */

/**
 * @def     SBC_GPIO_CTRL_GPIO_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_GPIO_CTRL_GPIO_Pos                  (0U)

/**
 * @def     SBC_GPIO_CTRL_GPIO_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_GPIO_CTRL_GPIO_Msk                  (0b00000111U)


/* --------------------------------  PWM_CTRL  -------------------------------------- */

/**
 * @def     SBC_PWM_DC_PWM_DC_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_PWM_CTRL_PWM_DC_Pos                   (0U)

/**
 * @def     SBC_PWM_DC_PWM_DC_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_PWM_CTRL_PWM_DC_Msk                   (0b11111111U)


/* --------------------------------  PWM_FREQ_CTRL  -------------------------------------- */

/**
 * @def     SBC_PWM_FREQ_CTRL_PWM_FREQ_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_PWM_FREQ_CTRL_PWM_FREQ_Pos            (0U)


/**
 * @def     SBC_PWM_FREQ_CTRL_PWM_FREQ_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_PWM_FREQ_CTRL_PWM_FREQ_Msk            (0b00000011U)


/* --------------------------------  HW_CTRL_3  ----------------------------------- */


/**
 * @def     SBC_HW_CTRL_3_TSD_THR_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_HW_CTRL_3_TSD_THR_Pos               (2U)

/**
 * @def     SBC_HW_CTRL_3_TSD_THR_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_HW_CTRL_3_TSD_THR_Msk               (0b00000100U)

/**
 * @def     SBC_HW_CTRL_3_ICC1_LIM_ADJ_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_HW_CTRL_3_ICC1_LIM_ADJ_Pos          (0U)

/**
 * @def     SBC_HW_CTRL_3_ICC1_LIM_ADJ_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_HW_CTRL_3_ICC1_LIM_ADJ_Msk          (0b00000011U)


/* --------------------------------  SYS_STATUS_CTRL_0  --------------------------- */

/**
 * @def     SBC_SYS_STATUS_CTRL_0_SYS_STAT_L_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_SYS_STATUS_CTRL_0_SYS_STAT_L_Pos    (0U)

/**
 * @def     SBC_SYS_STATUS_CTRL_0_SYS_STAT_L_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_SYS_STATUS_CTRL_0_SYS_STAT_L_Msk    (0b11111111U)


/* --------------------------------  SYS_STATUS_CTRL_1  --------------------------- */


/**
 * @def     SBC_SYS_STATUS_CTRL_0_SYS_STAT_H_Pos
 * 
 * @brief   Control register bit position.
 */
#define SBC_SYS_STATUS_CTRL_0_SYS_STAT_H_Pos    (0U)

/**
 * @def     SBC_SYS_STATUS_CTRL_0_SYS_STAT_H_Msk
 * 
 * @brief   Control register bit mask.
 */
#define SBC_SYS_STATUS_CTRL_0_SYS_STAT_H_Msk    (0b11111111U)






/* ================================================================================ */
/* ========   Selective Wake Control Registers Position & Mask        ============= */
/* ================================================================================ */



/* --------------------------------  SWK_CTRL  ------------------------------------ */


/**
 * @def     SBC_SWK_CTRL_OSC_CAL_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_CTRL_OSC_CAL_Pos                (7U)

/**
 * @def     SBC_SWK_CTRL_OSC_CAL_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_CTRL_OSC_CAL_Msk                (0b10000000U)

/**
 * @def     SBC_SWK_CTRL_TRIM_EN_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_CTRL_TRIM_EN_Pos                (5U)

/**
 * @def     SBC_SWK_CTRL_TRIM_EN_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_CTRL_TRIM_EN_Msk                (0b01100000U)

/**
 * @def     SBC_SWK_CTRL_CANTO_MASK_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_CTRL_CANTO_MASK_Pos             (4U)

/**
 * @def     SBC_SWK_CTRL_CANTO_MASK_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_CTRL_CANTO_MASK_Msk             (0b00010000U)

/**
 * @def     SBC_SWK_CTRL_CFG_VAL_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_CTRL_CFG_VAL_Pos                (0U)

/**
 * @def     SBC_SWK_CTRL_CFG_VAL_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_CTRL_CFG_VAL_Msk                (0b00000001U)


/* --------------------------------  SWK_BTL0_CTRL  ------------------------------- */


/**
 * @def     SBC_SWK_BTL0_CTRL_TBIT_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_BTL0_CTRL_TBIT_Pos              (0U)

/**
 * @def     SBC_SWK_BTL0_CTRL_TBIT_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_BTL0_CTRL_TBIT_Msk              (0b11111111U)


/* --------------------------------  SWK_BTL1_CTRL  ------------------------------- */


/**
 * @def     SBC_SWK_BTL1_CTRL_SP_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_BTL1_CTRL_SP_Pos                (0U)

/**
 * @def     SBC_SWK_BTL1_CTRL_SP_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_BTL1_CTRL_SP_Msk                (0b00111111U)


/* --------------------------------  SWK_ID3_CTRL  -------------------------------- */


/**
 * @def     SBC_SWK_ID3_CTRL_ID28_21_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_ID3_CTRL_ID28_21_Pos            (0U)

/**
 * @def     SBC_SWK_ID3_CTRL_ID28_21_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_ID3_CTRL_ID28_21_Msk            (0b11111111U)


/* --------------------------------  SWK_ID2_CTRL  -------------------------------- */


/**
 * @def     SBC_SWK_ID2_CTRL_ID20_13_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_ID2_CTRL_ID20_13_Pos            (0U)

/**
 * @def     SBC_SWK_ID2_CTRL_ID20_13_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_ID2_CTRL_ID20_13_Msk            (0b11111111U)


/* --------------------------------  SWK_ID1_CTRL  -------------------------------- */


/**
 * @def     SBC_SWK_ID1_CTRL_ID12_5_Pos
 * 
 * @brief   Selective wake register bit position. 
 */
#define SBC_SWK_ID1_CTRL_ID12_5_Pos             (0U)

/**
 * @def     SBC_SWK_ID1_CTRL_ID12_5_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_ID1_CTRL_ID12_5_Msk             (0b11111111U)


/* --------------------------------  SWK_ID0_CTRL  -------------------------------- */


/**
 * @def     SBC_SWK_ID0_CTRL_ID4_0_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_ID0_CTRL_ID4_0_Pos              (2U)

/**
 * @def     SBC_SWK_ID0_CTRL_ID4_0_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_ID0_CTRL_ID4_0_Msk              (0b01111100U)

/**
 * @def     SBC_SWK_ID0_CTRL_RTR_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_ID0_CTRL_RTR_Pos                (1U)

/**
 * @def     SBC_SWK_ID0_CTRL_RTR_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_ID0_CTRL_RTR_Msk                (0b00000010U)

/**
 * @def     SBC_SWK_ID0_CTRL_IDE_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_ID0_CTRL_IDE_Pos                (0U)

/**
 * @def     SBC_SWK_ID0_CTRL_IDE_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_ID0_CTRL_IDE_Msk                (0b00000001U)


/* --------------------------------  SWK_MASK_ID3_CTRL  --------------------------- */


/**
 * @def     SBC_SWK_MASK_ID3_CTRL_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_MASK_ID3_CTRL_Pos               (0U)

/**
 * @def     SBC_SWK_MASK_ID3_CTRL_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_MASK_ID3_CTRL_Msk               (0b11111111U)


/* --------------------------------  SWK_MASK_ID2_CTRL  --------------------------- */


/**
 * @def     SBC_SWK_MASK_ID2_CTRL_MASK_ID20_13_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_MASK_ID2_CTRL_MASK_ID20_13_Pos  (0U)

/**
 * @def     SBC_SWK_MASK_ID2_CTRL_MASK_ID20_13_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_MASK_ID2_CTRL_MASK_ID20_13_Msk  (0b11111111U)


/* --------------------------------  SWK_MASK_ID1_CTRL  --------------------------- */


/**
 * @def     SBC_SWK_MASK_ID1_CTRL_MASK_ID12_5_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_MASK_ID1_CTRL_MASK_ID12_5_Pos   (0U)

/**
 * @def     SBC_SWK_MASK_ID1_CTRL_MASK_ID12_5_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_MASK_ID1_CTRL_MASK_ID12_5_Msk   (0b11111111U)


/* --------------------------------  SWK_MASK_ID0_CTRL  --------------------------- */


/**
 * @def     SBC_SWK_MASK_ID0_CTRL_MASK_ID4_0_Pos
 * 
 * @brief   Selective wake register bit position. 
 */
#define SBC_SWK_MASK_ID0_CTRL_MASK_ID4_0_Pos    (2U)

/**
 * @def     SBC_SWK_MASK_ID0_CTRL_MASK_ID4_0_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_MASK_ID0_CTRL_MASK_ID4_0_Msk    (0b01111100U)


/* --------------------------------  SWK_DLC_CTRL  -------------------------------- */


/**
 * @def     SBC_SWK_DLC_CTRL_DLC_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_DLC_CTRL_DLC_Pos                (0U)

/**
 * @def     SBC_SWK_DLC_CTRL_DLC_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_DLC_CTRL_DLC_Msk                (0b00001111U)


/* --------------------------------  SWK_DATA7_CTRL  ------------------------------ */


/**
 * @def     SBC_SWK_DATA7_CTRL_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_DATA7_CTRL_Pos                  (0U)

/**
 * @def     SBC_SWK_DATA7_CTRL_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_DATA7_CTRL_Msk                  (0b11111111U)


/* --------------------------------  SWK_DATA6_CTRL  ------------------------------ */


/**
 * @def     SBC_SWK_DATA6_CTRL_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_DATA6_CTRL_Pos                  (0U)

/**
 * @def     SBC_SWK_DATA6_CTRL_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_DATA6_CTRL_Msk                  (0b11111111U)


/* --------------------------------  SWK_DATA5_CTRL  ------------------------------ */


/**
 * @def     SBC_SWK_DATA5_CTRL_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_DATA5_CTRL_Pos                  (0U)

/**
 * @def     SBC_SWK_DATA5_CTRL_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_DATA5_CTRL_Msk                  (0b11111111U)


/* --------------------------------  SWK_DATA4_CTRL  ------------------------------ */


/**
 * @def     SBC_SWK_DATA4_CTRL_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_DATA4_CTRL_Pos                  (0U)

/**
 * @def     SBC_SWK_DATA4_CTRL_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_DATA4_CTRL_Msk                  (0b11111111U)


/* --------------------------------  SWK_DATA3_CTRL  ------------------------------ */


/**
 * @def     SBC_SWK_DATA3_CTRL_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_DATA3_CTRL_Pos                  (0U)

/**
 * @def     SBC_SWK_DATA3_CTRL_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_DATA3_CTRL_Msk                  (0b11111111U)


/* --------------------------------  SWK_DATA2_CTRL  ------------------------------ */


/**
 * @def     SBC_SWK_DATA2_CTRL_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_DATA2_CTRL_Pos                  (0U)

/**
 * @def     SBC_SWK_DATA2_CTRL_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_DATA2_CTRL_Msk                  (0b11111111U)


/* --------------------------------  SWK_DATA1_CTRL  ------------------------------ */


/**
 * @def     SBC_SWK_DATA1_CTRL_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_DATA1_CTRL_Pos                  (0U)

/**
 * @def     SBC_SWK_DATA1_CTRL_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_DATA1_CTRL_Msk                  (0b11111111U)


/* --------------------------------  SWK_DATA0_CTRL  ------------------------------ */


/**
 * @def     SBC_SWK_DATA0_CTRL_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_DATA0_CTRL_Pos                  (0U)

/**
 * @def     SBC_SWK_DATA0_CTRL_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_DATA0_CTRL_Msk                  (0b11111111U)


/* --------------------------------  SWK_CAN_FD_CTRL  ----------------------------- */


/**
 * @def     SBC_SWK_CAN_FD_CTRL_DIS_ERR_CNT_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_CAN_FD_CTRL_DIS_ERR_CNT_Pos     (5U)

/**
 * @def     SBC_SWK_CAN_FD_CTRL_DIS_ERR_CNT_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_CAN_FD_CTRL_DIS_ERR_CNT_Msk     (0b00100000U)

/**
 * @def     SBC_SWK_CAN_FD_CTRL_RX_FILT_BYP_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_CAN_FD_CTRL_RX_FILT_BYP_Pos     (4U)

/**
 * @def     SBC_SWK_CAN_FD_CTRL_RX_FILT_BYP_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_CAN_FD_CTRL_RX_FILT_BYP_Msk     (0b00010000U)

/**
 * @def     SBC_SWK_CAN_FD_CTRL_FD_FILTER_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_CAN_FD_CTRL_FD_FILTER_Pos       (1U)

/**
 * @def     SBC_SWK_CAN_FD_CTRL_FD_FILTER_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_CAN_FD_CTRL_FD_FILTER_Msk       (0b00001110U)

/**
 * @def     SBC_SWK_CAN_FD_CTRL_CAN_FD_EN_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_CAN_FD_CTRL_CAN_FD_EN_Pos       (0U)

/**
 * @def     SBC_SWK_CAN_FD_CTRL_CAN_FD_EN_Msk
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_CAN_FD_CTRL_CAN_FD_EN_Msk       (0b00000001U)


/* --------------------------------  SWK_OSC_TRIM_CTRL  --------------------------- */


/**
 * @def     SBC_SWK_OSC_TRIM_CTRL_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_OSC_TRIM_CTRL_Pos               (0U)

/**
 * @def     SBC_SWK_OSC_TRIM_CTRL_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_OSC_TRIM_CTRL_Msk               (0b01111111U)


/* --------------------------------  SWK_OPT_CTRL  -------------------------------- */


/**
 * @def     SBC_SWK_OPT_CTRL_RX_WK_SEL_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_OPT_CTRL_RX_WK_SEL_Pos          (7U)

/**
 * @def     SBC_SWK_OPT_CTRL_RX_WK_SEL_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_OPT_CTRL_RX_WK_SEL_Msk          (0b10000000U)


/* --------------------------------  SWK_OSC_CAL_H_STAT  -------------------------- */


/**
 * @def     SBC_SWK_OSC_CAL_H_STAT_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_OSC_CAL_H_STAT_Pos              (0U)

/**
 * @def     SBC_SWK_OSC_CAL_H_STAT_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_OSC_CAL_H_STAT_Msk              (0b11111111U)


/* --------------------------------  SWK_OPT_CAL_L_STAT  -------------------------- */


/**
 * @def     SBC_SWK_OPT_CAL_L_STAT_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_OPT_CAL_L_STAT_Pos              (0U)

/**
 * @def     SBC_SWK_OPT_CAL_L_STAT_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_OPT_CAL_L_STAT_Msk              (0b11111111U)


/* --------------------------------  SWK_CDR_CTRL1  ------------------------------- */


/**
 * @def     SBC_SWK_CDR_CTRL1_SEL_FILT_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_CDR_CTRL1_SEL_FILT_Pos          (2U)

/**
 * @def     SBC_SWK_CDR_CTRL1_SEL_FILT_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_CDR_CTRL1_SEL_FILT_Msk          (0b00001100U)

/**
 * @def     SBC_SWK_CDR_CTRL1_CDR_EN_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_CDR_CTRL1_CDR_EN_Pos            (0U)

/**
 * @def     SBC_SWK_CDR_CTRL1_CDR_EN_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_CDR_CTRL1_CDR_EN_Msk            (0b00000001U)


/* --------------------------------  SWK_CDR_CTRL2  ------------------------------- */


/**
 * @def     SBC_SWK_CDR_CTRL2_SEL_OSC_CLK_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_CDR_CTRL2_SEL_OSC_CLK_Pos       (0U)

/**
 * @def     SBC_SWK_CDR_CTRL2_SEL_OSC_CLK_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_CDR_CTRL2_SEL_OSC_CLK_Msk       (0b00000011U)


/* --------------------------------  SWK_CDR_LIMIT_HIGH_CTRL  --------------------- */


/**
 * @def     SBC_SWK_CDR_LIMIT_HIGH_CTRL_CDR_LIM_H_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_CDR_LIMIT_HIGH_CTRL_CDR_LIM_H_Pos   (0U)

/**
 * @def     SBC_SWK_CDR_LIMIT_HIGH_CTRL_CDR_LIM_H_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_CDR_LIMIT_HIGH_CTRL_CDR_LIM_H_Msk   (0b11111111U)


/* --------------------------------  SWK_CDR_LIMIT_LOW_CTRL  ---------------------- */


/**
 * @def     SBC_SWK_CDR_LIMIT_LOW_CTRL_CDR_LIM_L_Pos
 * 
 * @brief   Selective wake register bit position.
 */
#define SBC_SWK_CDR_LIMIT_LOW_CTRL_CDR_LIM_L_Pos    (0U)

/**
 * @def     SBC_SWK_CDR_LIMIT_LOW_CTRL_CDR_LIM_L_Msk
 * 
 * @brief   Selective wake register bit mask.
 */
#define SBC_SWK_CDR_LIMIT_LOW_CTRL_CDR_LIM_L_Msk    (0b11111111U)






/* ================================================================================ */
/* =============   General Status Registers Position & Mask        ================ */
/* ================================================================================ */



/* --------------------------------  SUP_STAT_1  ---------------------------------- */


/**
 * @def     SBC_SUP_STAT_1_VS_UV_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_SUP_STAT_1_VS_UV_Pos                (6U)

/**
 * @def     SBC_SUP_STAT_1_VS_UV_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_SUP_STAT_1_VS_UV_Msk                (0b01000000U)

/**
 * @def     SBC_SUP_STAT_1_VS_OV_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_SUP_STAT_1_VS_OV_Pos                (5U)

/**
 * @def     SBC_SUP_STAT_1_VS_OV_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_SUP_STAT_1_VS_OV_Msk                (0b00100000U)

/**
 * @def     SBC_SUP_STAT_1_VCC1_OV_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_SUP_STAT_1_VCC1_OV_Pos              (1U)

/**
 * @def     SBC_SUP_STAT_1_VCC1_OV_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_SUP_STAT_1_VCC1_OV_Msk              (0b00000010U)

/**
 * @def     SBC_SUP_STAT_1_VCC1_WARN_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_SUP_STAT_1_VCC1_WARN_Pos            (0U)

/**
 * @def     SBC_SUP_STAT_1_VCC1_WARN_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_SUP_STAT_1_VCC1_WARN_Msk            (0b00000001U)


/* --------------------------------  SUP_STAT_0  ---------------------------------- */


/**
 * @def     SBC_SUP_STAT_0_POR_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_SUP_STAT_0_POR_Pos                  (7U)

/**
 * @def     SBC_SUP_STAT_0_POR_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_SUP_STAT_0_POR_Msk                  (0b10000000U)

/**
 * @def     SBC_SUP_STAT_0_VCC2_OT_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_SUP_STAT_0_VCC2_OT_Pos              (4U)

/**
 * @def     SBC_SUP_STAT_0_VCC2_OT_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_SUP_STAT_0_VCC2_OT_Msk              (0b00010000U)

/**
 * @def     SBC_SUP_STAT_0_VCC2_UV_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_SUP_STAT_0_VCC2_UV_Pos              (3U)

/**
 * @def     SBC_SUP_STAT_0_VCC2_UV_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_SUP_STAT_0_VCC2_UV_Msk              (0b00001000U)

/**
 * @def     SBC_SUP_STAT_0_VCC1_SC_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_SUP_STAT_0_VCC1_SC_Pos              (2U)

/**
 * @def     SBC_SUP_STAT_0_VCC1_SC_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_SUP_STAT_0_VCC1_SC_Msk              (0b00000100U)

/**
 * @def     SBC_SUP_STAT_0_VCC1_UV_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_SUP_STAT_0_VCC1_UV_Pos              (0U)

/**
 * @def     SBC_SUP_STAT_0_VCC1_UV_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_SUP_STAT_0_VCC1_UV_Msk              (0b00000001U)


/* --------------------------------  THERM_STAT  ---------------------------------- */


/**
 * @def     SBC_THERM_STAT_TSD2_SAFE_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_THERM_STAT_TSD2_SAFE_Pos            (3U)

/**
 * @def     SBC_THERM_STAT_TSD2_SAFE_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_THERM_STAT_TSD2_SAFE_Msk            (0b00001000U)

/**
 * @def     SBC_THERM_STAT_TSD2_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_THERM_STAT_TSD2_Pos                 (2U)

/**
 * @def     SBC_THERM_STAT_TSD2_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_THERM_STAT_TSD2_Msk                 (0b00000100U)

/**
 * @def     SBC_THERM_STAT_TSD1_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_THERM_STAT_TSD1_Pos                 (1U)

/**
 * @def     SBC_THERM_STAT_TSD1_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_THERM_STAT_TSD1_Msk                 (0b00000010U)

/**
 * @def     SBC_THERM_STAT_TPW_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_THERM_STAT_TPW_Pos                  (0U)

/**
 * @def     SBC_THERM_STAT_TPW_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_THERM_STAT_TPW_Msk                  (0b00000001U)


/* --------------------------------  DEV_STAT  ------------------------------------ */


/**
 * @def     SBC_DEV_STAT_DEV_STAT_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_DEV_STAT_DEV_STAT_Pos               (6U)

/**
 * @def     SBC_DEV_STAT_DEV_STAT_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_DEV_STAT_DEV_STAT_Msk               (0b11000000U)

/**
 * @def     SBC_DEV_STAT_WD_FAIL_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_DEV_STAT_WD_FAIL_Pos                (2U)

/**
 * @def     SBC_DEV_STAT_WD_FAIL_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_DEV_STAT_WD_FAIL_Msk                (0b00001100U)

/**
 * @def     SBC_DEV_STAT_SPI_FAIL_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_DEV_STAT_SPI_FAIL_Pos               (1U)

/**
 * @def     SBC_DEV_STAT_SPI_FAIL_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_DEV_STAT_SPI_FAIL_Msk               (0b00000010U)

/**
 * @def     SBC_DEV_STAT_FAILURE_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_DEV_STAT_FAILURE_Pos                (0U)

/**
 * @def     SBC_DEV_STAT_FAILURE_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_DEV_STAT_FAILURE_Msk                (0b00000001U)


/* --------------------------------  BUS_STAT  ------------------------------------ */


/**
 * @def     SBC_BUS_STAT_CANTO_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_BUS_STAT_CANTO_Pos                  (4U)

/**
 * @def     SBC_BUS_STAT_CANTO_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_BUS_STAT_CANTO_Msk                  (0b00010000U)

/**
 * @def     SBC_BUS_STAT_SYSERR_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_BUS_STAT_SYSERR_Pos                 (3U)

/**
 * @def     SBC_BUS_STAT_SYSERR_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_BUS_STAT_SYSERR_Msk                 (0b00001000U)

/**
 * @def     SBC_BUS_STAT_CAN_FAIL_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_BUS_STAT_CAN_FAIL_Pos               (1U)

/**
 * @def     SBC_BUS_STAT_CAN_FAIL_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_BUS_STAT_CAN_FAIL_Msk               (0b00000110U)

/**
 * @def     SBC_BUS_STAT_VCAN_UV_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_BUS_STAT_VCAN_UV_Pos                (0U)

/**
 * @def     SBC_BUS_STAT_VCAN_UV_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_BUS_STAT_VCAN_UV_Msk                (0b00000001U)


/* --------------------------------  WK_STAT_0  ----------------------------------- */


/**
 * @def     SBC_WK_STAT_0_CAN_WU_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_WK_STAT_0_CAN_WU_Pos                (5U)

/**
 * @def     SBC_WK_STAT_0_CAN_WU_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_WK_STAT_0_CAN_WU_Msk                (0b00100000U)

/**
 * @def     SBC_WK_STAT_0_TIMER_WU_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_WK_STAT_0_TIMER_WU_Pos              (4U)

/**
 * @def     SBC_WK_STAT_0_TIMER_WU_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_WK_STAT_0_TIMER_WU_Msk              (0b00010000U)

/**
 * @def     SBC_WK_STAT_0_WK_WU_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_WK_STAT_0_WK_WU_Pos                 (0U)

/**
 * @def     SBC_WK_STAT_0_WK_WU_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_WK_STAT_0_WK_WU_Msk                 (0b00000001U)


/* --------------------------------  WK_STAT_1  ----------------------------------- */


/**
 * @def     SBC_WK_STAT_1_GPIO_WK_WU_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_WK_STAT_1_GPIO_WK_WU_Pos            (4U)

/**
 * @def     SBC_WK_STAT_1_GPIO_WK_WU_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_WK_STAT_1_GPIO_WK_WU_Msk            (0b00010000U)


/* --------------------------------  WK_LVL_STAT  --------------------------------- */


/**
 * @def     SBC_WK_LVL_STAT_SBC_DEV_LVL_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_WK_LVL_STAT_SBC_DEV_LVL_Pos         (7U)

/**
 * @def     SBC_WK_LVL_STAT_SBC_DEV_LVL_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_WK_LVL_STAT_SBC_DEV_LVL_Msk         (0b10000000U)

/**
 * @def     SBC_WK_LVL_STAT_CFG0_STATE_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_WK_LVL_STAT_CFG0_STATE_Pos          (6U)

/**
 * @def     SBC_WK_LVL_STAT_CFG0_STATE_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_WK_LVL_STAT_CFG0_STATE_Msk          (0b01000000U)

/**
 * @def     SBC_WK_LVL_STAT_GPIO_LVL_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_WK_LVL_STAT_GPIO_LVL_Pos            (4U)

/**
 * @def     SBC_WK_LVL_STAT_GPIO_LVL_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_WK_LVL_STAT_GPIO_LVL_Msk            (0b00010000U)

/**
 * @def     SBC_WK_LVL_STAT_WK_LVL_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_WK_LVL_STAT_WK_LVL_Pos              (0U)

/**
 * @def     SBC_WK_LVL_STAT_WK_LVL_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_WK_LVL_STAT_WK_LVL_Msk              (0b00000001U)


/* --------------------------------  GPIO_OC_STAT  -------------------------------- */


/**
 * @def     SBC_GPIO_OC_STAT_GPIO_OC_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_GPIO_OC_STAT_GPIO_OC_Pos            (6U)

/**
 * @def     SBC_GPIO_OC_STAT_GPIO_OC_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_GPIO_OC_STAT_GPIO_OC_Msk            (0b01000000U)


/* --------------------------------  GPIO_OL_STAT  -------------------------------- */


/**
 * @def     SBC_GPIO_OL_STAT_GPIO_OL_Pos
 * 
 * @brief   General status register bit position.
 */
#define SBC_GPIO_OL_STAT_GPIO_OL_Pos            (6U)

/**
 * @def     SBC_GPIO_OL_STAT_GPIO_OL_Msk
 * 
 * @brief   General status register bit mask.
 */
#define SBC_GPIO_OL_STAT_GPIO_OL_Msk            (0b01000000U)







/* ================================================================================ */
/* =========   Selective Wake Status Registers Position & Mask        ============= */
/* ================================================================================ */




/* --------------------------------  SWK_STAT  ------------------------------------ */


/**
 * @def     SBC_SWK_STAT_SYNC_Pos
 * 
 * @brief   Selective wake status register bit position.
 */
#define SBC_SWK_STAT_SYNC_Pos                   (6U)

/**
 * @def     SBC_SWK_STAT_SYNC_Msk
 * 
 * @brief   Selective wake status register bit mask.
 */
#define SBC_SWK_STAT_SYNC_Msk                   (0b01000000U)

/**
 * @def     SBC_SWK_STAT_CANSIL_Pos
 * 
 * @brief   Selective wake status register bit position.
 */
#define SBC_SWK_STAT_CANSIL_Pos                 (3U)

/**
 * @def     SBC_SWK_STAT_CANSIL_Msk
 * 
 * @brief   Selective wake status register bit mask.
 */
#define SBC_SWK_STAT_CANSIL_Msk                 (0b00001000U)

/**
 * @def     SBC_SWK_STAT_SWK_SET_Pos
 * 
 * @brief   Selective wake status register bit position.
 */
#define SBC_SWK_STAT_SWK_SET_Pos                (2U)

/**
 * @def     SBC_SWK_STAT_SWK_SET_Msk
 * 
 * @brief   Selective wake status register bit mask.
 */
#define SBC_SWK_STAT_SWK_SET_Msk                (0b00000100U)

/**
 * @def     SBC_SWK_STAT_WUP_Pos
 * 
 * @brief   Selective wake status register bit position.
 */
#define SBC_SWK_STAT_WUP_Pos                    (1U)

/**
 * @def     SBC_SWK_STAT_WUP_Msk
 * 
 * @brief   Selective wake status register bit mask.
 */
#define SBC_SWK_STAT_WUP_Msk                    (0b00000010U)

/**
 * @def     SBC_SWK_STAT_WUF_Pos
 * 
 * @brief   Selective wake status register bit position.
 */
#define SBC_SWK_STAT_WUF_Pos                    (0U)

/**
 * @def     SBC_SWK_STAT_WUF_Msk
 * 
 * @brief   Selective wake status register bit mask.
 */
#define SBC_SWK_STAT_WUF_Msk                    (0b00000001U)





/* --------------------------------  SWK_ECNT_STAT  -------------------------------- */


/**
 * @def     SBC_SWK_ECNT_STAT_ECNT_Pos
 * 
 * @brief   Selective wake status register bit position.
 */
#define SBC_SWK_ECNT_STAT_ECNT_Pos              (0U)

/**
 * @def     SBC_SWK_ECNT_STAT_ECNT_Msk
 * 
 * @brief   Selective wake status register bit mask.
 */
#define SBC_SWK_ECNT_STAT_ECNT_Msk              (0b00111111U)


/* --------------------------------  SWK_CDR_STAT1  -------------------------------- */


/**
 * @def     SBC_SWK_CDR_STAT1_NAVG_SAT_Pos
 * 
 * @brief   Selective wake status register bit position.
 */
#define SBC_SWK_CDR_STAT1_NAVG_SAT_Pos          (0U)

/**
 * @def     SBC_SWK_CDR_STAT1_NAVG_SAT_Msk
 * 
 * @brief   Selective wake status register bit mask.
 */
#define SBC_SWK_CDR_STAT1_NAVG_SAT_Msk          (0b11111111U)


/* --------------------------------  SWK_CDR_STAT2  -------------------------------- */


/**
 * @def     SBC_SWK_CDR_STAT2_NAVG_SAT_Pos
 * 
 * @brief   Selective wake status register bit position.
 */
#define SBC_SWK_CDR_STAT2_NAVG_SAT_Pos          (4U)

/**
 * @def     SBC_SWK_CDR_STAT2_NAVG_SAT_Msk
 * 
 * @brief   Selective wake status register bit mask.
 */
#define SBC_SWK_CDR_STAT2_NAVG_SAT_Msk          (0b11110000U)






/* ================================================================================ */
/* ======   Family and Product Information Register Position & Mask        ======== */
/* ================================================================================ */



/* --------------------------------  FAM_PROD_STAT  -------------------------------- */


/**
 * @def     SBC_FAM_PROD_STAT_FAM_Pos
 * 
 * @brief   Family and product register bit position.
 */
#define SBC_FAM_PROD_STAT_FAM_Pos               (4U)

/**
 * @def     SBC_FAM_PROD_STAT_FAM_Msk
 * 
 * @brief   Family and product register bit mask.
 */
#define SBC_FAM_PROD_STAT_FAM_Msk               (0b11110000U)

/**
 * @def     SBC_FAM_PROD_STAT_PROD_Pos
 * 
 * @brief   Family and product register bit position.
 */
#define SBC_FAM_PROD_STAT_PROD_Pos              (0U)

/**
 * @def     SBC_FAM_PROD_STAT_PROD_Msk
 * 
 * @brief   Family and product register bit mask.
 */
#define SBC_FAM_PROD_STAT_PROD_Msk              (0b00001111U)






/* ================================================================================ */
/* ===============   General Control Registers Enumerations        ================ */
/* ================================================================================ */ 



/* --------------------------------  M_S_CTRL  ------------------------------------ */

typedef enum
{
    SBC_MODE_NORMAL                         = 0x00U,
    SBC_MODE_SLEEP,
    SBC_MODE_STOP,
    SBC_MODE_RESET
};

typedef enum
{
    SBC_VCC2_OFF                            = 0x00U,
    SBC_VCC2_ON_NORMAL,
    SBC_VCC2_ON_NORMAL_STOP,
    SBC_VCC2_ON_ALWAYS
};

typedef enum
{
    SBC_VCC1_OV_RST_NOACTION                = 0x00U,
    SBC_VCC1_OV_RST_RESTART_FAILSAFE
};

typedef enum
{
    SBC_VCC1_RT_VRT1                        = 0x00U,
    SBC_VCC1_RT_VRT2,
    SBC_VCC1_RT_VRT3,
    SBC_VCC1_RT_VRT4
};


/* --------------------------------  HW_CTRL_0  ----------------------------------- */

typedef enum
{
    SBC_SOFT_RESET_RST_TRIGGER_SOFTRST      = 0x00U,
    SBC_SOFT_RESET_RST_NOTRIGGER_SOFTRST
};

typedef enum
{
    SBC_FO_ON_NOT_ACTIVE                    = 0x00U,
    SBC_FO_ON_ACTIVE
};

typedef enum
{
    SBC_CP_EN_OFF                           = 0x00U,
    SBC_CP_EN_ON
};

typedef enum
{
    SBC_CFG1_RESTART_FAILSAFE_2WDFAIL       = 0x00U,
    SBC_CFG1_RESTART_FAILSAFE_1WDFAIL
};


/* --------------------------------  WD_CTRL  ------------------------------------- */

typedef enum
{
    SBC_CHECKSUM_0                       = 0x00U,
    SBC_CHECKSUM_1
};

typedef enum
{
    SBC_WD_STM_EN_0_ACTIVE_STOPMODE         = 0x00U,
    SBC_WD_STM_EN_0_NOTACTIVE_STOPMODE
};

typedef enum
{
    SBC_WD_WIN_TIMEOUT_WD                   = 0x00U,
    SBC_WD_WIN_WINDOW_WD
};

typedef enum
{
    SBC_WD_EN_WK_BUS_NOSTART_AFTER_CANWAKE  = 0x00U,
    SBC_WD_EN_WK_BUS_START_LONGOPENWINDOW_CANWAKE
};

typedef enum
{
    SBC_WD_TIMER_10MS                       = 0x00U,
    SBC_WD_TIMER_20MS,
    SBC_WD_TIMER_50MS,
    SBC_WD_TIMER_100MS,
    SBC_WD_TIMER_200MS,
    SBC_WD_TIMER_500MS,
    SBC_WD_TIMER_1000MS,
    SBC_WD_TIMER_10000MS
};


/* --------------------------------  BUS_CTRL_0  ---------------------------------- */

typedef enum
{
    SBC_BUS_CTRL_0_CAN_WAKECAPABLE_NOSWK    = 0x01U,
    SBC_BUS_CTRL_0_CAN_RECEIVEONLY_NOSWK,
    SBC_BUS_CTRL_0_CAN_NORMAL_NOSWK,
    SBC_BUS_CTRL_0_CAN_OFF,
    SBC_BUS_CTRL_0_CAN_WAKECAPABLE_SWK,
    SBC_BUS_CTRL_0_CAN_RECEIVEONLY_SWK,
    SBC_BUS_CTRL_0_CAN_NORMAL_SWK
};


/* --------------------------------  WK_CTRL_0  ----------------------------------- */

typedef enum
{
    WK_CTRL_0_TIMER_WK_EN_WAKEUP_DISABLED   = 0x00U,
    WK_CTRL_0_TIMER_WK_EN_WAKESOURCE
};

typedef enum
{
    SBC_WD_STM_EN_1_WATCHDOG_STOPMPDE       = 0x00U,
    SBC_WD_STM_EN_1_NOWATCHDOG_STOPMODE
};


/* --------------------------------  WK_CTRL_1  ----------------------------------- */

typedef enum
{
    SBC_INT_GLOBAL_WAKESOURCES_ONLY         = 0x00U,
    SBC_INT_GLOBAL_ALLINFORMATIONBITS
};

typedef enum
{
    SBC_WK_MEAS_WK_AS_WAKEUP                = 0x00U,
    SBC_WK_MEAS_WK_AS_VOLTAGESENSING
};

typedef enum
{
    SBC_WK_EN_WAKEUP_DISABLED               = 0x00U,
    SBC_WK_EN_WAKEUP_ENABLED
};


/* --------------------------------  WK_PUPD_CTRL  -------------------------------- */

typedef enum
{
    SBC_GPIO_WK_PUPD_NOPULLING              = 0x00U,
    SBC_GPIO_WK_PUPD_PULLDOWN,
    SBC_GPIO_WK_PUPD_PULLUP,
    SBC_GPIO_WK_PUPD_AUTOMATIC_PULLING
};

typedef enum
{
    SBC_WK_PUPD_NOPULLING                   = 0x00U,
    SBC_WK_PUPD_PULLDOWN,
    SBC_WK_PUPD_PULLUP,
    SBC_WK_PUPD_AUTOMATIC_PULLING
};


/* --------------------------------  BUS_CTRL_3  ---------------------------------- */

typedef enum
{
    SBC_CAN_FLASH_DISABLED                  = 0x00U,
    SBC_CAN_FLASH_ENABLED
};


/* --------------------------------  TIMER_CTRL  ---------------------------------- */

typedef enum
{
    SBC_TIMER_ON_TIMEROFF_HSX_LOW           = 0x00U,
    SBC_TIMER_ON_100US,
    SBC_TIMER_ON_300US,
    SBC_TIMER_ON_1MS,
    SBC_TIMER_ON_10MS,
    SBC_TIMER_ON_20MS,
    SBC_TIMER_ON_TIMEROFF_HSX_HIGH
};

typedef enum
{
    SBC_TIMER_PER_10MS                      = 0x00U,
    SBC_TIMER_PER_20MS,
    SBC_TIMER_PER_50MS,
    SBC_TIMER_PER_100MS,
    SBC_TIMER_PER_200MS,
    SBC_TIMER_PER_500MS,
    SBC_TIMER_PER_1S,
    SBC_TIMER_PER_2S,
    SBC_TIMER_PER_5S,
    SBC_TIMER_PER_10S,
    SBC_TIMER_PER_20S,
    SBC_TIMER_PER_50S,
    SBC_TIMER_PER_100S,
    SBC_TIMER_PER_200S,
    SBC_TIMER_PER_500S,
    SBC_TIMER_PER_1000S
};


/* --------------------------------  HW_CTRL_1  ----------------------------------- */

typedef enum
{
    SBC_RSTN_HYS_DEFAULT                    = 0x00U,
    SBC_RSTN_HYS_HIGHEST_VRT
};

typedef enum
{
    SBC_TSD2_DEL_NO_WAIT_RELEASE_EXTENSION  = 0x00U,
    SBC_TSD2_DEL_64S_AFTER_16_TSD2_EVENTS
};

typedef enum
{
    SBC_RSTN_DEL_TRD1                       = 0x00U,
    SBC_RSTN_DEL_TRD2
};

typedef enum
{
    SBC_CFG_LOCK_0_NOTLOCKED                = 0x00U,
    SBC_CFG_LOCK_0_LOCKED
};


/* --------------------------------  HW_CTRL_2  ----------------------------------- */

typedef enum
{
    SBC_2MHZ_FREQ_1_8_MHZ                   = 0x00U,
    SBC_2MHZ_FREQ_2_0_MHZ,
    SBC_2MHZ_FREQ_2_2_MHZ,
    SBC_2MHZ_FREQ_2_4_MHZ
};

typedef enum
{
    SBC_I_PEAK_TH_LOW                       = 0x00U,
    SBC_I_PEAK_TH_HIGH
};

typedef enum
{
    SBC_SS_MOD_FR_DISABLED                  = 0x00U,
    SBC_SS_MOD_FR_15_6KHZ,
    SBC_SS_MOD_FR_31_2KHZ,
    SBC_SS_MOD_FR_62_5KHZ
};

typedef enum
{
    SBC_CFG_LOCK_1_NOTLOCKED                = 0x00U,
    SBC_CFG_LOCK_1_LOCKED
};


/* --------------------------------  GPIO_CTRL  ----------------------------------- */

typedef enum
{
    SBC_GPIO_FO                             = 0x00U,
    SBC_GPIO_HSS_TIMER                      = 0x03U,
    SBC_GPIO_OFF,
    SBC_GPIO_WAKE_INPUT,
    SBC_GPIO_LSS_PWM,
    SBC_GPIO_HSS_PWM
};


/* --------------------------------  PWM_CTRL  ------------------------------------ */

typedef enum
{
    SBC_PWM_DC_0                            = 0x00U,
    SBC_PWM_DC_10                           = 0x19U,
    SBC_PWM_DC_20                           = 0x51U,
    SBC_PWM_DC_30                           = 0x4DU,
    SBC_PWM_DC_40                           = 0x66U,
    SBC_PWM_DC_50                           = 0x80U,
    SBC_PWM_DC_60                           = 0x99U,
    SBC_PWM_DC_70                           = 0xB3U,
    SBC_PWM_DC_80                           = 0xCCU,
    SBC_PWM_DC_90                           = 0xE6U,
    SBC_PWM_DC_100                          = 0xFFU
};


/* --------------------------------  PWM_FREQ_CTRL  ------------------------------- */

typedef enum
{
    SBC_PWM_FREQ_100HZ                      = 0x00U,
    SBC_PWM_FREQ_200HZ,
    SBC_PWM_FREQ_325HZ,
    SBC_PWM_FREQ_400HZ
};


/* --------------------------------  HW_CTRL_3 ----------------------------------- */

typedef enum
{
    SBC_TSD_THR_DEFAULT                     = 0x00U,
    SBC_TSD_THR_HIGHER
};

typedef enum
{
    SBC_ICC1_LIM_ADJ_750MA                  = 0x00U,
    SBC_ICC1_LIM_ADJ_1000MA,
    SBC_ICC1_LIM_ADJ_1200MA,
    SBC_ICC1_LIM_ADJ_1500MA
};






/* ================================================================================ */
/* ==========   Selective Wake Control Registers Enumerations        ============== */
/* ================================================================================ */ 



/* --------------------------------  SWK_CTRL  ------------------------------------ */

typedef enum
{ 
    SBC_OSC_CAL_DISABLED                    = 0x00U,
    SBC_OSC_CAL_ENABLED
};

typedef enum
{
    SBC_TRIM_EN_LOCKED                      = 0x00U,
    SBC_TRIM_EN_UNLOCKED                    = 0x03U
};

typedef enum
{
    SBC_CANTO_MASK_NOINT                    = 0x00U,
    SBC_CANTO_MASK_INT_ON_TO
};

typedef enum
{
    SBC_CFG_VAL_NOTVALID                    = 0x00U,
    SBC_CFG_VAL_VALID
};


/* --------------------------------  SWK_ID0_CTRL --------------------------------- */

typedef enum
{
    SBC_RTR_NORMAL_DATA_FRAME               = 0x00U,
    SBC_RTR_REMOTE_TRANSMIT_REQUEST
};

typedef enum
{
    SBC_IDE_STANDARD                         = 0x00U,
    SBC_IDE_EXTENDED
};


/* --------------------------------  SWK_DLC_CTRL --------------------------------- */

typedef enum
{
    SBC_DLC_0BYTES                          = 0x00U,
    SBC_DLC_1BYTES,
    SBC_DLC_2BYTES,
    SBC_DLC_3BYTES,
    SBC_DLC_4BYTES,
    SBC_DLC_5BYTES,
    SBC_DLC_6BYTES,
    SBC_DLC_7BYTES,
    SBC_DLC_8BYTES
};


/* --------------------------------  SWK_CAN_FD_CTRL ------------------------------ */

typedef enum
{
    SBC_DIS_ERR_CNT_ENABLED                 = 0x00U,
    SBC_DIS_ERR_CNT_DISABLED
};

typedef enum
{
    SBC_RX_FILT_BYP_NOTBYPASSED             = 0x00U,
    SBC_RX_FILT_BYP_BYPASSED
};

typedef enum
{
    SBC_FD_FILTER_50NS                      = 0x00U,
    SBC_FD_FILTER_100NS,
    SBC_FD_FILTER_150NS,
    SBC_FD_FILTER_200NS,
    SBC_FD_FILTER_250NS,
    SBC_FD_FILTER_300NS,
    SBC_FD_FILTER_350NS,
    SBC_FD_FILTER_700NS
};

typedef enum
{
    SBC_CAN_FD_EN_DISABLED                  = 0x00U,
    SBC_CAN_FD_EN_ENABLED
};


/* --------------------------------  SWK_OPT_CTRL --------------------------------- */

typedef enum
{ 
    SBC_RX_WK_SEL_LOWPOWER                  = 0x00U,
    SBC_RX_WK_SEL_STANDARD
};


/* --------------------------------  SWK_CDR_CTRL1 -------------------------------- */

typedef enum
{ 
    SBC_SEL_FILT_TC8                        = 0x00U,
    SBC_SEL_FILT_TC16,
    SBC_SEL_FILT_TC32,
    SBC_SEL_FILT_ADAPT
};

typedef enum
{
    SBC_CDR_EN_DISABLED                     = 0x00U,
    SBC_CDR_EN_ENABLED
};


/* --------------------------------  SWK_CDR_CTRL2 -------------------------------- */

typedef enum
{
    SBC_SEL_OSC_CLK_80MHZ                   = 0x00U,
    SBC_SEL_OSC_CLK_40MHZ,
    SBC_SEL_OSC_CLK_20MHZ,
    SBC_SEL_OSC_CLK_10MHZ
};






/* ================================================================================ */
/* ==========   General Status Information Registers Enumerations        ========== */
/* ================================================================================ */ 



/* --------------------------------  SUP_STAT_1  ---------------------------------- */

typedef enum
{
    SBC_VS_UV_NOEVENT                       = 0x00U,
    SBC_VS_UV_EVENT
};

typedef enum
{
    SBC_VS_OV_NOEVENT                       = 0x00U,
    SBC_VS_OV_EVENT
};

typedef enum
{ 
    SBC_VCC1_OV_NOEVENT                     = 0x00U,
    SBC_VCC1_OV_EVENT
};

typedef enum
{
    SBC_VCC1_UV_PREWARN_NOEVENT             = 0x00U,
    SBC_VCC1_UV_PREWARN_EVENT
};


/* --------------------------------  SUP_STAT_0 ----------------------------------- */

typedef enum
{
    SBC_POR_NOEVENT                         = 0x00U,
    SBC_POR_EVENT
};

typedef enum
{
    SBC_VCC2_OT_NOEVENT                     = 0x00U,
    SBC_VCC2_OT_EVENT
};

typedef enum
{
    SBC_VCC2_UV_NOEVENT                     = 0x00U,
    SBC_VCC2_UV_EVENT
};

typedef enum
{
    SBC_VCC1_SC_NOEVENT                     = 0x00U,
    SBC_VCC1_SC_TO_GND_EVENT
};

typedef enum
{
    SBC_VCC1_UV_NOEVENT                     = 0x00U,
    SBC_VCC1_UV_EVENT
};


/* --------------------------------  THERM_STAT ----------------------------------- */

typedef enum
{
    SBC_TSD2_SAFE_NOSAFESTATE               = 0x00U,
    SBC_TSD2_SAFE_SAFESTATE_DETECTED
};

typedef enum
{
    SBC_TSD2_NOEVENT                        = 0x00U,
    SBC_TSD2_EVENT
};

typedef enum
{
    SBC_TSD1_NOEVENT                        = 0x00U,
    SBC_TSD1_EVENT
};

typedef enum
{
    SBC_TPW_NOEVENT                         = 0x00U,
    SBC_TPW_EVENT
};


/* --------------------------------  DEV_STAT ------------------------------------- */

typedef enum
{
    SBC_DEV_STAT_CLEARED                    = 0x00U,
    SBC_DEV_STAT_RESTART_AFTER_FAIL,
    SBC_DEV_STAT_SLEEP_MODE
};

typedef enum
{
    SBC_WD_FAIL_NOFAIL                      = 0x00U,
    SBC_WD_FAIL_1FAIL,
    SBC_WD_FAIL_2FAIL
};

typedef enum
{
    SBC_SPI_FAIL_NOEVENT                    = 0x00U,
    SBC_SPI_FAIL_EVENT
};

typedef enum
{
    SBC_FAILURE_NOEVENT                     = 0x00U,
    SBC_FAILURE_EVENT
};


/* --------------------------------  BUS_STAT ------------------------------------- */

typedef enum
{
    SBC_CANTO_NORMAL                        = 0x00U,
    SBC_CANTO_TIMEOUT
};

typedef enum
{
    SBC_SYSERR_NOEVENT                      = 0x00U,
    SBC_SYSERR_DETECTED
};

typedef enum
{
    SBC_CAN_FAIL_NO_FAIL                    = 0x00U,
    SBC_CAN_FAIL_TSD,
    SBC_CAN_FAIL_TXD_DOM_TO,
    SBC_CAN_FAIL_BUS_DOM_TO
};

typedef enum
{
    SBC_VCAN_UV_NOEVENT                     = 0x00U,
    SBC_VCAN_UV_EVENT
};


/* --------------------------------  WK_STAT_0 ------------------------------------ */

typedef enum
{
    SBC_CAN_WU_NOEVENT                      = 0x00U,
    SBC_CAN_WU_EVENT
};

typedef enum
{
    SBC_TIMER_WU_NOEVENT                    = 0x00U,
    SBC_TIMER_WU_EVENT
};

typedef enum
{
    SBC_WK_WU_NOEVENT                       = 0x00U,
    SBC_WK_WU_EVENT
};


/* --------------------------------  WK_STAT_1 ------------------------------------ */

typedef enum
{
    SBC_GPIO_WK_WU_NOEVENT                  = 0x00U,
    SBC_GPIO_WK_WU_EVENT
};


/* --------------------------------  WK_LVL_STAT ---------------------------------- */

typedef enum
{
    SBC_DEV_LVL_NORMAL                      = 0x00U,
    SBC_DEV_LVL_DEVELOPMENT_MODE
};

typedef enum
{
    SBC_CFG0_STATE_CONFIG_2_4               = 0x00U,
    SBC_CFG0_STATE_CONFIG_1_3
};

typedef enum
{
    SBC_GPIO_LVL_LOW                        = 0x00U,
    SBC_GPIO_LVL_HIGH
};

typedef enum
{
    SBC_WK_LVL_LOW                          = 0x00U,
    SBC_WK_LVL_HIGH
};


/* --------------------------------  GPIO_OC_STAT --------------------------------- */

typedef enum
{
    SBC_GPIO_OC_NOEVENT                     = 0x00U,
    SBC_GPIO_OC_EVENT
};


/* --------------------------------  GPIO_OL_STAT --------------------------------- */

typedef enum
{
    SBC_GPIO_OL_NOEVENT                     = 0x00U,
    SBC_GPIO_OL_EVENT
};






/* ================================================================================ */
/* =============   Selective Wake Status Registers Enumerations        ============ */
/* ================================================================================ */ 



/* --------------------------------  SWK_STAT  ------------------------------------ */

typedef enum
{
    SBC_SYNC_NOT_SYNCHRONOUS                = 0x00U,
    SBC_SYNC_VALID_FRAME_RECEIVED
};

typedef enum
{
    SBC_CANSIL_NOT_EXCEEDED                 = 0x00U,
    SBC_CANSIL_EXCEEDED
};

typedef enum
{
    SBC_SWK_SET_SWK_NOT_ACTIVE              = 0x00U,
    SBC_SWK_SET_SWK_ACTIVE
};

typedef enum
{
    SBC_WUP_NO_WUP                          = 0x00U,
    SBC_WUP_DETECTED
};

typedef enum
{
    SBC_WUF_NO_WUF                          = 0x00U,
    SBC_WUF_DETECTED
};


/* --------------------------------  SWK_ECNT_STAT  ------------------------------ */

typedef enum
{
    SBC_ECNT_NOEVENT                        = 0x00U,
    SBC_ECNT_31_FRAME_ERRORS                = 0x1FU,
    SBC_ECNT_ERROR_OVERFLOW                 = 0x20U
};


/* ================================================================================ */
/* ========   Family and Product Information Registers Enumerations        ======== */
/* ================================================================================ */ 



/* --------------------------------  FAM_PROD_STAT  ------------------------------- */

typedef enum
{
    SBC_FAM_DRIVER                          = 0x01U,
    SBC_FAM_DCDC,
    SBC_FAM_MIDRANGE,
    SBC_FAM_MULTICAN,
    SBC_FAM_LITE,
    SBC_FAM_MIDRANGEPLUS                    = 0x07U
};

typedef enum
{
    SBC_PROD_TLE9461                        = 0x06U,
    SBC_PROD_TLE9461V33,
    SBC_PROD_TLE9471                        = 0x0EU,
    SBC_PROD_TLE9471V33
};


#endif  /* TLE94x1_DEFINES_H */
