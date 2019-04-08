#include "Adafruit_NeoPixel.h"
#include <SPI.h>
#include "mcp2515.h"
#include "TLE94x1.h"
#include "TLE94x1_SPI.h"

struct can_frame canMsg;
MCP2515 mcp2515(9);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, 6, NEO_GRB + NEO_KHZ800);


long timeref;
bool irqSBC = false;


void irqSBC_Handler() {
  irqSBC = true;
}

void irqSBC_Wake_Handler(uint8_t value) {    
    Serial.println("Sending can_frame..");   
    
    struct can_frame canFrame = {.can_id = 0xAA , .can_dlc = 1, .data = {0xAA} };
    
    if (SBC_Read_RegField(SBC_WK_LVL_STAT, SBC_WK_LVL_STAT_WK_LVL_Msk, SBC_WK_LVL_STAT_WK_LVL_Pos) == SBC_WK_LVL_HIGH) {
      canFrame.data[0] = 0x01;
    }
    else {
      canFrame.data[0] = 0x00;
    }
    
    mcp2515.sendMessage(&canFrame);
}

/* Helper function to avoid regular resending of CAN frames if CAN frame is not acknowledged */
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

    /* Start Uart */
    Serial.begin(115200);
    Serial.println("Starting LiteSBC Shield General Code Example...");
  
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
    attachInterrupt(1, irqSBC_Handler, RISING);

    SBC_Register_Callback(SBC_ISR_WK_WU, irqSBC_Wake_Handler);

    /* Initialize LEDs */
    strip.begin();
    strip.setBrightness(255);
    strip.show();
}

void loop() {

    /* Trigger Watchdog every 100ms */
    if (millis() > timeref + 100) {
        SBC_WD_Trigger();
        timeref = millis();
    }


    /* Handle SBC_ISR() if INTN was toggeled */
    if (irqSBC) {
      SBC_ISR();
      irqSBC = false;      
    }


      
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
    } 
    
    
    
}
