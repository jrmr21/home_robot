#ifndef MOTOR_FUNC_H
#define MOTOR_FUNC_H

#define PWMG_AV     9
#define PWMG_AR     6

#define PWMD_AV     11
#define PWMD_AR     10

#define MG_ENABLE   8
#define MD_ENABLE   12


#define AIR_ENABLE  13


static uint8_t min_power = 50;

// FUNC DEFINE :

void set_min_power(uint8_t power = 0)
{
  min_power = power; 
}

void init_pinOut(void)
{
  pinMode(PWMD_AV, OUTPUT);
  pinMode(PWMD_AR, OUTPUT);

  
  pinMode(PWMD_AV, OUTPUT);
  pinMode(PWMD_AR, OUTPUT);
  
  pinMode(MG_ENABLE, OUTPUT);
  pinMode(MD_ENABLE, OUTPUT);

  
  pinMode(AIR_ENABLE, OUTPUT);
}

void set_all_low(void)
{
  digitalWrite(PWMD_AV, 0);
  digitalWrite(PWMD_AR, 0);
  
  digitalWrite(PWMG_AV, 0);
  digitalWrite(PWMG_AR, 0);

  digitalWrite(MG_ENABLE, 0);
  digitalWrite(MD_ENABLE, 0);
  
  digitalWrite(AIR_ENABLE, 0);
}

void motor_D_crtl(uint8_t mode = 0, uint8_t power = min_power)
{
  if (mode == 1)
  {
    digitalWrite(MD_ENABLE, HIGH);
    
    analogWrite(PWMD_AV, 0);
    analogWrite(PWMD_AR, power);
  }
  else if (mode == 2)
  {
    digitalWrite(MD_ENABLE, HIGH);
    
    analogWrite(PWMD_AV, power);
    analogWrite(PWMD_AR, 0);
  }
  else
  {
    digitalWrite(MD_ENABLE, LOW);
    analogWrite(PWMD_AV, 0);
    analogWrite(PWMD_AR, 0);
  }
}

void motor_G_crtl(uint8_t mode = 0, uint8_t power = min_power)
{
  if (mode == 1)
  {
    digitalWrite(MG_ENABLE, HIGH);
    
    analogWrite(PWMG_AV, 0);
    analogWrite(PWMG_AR, power);
  }
  else if (mode == 2)
  {
    digitalWrite(MG_ENABLE, HIGH);
    
    analogWrite(PWMG_AV, power);
    analogWrite(PWMG_AR, 0);
  }
  else
  {
    digitalWrite(MG_ENABLE, LOW);
    analogWrite(PWMG_AV, 0);
    analogWrite(PWMG_AR, 0);
  }
}

void motor_test(void)
{
  motor_D_crtl(1, min_power);
  motor_G_crtl(2, min_power);
  
  delay(3000);

  motor_D_crtl(2, min_power);
  motor_G_crtl(1, min_power);
  
  delay(3000);
  
  motor_D_crtl(0);
  motor_G_crtl(0);
}
#endif
