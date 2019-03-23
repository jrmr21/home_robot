/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "src/header/core_headers.h"
//#include "src/header/stats_report.h"

DigitalOut	led1(LED);
DigitalOut	led2(LED2);

void	test(void)
{
	PwmOut cam1(SERVO_CAM1);

	cam1.period_ms(1.5);
	
	cam1.write(0.50f);

	cam1.write(0);
}
int	main(int argc, char **argv)
{
	while (1);
	
	char	power;
	char	flag;

	flag	= 0;
	power	= 0;
	MotorD_init();
	
	test();
	while (5)
	{
		
		MotorD_avant(power);
		power += 5;
		if (power > 100)
			power = 0;


		led1 = led2 = flag = !flag;
		wait(1);
	}

	return (0);
}
