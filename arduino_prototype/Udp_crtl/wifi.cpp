#include "wifi.h"

extern String wifi_connection()
{
    IPAddress apIP(192, 168, 1, 177); 

    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0)); 
    //  https://42bots.com/tutorials/esp8266-example-wi-fi-access-point-web-server-static-ip-remote-control/
    WiFi.softAP(ssid, password);
    
    UDPTestServer.begin(UDPPort);  //  run UDP port 
     
     return "connecté";  
}


// 0 == ID
// 1 == lenght
// x == data...

extern void get_wifi_messageTabInt()
{
    uint8_t cb = UDPTestServer.parsePacket();       //  on check la reception des données
    
    if (cb)                                     //  si c est vrai
    {
      UDPTestServer.read(&packetBuffer[ID_CASE], packetSize);     //  reception des data dans packet buffer

      Serial.println("succes received");
      Serial.print("lenght : ");
      Serial.println(packetBuffer[LENGHT_CASE]);
      Serial.println(packetBuffer[ID_CASE]);
      
      Serial.print("data : ");
      for (uint8_t i = 0; i < packetBuffer[LENGHT_CASE]; i++)
      {
        Serial.println(packetBuffer[DATA_CASE + i]);
      }
      Serial.println("");

      SerialWriteTab(&packetBuffer[DATA_CASE + 1], 1);
    }
}
