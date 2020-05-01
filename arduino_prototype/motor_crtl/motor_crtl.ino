#include "motor_func.h"
#include "driver_func.h"


void setup() 
{
  uint8_t   prepare   = 1;
  uint16_t  time_out  = 500;
  
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
    String    data;
    
    if (uart.available() > 0)
    {
      data = uart.readString();

      if (data[0] == 48)
      {
        time_out |= data[1] << 8;
        time_out |= data[2];

        set_min_power(data[3]);
        
        Serial.println("succes setup");
        prepare = 0;
      }

      uart.flush();
    }
  }
  
  while (1)
  {
    String    data;
    uint8_t i   = 0;
    
    data[0] = 0;
    
    if (uart.available() > 0)
    {
      data = uart.readString();

      Serial.print("I received: ");
      Serial.println(data);

      uart.flush();
    }
  }
}
