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

#include "DHT22.h"

//==============================================================================
//	GLOBAL FUNCTION PROTOTYPES
//==============================================================================

//==============================================================================
//  EXTERNAL OR GLOBAL DATA TYPES
//==============================================================================

sbit dht22_S1_pin at RD3_bit;
sbit dht22_S1_pin_direction at TRISD3_bit;

dht22_sensor dht22_S1_object; // data structure sensor 1 DHT22
char txt[20];

//==============================================================================
//  Global Structures
//==============================================================================