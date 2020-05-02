#include "motor_func.h"
#include "driver_func.h"


void setup() 
{
  uint8_t   prepare   = 1;
  uint16_t  time_out  = 0;
  
  init_pinOut();
  driver_init();
  
  set_all_low();

  Serial.begin(9600);

  /*
      data [0]  == 0  (set init mode)
      data [1]  == X  (uint16_t time out MSB)
      data [2]  == X  (uint16_t time out MSB)
      data [3]  == X  (uint8_t  min power)
   */
   
  while (prepare)
  {
    uint8_t    data[4];

    Serial.println("wait card...");
    if (uart.available() > 0)
    {
      uart.readBytes(data, 4);

      if (data[0] == 0)
      {
        time_out |= data[1] << 8;
        time_out |= data[2];

        set_min_power(data[3]);

        Serial.println("succes setup");
        Serial.print("time max : ");
        Serial.println(time_out, DEC);

        Serial.print("power min: ");
        Serial.println(data[3], DEC);
        prepare = 0;
      }

      uart.flush();
    }
  }
  
  while (1)
  {
    uint8_t    data[2] = {0};
    
    if (uart.available() > 0)
    {
      uart.readBytes(data, 2);

      Serial.println(data[0], DEC);
      Serial.println(data[1], DEC);
      
      switch (data[0])
      {
        case 15 :
          Serial.println("change min speed");
          set_min_power(data[1]);
          break;
        
        case 16 :
          Serial.println("foward move");
          motor_G_crtl(1);
          motor_D_crtl(1); 
          break;
          
        case 17 :
          Serial.println("backward move");
          motor_G_crtl(2);
          motor_D_crtl(2);
          break;
        
        case 18 :
          Serial.println("left move");
          motor_G_crtl(2);
          motor_D_crtl(1);
          break;

        case 19 :
          Serial.println("right move");
          motor_G_crtl(1);
          motor_D_crtl(2);
          break;
          
        case 20 :
          Serial.println("STOP !! move");
          motor_G_crtl();
          motor_D_crtl(); 
          break;  
      }
      
      uart.flush();
    }
  }
}
