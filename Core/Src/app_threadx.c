/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_threadx.c
  * @author  MCD Application Team
  * @brief   ThreadX applicative file
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

/* Includes ------------------------------------------------------------------*/
#include "app_threadx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"
#include "logger.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MY_APP_STACK_SIZE 1024
#define TRACEX_BUFFER_SIZE  0x10000
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
TX_THREAD myAppThread;
uint8_t myAppStack[MY_APP_STACK_SIZE];
uint8_t tracexBuffer[TRACEX_BUFFER_SIZE] __attribute__ ((section (".trace")));
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
VOID myAppThreadEntry(ULONG initial_input);
/* USER CODE END PFP */

/**
  * @brief  Application ThreadX Initialization.
  * @param memory_ptr: memory pointer
  * @retval int
  */
UINT App_ThreadX_Init(VOID *memory_ptr)
{
  UINT ret = TX_SUCCESS;
  /* USER CODE BEGIN App_ThreadX_MEM_POOL */

  /* USER CODE END App_ThreadX_MEM_POOL */
  /* USER CODE BEGIN App_ThreadX_Init */
  tx_thread_create(&myAppThread, "my app thread", myAppThreadEntry, 1, myAppStack, MY_APP_STACK_SIZE, 18, 18, TX_NO_TIME_SLICE, TX_AUTO_START);

  tx_trace_enable(tracexBuffer, TRACEX_BUFFER_SIZE, 30);
  /* USER CODE END App_ThreadX_Init */

  return ret;
}

  /**
  * @brief  Function that implements the kernel's initialization.
  * @param  None
  * @retval None
  */
void MX_ThreadX_Init(void)
{
  /* USER CODE BEGIN  Before_Kernel_Start */

  /* USER CODE END  Before_Kernel_Start */

  tx_kernel_enter();

  /* USER CODE BEGIN  Kernel_Start_Error */

  /* USER CODE END  Kernel_Start_Error */
}

/* USER CODE BEGIN 1 */

VOID myAppThreadEntry(ULONG initial_input)
{
  static const char* msgText = "my App tick #%d\n\r";
  uint32_t message[MSG_SIZE];
  static uint32_t counter = 0;
  while(1)
  {
    HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
    /* send a log message with the counter value */
    message[0] = (uint32_t)msgText;
    message[1] = counter++;
    tx_queue_send(&loggerQueue, message, TX_WAIT_FOREVER);
    tx_thread_sleep(MS_TO_TICKS(100));  /* 100 ms */
    HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
    tx_thread_sleep(MS_TO_TICKS(900));  /* 900 ms */
  } 
}

/* USER CODE END 1 */
