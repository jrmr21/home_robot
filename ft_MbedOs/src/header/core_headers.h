#ifndef CORE_HEADERS_H__
#define CORE_HEADERS_H__

#include "mbed.h"

//**********	pinout		********

#define LED     PA_5
#define LED2    PB_3


//**********	motor.cpp	*********

#define D0 PA_5         //  patte 1 motor D
//#define D0 PB_4         //  patte 1 motor D
//#define D1 PB_5 	//  patte 2 motor D
#define D1 PB_3 	//  patte 2 motor D

static PwmOut MotorD0(D0);          	//  moteur pwm
static PwmOut MotorD1(D1); 

void	MotorD_init(int time = 0.5f ); 	// 500ms    default deltaTime PWM

void	MotorD_avant(int vitesse);
void	MotorD_arriere(int vitesse);
void	MotorD_stop(void);


#endif
