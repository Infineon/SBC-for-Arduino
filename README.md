# SBC-for-Arduino
For more details please read our [User Manual](https://github.com/Infineon/SBC-for-Arduino/raw/master/LiteSBC_Arduino_Shield_UserManual.pdf)

<img src="https://github.com/Infineon/SBC-for-Arduino/blob/master/ReadMe%20Documents/Shield_top-view.jpg?raw=true" width=600>

The **Lite DCDC System Basis Chip Shield with TLE9471-3ES for Arduino** is based the new [Infineon Lite SBC](https://www.infineon.com/cms/de/product/automotive-system-ic/system-basis-chips-sbc/lite-sbc-family/).
The device is designed for various CAN automotive applications as main supply for the microcontroller and as interface for a CAN bus network including the CAN Partial Networking feature. 
To support these applications, the System Basis Chip (SBC) provides the main functions, such as a 5 V lowdropout voltage regulator (Buck SMPS) for e.g. a microcontroller supply, 
another 5 V low-dropout voltage regulator with off-board protection for e.g. sensor supply, a HS-CAN transceiver supporting CAN FD and CAN Partial Networking 
(incl. FD tolerant mode) for data transmission, a high-voltage GPIO with embedded protective functions and a 16-bit Serial Peripheral Interface (SPI) to control and monitor the device. 
Also implemented are a configurable timeout / window watchdog circuit with a reset feature, one Fail Output and an undervoltage reset feature. 
The device offers low-power modes in order to minimize current consumption on applications that are connected permanently to the battery. 
A wake-up from the low-power mode is possible via a message on the buses, via the bi-level sensitive monitoring/wake-up input as well as via cyclic wake.

## Key Features of the shield
* Supply voltage range 9 to 12 V
* 9 WS2812B LEDs powered by the integrated buck converter of the Lite SBC
* Microchip MCP2515 SPI-CAN protocol handler for CAN communication
* Power mosfets driven by the integrated charge pump of the Lite SBC to switch loads up to 2.5 amps. An external freewheeling diode allows switching of inductive loads
* High voltage level input for wake signalization and/or standard high voltage input
* Switchable 120 Ohm CAN termination
* Switchable SBC test mode and Arduino reset

## Application diagram
The WK input has an ESD protection and also a passive pull-down. The easiest way to connect a switch is a switchable connection to the positive input supply rail. But also any signal with a logic high level of over 4 volts can be applied here. 
The SW output can drive directly a connected load (e.g. light-bulbs, small motors, etc). The load must be externally connected to GND. The GNDs of the other CAN communication nodes and the GND of the shield should be connected together.

<img src="https://github.com/Infineon/SBC-for-Arduino/blob/master/ReadMe%20Documents/overview.png?raw=true" width=600>

## Arduino Code Examples
Two code examples for the shield are offered
* CAN-PN demonstration
* General code example to demonstrate CAN communication, Control of LEDs, SW output and the WK input

A more detailled description can be found in the [User Manual](https://github.com/Infineon/SBC-for-Arduino/raw/master/LiteSBC_Arduino_Shield_UserManual.pdf)

## Thermal Behaviour
![alt text](https://github.com/Infineon/SBC-for-Arduino/blob/master/ReadMe%20Documents/thermal_2_5_amps.jpg?raw=true "Thermal Behaviour Switched Power 2.5 Amps")
The picture shows the shield with an external load of 2.5 amps. The board heats up to approx. 60 degrees.
