#include <Arduino.h>
#include <mcp2515.h>

MCP2515 mcp2515(2); // cs/ss pin is 5 

struct can_frame canMessage;

void setup() {
  Serial.begin(9600);
  SPI.begin();
   mcp2515.reset();
   mcp2515.setBitrate(CAN_500KBPS,MCP_8MHZ);
   mcp2515.setNormalMode();
  
  
}

void loop() {
  int speed = 14;
  int temp = 25;

  canMessage.can_id = 0x000;
  canMessage.can_dlc = 4;
  canMessage.data[0] = speed;
  canMessage.data[1] = temp;

  mcp2515.sendMessage(&canMessage);


}