#ifndef _MENU_H_
#define _MENU_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "OLED_Driver.h"
#include "OLED_Front.h"
#include "Rotary.h"
typedef struct option_class
{
    char *Name;
    void (*Func)(void);
    const char * Image;
    uint8_t NameLen;
    //option_class1 *next;
    //option_class1 *prev;
}option_class1;   




#endif // !