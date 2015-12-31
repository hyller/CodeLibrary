/**
  ******************************************************************************
  * @file    SMARTCARD_T0/Inc/platform_config.h 
  * @author  MCD Application Team
  * @version V1.3.0
  * @date    18-December-2015
  * @brief   Evaluation board specific configuration file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLATFORM_CONFIG_H
#define __PLATFORM_CONFIG_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define SC_USART                           USART3
#define SC_USART_CLK_ENABLE()              __HAL_RCC_USART3_CLK_ENABLE()
#define SC_USART_CLK_DISABLE();            __HAL_RCC_USART3_CLK_DISABLE()
#define SC_USART_FORCE_RESET()             __HAL_RCC_USART3_FORCE_RESET()
#define SC_USART_RELEASE_RESET()           __HAL_RCC_USART3_RELEASE_RESET()
#define SC_USART_IRQn                      USART3_IRQn
#define SC_USART_IRQHandler                USART3_IRQHandler

#define SC_USART_TX_PIN                    GPIO_PIN_10                
#define SC_USART_TX_GPIO_PORT              GPIOB                       
#define SC_USART_TX_CLK_ENABLE()           __HAL_RCC_GPIOB_CLK_ENABLE()

#define SC_USART_CK_PIN                    GPIO_PIN_12                
#define SC_USART_CK_GPIO_PORT              GPIOB
#define SC_USART_CK_CLK_ENABLE()           __HAL_RCC_GPIOB_CLK_ENABLE()


/* Smartcard Inteface GPIO pins */
#define SC_3_5V_PIN                        GPIO_PIN_0
#define SC_3_5V_GPIO_PORT                  GPIOB
#define SC_3_5V_CLK_ENABLE()               __HAL_RCC_GPIOB_CLK_ENABLE()

#define SC_RESET_PIN                       GPIO_PIN_11
#define SC_RESET_GPIO_PORT                 GPIOB
#define SC_RESET_CLK_ENABLE()              __HAL_RCC_GPIOB_CLK_ENABLE()

#define SC_CMDVCC_PIN                      GPIO_PIN_6
#define SC_CMDVCC_GPIO_PORT                GPIOC
#define SC_CMDVCC_CLK_ENABLE()             __HAL_RCC_GPIOC_CLK_ENABLE()

#define SC_OFF_PIN                         GPIO_PIN_7
#define SC_OFF_GPIO_PORT                   GPIOC
#define SC_OFF_CLK_ENABLE()                __HAL_RCC_GPIOC_CLK_ENABLE()

#define SC_OFF_EXTI_IRQn                   EXTI9_5_IRQn 
#define SC_OFF_EXTI_IRQHandler             EXTI9_5_IRQHandler

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __PLATFORM_CONFIG_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
