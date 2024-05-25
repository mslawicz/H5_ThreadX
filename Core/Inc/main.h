/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h5xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#if !defined(UNUSED)
#define UNUSED(x) ((void)(x))
#endif /* UNUSED */
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);
void MX_USB_PCD_Init(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PUSHBUTTON_Pin GPIO_PIN_13
#define PUSHBUTTON_GPIO_Port GPIOC
#define PUSHBUTTON_EXTI_IRQn EXTI13_IRQn
#define LED_Y_Pin GPIO_PIN_4
#define LED_Y_GPIO_Port GPIOF
#define LED_G_Pin GPIO_PIN_0
#define LED_G_GPIO_Port GPIOB
#define LED_R_Pin GPIO_PIN_4
#define LED_R_GPIO_Port GPIOG
#define TEST_3_Pin GPIO_PIN_6
#define TEST_3_GPIO_Port GPIOC
#define TEST_1_Pin GPIO_PIN_8
#define TEST_1_GPIO_Port GPIOC
#define TEST_2_Pin GPIO_PIN_9
#define TEST_2_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */
#define MS_TO_TICKS(ms) (ms * TX_TIMER_TICKS_PER_SECOND / 1000)
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
