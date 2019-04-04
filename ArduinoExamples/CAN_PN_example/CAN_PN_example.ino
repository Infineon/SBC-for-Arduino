/*
 * CAN Selective Wake example
 * 
 * Will go to sleep after first valid CAN message.
 * Blinks green when woken via CAN PN and falls back to sleep again immediately.
 * CAN PN message is 0x0xDEADC0DECODEBASE.
 * CAN PN ID is 0x02D.
 */

#include "Adafruit_NeoPixel.h"

#include <SPI.h>
#include "mcp2515.h"
#include "TLE94x1.h"
#define LEDPIN 6


Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, LEDPIN, NEO_GRB + NEO_KHZ800);

long wdTimeRef;
long sleepRepeatTimeRef;
bool sleepRepeatStart = false;
bool waitForValidCanFrameToEnterSleep = false;



void setup() {
    strip.begin();
    strip.setBrightness(50);
    strip.show(); 
    
    //Set CS Pin of MCP2515 to constant high as the CAN controller is not used
    pinMode(9, OUTPUT);
    digitalWrite(9,HIGH);

    //Start Uart
    Serial.begin(115200);
    Serial.println("Arduino Reset");
  
         
    /* Initialize SBC */
    SBC_ErrorCode err = SBC_Init();
    if(err.flippedBitsMask != 0) {
        Serial.print("Failed to initialize SBC at register 0b");
        Serial.print(err.SBC_Register, BIN);
        Serial.print(". Expected value 0b");
        Serial.print(err.expectedValue, BIN);
        Serial.print(". Flipped bits 0b");
        Serial.println(err.flippedBitsMask, BIN);
        Serial.println("Please check configuration or maybe is sleeping.");
        waitForValidCanFrameToEnterSleep = false;
    } else {
        Serial.println("SBC initialization successful.");
        waitForValidCanFrameToEnterSleep = true;
        sleepRepeatStart = true;
        
        //Set LEDs to Green to indicate SBC activity 
        for (int i=0; i<9; i++) {
            strip.setPixelColor(0,0x00FF00);
            strip.show();
        }
        
    }
    
  
        
 
    /* Check for Power-On Reset */
    if((uint8_t)(SBC_Read_Command(SBC_SUP_STAT_0)) >> SBC_SUP_STAT_0_POR_Pos == SBC_POR_EVENT) {
        /* Power-on reset detected */
        Serial.println("POWER-ON RESET detected");

        /* Clear POR event */
        SBC_Write_RegField(SBC_SUP_STAT_0, SBC_SUP_STAT_0_POR_Msk, SBC_SUP_STAT_0_POR_Pos, SBC_POR_NOEVENT, NULL);

        
    }
    wdTimeRef = millis();
    sleepRepeatTimeRef = millis();
}

void loop() {

    /* Trigger Watchdog every 100ms */
    if(millis() > wdTimeRef + 100) {
        SBC_WD_Trigger();
        wdTimeRef = millis();
    }

    if (millis() > sleepRepeatTimeRef + 500 && sleepRepeatStart==true) {
      waitForValidCanFrameToEnterSleep = true;
      sleepRepeatTimeRef = millis();
    }
  
    /* In case SBC is initialized successfully, wait for valid CAN frame to get CAN Sync - then enter sleep mode */
    if(waitForValidCanFrameToEnterSleep) {
      waitForValidCanFrameToEnterSleep = false;
        uint8_t SWK_statusVal = (uint8_t)SBC_Read_Command(SBC_SWK_STAT);
        
        if(((SWK_statusVal & SBC_SWK_STAT_SYNC_Msk) >> SBC_SWK_STAT_SYNC_Pos) == SBC_SYNC_VALID_FRAME_RECEIVED) {

          /* SBC protocol handler is in sync, enter sleep mode now, turn off LEDs */
            Serial.print("Enter Sleep Mode now");
            for (int i=0; i<9; i++) {
              strip.setPixelColor(0,0x000000);
              strip.show();
            }
            
            SBC_ErrorCode err = SBC_Mode_Sleep();
            if(err.flippedBitsMask != 0) {
                
                Serial.print("Tried entering Sleep Mode register 0b");
                Serial.print(err.SBC_Register, BIN);
                Serial.print(". Expected value 0b");
                Serial.print(err.expectedValue, BIN);
                Serial.print(". Flipped bits 0b");
                Serial.println(err.flippedBitsMask, BIN);
                
                //turn LEDs to RED in case of go-to-sleep fail
                for (int i=0; i<9; i++) {
                  strip.setPixelColor(0,0xFF0000);
                  strip.show();
                }
                
            } else {
                //SBC is in sleep-mode now... Arduino waits to get reset from SBC, then restart of the software
                Serial.println("Entered Sleep Mode");
                sleepRepeatStart==false;
            }
        }
    }
}
