#ifndef DRIVER_FUNC_H
#define DRIVER_FUNC_H

#define TEMP  7
#define RX    4
#define TX    5

#include <SoftwareSerial.h>

// software serial #1: RX = digital pin 10, TX = digital pin 11
SoftwareSerial uart(RX, TX);

void driver_init(void)
{
  uart.begin(9600);
  
}


#endif
