#include "header/core_headers.h"

//	Threads declaration in main.cpp
extern Queue<char, 8>		QSerial;

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


void	tsk_cam(void)
{
	int	posX;
	int	posY;
	char	*data;

	
	PwmOut cam1(SERVO_CAM1);
	cam1.pulsewidth_us(1500); 	//NB in microseconds	
		
	PwmOut cam2(SERVO_CAM2);
	cam2.pulsewidth_us(1500);	

	posX =  mapping(90, 0, 180, 1000, 2000);
	posY = posX;

	cam2.pulsewidth_us(posX);	// 1000 to 2000
	Thread::wait(100);	

	cam1.pulsewidth_us(posY);	// 1000 to 2000
	Thread::wait(100);	

	while (1)
	{
		osEvent QData = QSerial.get();
		if (QData.status == osEventMessage)
			data = (char *)QData.value.p;
		
		if ((atoi(data + 1) > -1) && (atoi(data + 1) < 181))
		{
			if (data[0] == 'x')
				posX = mapping(atoi(data + 1), 0, 180, 1000, 2000);
			else if(data[0] == 'y')
				posY = mapping(atoi(data + 1), 0, 180, 1000, 2000);
			
		}
	
		cam2.pulsewidth_us(posY);        // 1000 to 2000
		cam1.pulsewidth_us(posX);        // 1000 to 2000	

		Thread::wait(100);
	}
}

void	tsk_Serial2(Serial *pc)
{
	char	data[20];
	
	strcpy(data, "\0");
	while (1)
	{
		pc->scanf("%s", data);
		pc->printf(data);
		
		//if (data[0] == 'x' || data[0] == 'y')
			QSerial.put(data);	// send data
		Thread::wait(50);
	}
}
