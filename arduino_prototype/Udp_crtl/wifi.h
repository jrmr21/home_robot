#ifndef WIFI_H
#define WIFI_H
#include <arduino.h>

#include "uart.h"
#include "ESP8266WiFi.h"
#include <WiFiUdp.h>

#include <WiFiClient.h>         
#include <ESP8266WebServer.h>     


#define ID_CONNECTION 142

#define ENABLE_CASE   0
#define ID_CASE       1
#define LENGHT_CASE   2
#define DATA_CASE     3

static const char* ssid     = "JrmrRobot";   //          id et mdp de connection
static const char* password = "mainbot123";   // 


static WiFiUDP UDPTestServer;             //  objet UDP
static unsigned int UDPPort = 7979;       //  port de com
static const int packetSize = 23;         //  taille des messages   ( on peut le remplacer par un define )
static uint8_t packetBuffer[packetSize];  //   tableau de reception des data



extern String wifi_connection();
extern void get_wifi_messageTabInt();
#endif
