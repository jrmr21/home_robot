/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "header/core_headers.h"
//#include "src/header/stats_report.h"

Queue<char, 8>		QSerial;
Queue<char, 8>		QMotor;


int	main(int argc, char **argv)
{
	Serial	pc2(PA_9, PA_10);

	pc2.baud(9600);
	
	Thread *thread1 = new Thread(osPriorityNormal1, 256, NULL, NULL);	// 250 byte is minimum stack size, else destroy your program
	thread1->start( callback( tsk_blink));

	Thread *thread2 = new Thread(osPriorityNormal1, 550, NULL, NULL);	// 250 byte is minimum stack size, else destroy your program
	thread2->start( callback( tsk_cam));

	Thread *thread3 = new Thread(osPriorityNormal1, 256, NULL, NULL);	// 250 byte is minimum stack size, else destroy your program
	thread3->start( callback( tsk_motor));
	
	Thread *thread4 = new Thread(osPriorityNormal1, 1200, NULL, NULL);	// 250 byte is minimum stack size, else destroy your program
	thread4->start( callback( tsk_Serial2, &pc2));

	while (1)
		Thread::wait(500);
	
	return (0);
}
