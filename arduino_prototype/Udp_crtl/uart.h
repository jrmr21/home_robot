#ifndef UART_H
#define UART_H

#define RX    D5
#define TX    D6

#include <SoftwareSerial.h>

// software serial #1: RX = digital pin 10, TX = digital pin 11
static SoftwareSerial MotorSerial(RX, TX);

void driver_init(void);
void SerialWriteTab(uint8_t *data, uint16_t lenght);

#endif
