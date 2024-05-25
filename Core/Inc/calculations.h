#ifndef __CALCULATIONS_H
#define __CALCULATIONS_H

#include "tx_api.h"

#define CALC_START_FLAG 1

extern VOID calcThreadEntry(ULONG initial_input);
extern TX_EVENT_FLAGS_GROUP myFlags;

#endif /* __CALCULATIONS_H */