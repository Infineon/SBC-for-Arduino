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
 * @file        TLE94x1_SPI.h
 *
 * @brief       Declaration file for TLE94x1 SBC family device SPI functions
 *
 * @version     V1.0.0
 * @date        26. March 2019
 * @author      Markus Noll / markus.noll@infineon.com
 *******************************************************************************************************/



 
#ifndef TLE94x1_SPI_H
#define TLE94x1_SPI_H
 




 
/* ================================================================================ */
/* ============================   HEADER FILES     ================================ */
/* ================================================================================ */ 

#include <stdint.h>



/* ================================================================================ */
/* =============================   SPI Functions     ============================== */
/* ================================================================================ */

/**
 * @brief   IMPORTANT! THIS METHOD HAS TO BE DEFINED BY THE USER
 * 
 *          The function has to initialze the SPI of the uC and will be called once during SBC_Init().
 *          In case, the SPI hardware is already initialized by some other code before, it can be left blank.
 * 
 * @retval  Method has to return 0 if initialization was successful.
 */
int8_t SBC_SPI_INIT(void);

/**
 * @brief   IMPORTANT! THIS METHOD HAS TO BE DEFINED BY THE USER
 * 
 *          The function will be called by the library everytime when a SPI communication is needed.
 *          The function proceeds a bidirectional 16-bit transfer to/from the SBC  .
 *          As some UCs only supports 8-Bit transfers, the input arguments are split in two 8-bit arguments.
 *          For further implementation details have a look at datasheet chapter 13.1 or at the Arduino-examples.
 * 
 * @param   Upper   The first 8 bit to transmit to the SBC.
 * @param   Lower   The second 8 bit to transmit to the SBC.
 * @retval  The function will return all 16 bits received from the SBC. 
 *          Bit[15:8] are the first 8 bits received (Status-Information-Field).
 *          Bit[7:0] is the data-field transmitted of the SBC.
 */	
uint16_t SBC_SPI_TRANSFER16(uint8_t Upper, uint8_t Lower);

#endif /* TLE94x1_SPI_H */
