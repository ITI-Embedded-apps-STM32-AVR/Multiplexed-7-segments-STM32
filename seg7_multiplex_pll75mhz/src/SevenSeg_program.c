// libs
#include "STD_TYPES.h"
#include "BIT_MAN.h"
// MACL
#include "DIO_interface.h"
// own
#include "SevenSeg_interface.h"
#include "SevenSeg_config.h"

u8 last_value = SEVENSEG_INITIAL_VALUE;

u8 numbers[] = {
	/*natural numbers*/
	0b00111111, /*0*///
	0b00000110, /*1*/
	0b01011011, /*2*/
	0b01001111, /*3*/
	0b01100110, /*4*/
	0b01101101, /*5*/
	0b01111101, /*6*/
	0b00000111, /*7*/
	0b01111111, /*8*/
	0b01101111, /*9*/

	/*snake shapes*/
	0b00000001, /*10*/
	0b00000010, /*11*/
	0b00000100, /*12*/
	0b00001000, /*13*/
	0b00010000, /*14*/
	0b00100000, /*15*/
	0b01000000, /*16*/
};


void SevenSeg_setNum(u8 number, u8 seg)
{
   /*common anode*/
   #if SEVENSEG_MODE == 0
      if (seg == 1)
      {
         DIO_setPinVal( SEVENSEG1_PORT_A, SEVENSEG1_PIN_A, BIT_GET(~numbers[number], 0) );
         DIO_setPinVal( SEVENSEG1_PORT_B, SEVENSEG1_PIN_B, BIT_GET(~numbers[number], 1) );
         DIO_setPinVal( SEVENSEG1_PORT_C, SEVENSEG1_PIN_C, BIT_GET(~numbers[number], 2) );
         DIO_setPinVal( SEVENSEG1_PORT_D, SEVENSEG1_PIN_D, BIT_GET(~numbers[number], 3) );
         DIO_setPinVal( SEVENSEG1_PORT_E, SEVENSEG1_PIN_E, BIT_GET(~numbers[number], 4) );
         DIO_setPinVal( SEVENSEG1_PORT_F, SEVENSEG1_PIN_F, BIT_GET(~numbers[number], 5) );
         DIO_setPinVal( SEVENSEG1_PORT_G, SEVENSEG1_PIN_G, BIT_GET(~numbers[number], 6) );
         //DIO_setPinVal( SEVENSEG1_PORT_H, SEVENSEG1_PIN_H, BIT_GET(~numbers[number], 7) );
      }
      else if (seg == 2)
      {
        DIO_setPinVal( SEVENSEG2_PORT_A, SEVENSEG2_PIN_A, BIT_GET(~numbers[number], 0) );
        DIO_setPinVal( SEVENSEG2_PORT_B, SEVENSEG2_PIN_B, BIT_GET(~numbers[number], 1) );
        DIO_setPinVal( SEVENSEG2_PORT_C, SEVENSEG2_PIN_C, BIT_GET(~numbers[number], 2) );
        DIO_setPinVal( SEVENSEG2_PORT_D, SEVENSEG2_PIN_D, BIT_GET(~numbers[number], 3) );
        DIO_setPinVal( SEVENSEG2_PORT_E, SEVENSEG2_PIN_E, BIT_GET(~numbers[number], 4) );
        DIO_setPinVal( SEVENSEG2_PORT_F, SEVENSEG2_PIN_F, BIT_GET(~numbers[number], 5) );
        DIO_setPinVal( SEVENSEG2_PORT_G, SEVENSEG2_PIN_G, BIT_GET(~numbers[number], 6) );
        //DIO_setPinVal( SEVENSEG2_PORT_H, SEVENSEG2_PIN_H, BIT_GET(~numbers[number], 7) );
      }
   #elif SEVENSEG_MODE == 1
      /*common cathode*/
      if (seg == 1)
      {
         DIO_setPinVal( SEVENSEG1_PORT_A, SEVENSEG1_PIN_A, BIT_GET(numbers[number], 0) );
         DIO_setPinVal( SEVENSEG1_PORT_B, SEVENSEG1_PIN_B, BIT_GET(numbers[number], 1) );
         DIO_setPinVal( SEVENSEG1_PORT_C, SEVENSEG1_PIN_C, BIT_GET(numbers[number], 2) );
         DIO_setPinVal( SEVENSEG1_PORT_D, SEVENSEG1_PIN_D, BIT_GET(numbers[number], 3) );
         DIO_setPinVal( SEVENSEG1_PORT_E, SEVENSEG1_PIN_E, BIT_GET(numbers[number], 4) );
         DIO_setPinVal( SEVENSEG1_PORT_F, SEVENSEG1_PIN_F, BIT_GET(numbers[number], 5) );
         DIO_setPinVal( SEVENSEG1_PORT_G, SEVENSEG1_PIN_G, BIT_GET(numbers[number], 6) );
         //DIO_setPinVal( SEVENSEG1_PORT_H, SEVENSEG1_PIN_H, BIT_GET(numbers[number], 7) );
      }
      else if (seg == 2)
      {
        DIO_setPinVal( SEVENSEG2_PORT_A, SEVENSEG2_PIN_A, BIT_GET(numbers[number], 0) );
        DIO_setPinVal( SEVENSEG2_PORT_B, SEVENSEG2_PIN_B, BIT_GET(numbers[number], 1) );
        DIO_setPinVal( SEVENSEG2_PORT_C, SEVENSEG2_PIN_C, BIT_GET(numbers[number], 2) );
        DIO_setPinVal( SEVENSEG2_PORT_D, SEVENSEG2_PIN_D, BIT_GET(numbers[number], 3) );
        DIO_setPinVal( SEVENSEG2_PORT_E, SEVENSEG2_PIN_E, BIT_GET(numbers[number], 4) );
        DIO_setPinVal( SEVENSEG2_PORT_F, SEVENSEG2_PIN_F, BIT_GET(numbers[number], 5) );
        DIO_setPinVal( SEVENSEG2_PORT_G, SEVENSEG2_PIN_G, BIT_GET(numbers[number], 6) );
        //DIO_setPinVal( SEVENSEG2_PORT_H, SEVENSEG2_PIN_H, BIT_GET(numbers[number], 7) );
      }
   #endif
   
   last_value = number;
}

