#include "x_nucleo_nfc05.h"





//extern sCCFileInfo CCFileStruct;

// This is a constructor

X_Nucleo_NFC05::X_Nucleo_NFC05(SPI *spiChannel, DigitalOut *led_1)
{

	mspiChannel = spiChannel;
	mled_1 = led_1;
}

/**
  * @brief  This function initialize the device
  * @param  mi2cChannel : I2C Channel
  * @param  mLPD : A digital PIN
  * @retval status(int) : Return if the write operation is succesful
  */

void X_Nucleo_NFC05::begin(SPI *mspiChannel) {

}


/**
  * @brief  This function light on selected Led
  * @param  led : Led to be lit on
  * @retval None
  */
void X_Nucleo_NFC05::ledOn(DigitalOut* led) {
	led -> write(1);
}

/**
  * @brief  This function light off selected Led
  * @param  led : Led to be lit off
  * @retval None
  */

void X_Nucleo_NFC05::ledOff(DigitalOut* led) {
	*led = 0;
}

// WHAT OTHER FUNCTION WE WANT? WRITE URI AND READ URI? WHAT ELSE?

void spiInitMain(SPI_HandleTypeDef hspi1, SPI_InitTypeDef Init){

	  hspi1.Instance = SPI1;
	  hspi1.Init.Mode = SPI_MODE_MASTER;
	  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
	  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
	  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
	  hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
	  hspi1.Init.NSS = SPI_NSS_SOFT;
	  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
	  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
	  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
	  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	/*  if (HAL_SPI_Init(&hspi1) != HAL_OK) {
	    Error_Handler();
	  }
*/
}

