/**
  @page RTC_Standby RTC_LowPower_STANDBY example
  
  @verbatim
  ******************** (C) COPYRIGHT 2015 STMicroelectronics *******************
  * @file    RTC/RTC_LowPower_STANDBY/readme.txt 
  * @author  MCD Application Team
  * @version V1.3.0
  * @date    18-December-2015
  * @brief   Description of the RTC STANDBY example.
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
 
This example shows how to enter the system to STANDBY mode and wake-up from this
mode using RTC Alarm Event connected to EXTI_Line17.
This example shows also how to calculate date on the STM32F1xx after waking up
standby.

In the associated software, the system clock is set to 24 MHz, the SysTick is 
programmed to generate an interrupt each 1 ms.
The LSI clock is used as RTC clock source by default.

In the associated software
  - the system clock is set to 24 MHz.
  - the EXTI_Line17 connected internally to the RTC Alarm event is configured
    to generate an interrupt on rising edge after 15s.

The system enters STANDBY mode after configurating time, alarm and date:
- time to 23h59:55
- date to 31th of October 2014
- alarm to 00h00:10.

Before enter in STANDBY mode, date is saved in 3 different backup registers (day,
month and year).
After wake-up from STANDBY mode, program execution restarts in the same way as after
a RESET.
As a day elapsed at the alarm event, a date update is performed:
- read old date available in 3 backup registers
- add 1 day to the old date
- check that the new date is equal to 1st of November 2014.

One of the above scenario can occur.
 - LED4 Toggle: HAL configuration failed (system will go to an infinite loop)
 - LED_BLUE ON: After wake-up, SW did not detect a day elapsed
 - LED_GREEN ON: day elapsed well detected but date update failed
 - LED_GREEN & LED_BLUE ON: date updtate performed correctly

@note This example can not be used in DEBUG mode, this is due to the fact 
      that the Cortex-M3 core is no longer clocked during low power mode 
      so debugging features are disabled

@note Care must be taken when HAL_RCCEx_PeriphCLKConfig() is used to select 
      the RTC clock source; in this case the Backup domain will be reset in  
      order to modify the RTC Clock source, as consequence RTC registers (including 
      the backup registers) and RCC_CSR register are set to their reset values.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.
      
@par Directory contents 

  - RTC/RTC_LowPower_STANDBY/Inc/stm32f1xx_conf.h         HAL Configuration file
  - RTC/RTC_LowPower_STANDBY/Inc/stm32f1xx_it.h           Header for stm32f1xx_it.c
  - RTC/RTC_LowPower_STANDBY/Inc/main.h                   Header file for main.c
  - RTC/RTC_LowPower_STANDBY/Src/system_stm32f1xx.c       STM32F1xx system clock configuration file
  - RTC/RTC_LowPower_STANDBY/Src/stm32f1xx_it.c           Interrupt handlers
  - RTC/RTC_LowPower_STANDBY/Src/main.c                   Main program
  - RTC/RTC_LowPower_STANDBY/Src/stm32f1xx_hal_msp.c  HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32F100xB devices
    
  - This example has been tested with STMicroelectronics STM32VL-Discovery
    evaluation board and can be easily tailored to any other supported device 
    and development board.

 @par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
