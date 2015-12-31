/**
  @page PWR_STANDBY PWR standby example
  
  @verbatim
  ******************** (C) COPYRIGHT 2015 STMicroelectronics *******************
  * @file    PWR/PWR_STANDBY/readme.txt 
  * @author  MCD Application Team
  * @version V1.3.0
  * @date    18-December-2015
  * @brief   Description of the PWR STANDBY example.
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
 
This example shows how to enters the system to STANDBY mode and wake-up from this
mode using: external RESET or WKUP pin.
This example shows also how to configure the stm32f1xx system to measure 
STANDBY mode current consumption.

In the associated software
  - the system clock is set to 64 MHz.
  - PA.00 is configured to wake up the system after entering Standby mode.
  - the SysTick is programmed to generate an interrupt each 1 ms.
  
The system enters STANDBY mode after 5s and will wait for injecting 3.3V on PA.00
PWR_WAKEUP_PIN1. Current consumption could be monitored through an amperemeter connected to JP6.

    - STANDBY Mode 
    ===============
            - VREFINT OFF with fast wakeup enabled
            - No IWDG
            - Wakeup using PWR_WAKEUP_PIN1 (PA.00)

@note This example can not be used in DEBUG mode, this is due to the fact 
      that the Cortex-M3 core is no longer clocked during low power mode 
      so debugging features are disabled

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - PWR/PWR_STANDBY/Inc/stm32f1xx_conf.h         HAL Configuration file
  - PWR/PWR_STANDBY/Inc/stm32f1xx_it.h           Header for stm32f1xx_it.c
  - PWR/PWR_STANDBY/Inc/main.h                   Header file for main.c
  - PWR/PWR_STANDBY/Src/system_stm32f1xx.c       STM32F1xx system clock configuration file
  - PWR/PWR_STANDBY/Src/stm32f1xx_it.c           Interrupt handlers
  - PWR/PWR_STANDBY/Src/main.c                   Main program

@par Hardware and Software environment

  - STM32F103RB-Nucleo Set-up
    - Wake-up will be done in putting 3.3V to PA.00 pin (present on pin28 of CN7).
      Wired should be put between PA.00 and GND before running test. Connect to 3V3 to awake board.
    - Connect an amperemeter to JP6 to measure the IDD current

  - This example runs on STM32F1xx devices
      
  - This example has been tested with STMicroelectronics STM32F103RB-Nucleo
    evaluation board and can be easily tailored to any other supported device 
    and development board.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
