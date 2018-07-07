#include "DHT22.h"

/**************************************************************************/
/*!
    @brief  floattostr_
*/
/**************************************************************************/
void floattostr_(float x, unsigned char *str, char precision) {
  //convert float to string data
  int ie, i, k, ndig;
  double y;
  ndig = ( precision<=0) ? 7 : (precision > 22 ? 23 : precision+1);
  ie = 0;
  /* if x negative, write minus and reverse */
  if ( x < 0) {
    *str++ = '-';
    x = -x;
  }
  /* put x in range 1 <= x < 10 */
  if (x > 0.0) 
    while (x < 1.0) {
      x *= 10.0;                // a la place de =*
      ie--;
    }
  while (x >= 10.0) {
    x = x/10.0;
    ie++;
  }
  ndig += ie;           // a la place de =+
  //round. x is between 1 and 10 and ndig will be printed to
  // right of decimal point so rounding is ...
  for (y = i = 1; i < ndig; i++)
    y = y/10.;
  x += y/2.;
  if (x >= 10.0) {x = 1.0; ie++;}

  if (ie<0){
    *str++ = '0'; *str++ = '.';
    if (ndig < 0) ie = ie-ndig;
    for (i = -1; i > ie; i--)  *str++ = '0';
  }
  for (i=0; i < ndig; i++) {
    k = x;
    *str++ = k + '0';
    if (i ==  ie ) *str++ = '.';
    x -= (y=k);
    x *= 10.0;
  }
  *str = '\0';
}

/**************************************************************************/
/*!
    @brief  dht22_get_byte
*/
/**************************************************************************/
 
char dht22_get_byte(char s_number) {
  char dht22_data, count_for, delaycnt=0;
 
  for (count_for = 0; count_for < 8; count_for++) {
      while(!dht22_S1_pin) {
        Delay_us(1);delaycnt++;
        if (delaycnt > 250) break;
      }
      delay_us(30); delaycnt=0;

      if(dht22_S1_pin == 0)
        dht22_data &= ~(1<<(7 - count_for));
      else {
        dht22_data|= (1 << (7 - count_for));
        while(dht22_S1_pin) {
          Delay_us(1);delaycnt++;
          if (delaycnt > 250)break;
        }
      }
  }
  return dht22_data;
}

/**************************************************************************/
/*!
    @brief  dht22_S1_function
*/
/**************************************************************************/

char dht22_S1_function(char value) {

   char res_=0;
   dht22_S1_pin_direction = 0;    
   dht22_S1_pin=0;  
   delay_ms(18); 
         
   dht22_S1_pin=1;   
   delay_us(30);  
   dht22_S1_pin_direction = 1;    //configura entrada pin del sensor
    
   delay_us(40);
   if (dht22_S1_pin == 0) {
     delay_us(80);
     if (dht22_S1_pin == 1) res_= 1;
     delay_us(40);
   }
   if(res_ == dht22_noresponse)  return(res_);

   res_ = 0;  //inicializa cero para procesar lectura

   dht22_S1_object.hum1_  = dht22_get_byte(1);
   dht22_S1_object.hum2_  = dht22_get_byte(1);
   dht22_S1_object.temp1_ = dht22_get_byte(1);
   dht22_S1_object.temp2_ = dht22_get_byte(1);
   dht22_S1_object.checksum_ = dht22_get_byte(1);

   if (dht22_S1_object.checksum_== ((dht22_S1_object.hum1_ + dht22_S1_object.hum2_ + dht22_S1_object.temp1_ + dht22_S1_object.temp2_) & 0XFF)) {
      //Calcula Temperatura
     dht22_S1_object.Temp_= dht22_S1_object.temp1_;
     dht22_S1_object.Temp_ = ( dht22_S1_object.Temp_ << 8) |  dht22_S1_object.Temp2_;
         
     if (dht22_S1_object.Temp_ > 0X8000) {
       dht22_S1_object.Temp_ = dht22_S1_object.Temp_  & 0X7FFF;
     }
     dht22_S1_object.temperature_=dht22_S1_object.Temp_/10.0;
     //calcula Humedad
     dht22_S1_object.hume_ = dht22_S1_object.hum1_;
     dht22_S1_object.hume_ = (dht22_S1_object.hume_<< 8) | dht22_S1_object.hum2_;
     dht22_S1_object.humedad_ = dht22_S1_object.hume_ / 10.0;
     res_=1;
   }
   if(res_=dht22_noresponse)  return(dht22_errorcheck_sum);
   else  return(dht22_ok);
}

