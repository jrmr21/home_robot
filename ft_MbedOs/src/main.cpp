/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "header/core_headers.h"
//#include "src/header/stats_report.h"



int	main(int argc, char **argv)
{
	
	Thread *thread1 = new Thread(osPriorityNormal1, 250, NULL, NULL);	// 250 byte is minimum stack size, else destroy your program
	thread1->start( callback( tsk_blink));

	while (1)
		Thread::wait(1);	
	return (0);
}
