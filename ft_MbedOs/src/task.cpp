#include "header/core_headers.h"

//	Threads declaration in main.cpp


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


void	tsk_cam(Serial *pc)
{
	int pos;
	char command[5]; 	

	pos = 0;	
	

	PwmOut cam1(SERVO_CAM1);
	cam1.pulsewidth_us(1500); 	//NB in microseconds	
		
	PwmOut cam2(SERVO_CAM2);
	cam2.pulsewidth_us(1500);	

	pos =  mapping(90, 0, 180, 1000, 2000);


	cam2.pulsewidth_us(pos);	// 1000 to 2000
	Thread::wait(100);	

	cam1.pulsewidth_us(pos);	// 1000 to 2000
	Thread::wait(100);	

	while (1)
	{
		if (pc->readable())
		{
			int x;

			x = 0;
			pc->scanf("%s", command);
			x = atoi(command + 1);			// clear 'x' or 'y'
			pos =  mapping(x, 0, 180, 1000, 2000);
			
			cam2.pulsewidth_us(pos);        // 1000 to 2000
 			Thread::wait(100);  
		}	
		Thread::wait(10);
	}
}
