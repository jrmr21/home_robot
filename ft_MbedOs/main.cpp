/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "src/header/core_headers.h"
#include "src/header/stats_report.h"

int main(int argc, char **argv)
{
	char	power;

	power	= 0;
	MotorD_init(1);
	while (5)
	{
		MotorD_avant(power);
		power += 2;
		if (power > 100)
			power = 0;
		wait(3);
	}

	return (0);
}
