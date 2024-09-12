#ifndef _ROTARY_H_
#define _ROTARY_H_
#include <stdint.h>
#include "stm32f1xx_hal.h"


extern int16_t getRotaryCnt(void);
extern void RotaryEncoder_IRQ_Callback(void);

#endif // !_ROTARY_H_


