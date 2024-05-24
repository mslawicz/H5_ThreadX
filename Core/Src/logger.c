#include "logger.h"
#include "main.h"
#include "stdio.h"

#define TXT_MAX_SIZE    100
#define LOGGER_QUEUE_SIZE 32

TX_QUEUE loggerQueue;   /* queue object */
uint32_t loggerQueueBuffer[LOGGER_QUEUE_SIZE * MSG_SIZE];  /* queue buffer */
char loggerText[TXT_MAX_SIZE];  /* buffer for a text sent to USB link */

void loggerTask(void)
{
    const char noTxtPointerMessage[] = "Warning: a message with null pointer received\r\n";
    uint32_t message[2];

    /* create logger message queue for 2x32-bit messages */
    tx_queue_create(&loggerQueue, "Logger Queue", 2, loggerQueueBuffer, LOGGER_QUEUE_SIZE * MSG_SIZE * sizeof(uint32_t));

    while(1)
    {  
        /* wait for a logger message */
        tx_queue_receive(&loggerQueue, message, TX_WAIT_FOREVER);
        if(message[0] != 0)
        {
            /* a pointer to the log text has been received */
            if(message[1] != 0xFFFFFFFF)
            {
                /* the second argument is a number to be displayed */
                snprintf(loggerText, TXT_MAX_SIZE, (const char*)message[0], message[1]);
            }
            else
            {
                /* no second argument */
                snprintf(loggerText, TXT_MAX_SIZE, (const char*)message[0]);
            } 
            /* send message to USB link */       
            loggerSendData((uint8_t*)loggerText, strlen(loggerText));
        }
        else
        {
            /* this should not happen - display warning */
            loggerSendData((uint8_t*)noTxtPointerMessage, strlen(noTxtPointerMessage));
        }
    }    
}