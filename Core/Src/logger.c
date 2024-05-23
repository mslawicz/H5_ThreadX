#include "logger.h"
#include "main.h"
#include "tx_api.h"

void loggerTask(void)
{
    const char txt[] = "2 seconds elapsed\r\n";

    while(1)
    {
        loggerSendData((uint8_t*)txt, strlen(txt));
        HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET);
        tx_thread_sleep(MS_TO_TICKS(100));
        HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
        tx_thread_sleep(MS_TO_TICKS(1900));
    }    
}