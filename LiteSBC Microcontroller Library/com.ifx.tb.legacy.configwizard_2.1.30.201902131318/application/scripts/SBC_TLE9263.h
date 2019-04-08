/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2018, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **********************************************************************************************************************/
#ifndef SBC_TLE9263_H
#define SBC_TLE9263_H

/* XML Version 0.0.5 */
#define SBC_XML_VERSION (00005u)

#define CTRL_BUS_CTRL_1 (0x20u) /*decimal 32*/

#define CTRL_BUS_CTRL_2 (0x0u) /*decimal 0*/

#define CTRL_GPIO_CTRL (0x0u) /*decimal 0*/

#define CTRL_HS_CTRL1 (0x0u) /*decimal 0*/

#define CTRL_HS_CTRL2 (0x0u) /*decimal 0*/

#define CTRL_HW_CTRL (0x0u) /*decimal 0*/

#define CTRL_M_S_CTRL (0x0u) /*decimal 0*/

#define CTRL_PWM1_DC (0.0)

#define CTRL_PWM2_DC (0.0)

#define CTRL_PWM_FREQ_CTRL (0x0u) /*decimal 0*/

#define CTRL_SW_SD_CTRL (0x0u) /*decimal 0*/

#define CTRL_TIMER1_CTRL (0x0u) /*decimal 0*/

#define CTRL_TIMER2_CTRL (0x0u) /*decimal 0*/

#define CTRL_WD_CTRL (0x0u) /*decimal 0*/

#define CTRL_WK_CTRL_1 (0x0u) /*decimal 0*/

#define CTRL_WK_CTRL_2 (0x7u) /*decimal 7*/

#define CTRL_WK_FLT_CTRL (0x0u) /*decimal 0*/

#define CTRL_WK_PUPD_CTRL (0x0u) /*decimal 0*/

#define LED_MODE (0x2u) /*decimal 2*/

#define LED_PRODUCT (0x0u) /*decimal 0*/

#define LED_TARGET (0x0u) /*decimal 0*/

#define LED_USB (0x0u) /*decimal 0*/

#define LED_VOLTAGE (0x2u) /*decimal 2*/

#define STATUS_REG_READ_STOP (0x0u) /*decimal 0*/

#define WDT_STOP (0x0u) /*decimal 0*/

#endif /* SBC_TLE9263_H */
