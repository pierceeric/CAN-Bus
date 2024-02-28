// CAN Receiver Code (Arduino UNO):
// modified from :https://circuitdigest.com/microcontroller-projects/arduino-can-tutorial-interfacing-mcp2515-can-bus-module-with-arduino

#include <SPI.h>              //Library for using SPI Communication 
#include <mcp2515.h>          //Library for using CAN Communication
 
int first = 0;

struct can_frame canMsg; 

MCP2515 mcp2515(10);                 // SPI CS Pin 10 

void setup() {
  SPI.begin();                       //Begins SPI communication
  Serial.begin(9600);                //Begins Serial Communication at 9600 baudrate 

  mcp2515.reset();                          
  mcp2515.setBitrate(CAN_250KBPS,MCP_16MHZ); //Sets CAN speed 255 kbps and Clock (crystal) 16 MHz 

  // Select 1 of the 3 modes
  mcp2515.setNormalMode();
  Serial.println("Normal mode is set.");
  // mcp2515.setLoopbackMode();   // Loopback
  //Serial.println("Loopback mode is set.");
  //mcp2515.setListenOnlyMode(); // Listen Only
  //Serial.println("Listen Only mode is set.");
  
}

void loop() 
{
  while (first < 1){
    Serial.println("entered the VOID to LISTEN");
    ++first;
  }
  
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) // To receive data (Poll Read)
  {
    Serial.println("Reading Data");

    uint8_t byte0 = canMsg.data[0];     
    uint8_t byte1 = canMsg.data[1];
    uint8_t byte2 = canMsg.data[2];
    uint8_t byte3 = canMsg.data[3];
    uint8_t byte4 = canMsg.data[4];
    uint8_t byte5 = canMsg.data[5];
    uint8_t byte6 = canMsg.data[6];
    uint8_t byte7 = canMsg.data[7];

    if (byte0 < 0x10)               // If data byte is less than 0x10, add a leading zero
      {
        Serial.print("0");
      }
    Serial.print(byte0, HEX);
    Serial.print(" ");
    
    if (byte1 < 0x10)               // If data byte is less than 0x10, add a leading zero
      {
        Serial.print("0");
      }
    Serial.print(byte1, HEX);
    Serial.print(" ");
    
    if (byte2 < 0x10)               // If data byte is less than 0x10, add a leading zero
      {
        Serial.print("0");
      }
    Serial.print(byte2, HEX);
    Serial.print(" ");  

    if (byte3 < 0x10)               // If data byte is less than 0x10, add a leading zero
      {
        Serial.print("0");
      }
    Serial.print(byte3, HEX);
    Serial.print(" ");  

    if (byte4 < 0x10)               // If data byte is less than 0x10, add a leading zero
      {
        Serial.print("0");
      }
    Serial.print(byte4, HEX);
    Serial.print(" ");  

    if (byte5 < 0x10)               // If data byte is less than 0x10, add a leading zero
      {
        Serial.print("0");
      }
    Serial.print(byte5, HEX);
    Serial.print(" ");  

    if (byte6 < 0x10)               // If data byte is less than 0x10, add a leading zero
      {
        Serial.print("0");
      }
    Serial.print(byte6, HEX);
    Serial.print(" ");  

    if (byte7 < 0x10)               // If data byte is less than 0x10, add a leading zero
      {
        Serial.print("0");
      }
    Serial.print(byte7, HEX);
    Serial.print(" \n");

    delay(1000);
    
  }

}
