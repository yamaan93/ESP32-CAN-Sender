#include <Arduino.h>

#include "mcp2515.h"
#include "esp_system.h"
#include "driver/spi_master.h"

struct can_frame frame;
spi_device_handle_t spi;

MCP2515 mcp2515(&spi);

void setup()
{

  Serial.begin(9600);
  Serial.print("MOSI: ");
  Serial.println(MOSI);
  Serial.print("MISO: ");
  Serial.println(MISO);
  Serial.print("SCK: ");
  Serial.println(SCK);
  Serial.print("SS: ");
  Serial.println(SS);

  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
}

void loop()
{
  struct can_frame message;
  message.can_id = 0x000;
  message.can_dlc = 4;

  for (int i = 0; i < message.can_dlc; i++)
  {
    message.data[i] = i;
  }
  mcp2515.sendMessage(MCP2515::TXB1, &message);
}