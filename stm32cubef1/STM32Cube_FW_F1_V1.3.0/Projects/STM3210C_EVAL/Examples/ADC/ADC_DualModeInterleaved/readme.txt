/**
  @page ADC_DualModeInterleaved Two ADC in multimode dual-mode interleaved, transfer by DMA

  @verbatim
  ******************** (C) COPYRIGHT 2015 STMicroelectronics *******************
  * @file    ADC/ADC_DualModeInterleaved/readme.txt 
  * @author  MCD Application Team
  * @version V1.3.0
  * @date    18-December-2015
  * @brief   Description of the Dual interleaved mode @18MSamplesPerSec Example
  ******************************************************************************
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
  @endverbatim

@par Example Description 

This example provides a short description of how to use two ADC peripherals to
perform conversions in interleaved dual-mode.


One compilation switch is available to select ADC configuration continuous mode
and external trigger (located in main.h):
 - "ADC_TRIGGER_FROM_TIMER" defined: ADC is operating in not continuous mode
   and conversions are trigger by external trigger: timer.
 - "ADC_TRIGGER_FROM_TIMER" not defined: ADC is operating in continuous mode
   and first conversion is trigger by software trigger.

One compilation switch is available to generate a waveform voltage
for test (located in main.h):
 - "WAVEFORM_VOLTAGE_GENERATION_FOR_TEST" defined: For this example purpose, generates a
   waveform voltage on a spare DAC channel DAC_CHANNEL_1 (pin PA.04),
   so user has just to connect a wire between DAC channel output and ADC input to run this example.
 - "WAVEFORM_VOLTAGE_GENERATION_FOR_TEST" not defined: no voltage is generated, user has
   to connect a voltage source to the selected ADC channel input to run this example.


Note: In this example, ADC sampling rate is not set as the highest possible (ADC parameters not set for this purpose: resolution 12 bits, ... ).
      ADC sampling rate can be increased by modifying resolution and sampling time, but this will decrease the conversion accuracy.

Other peripherals related to ADC are used:
Mandatory:
 - GPIO peripheral is used in analog mode to drive signal from device pin to
   ADC input.
Optionally:
 - Timer peripheral is used to trigger ADC conversions.
 - DMA peripheral is used to transfer ADC converted data.
   Both ADC are using the same DMA (DMA of ADC master).

ADC conversion results:
 - ADC conversions results are transferred automatically by DMA, into variable
   array "aADCDualConvertedValues".
   ADC master and ADC slave results are concatenated on data register 32 bits of ADC master:
   - ADC master results in the 16 LSB [15:0] (with ADC resolution 12 bits, bits effectively used are [11:0])
   - ADC slave results in the 16 MSB [31:16] (with ADC resolution 12 bits, bits effectively used are [27:16])

 - DMA are configured to operate continuously, in circular mode.
   Data is transfered by words every ADC1+ADC2 conversions.
   When DMA transfer half-buffer and complete buffer length are reached, callbacks 
   HAL_ADC_ConvCpltCallback() and HAL_ADC_ConvCpltCallback() are called.

 - For the purpose of this example, dual conversion values are
   dispatched into 2 arrays corresponding to each ADC conversion values
   (aADCxConvertedValues, aADCyConvertedValues)


Board settings:
  ADC1 and ADC2 are configured to convert the same channel: ADC_CHANNEL_4 (pin PA.04).

 - The voltage input on ADC channel is provided from DAC channel (if compilation switch "WAVEFORM_VOLTAGE_GENERATION_FOR_TEST" is defined)
   ADC and DAC channel have been chosen to have the same pad shared at device level: pin PA.04
   ==> Therefore, there is no external connection needed to run this example.

STM3210C-EVAL RevC board LED is used to monitor the program execution status:
 - Normal operation: LED_GREEN is turned-on/off in function of ADC conversion
   status:
    - Turned-off if ADC conversions buffer is not full
    - Turned-on if ADC conversions buffer is full
 - Error: In case of error, LED_RED is toggling at a frequency of 1Hz.

@note See document "ADC timing simulation DualMode.xls" describing the conversions timing.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - ADC/ADC_DualModeInterleaved/Inc/stm32f1xx_hal_conf.h    HAL configuration file
  - ADC/ADC_DualModeInterleaved/Inc/stm32f1xx_it.h          DMA interrupt handlers header file
  - ADC/ADC_DualModeInterleaved/Inc/main.h                  Header for main.c module  
  - ADC/ADC_DualModeInterleaved/Src/stm32f1xx_it.c          DMA interrupt handlers
  - ADC/ADC_DualModeInterleaved/Src/main.c                  Main program
  - ADC/ADC_DualModeInterleaved/Src/stm32f1xx_hal_msp.c     HAL MSP file
  - ADC/ADC_DualModeInterleaved/Src/system_stm32f1xx.c      stm32f1xx system source file

@par Hardware and Software environment 

  - This example runs on STM32F1xx with at least 2 ADC instances devices.

  - This example has been tested with STM3210C-EVAL RevC board and can be
    easily tailored to any other supported device and development board. 

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
