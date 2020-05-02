#include "wifi.h"

void setup() 
{
  Serial.begin(115200);
  wifi_connection();                                          // lance le serveur

  delay(2000);
  driver_init();
  
  packetBuffer[ENABLE_CASE] = 0;
}

void loop()
{
    get_wifi_messageTabInt();
    delay(100);
}

