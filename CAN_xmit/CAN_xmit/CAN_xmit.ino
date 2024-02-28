// CAN Transmitter Code (Arduino Nano):
// modified from https://circuitdigest.com/microcontroller-projects/arduino-can-tutorial-interfacing-mcp2515-can-bus-module-with-arduino

#include <SPI.h>          //Library for using SPI Communication 
#include <mcp2515.h>      //Library for using CAN Communication

struct can_frame canMsg;

MCP2515 mcp2515(10); // Set the pin number where SPI CS is connected (10 by default)

void setup() 
{
  while (!Serial);
  Serial.begin(9600);        // Set Baud Rate on Serial Port
  SPI.begin();               // Begins SPI communication
  
  mcp2515.reset();                          // Reset the MCP2515
  mcp2515.setBitrate(CAN_250KBPS,MCP_8MHZ); //Set the CAN bus speed, and clock (crystal on CAN Hat)
  
  // Select one of the next 3 modes:
  mcp2515.setNormalMode();        //Normal
  // mcp2515.setLoopbackMode();   // Loopback
  // mcp2515.setListenOnlyMode(); // Listen Only

  SERIAL_PORT_MONITOR.println("CAN started!");
  
}

void loop() 
{
  for(uint8_t myCount = 0; myCount<= 0xF; myCount++){
  
  canMsg.can_id  = 0x036;       //Set 11-bit CAN ID
  canMsg.can_dlc = 8;           //CAN Data Length Code
  canMsg.data[0] = myCount;         //Update value in Data Byte[0]
  canMsg.data[1] = 0x01;            //Update value in Data Byte[1]
  canMsg.data[2] = 0xB;             //Update value in Data Byte[2]
  canMsg.data[3] = 0x02;            //Update value in Data Byte[3]
  canMsg.data[4] = 0xC;             //Update value in Data Byte[4]
  canMsg.data[5] = 0x03;            //Update value in Data Byte[5]
  canMsg.data[6] = 0xD;             //Update value in Data Byte[6]
  canMsg.data[7] = 0x04;            //Update value in Data Byte[7]

  mcp2515.sendMessage(&canMsg);     //Send the CAN message

  SERIAL_PORT_MONITOR.println("CAN message sent.");
  Serial.println(myCount, HEX);
  delay(1000);
  }
}
