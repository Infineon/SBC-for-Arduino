/*
 * LED and Charge Pump example
 * 
 * Change color and brightness of a single LED by CAN ID 0x100.
 * First byte (byte[0] is the index of the LED in range 0 to 8.
 * The next 3 bytes are red, green and blue values respectively.
 * 
 * Change all LEDs at once by CAN ID 0x101.
 * First 3 bytes are red, green and blue values respectively.
 * 
 * Set Charge Pump and FO_LED by CAN ID 0x102.
 * First byte will start the charge pump on any value greater than 0. Send 0 to turn it off.
 * First byte will start the FO_LED on any value greater than 0. Send 0 to turn it off.
 */

#include "Adafruit_NeoPixel.h"

#include <SPI.h>
#include "mcp2515.h"
#include "TLE94x1.h"
#include "TLE94x1_SPI.h"

struct can_frame canMsg;
MCP2515 mcp2515(9);

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, PIN, NEO_GRB + NEO_KHZ800);


long timeref, timeref2;
bool ison = false;
bool toggledFOCP = false;

void irqHandler() {
    MCP2515::ERROR err = mcp2515.readMessage(&canMsg);
    Serial.println("Int. CAN");

    if (err == MCP2515::ERROR_OK) {
        switch (canMsg.can_id)
        {   
            /* Change single pixel color using can_id 0x100 */
            case 0x100:
                strip.setPixelColor(canMsg.data[0], strip.Color(canMsg.data[1], canMsg.data[2], canMsg.data[3]));
                strip.show();
                break;

            /* Change all pixels to a color using can_id 0x101 */
            case 0x101:
                for (int i = 0; i < strip.numPixels(); i++)  {
                    strip.setPixelColor(i, strip.Color(canMsg.data[0], canMsg.data[1], canMsg.data[2]));
                    strip.show(); 
                }
                break;

            /* Turn on/off the Charge Pump and Failure Output */
            case 0x102:
                if(canMsg.data[0]) {
                    SBC_CP_On();
                } else {
                    SBC_CP_Off();
                }
                if(canMsg.data[1]) {
                    SBC_FO_Test_On();
                } else {
                    SBC_FO_Test_Off();
                }
                break;

            /* Blink red */
            default:
                for (int i = 0; i < strip.numPixels(); i++)  {
                    strip.setPixelColor(i, 0xff0000);
                    strip.show(); 
                }
                delay(250);
                for (int i = 0; i < strip.numPixels(); i++)  {
                    strip.setPixelColor(i, 0x000000);
                    strip.show(); 
                }
                break;
        }
    } else {
        Serial.print("Check CAN error ");
        Serial.println(err, DEC);
    }
}

void sendCanMessage(uint8_t value) {    
    Serial.println("Sending can_frame..");
    struct can_frame canFrame = {.can_id = 0xAA , .can_dlc = 1, .data = {0xAA} };
    mcp2515.sendMessage(&canFrame);
}

void mcp2515setOneShotMode(void) {
    SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));
    digitalWrite(9, LOW);
    SPI.transfer(0x05U);
    SPI.transfer(0x0FU);
    SPI.transfer(0b00001000U);
    SPI.transfer(0xFFU);
    digitalWrite(9, HIGH);
    SPI.endTransaction();
}

void setup() {
    Serial.begin(115200);
    Serial.println("Start Arduino Setup");
  
    SPI.begin();

    /* Initialize MCP2515 */
    mcp2515.reset();
    mcp2515.setBitrate(CAN_500KBPS);
    mcp2515setOneShotMode();
    mcp2515.setNormalMode();

    /* Initialize SBC */
    SBC_ErrorCode err = SBC_Init();
    if(err.flippedBitsMask != 0) {
        Serial.print("Failed to initialize SBC at register 0b");
        Serial.print(err.SBC_Register, BIN);
        Serial.print(". Expected value 0b");
        Serial.print(err.expectedValue, BIN);
        Serial.print(". Flipped bits 0b");
        Serial.println(err.flippedBitsMask, BIN);
        Serial.println("Please check configuration.");
    } else {
        Serial.println("SBC initialization successful.");
    }

    /* Initialize interrupts */
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    attachInterrupt(0, irqHandler, FALLING);
    attachInterrupt(1, SBC_ISR, RISING);

    SBC_Register_Callback(SBC_ISR_WK_WU, sendCanMessage);

    /* Initialize LEDs */
    strip.begin();
    strip.setBrightness(255);
    strip.show();

    timeref = millis();
    timeref2 = timeref;
}

void loop() {

    /* Trigger Watchdog every 100ms */
    if (millis() > timeref + 100) {
        SBC_WD_Trigger();
        timeref = millis();
    }
}
