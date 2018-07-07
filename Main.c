#include "DHT22.h"

// using RD3 pin to DHT22 connection
sbit  dht22_S1_pin  at RD3_bit;
sbit  dht22_S1_pin_direction  at TRISD3_bit;
dht22_sensor  dht22_S1_object;       // data structure sensor 1 DHT22

char txt[20];
void main() {
  //todo digital
  UART1_Init(9600);
  UART1_Write_Text("System boot up \r");
  
  while (1){

    switch (dht22_S1_function(1))  {
      case dht22_ok:
        floattostr_(dht22_S1_object.temperature_,txt,1);
        UART1_Write_Text("Temp1:");
        UART1_Write_Text(txt);
        floattostr_(dht22_S1_object.humedad_,txt,1);
        UART1_Write_Text("  Hume1:");
        UART1_Write_Text(txt);
        break;

      case dht22_errorcheck_sum:
        UART1_Write_Text("Eror \r");
        break;

      case dht22_noresponse:
        UART1_Write_Text("No respose \r");
        break;

    }

   UART1_Write_Text("\r");

   delay_ms(3000); //3 seconds delay

  }
}

