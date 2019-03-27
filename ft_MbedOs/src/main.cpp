/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "header/core_headers.h"
//#include "src/header/stats_report.h"



int	main(int argc, char **argv)
{
	Serial      pc(USBTX, USBRX);
	
	pc.baud(9600);
	Thread *thread1 = new Thread(osPriorityNormal1, 250, NULL, NULL);	// 250 byte is minimum stack size, else destroy your program
	thread1->start( callback( tsk_blink));

	Thread *thread2 = new Thread(osPriorityNormal1, 550, NULL, NULL);	// 250 byte is minimum stack size, else destroy your program
	thread2->start( callback( tsk_cam, &pc));


	while (1)
		Thread::wait(510);	
	return (0);
}
