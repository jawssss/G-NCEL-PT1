#define REMOTEXY_MODE__ESP8266_HARDSERIAL_CLOUD
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 2
#include <RemoteXY.h>


#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "TP-Link_CDE4"
#define REMOTEXY_WIFI_PASSWORD "15767400"
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "6075756623071eeb2fdae0c770dfecfc"



#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 209 bytes
  { 255,3,0,33,0,202,0,16,162,0,67,4,68,5,23,8,31,24,11,67,
  4,68,15,23,8,31,24,11,129,0,12,6,54,6,2,83,196,177,99,97,
  107,108,196,177,107,32,68,101,196,159,101,114,105,32,194,176,67,32,58,0,
  129,0,23,16,44,6,2,78,101,109,32,68,101,196,159,101,114,105,32,37,
  32,58,0,2,0,33,48,22,11,2,26,31,31,79,78,0,79,70,70,0,
  129,0,4,38,22,8,2,79,100,97,32,49,0,129,0,33,38,22,8,2,
  79,100,97,32,50,0,2,0,5,48,22,11,2,26,31,31,79,78,0,79,
  70,70,0,2,0,62,48,22,11,2,26,31,31,79,78,0,79,70,70,0,
  129,0,62,38,22,8,2,79,100,97,32,51,0,129,0,4,25,63,6,2,
  84,111,112,114,97,107,32,78,101,109,32,68,117,114,117,109,117,32,58,0,
  67,4,68,25,23,8,16,24,11 };
  

struct {

    
  uint8_t switch_1; 
  uint8_t switch_2; 
  uint8_t switch_3;
    
  char text_1[11];  
  char text_2[11];  
  char text_3[11];
    
  uint8_t connect_flag;  




} RemoteXY;
#pragma pack(pop)

#define PIN_SWITCH_3 13
#define PIN_SWITCH_1 11
#define PIN_SWITCH_2 12
int sensor_pin = A0;
int cikis_degeri ;

void setup() 
{
  


  Serial.begin(115200);
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode (PIN_SWITCH_2, OUTPUT);
  pinMode (PIN_SWITCH_3, OUTPUT);
  
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_3, (RemoteXY.switch_3==0)?LOW:HIGH);
  
  DHT.read(DHT11_PIN);
  float temp = DHT.temperature;
  float hum = DHT.humidity; 
  dtostrf(temp, 0, 1, RemoteXY.text_1);
  dtostrf(hum, 0, 1, RemoteXY.text_2);
  delay(1000);
    
  cikis_degeri= analogRead(sensor_pin);
  cikis_degeri = map(cikis_degeri,550,0,0,100);
  dtostrf(cikis_degeri, 0, 1, RemoteXY.text_3);
  delay(1000);
     
}