void SevenSeg_enable(u8 seg)
{
   /*common anode*/
   #if SEVENSEG_MODE == 0
	  if (seg == 1)
	  {
		  DIO_setPinVal( SEVENSEG1_PORT_ENABLE, SEVENSEG1_PIN_ENABLE, 1 );
	  }
	  else if (seg == 2)
	  {
		  DIO_setPinVal( SEVENSEG2_PORT_ENABLE, SEVENSEG2_PIN_ENABLE, 1 );
	  }
   #elif SEVENSEG_MODE == 1
      /*common cathode*/
	  if (seg == 1)
	  {
		  DIO_setPinVal( SEVENSEG1_PORT_ENABLE, SEVENSEG1_PIN_ENABLE, 0 );
	  }
	  else if (seg == 2)
	  {
		  DIO_setPinVal( SEVENSEG2_PORT_ENABLE, SEVENSEG2_PIN_ENABLE, 0 );
	  }
   #endif
   
   SevenSeg_setNum(last_value, seg);
}

void SevenSeg_disable(u8 seg)
{
   /*common anode*/
   #if SEVENSEG_MODE == 0
	  if (seg == 1)
	  {
		  DIO_setPinVal( SEVENSEG1_PORT_ENABLE, SEVENSEG1_PIN_ENABLE, 0 );
	  }
	  else if (seg == 2)
	  {
		  DIO_setPinVal( SEVENSEG2_PORT_ENABLE, SEVENSEG2_PIN_ENABLE, 0 );
	  }
   #elif SEVENSEG_MODE == 1
    /*common cathode*/
	  if (seg == 1)
	  {
		  DIO_setPinVal( SEVENSEG1_PORT_ENABLE, SEVENSEG1_PIN_ENABLE, 1 );
	  }
	  else if (seg == 2)
	  {
		  DIO_setPinVal( SEVENSEG2_PORT_ENABLE, SEVENSEG2_PIN_ENABLE, 1 );
	  }
   #endif   
}
