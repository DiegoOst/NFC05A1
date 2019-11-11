/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

  /*! \file
 *
 *  \author 
 *
 *  \brief Main program body.
 *
 */
  


/* USER CODE BEGIN Includes */
#include "mbed.h"
#include "timer.h"
#include "logger.h"
#include "st_errno.h"
#include "rfal_rf.h"
#include "rfal_analogConfig.h"
#include "ST25R3911.h"
#include "x_nucleo_nfc05.h"
#include "x_nucleo_nfc05a1.h"
#include "st25r3911_interrupt.h"

#include <stdint.h>


/* USER CODE END Includes */



#ifndef MYBOOLEAN_H
#define MYBOOLEAN_H

#define false 0
#define true 1
#define bool int

#endif




SPI_HandleTypeDef hspi1;
SPI_InitTypeDef Init;
ST25R3911 mST25;

SPI mspiChannel(SPI_MOSI, SPI_MISO, SPI_SCK);
DigitalOut gpio_cs(SPI_CS);

DigitalIn uButton(BUTTON1);
DigitalOut fieldLED_01(A1); //LED_F_PIN
DigitalOut fieldLED_02(A2); //LED_B_PIN
DigitalOut fieldLED_03(A3); //LED_A_PIN
DigitalOut fieldLED_04(D5); //LED_V_PIN
DigitalOut fieldLED_05(D4); //LED_AP2P_PIN
DigitalOut fieldLED_06(D7); //LED_FIELD_PIN

X_Nucleo_NFC05 mNFC05(&mspiChannel, &fieldLED_01);


InterruptIn IRQ(SYS_WKUP);

volatile bool wakeupFlag = 0;

void st25Handler( void )
{

	//st25r3911Isr( &mspiChannel, &mST25, &gpio_cs, &IRQ );
}



int main(void)
{

	/* Setting format and frequency for SPI communication */
	gpio_cs = 1;
	mspiChannel.format(8, 1);
	mspiChannel.frequency(4000000);

	/* Set IRQ handler */
	IRQ.rise(&st25Handler);

	/* Set default Config for rfal */
	rfalAnalogConfigInitialize();

  if( rfalInitialize(&mspiChannel, &mST25, &gpio_cs, &IRQ, &fieldLED_01, &fieldLED_02, &fieldLED_03, &fieldLED_04, &fieldLED_05, &fieldLED_06 ) != ERR_NONE )
  {

	  /* If here, there is an error in rfal Initialization */
	  while(1)
	  {
		  /* Blink the LED to communicate an error */
		  fieldLED_01.write(1);
		  fieldLED_02.write(1);
		  fieldLED_03.write(1);
		  fieldLED_04.write(1);
		  fieldLED_05.write(1);
		  fieldLED_06.write(1);
		  wait_ms(200);
		  fieldLED_01.write(0);
		  fieldLED_02.write(0);
		  fieldLED_03.write(0);
		  fieldLED_04.write(0);
		  fieldLED_05.write(0);
		  fieldLED_06.write(0);
		  wait_ms(300);
	  }
  }
  else
  {
	  /* Initialization succeeded */
	  for(int i = 0; i < 6; i++)
	  {
	  fieldLED_01.write(1);
	  fieldLED_02.write(1);
	  fieldLED_03.write(1);
      fieldLED_04.write(1);
	  fieldLED_05.write(1);
	  fieldLED_06.write(1);
	  wait_ms(200);
	  fieldLED_01.write(0);
	  fieldLED_02.write(0);
	  fieldLED_03.write(0);
	  fieldLED_04.write(0);
	  fieldLED_05.write(0);
	  fieldLED_06.write(0);
	  wait_ms(300);

	  }

  }


	while(1)
	{


    /* Run RFAL Worker */
    rfalWorker(&mspiChannel, &mST25, &gpio_cs, &IRQ, &fieldLED_01, &fieldLED_02, &fieldLED_03, &fieldLED_04, &fieldLED_05, &fieldLED_06 );
    
    /* Run Demo Application */
    demoCycle(&mspiChannel, &mST25, &uButton, &gpio_cs, &IRQ, &fieldLED_01, &fieldLED_02, &fieldLED_03, &fieldLED_04, &fieldLED_05, &fieldLED_06 );
	}

}

/**
  * @}
*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
