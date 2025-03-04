/**
  @page ADC_AnalogWatchdog ADC example

  @verbatim
  ******************************************************************************
  * @file    Examples/ADC/ADC_AnalogWatchdog/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the ADC_AnalogWatchdog example.
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

How to use the ADC peripheral to perform conversions with an analog watchdog 
and out-of-window interrupts enabled.

Example configuration:
The ADC launch conversions in continuous mode on the selected channel. DMA is configured
to transfer conversion data in an array, in circular mode.
Analog watchdog 1 is enabled, minimum and maximum thresholds are respectively set to 1/8
and 5/8 of full range scale (between about 0.41V and 2.06V with full range of 3.3V).

Example execution:
From the start, the ADC converts the selected channel continuously. DMA transfers conversion data to the array. Results array is updated indefinitely (DMA in circular mode).
If the conversion results is out of the analog window thresholds, ADC analog window IRQ handler (HAL_ADC_LevelOutOfWindowCallback) is called "ubAnalogWatchdogStatus" is SET and
LED1 is turned on.

For debug: variables to monitor with debugger watch window:
 - "aADCxConvertedData": ADC group regular conversion data (array of data)
 - "ubAnalogWatchdogStatus": ADC analog window status (SET = voltage out of window / RESET otherwise)

Connection needed:
None, if ADC channel and DAC channel are selected on the same GPIO.
Otherwise, connect a wire between DAC channel output and ADC input.

Other peripherals used:
  1 GPIO for LED
  1 GPIO for analog input: PA4 (Connector CN10 pin 28)
  DAC
  1 GPIO for DAC channel output PA4 (Connector CN10 pin 28)
  1 GPIO for push button
  DMA

Board settings:
 - ADC is configured to convert ADC_CHANNEL_4 (Connector CN10 pin 28).
 - The voltage input on ADC channel is provided from DAC (DAC1_CHANNEL_1).
   ADC input from pin PA4 and DAC output to pin PA4:
   If same pin is used no connection is required, it is done internally. Otherwise, user need to connect a wire between Connector CN10 pin 28 and Connector CN10 pin 28
 - Voltage is increasing at each click on Tamper push-button, from 0 to maximum range in 4 steps.
   Clicks on Tamper push-button follow circular cycles: At clicks counter maximum value reached, counter is set back to 0.


To observe voltage level applied on ADC channel through GPIO, connect a voltmeter on
pin PA4 (Connector CN10 pin 28).

STM32G0C1E-EV board LED is be used to monitor the program execution status:
 - Normal operation: LED1 is turned-on/off in function of ADC conversion
   result.
    - Turned-off if voltage into of AWD window
    - Turned-on if voltage is out of AWD window
 - Error: In case of error, LED1 is toggling twice at a frequency of 1Hz.

@par Keywords

ADC, analog digital converter, analog, conversion, voltage, channel, analog input, trigger, analog watchdog, threshold, window

@par Directory contents 

  - ADC/ADC_AnalogWatchdog/Inc/stm32g0xx_hal_conf.h    HAL configuration file
  - ADC/ADC_AnalogWatchdog/Inc/stm32g0xx_it.h          Interrupt handlers header file
  - ADC/ADC_AnalogWatchdog/Inc/main.h                        Header for main.c module  
  - ADC/ADC_AnalogWatchdog/Src/stm32g0xx_it.c          Interrupt handlers
  - ADC/ADC_AnalogWatchdog/Src/stm32g0xx_hal_msp.c     HAL MSP module
  - ADC/ADC_AnalogWatchdog/Src/main.c                        Main program
  - ADC/ADC_AnalogWatchdog/Src/system_stm32g0xx.c      STM32G0xx system source file


@par Hardware and Software environment

  - This example runs on STM32G0C1xx devices.
    
  - This example has been tested with STM32G0C1E-EV board and can be
    easily tailored to any other supported device and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
