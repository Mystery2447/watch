#include "Rotary.h"

static int16_t cnt=0;
static uint8_t flag_exti=0;
static uint8_t rising_lvl=0;
static uint8_t falling_lvl=0;
int16_t getRotaryCnt(void)
{
    int16_t temp=0;
    temp = cnt;
    cnt=0;
    return temp;
}

void RotaryEncoder_IRQ_Callback(void)
{
    if((HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==0 )&&(flag_exti==0) )
    {
        flag_exti=1;
        falling_lvl=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);
    }
    else if((HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==1 )&&(flag_exti==1) )
    {
        flag_exti=0;
        rising_lvl=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);
        if((falling_lvl==1)&& (rising_lvl==0))
        {
            cnt--;
        }
        else if((falling_lvl==0)&& (rising_lvl==1))
        {
            cnt++;
        }
    }

}


