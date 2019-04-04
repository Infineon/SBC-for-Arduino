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
 * @file        TLE94x1_SPI.c
 *
 * @brief       Implementation of all SPI related functions
 *
 * @version     V1.0.0
 * @date        26. March 2019
 * @author      Markus Noll / markus.noll@infineon.com
 *******************************************************************************************************/




/* ================================================================================ */
/* ============================   HEADER FILES     ================================ */
/* ================================================================================ */ 

#include "TLE94x1_SPI.h"

/* Example implementation for Arduino */
#include <Arduino.h>
#include <SPI.h>






/* ================================================================================ */
/* =======================   SPI communication functions     ====================== */
/* ================================================================================ */ 



int8_t SBC_SPI_INIT(void) {
    pinMode(8, OUTPUT);
    digitalWrite(8, HIGH);
    SPI.begin();
    return 0;
}



uint16_t SBC_SPI_TRANSFER16(uint8_t Upper, uint8_t Lower) {
    uint16_t outdata = 0;
    SPI.beginTransaction(SPISettings(1000000, LSBFIRST, SPI_MODE1));
    digitalWrite(8, LOW);
    outdata = (SPI.transfer(Upper) << 8); 
    outdata |= SPI.transfer(Lower);
    SPI.endTransaction();
    digitalWrite(8, HIGH);
    return outdata;
}
