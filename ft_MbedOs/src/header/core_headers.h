#ifndef CORE_HEADERS_H__
#define CORE_HEADERS_H__

#include "mbed.h"
#include "rtos.h" 

//**********	pinout		********

#define LED     PA_5
#define LED2    PB_3

#define D0	PB_4         //  patte 1 motor D
#define D1	PB_5	 	//  patte 2 motor D

#define SERVO_CAM1	PA_8
#define SERVO_CAM2	PB_1



//**********	task.cpp	*********

void    tsk_blink(void);
void	tsk_cam(Serial *pc);




//**********	motor.cpp	*********

//static PwmOut MotorD0(D0);          	//  moteur pwm
//static PwmOut MotorD1(D1); 

void	MotorD_init(int time = 100 ); 	// 0.1ms    default deltaTime PWM

void	MotorD_avant(int vitesse);
void	MotorD_arriere(int vitesse);
void	MotorD_stop(void);



//**********	tools.cpp	*********

int	mapping(float x, int in_min, int in_max, int out_min, int out_max);
void	croissant(float *tableau );
float	moyenne(float *tableau );

#endif
