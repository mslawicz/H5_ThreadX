#include "logger.h"
#include "main.h"
#include "tx_api.h"

void loggerTask(void)
{
  while(1)
  {
    HAL_GPIO_WritePin(TEST_1_GPIO_Port, TEST_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(TEST_1_GPIO_Port, TEST_1_Pin, GPIO_PIN_RESET);
    tx_thread_sleep(20);
    HAL_GPIO_WritePin(TEST_1_GPIO_Port, TEST_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(TEST_1_GPIO_Port, TEST_1_Pin, GPIO_PIN_RESET);
    tx_thread_sleep(50);
  }    
}