#include "menu.h"
#define MAX_DISPLAY 3

void menu1(void)
{
    option_class1 opt1[]=
    {
    {"option1",NULL,APPADDV,7},
    {"option2",NULL,APPsetting,7},
    {"option3",NULL,APPWXZF,7},
    {"option4",NULL,APPGAME,7},
    {"option5",NULL,APPVIDEO,7},
    {".."}
    };
    int8_t flag_reverse=0;  //代表屏幕跳转方向，1为向右滑动，-1为向左
    uint8_t option_cnt=0;
    while(opt1[option_cnt++].Name[0]!='.');
    --option_cnt;         //计算option个数

    uint8_t screen_target=0;
    uint8_t screen_last=0;
    static int8_t cusor_target=0;//光标目标位置
    int8_t button_evernt=0;//可作为方向判断
    int8_t cusor_display;//光标显示位置
    uint8_t cusor_last;//上次光标位置


    int8_t para_rectangle;//方框移动系数
    while(1)
    {

        if(button_evernt=getRotaryCnt())
        {
            cusor_target += button_evernt;
            cusor_last = cusor_display;
            cusor_display+= button_evernt;
            para_rectangle = (cusor_display - cusor_last)*40;//系数调整

            screen_last = screen_target;
            //目标光标越界判断
            if(cusor_target<0)
            {
                cusor_target = option_cnt-1;
                flag_reverse = -1;
            }
            else if(cusor_target>=option_cnt)
            {
                cusor_target = 0;
                flag_reverse = 1;   
            }

            if(cusor_display>=MAX_DISPLAY)
            {
                screen_target++;
                //cusor_display = 0;
            }
            else if(cusor_display<0)
            {
                screen_target--;
                //cusor_display = MAX_DISPLAY-1;
            }
            if(flag_reverse)
            {
                if(flag_reverse==1)screen_target = 0;
                else if(flag_reverse==-1)screen_target = option_cnt-2;
                flag_reverse = 0;
            }


            if(screen_target>screen_last)cusor_display = MAX_DISPLAY-1;
            else if(screen_target<screen_last)cusor_display = 0;
            
            



        }
        para_rectangle/=1.3;

        // if(cusor_last!=cusor_display)//光标偏移
        // {
        //     //选中的光标需要移动
        //     if((button_evernt==-1)&&(cusor_target==option_cnt-1))
        //     {
        //         cusor_display = MAX_DISPLAY-1;
        //     }
        //     else if((button_evernt==1)&&(cusor_target==0))
        //     {
        //         cusor_display = 0;
        //         flag_reverse = 1;
        //     }
        //     //记录这次的显示光标的位置，作为下次判断
        //     cusor_last = cusor_display;
        // }
        if(cusor_display!=cusor_last)
        {
            
            OLED_DrawRectangle(((cusor_display*40)+4)-para_rectangle,4,40,40,OLED_UNFILLED);
        }
        if(screen_last!= screen_target)
        {
            
            
            OLED_ShowImage();
            //OLED_DrawRectangle(,63,,1);   //选中的光标

        }








        OLED_Update();
    }


    
    
}
