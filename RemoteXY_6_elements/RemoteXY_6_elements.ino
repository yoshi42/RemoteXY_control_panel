// определение режима соединения и подключение библиотеки RemoteXY 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// настройки соединения 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// конфигурация интерфейса  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,2,0,2,0,57,0,10,161,1,
  2,1,29,9,19,9,2,26,31,31,
  79,78,0,79,70,70,0,65,2,51,
  10,7,7,2,1,29,20,19,9,2,
  26,31,31,79,78,0,79,70,70,0,
  65,2,51,21,7,7,129,0,5,26,
  18,6,17,0 };
  
// структура определяет все переменные и события вашего интерфейса управления 
struct {

    // input variables
  uint8_t switch_1; // =1 если переключатель включен и =0 если отключен 
  uint8_t switch_2; // =1 если переключатель включен и =0 если отключен 

    // output variables
  uint8_t led_1_g; // =0..255 яркость зеленого цвета индикатора 
  uint8_t led_2_g; // =0..255 яркость зеленого цвета индикатора 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define LED_1 D0

void setup() 
{
  RemoteXY_Init (); 
  pinMode(LED_1, OUTPUT);    // LED pin as output
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  if(RemoteXY.switch_1==1)  
    {
      digitalWrite(LED_1, LOW);
      RemoteXY.led_1_g = 255;
    }
  else 
    {
      digitalWrite(LED_1, HIGH);
      RemoteXY.led_1_g = 0;
    }

  if(RemoteXY.switch_2==1)  
    {
      RemoteXY.led_2_g = 255;
    }
  else 
    {
      RemoteXY.led_2_g = 0;
    }
  
  // TODO you loop code
  // используйте структуру RemoteXY для передачи данных
}