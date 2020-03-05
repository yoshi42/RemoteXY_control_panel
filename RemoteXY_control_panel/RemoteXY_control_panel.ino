
//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

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
  { 255,1,0,1,0,70,0,10,161,1,
  2,1,10,23,19,9,2,26,31,31,
  79,78,0,79,70,70,0,65,2,42,
  24,7,7,129,0,14,2,31,6,17,
  84,104,101,32,72,111,117,115,101,0,
  129,0,3,9,57,6,17,81,117,101,
  115,116,32,99,111,110,116,114,111,108,
  32,112,97,110,101,108,0 };
  
// структура определяет все переменные и события вашего интерфейса управления 
struct {

    // input variables
  uint8_t switch_1; // =1 если переключатель включен и =0 если отключен 

    // output variables
  uint8_t led_1_g; // =0..255 яркость зеленого цвета индикатора 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_1 D4
#define LED_1 D0            // Led in NodeMCU at pin GPIO16 (D0).

void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode(LED_1, OUTPUT);    // LED pin as output.
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  if(RemoteXY.switch_1==0)  
    {
      digitalWrite(LED_1, HIGH);
      RemoteXY.led_1_g = 0;
    }
  else 
    {
      digitalWrite(LED_1, LOW);
      RemoteXY.led_1_g = 255;
    }

  // TODO you loop code
  // используйте структуру RemoteXY для передачи данных

/*digitalWrite(LED, HIGH);// turn the LED off.(Note that LOW is the voltage level but actually 
digitalWrite(LED, LOW);
delay(1000);*/


}
