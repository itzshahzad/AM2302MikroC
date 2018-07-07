extern sfr sbit  dht22_S1_pin ;
extern sfr sbit  dht22_S1_pin_direction;

enum dht22_estado {dht22_noresponse,dht22_ok,dht22_errorcheck_sum};

typedef struct dht22_est {
  char   temp1_,temp2_,hum1_,hum2_;
  unsigned int Temp_, hume_, checksum_;
  float temperature_,humedad_;
}dht22_sensor;

extern dht22_sensor  dht22_S1_object;   //crea el sesnor con la estructura   guarda la lectura en    dht22_lectura.temperatura y   dht22_lectura.humedad;


char mutli_dht22(char va);
void floattostr_(float x, unsigned char *str,char precision);

char  dht22_S1_function(char value);    //lee  informacion dels sensor temperatura y humedad
