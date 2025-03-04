/**
  @page CRYP_AESModes  Encrypt and Decrypt data using AES Algo in ECB/CBC/CTR
  chaining modes with all possible key sizes.
  
  @verbatim
  ******************************************************************************
  * @file    CRYP/CRYP_AESModes/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the CRYP AES Algorithm in all modes and all key sizes
             Example
  ******************************************************************************
  *
  * Copyright (c) 2020 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                       opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  @endverbatim

@par Example Description 

How to use the CRYP peripheral to encrypt and decrypt data using AES in chaining
modes (ECB, CBC, CTR).

In this example, the following key sizes are used: 128 or 256.

Ciphering/Deciphering with a 128-bit long key is used in polling mode with data type set to 8-bit (byte swapping).
Ciphering/Deciphering with a 256-bit long key is used in interrupt mode with data type set to 32-bit (no swapping).
For ECB and CBC, key derivation is carried out at the same time as decryption.

With the 256-bit long key processing, the ciphering output is used as deciphering input. 

This example successively carries out

1. ECB mode:
   - AES128 ECB encryption
   - AES256 ECB encryption
   - AES128 ECB decryption
   - AES128 ECB decryption and key derivation
   - AES256 ECB decryption and key derivation
2. CBC mode:
   - AES128 CBC encryption
   - AES256 CBC encryption
   - AES128 CBC decryption
   - AES128 CBC decryption and key derivation
   - AES256 CBC decryption and key derivation
3. CTR mode:
   - AES128 CTR encryption
   - AES256 CTR encryption
   - AES128 CTR decryption
   - AES256 CTR decryption

When resorting to IAR Embedded Workbench IDE, AES algorithms processing status
are displayed on debugger Terminal I/O as follows: View --> Terminal I/O.
When resorting to MDK-ARM KEIL IDE:
Command Code could not be displayed on debugger but user can use the Virtual Com port of the STM32G0C1E-EV
to display Command Code on PC side using an hyperterminal. See below, information related to this possibility.
When resorting to STM32CubeIDE:
Command Code is displayed on debugger as follows: Window--> Show View--> Console.
In Debug configuration : 
- Window\Debugger, select the Debug probe : ST-LINK(OpenOCD)
- window\ Startup,add the command "monitor arm semihosting enable"

Results can be displayed on PC (through HyperTerminal or TeraTerm) by Virtual Com Port
in enabling USE_VCP_CONNECTION compilation switch and with the proper configuration
(115200 bauds, 8 bits data, 1 stop bit, no parity, no HW flow control).
When resorting to STM32CubeIDE:
In properties :
- Include �syscals.c� in USER folder
- Clear MCU GCC linker > Misellanious >Flags > " -specs=rdimon.specs -lc -lrdimon"
In debug Configuration:
- Add new configuration 
- Window\Debugger, select the Debug probe : ST-LINK(GDB server)

When all ciphering and deciphering operations are successful, LED2 is turned on.
In case of ciphering or deciphering issue, LED3 is turned on. 

@par Keywords

Security, Cryptography, CRYPT, AES, ECB, CBC, CTR, MAC, USART

@par Directory contents

  - CRYP/CRYP_AESModes/Inc/stm32g0xx_hal_conf.h    HAL configuration file
  - CRYP/CRYP_AESModes/Inc/stm32g0xx_it.h          Interrupt handlers header file
  - CRYP/CRYP_AESModes/Inc/main.h                  Header for main.c module
  - CRYP/CRYP_AESModes/Src/stm32g0xx_it.c          Interrupt handlers
  - CRYP/CRYP_AESModes/Src/main.c                  Main program
  - CRYP/CRYP_AESModes/Src/stm32g0xx_hal_msp.c     HAL MSP module
  - CRYP/CRYP_AESModes/Src/system_stm32g0xx.c      STM32G0xx system source file


@par Hardware and Software environment

  - This example runs on STM32G0C1VETx devices.
  - This example has been tested with one STM32G0C1E-EV board embedding
    a STM32G0C1VETx device and can be easily tailored to any other supported device
    and development board.

  - STM32G0C1E-EV Set-up
     - In order to select use of Virtual COM port feature of STLINK for connection between STM32G0C1E-EV and PC,
       USE_VCP_CONNECTION should be defined to 1 in main.h file.

     - Connect ST-Link cable to the PC USB port to send/receive data between PC and board.
       A virtual COM port will then appear in the HyperTerminal.

     - Hyperterminal configuration:
       - BaudRate = 115200 baud  
       - Word Length = 8 Bits
       - One Stop Bit
       - No parity
       - Hardware flow control disabled (RTS and CTS signals)

@par How to use it ?

In order to make the program work, you must do the following:
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
