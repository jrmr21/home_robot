#include "uart.h"

void driver_init(void)
{
  MotorSerial.begin(9600);

  uint8_t tab[4];

  tab[0] = 0;   // id init
  tab[1] = 0;
  tab[2] = 200; // > 200ms timeout
  tab[3] = 70;

  SerialWriteTab(tab, 4);
}

void SerialWriteTab(uint8_t *data, uint16_t lenght)
{
  for (uint16_t i = 0; i < lenght; i++)
  {
    MotorSerial.write(data[i]);
  }
  MotorSerial.println();
}

