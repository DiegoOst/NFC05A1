# NFC05A1
NFC05A1 is the the demo application for the STMicroelectronics X-NUCLEO-NFC05A1 expansion board.
# Overview
This repository include some files and libraries useful to communicate with the X-NUCLEO-NFC05A1.
The following libraries have been used:

- BSP05
- RFAL
- ST25R3911

Furthermore the package includes some feature:

- NFC05A1 class containing methods to turn ON and OFF the expansion board LEDs
- Initialization of the SPI and the RFAL Analog Configuration Settings
  
# Tested Platforms
This firmware has been tested on STM32 NUCLEO-F401RE
# Example Application
NFC05A1 program gives the possibility to the user to read the URI information written by the developing board on the expansion board. The LEDs will blink for few seconds to indicate that the initialization of the board is happening. As soon as It finishes and the device is ready to communicate with external NFC devices, LED6 will blink waiting for a NFC device to be close to it in order to read his URI value.
