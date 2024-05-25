#include "calculations.h"
#include "main.h"
#include "logger.h"

VOID calcThreadEntry(ULONG initial_input)
{
    UNUSED(initial_input);
    static const char* msgStart = "calculations start\n\r";
    static const char* msgStop = "calculations stop\n\r";
    uint32_t message[MSG_SIZE];
    ULONG actualFlags;

    while(1)
    {
        /* wait for the flag to start calculations */
        tx_event_flags_get(&myFlags, CALC_START_FLAG, TX_AND_CLEAR, &actualFlags, TX_WAIT_FOREVER);
        /* flag received */
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
}