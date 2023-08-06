//==============================================================================
//
//  main.c
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

#include "main.h"

//==============================================================================
//
//   void  main(void)
//
//   Author:   M. Shahzad
//   Date:     06/08/2021
//
//! This function takes care of initlization and fetching DHT11 temperature and
//! humidity vlaues and print on the serial console
//
//==============================================================================

void main()
{
	// todo digital
	UART1_Init(9600);
	UART1_Write_Text("System boot up \r");

	while (1)
	{

		switch (dht22_S1_function(1))
		{
		case dht22_ok:
			floattostr_(dht22_S1_object.temperature_, txt, 1);
			UART1_Write_Text("Temp1:");
			UART1_Write_Text(txt);

			floattostr_(dht22_S1_object.humedad_, txt, 1);
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

		delay_ms(3000); // 3 seconds delay
	}
}
