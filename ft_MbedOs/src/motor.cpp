#include "header/core_headers.h"

static PwmOut MotorD0(D0);
static PwmOut MotorD1(D1);


void	 MotorD_init(int time)
{
    MotorD0.period_us(time);      //  .5s  default deltaTime PWM
    MotorD1.period_us(time);      
}

void	 MotorD_avant(int vitesse)
{ 
    MotorD0 = vitesse * 0.01;
    MotorD1 = 0;
}

void	MotorD_arriere(int vitesse)
{
    MotorD0 = 0;
    MotorD1 = vitesse * 0.01;
}

void	 MotorD_stop(void)
{
    MotorD0 = 0;
    MotorD1 = 0;
}
