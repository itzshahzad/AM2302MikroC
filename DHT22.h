//==============================================================================
//
//  main.h
//
//
//==============================================================================
//  FILE INFORMATION
//==============================================================================
//
//  Source:
//
//  Project:    Humidity and temperature monitoring
//
//  Author:     M.Shahzad
//
//  Date:       20/03/2023
//
//  Revision:   1.0
//
//==============================================================================
//  FILE DESCRIPTION
//==============================================================================
//
//! \file
//! This module takes care of the
//
//==============================================================================
//  REVISION HISTORY
//==============================================================================
//  Revision: 1.0
//
//

//==============================================================================
//  INCLUDES
//==============================================================================

//==============================================================================
//	GLOBAL FUNCTION PROTOTYPES
//==============================================================================
char mutli_dht22(char va);
void floattostr_(float x, unsigned char *str, char precision);

char dht22_S1_function(char value); // lee  informacion dels sensor temperatura y humedad

//==============================================================================
//  EXTERNAL OR GLOBAL DATA TYPES
//==============================================================================

extern dht22_sensor dht22_S1_object;
extern sfr sbit dht22_S1_pin;
extern sfr sbit dht22_S1_pin_direction;

//==============================================================================
//  Global Structures
//==============================================================================

enum dht22_estado
{
	dht22_noresponse,
	dht22_ok,
	dht22_errorcheck_sum
};

typedef struct dht22_est
{
	char temp1_, temp2_, hum1_, hum2_;
	unsigned int Temp_, hume_, checksum_;
	float temperature_, humedad_;
} dht22_sensor;
