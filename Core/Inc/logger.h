#ifndef __LOGGER_H
#define __LOGGER_H

#include "stdint.h"
#include "stddef.h"

extern void loggerTask(void);
extern unsigned long loggerSendData(uint8_t* data, size_t size);

#endif /* __LOGGER_H */
