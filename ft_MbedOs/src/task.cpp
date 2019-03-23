#include "header/core_headers.h"

//	Threads declaration in main.cpp
//Thread thread1(osPriorityNormal, 128, NULL);


void	tsk_blink(void) 
{
	DigitalOut      led(LED2);

	led   = 0;
	while (1) 
	{
		led = !led;
		Thread::wait(500);
	}
}

