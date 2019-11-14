#ifndef _X_NUCLEO_NFC05_H_
#define _X_NUCLEO_NFC05_H_

#include "ST25R3911.h"
#include "mbed.h"


using namespace std;



/* Class of the NFC05A1
 *
 * begin: It initializes the device in order to start the communication with it
 * writeURI: Method that implements the write of an URI through I2C communication
 * readURI: Reading of an URI coming from an NFC tag
 * writeWiFi: Write the WiFi in the NFC tag
 * readWiFi: Read the WiFi coming from another device that writes on the NFC tag
 * ledON: It lights one of the three LED based on input PIN
 * ledOFF: It lights off one of the three LED based on input PIN
 *
 */
class X_Nucleo_NFC05 {
    public:
    X_Nucleo_NFC05(SPI *spiChannel, DigitalOut *led_1);
    void begin(SPI *spiChannel);
    void ledOn(DigitalOut *led);
    void ledOff(DigitalOut *led);
    void spiInitMain(SPI_HandleTypeDef hspi1, SPI_InitTypeDef Init);
    private:
    DigitalOut *mled_1;
    DigitalOut *mled_2;
    DigitalOut *mled_3;
    SPI *mspiChannel;
    SPI_HandleTypeDef hspi1;
};

//do we need it
extern X_Nucleo_NFC05 X_Nucleo_Nfc05;

#endif
