#ifndef __LOGGER_H
#define __LOGGER_H

#include "stdint.h"
#include "stddef.h"
#include "tx_api.h"

#define MSG_SIZE    2

extern void loggerTask(void);
extern unsigned long loggerSendData(uint8_t* data, size_t size);
extern TX_QUEUE loggerQueue;

#endif /* __LOGGER_H */
