#include "calculations.h"
#include "main.h"
#include "logger.h"

VOID calcThreadEntry(ULONG initial_input)
{
    UNUSED(initial_input);
    static const char* msgStart = "calculations start\n\r";
    static const char* msgStop = "calculations stop\n\r";
    static const char* msgPB = "pushbutton pressed\n\r";
    uint32_t message[MSG_SIZE];
    ULONG actualFlags;

    while(1)
    {
        /* wait for the flag to start calculations */
        tx_event_flags_get(&myFlags, CALC_START_FLAG | PUSH_BUTTON_FLAG, TX_OR_CLEAR, &actualFlags, TX_WAIT_FOREVER);
        /* check flags */
        if((actualFlags & CALC_START_FLAG) != 0 )
        {
            /* calculation request flag received */
            /* send a log message */
            message[0] = (uint32_t)msgStart;
            message[1] = 0xFFFFFFFF;
            tx_queue_send(&loggerQueue, message, TX_WAIT_FOREVER);      
            /* calculations simulated with HAL_delay function */
            HAL_Delay(800); 
            /* send a log message */
            message[0] = (uint32_t)msgStop;
            message[1] = 0xFFFFFFFF;
            tx_queue_send(&loggerQueue, message, TX_WAIT_FOREVER);     
        }

        if((actualFlags & PUSH_BUTTON_FLAG) != 0 )
        {
            /* send a log message */
            message[0] = (uint32_t)msgPB;
            message[1] = 0xFFFFFFFF;
            tx_queue_send(&loggerQueue, message, TX_WAIT_FOREVER);                
        }             
    }
}

void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_13)
    {
        tx_event_flags_set(&myFlags, PUSH_BUTTON_FLAG, TX_OR);
    }
}