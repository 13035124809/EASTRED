#include "step.h"
#include "sys.h"
#include "timer.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"
#include "wave.h"
#include "infrared_INIT.h"
#include "self_control.h"
//extern float Left_dist;
//extern float Front_dist;
//extern float Right_dist;
//extern float BackLeft_dist;
//extern float BackRight_dist;
int value[]=
{
    385,385,385,385,385,385,385,385,385,385,//10
    385,385,385,385,385,385,385,385,385,385,//20
    385,385,385,385,385,385,385,385,385,385,//30
    385,385,385,385,385,385,385,385,385,385,//40
    385,385,385,385,385,385,385,385,385,385,//50
    385,385,385,385,385,385,385,385,385,385,//60
    385,385,385,385,385,385,385,385,385,385,//70
    385,385,385,385,385,385,385,385,385,385,//80
    385,385,385,385,385,385,385,385,385,385,//90
    385,385,385,385,385,385,385,385,385,385,//100
    385,385,385,385,385,385,385,385,385,385,//110
    385,385,385,385,385,385,385,385,385,385,//120
    370,370,370,370,370,370,370,370,370,357,//130
    357,357,357,357,357,357,357,345,345,345,//140
    345,345,345,345,345,333,333,333,333,333,//150
    333,323,323,323,323,323,323,312,312,312,//160
    312,312,312,303,303,303,303,303,294,294,//170
    294,294,294,286,286,286,286,278,278,278,//180
    278,270,270,270,270,263,263,263,263,256,//190
    256,256,256,250,250,250,244,244,244,238,//200
    238,238,233,233,233,227,227,227,222,222,//210
    222,217,217,217,213,213,208,208,208,204,//220
    204,200,200,200,196,196,192,192,189,189,//230
    185,185,182,182,179,179,175,175,172,172,//240
    169,169,167,167,164,164,161,161,159,156,//250
    156,154,154,152,149,149,147,145,145,143,//260
    141,141,139,137,137,135,133,133,132,130,//270
    128,128,127,125,123,123,122,120,119,119,//280
    118,116,115,114,112,112,111,110,109,108,//290
    106,105,104,104,103,102,101,100,99,98,//300
    97,96,95,94,93,93,92,91,90,89,//310
    88,88,87,86,85,85,84,83,83,82,//320
    81,80,79,79,78,78,77,76,76,75,//330
    74,74,73,72,72,71,70,70,69,69,//340
    68,68,67,67,66,66,65,65,64,64,//350
    63,63,62,62,61,61,61,60,60,59,//360
    59,58,58,57,57,57,56,56,56,55,//370
    55,54,54,54,53,53,53,52,52,52,//380
    51,51,51,51,50,50,50,49,49,49,//390
    48,48,48,48,47,47,47,47,46,46,//400
    46,45,45,45,45,45,44,44,44,44,//410
    43,43,43,43,43,43,42,42,42,42,//420
    42,41,41,41,41,41,41,40,40,40,//430
    40,40,40,40,39,39,39,39,39,39,//440
    39,38,38,38,38,38,38,38,38,37,//450
    37,37,37,37,37,37,37,37,36,36,//460
    36,36,36,36,36,36,36,36,36,35,//470
    35,35,35,35,35,35,35,35,35,35,//480
    35,35,34,34,34,34,34,34,34,34,//490
    34,34,34,34,34,34,34,34,34,33,//500
    33,33,33,33,33,33,33,33,33,33,//510
    33,33,33,33,33,33,33,33,33,33,//520
    32,32,32,32,32,32,32,32,32,32,//530
    32,32,32,32,32,32,32,32,32,32,//540
    32,32,32,32,32,32,32,32,32,32,//550
    32,32,32,32,31,31,31,31,31,31,//560
    31,31,31,31,31,31,31,31,31,31,//570
    31,31,31,31,31,31,31,31,31,31,//580
    31,31,31,31,31,31,31,31,31,31,//590
    31,31,31,31,31,31,31,31,31,31,//600
    31,31,31,31,31,31,31,31,31,31,//610
    31,31,31,31,31,31,31,31,31,31,//620
};
int value1[]=
{   3571,3571,3571,3571,3571,3571,3571,3571,3125,3125,//10
    3125,3125,3125,3125,3125,2778,2778,2778,2778,2778,//20
    2500,2500,2500,2500,2273,2273,2273,2083,2083,2083,//30
    1923,1923,1923,1786,1786,1667,1667,1562,1562,1471,//40
    1471,1389,1316,1316,1250,1190,1190,1136,1087,1042,//50
    1000,962,926,893,862,833,806,781,758,714,//60
    694,658,641,625,595,568,556,532,510,490,//70
    472,455,439,424,410,397,385,368,357,342,//80
    333,321,312,301,291,281,272,263,258,250,//90
    240,234,227,221,216,210,205,198,194,189,//100
    184,180,176,172,168,164,161,158,155,152,//110
    150,146,144,142,140,137,135,133,131,130,//120
    128,126,124,123,121,120,119,118,117,116,//130
    115,114,113,112,111,110,109,108,108,107,//140
    106,106,105,105,104,104,103,103,102,102,//150
    102,101,101,100,100,100,100,99,99,99,//160
    98,98,98,98,98,98,97,97,97,97,//170
    97,97,97,97,96,96,96,96,96,96,//180
    96,95,95,95,95,95,95,95,95,95,//190
    95,95,95,95,95,95,95,95,95,95,//200
    95,95,95,94,93,92,91,90,89,88,//210
    87,86,85,84,82,80,78,76,74,72,//220
    70,68,66,64,62,60,58,56,54,53,//230
    52,51,50,49,48,47,46,45,45,45,//240
    44,44,44,44,43,43,43,43,43,43,//250
    42,42,42,42,42,42,42,41,41,41,//260
    41,41,41,41,40,40,40,40,40,40,//270
    40,40,39,39,39,39,39,39,39,39,//280
    39,38,38,38,38,38,38,38,38,38,//290
    38,37,37,37,37,37,37,37,37,37,//300
    37,37,36,36,36,36,36,36,36,36,//310
    36,36,36,36,35,35,35,35,35,35,//320
    35,35,35,35,35,35,35,34,34,34,//330
    34,34,34,34,34,34,34,34,34,34,//340
    34,33,33,33,33,33,33,33,33,33,//350
    33,33,33,33,33,33,32,32,32,32,//360
    32,32,32,32,32,32,32,32,32,32,//370
    32,32,31,31,31,31,31,31,31,31,//380
    31,31,31,31,31,31,31,31,31,30,//390
    30,30,30,30,30,30,30,30,30,30,//400
    30,30,30,30,30,30,30,30,29,29,//410
    29,29,29,29,29,29,29,29,29,29,//420
    29,29,29,29,29,29,29,28,28,28,//430
    28,28,28,28,28,28,28,28,28,28,//440
    28,28,28,28,28,28,28,27,27,27,//450
    27,27,27,27,27,27,27,27,27,27,//460
    27,27,27,27,27,27,27,27,26,26,//470
    26,26,26,26,26,26,26,26,26,26,//480
    26,26,26,26,26,26,26,26,26,26,//490
    26,25,25,25,25,25,25,25,25,25,//500
    25,25,25,25,25,25,25,25,25,25//510
};
void speed_up(int ia,int step)//四个电机一起加速
{
    int Count=0;//加速标志数
    int Speed;

    switch(ia)//设定四个步进电机目标步数
    {
    case 0:
        //
        SetpMotor_SetStep(0,step);	//后退
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,-step);
        break;
    case 1:
        SetpMotor_SetStep(0,-step);	//前进
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,step);
        break;
    case 2:
        SetpMotor_SetStep(0,-step);	//左移
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,step);
        break;
    case 3:
        SetpMotor_SetStep(0,step);	//右移
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,-step);
        break;
    case 4:
        SetpMotor_SetStep(0,-step);	//正旋
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,-step);
        break;
    case 5:
        SetpMotor_SetStep(0,step);	//逆旋
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,step);
        break;
    }


    for(Count = 0; Count<=619; Count++)//每隔2ms重复设定速度值，越小越快
    {
        Speed=value[Count];
        delay_ms(4);//2ms时步数需要>1700；
        SetpMotor_SetSpeed(0,Speed);
        SetpMotor_SetSpeed(1,Speed);
        SetpMotor_SetSpeed(2,Speed);
        SetpMotor_SetSpeed(3,Speed);
    }
}
void speed_up_CNT_ms(int ia,int CNT,u16 nms,s32 step)
{
    int Count=0;//加速标志数
    int Speed;

    switch(ia)//设定四个步进电机目标步数
    {
    case 0:
        //
        SetpMotor_SetStep(0,step);	//后退
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,-step);
        break;
    case 1:
        SetpMotor_SetStep(0,-step);	//前进
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,step);
        break;
    case 2:
        SetpMotor_SetStep(0,-step);	//左移
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,step);
        break;
    case 3:
        SetpMotor_SetStep(0,step);	//右移
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,-step);
        break;
    case 4:
        SetpMotor_SetStep(0,-step);	//正旋
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,-step);
        break;
    case 5:
        SetpMotor_SetStep(0,step);	//逆旋
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,step);
        break;
    }


    for(Count = 0; Count<CNT; Count++)//每隔2ms重复设定速度值，越小越快
    {
        Speed=value1[Count];
        delay_ms(nms);//2ms时步数需要>1700；
        SetpMotor_SetSpeed(0,Speed);
        SetpMotor_SetSpeed(1,Speed);
        SetpMotor_SetSpeed(2,Speed);
        SetpMotor_SetSpeed(3,Speed);
    }
}
void speed_up_CNT_us(int ia,int CNT,u32 nus,s32 step)
{
    int Count=0;//加速标志数
    int Speed;

    switch(ia)//设定四个步进电机目标步数
    {
    case 0:
        //
        SetpMotor_SetStep(0,step);	//后退
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,-step);
        break;
    case 1:
        SetpMotor_SetStep(0,-step);	//前进
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,step);
        break;
    case 2:
        SetpMotor_SetStep(0,-step);	//左移
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,step);
        break;
    case 3:
        SetpMotor_SetStep(0,step);	//右移
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,-step);
        break;
    case 4:
        SetpMotor_SetStep(0,-step);	//正旋
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,-step);
        break;
    case 5:
        SetpMotor_SetStep(0,step);	//逆旋
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,step);
        break;
    }


    for(Count = 0; Count<CNT; Count++)//每隔2ms重复设定速度值，越小越快
    {
        Speed=value[Count];
        delay_us(nus);//2ms时步数需要>1700；
        SetpMotor_SetSpeed(0,Speed);
        SetpMotor_SetSpeed(1,Speed);
        SetpMotor_SetSpeed(2,Speed);
        SetpMotor_SetSpeed(3,Speed);
    }
}
void run(int ia,s32 step,s32 Speed)
{   switch(ia)//设定四个步进电机目标步数
    {
    case 0:
        //
        SetpMotor_SetStep(0,step);	//后退
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,-step);
        break;
    case 1:
        SetpMotor_SetStep(0,-step);	//前进
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,step);
        break;
    case 2:
        SetpMotor_SetStep(0,-step);	//左移
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,step);
        break;
    case 3:
        SetpMotor_SetStep(0,step);	//右移
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,-step);
        break;
    case 4:
        SetpMotor_SetStep(0,-step);	//正旋
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,-step);
        break;
    case 5:
        SetpMotor_SetStep(0,step);	//逆旋
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,step);
        break;
    }
    SetpMotor_SetSpeed(0,Speed);
    SetpMotor_SetSpeed(1,Speed);
    SetpMotor_SetSpeed(2,Speed);
    SetpMotor_SetSpeed(3,Speed);
}
void speed_down(int ia,int step)//四个电机一起加速
{
    int Count;//加速标志数
    int Speed;
    switch(ia)//设定四个步进电机目标步数
    {
    case 0:
        SetpMotor_SetStep(0,step);	//后退
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,-step);
        break;
    case 1:
        SetpMotor_SetStep(0,-step);	//前进
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,step);
        break;
    case 2:
        SetpMotor_SetStep(0,-step);	//左移
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,step);
        break;
    case 3:
        SetpMotor_SetStep(0,step);	//右移
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,-step);
        break;
    case 4:
        SetpMotor_SetStep(0,-step);	//正旋
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,-step);
        break;
    case 5:
        SetpMotor_SetStep(0,step);	//逆旋
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,step);
        break;
    }
    for(Count = 619; Count>0; Count--)//每隔2ms重复设定速度值，越大越慢
    {
        Speed=value[Count];
        Speed=value[Count];
        Speed=value[Count];
        Speed=value[Count];
        delay_us(20);
        SetpMotor_SetSpeed(0,Speed);
        SetpMotor_SetSpeed(1,Speed);
        SetpMotor_SetSpeed(2,Speed);
        SetpMotor_SetSpeed(3,Speed);
    }
}
void speed_down_CNT_us(int ia,int CNT,u32 nus,s32 step)
{
    int Count;//加速标志数
    int Speed;
    switch(ia)//设定四个步进电机目标步数
    {
    case 0:
        SetpMotor_SetStep(0,step);	//后退
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,-step);
        break;
    case 1:
        SetpMotor_SetStep(0,-step);	//前进
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,step);
        break;
    case 2:
        SetpMotor_SetStep(0,-step);	//左移
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,step);
        break;
    case 3:
        SetpMotor_SetStep(0,step);	//右移
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,-step);
        break;
    case 4:
        SetpMotor_SetStep(0,-step);	//正旋
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,-step);
        break;
    case 5:
        SetpMotor_SetStep(0,step);	//逆旋
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,step);
        break;
    }
    for(Count = CNT; Count>0; Count--)//每隔2ms重复设定速度值，越大越慢
    {
        Speed=value[Count];
        Speed=value[Count];
        Speed=value[Count];
        Speed=value[Count];
        delay_us(nus);
        SetpMotor_SetSpeed(0,Speed);
        SetpMotor_SetSpeed(1,Speed);
        SetpMotor_SetSpeed(2,Speed);
        SetpMotor_SetSpeed(3,Speed);
    }
}
void speed_down_CNT_ms(int ia,int CNT,u16 nms,s32 step)
{
    int Count;//加速标志数
    int Speed;
    switch(ia)//设定四个步进电机目标步数
    {
    case 0:
        SetpMotor_SetStep(0,step);	//后退
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,-step);
        break;
    case 1:
        SetpMotor_SetStep(0,-step);	//前进
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,step);
        break;
    case 2:
        SetpMotor_SetStep(0,-step);	//左移
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,step);
        break;
    case 3:
        SetpMotor_SetStep(0,step);	//右移
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,-step);
        break;
    case 4:
        SetpMotor_SetStep(0,-step);	//正旋
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,-step);
        break;
    case 5:
        SetpMotor_SetStep(0,step);	//逆旋
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,step);
        break;
    }
    for(Count = CNT; Count>0; Count--)//每隔2ms重复设定速度值，越大越慢
    {
        Speed=value1[Count];
        Speed=value1[Count];
        Speed=value1[Count];
        Speed=value1[Count];
        delay_ms(nms);
        SetpMotor_SetSpeed(0,Speed);
        SetpMotor_SetSpeed(1,Speed);
        SetpMotor_SetSpeed(2,Speed);
        SetpMotor_SetSpeed(3,Speed);
    }
}
void step_wait(void)
{   int wait=0;
    if(motor[0].target!=motor[0].step)
        wait=1;
    while(wait)
    {
        if(motor[0].target==motor[0].step)
        {
            motor[0].step=motor[0].target=0;
            motor[1].step=motor[1].target=0;
            motor[2].step=motor[2].target=0;
            motor[3].step=motor[3].target=0;
            wait=0;
        }
    }

}
void GO(int ib)
{   int going_wait=0;
    int GO_CONT,lCount;
    int IFx;
    s32 DOWN_speed;
//    float F_flag,B_flag;
    float L,R;
    switch(ib)
    {
    case 0:
        while(1)
        {
            if(SortAndCal(0,5)<900||SortAndCal(4,5)<900)//判断起步模块
            {   PBout(8)=1;
                speed_up_CNT_ms(0,340,2,50000);
                IFx=1;
                break;
            } else if(SortAndCal(0,5)>=900||SortAndCal(4,5)>=900)
            {
                speed_up_CNT_ms(0,509,2,50000);//后退起步
                IFx=0;
                break;
            }PBout(8)=0;
        }
        if(motor[0].target!=motor[0].step)//当距离<600的时候开始减速到60
            going_wait=1;
        while(going_wait)
        {
            if((R_above==0||L_above==0)&&SortAndCal(0,5)>900)
            {
                if(SortAndCal(2,5)<40||SortAndCal(3,5)<40)
                {
                    speed_down_CNT_ms(0,340,3,50000);
                    self_control();
                    GO(0);
                    going_wait=0;
                }
            }
            else if(going_wait&&SortAndCal(0,5)<600&&SortAndCal(4,5)<600&&SortAndCal(1,5)>800&&IFx==0)//快速起步时的减速模块
            {
                delay_ms(2);
                if(going_wait&&SortAndCal(0,5)<600&&SortAndCal(4,5)<600&&SortAndCal(1,5)>800&&IFx==0)
                {   PBout(8)=1;
                    for(GO_CONT = 509; GO_CONT>340; GO_CONT--)//每隔200us重复设定速度值，越大越慢
                    {
                        DOWN_speed=value[GO_CONT];
                        delay_ms(2);
                        SetpMotor_SetSpeed(0,DOWN_speed);
                        SetpMotor_SetSpeed(1,DOWN_speed);
                        SetpMotor_SetSpeed(2,DOWN_speed);
                        SetpMotor_SetSpeed(3,DOWN_speed);
                    }
                    IFx=2; PBout(8)=0;
                }
            }
            else if(going_wait&&(SortAndCal(0,5)<80||SortAndCal(4,5)<80)&&SortAndCal(1,5)>800)
            {   delay_ms(2);
                if(going_wait&&(SortAndCal(0,5)<80||SortAndCal(4,5)<80)&&SortAndCal(1,5)>800)
                {
                    for(GO_CONT = 340; GO_CONT>0; GO_CONT--)//每隔200us重复设定速度值，越大越慢
                    {

                        DOWN_speed=value[GO_CONT];
                        delay_us(50);
                        if(GO_CONT==1) DOWN_speed=3000;
                        SetpMotor_SetSpeed(0,DOWN_speed);
                        SetpMotor_SetSpeed(1,DOWN_speed);
                        SetpMotor_SetSpeed(2,DOWN_speed);
                        SetpMotor_SetSpeed(3,DOWN_speed);
                    }
                    speed_up_CNT_us(1,358,10,50000);
                    going_wait=0;
                    motor[0].step=motor[0].target=0;
                    motor[1].step=motor[1].target=0;
                    motor[2].step=motor[2].target=0;
                    motor[3].step=motor[3].target=0;
                }
            }
        }
        break;
    case 1:
        while(1)
        {
            if(SortAndCal(1,5)<900&&(SortAndCal(0,5)>800||SortAndCal(4,5)>800))
            {   PBout(8)=1;
                speed_up_CNT_ms(1,340,2,50000);
                IFx=1;
                break;
            } else if(SortAndCal(1,5)>=900)
            {
                speed_up_CNT_ms(1,509,2,50000);
                IFx=0;
                break;
            } PBout(8)=0;
        }
        if(motor[0].target!=motor[0].step)//当距离<600的时候开始减速到60
            going_wait=1;
        while(going_wait)
        {   //printf("qian%f\r\n",SortAndCal(1,5));
            if((R_above==0||L_above==0)&&SortAndCal(1,5)>900)
            {
                if(SortAndCal(2,5)<40||SortAndCal(3,5)<40)
                {
                    speed_down_CNT_ms(1,340,3,50000);
                    self_control();
                    GO(1);
                    going_wait=0;
                }
            }
            else if(going_wait&&SortAndCal(0,5)>800&&SortAndCal(4,5)>800&&SortAndCal(1,5)<600&&IFx==0)
            {   delay_ms(2);
                if(going_wait&&SortAndCal(0,5)>800&&SortAndCal(4,5)>800&&SortAndCal(1,5)<600&&IFx==0)
                {
                    for(GO_CONT = 509; GO_CONT>340; GO_CONT--)//每隔200us重复设定速度值，越大越慢
                    { PBout(8)=1;
                        DOWN_speed=value[GO_CONT];
                        delay_ms(2);
                        SetpMotor_SetSpeed(0,DOWN_speed);
                        SetpMotor_SetSpeed(1,DOWN_speed);
                        SetpMotor_SetSpeed(2,DOWN_speed);
                        SetpMotor_SetSpeed(3,DOWN_speed);
                    }
                    IFx=2; PBout(8)=0;
                }
            }
            else if(going_wait&&SortAndCal(0,5)>800&&SortAndCal(4,5)>800&&SortAndCal(1,5)<125)
            {   delay_ms(2);
                if(going_wait&&SortAndCal(0,5)>800&&SortAndCal(4,5)>800&&SortAndCal(1,5)<125)
                {
                    for(GO_CONT = 340; GO_CONT>0; GO_CONT--)//每隔200us重复设定速度值，越大越慢
                    {
                        DOWN_speed=value[GO_CONT];
                        delay_us(2);
                        if(GO_CONT==1) DOWN_speed=3000;
                        SetpMotor_SetSpeed(0,DOWN_speed);
                        SetpMotor_SetSpeed(1,DOWN_speed);
                        SetpMotor_SetSpeed(2,DOWN_speed);
                        SetpMotor_SetSpeed(3,DOWN_speed);
                    }
                    speed_up_CNT_us(0,358,10,50000);
                    going_wait=0;
                    motor[0].step=motor[0].target=0;
                    motor[1].step=motor[1].target=0;
                    motor[2].step=motor[2].target=0;
                    motor[3].step=motor[3].target=0;
                }
            }
        }
        break;
    case 2://开始时的左移
//        speed_up_CNT_ms(2,240,6,1600);//320  35  240 45
//        step_wait();
//        run(2,50000,35);
        speed_up(2,500000);
        if(motor[0].target!=motor[0].step)//当距离<600的时候开始减速到60
            going_wait=1;
        while(going_wait)
        {
            if(L_front==0)
            {   delay_ms(5);
                if(L_front==0)
                {
                    motor[0].step=motor[0].target=0;
                    motor[1].step=motor[1].target=0;
                    motor[2].step=motor[2].target=0;
                    motor[3].step=motor[3].target=0;
                    going_wait=0;
                }
            }
        }
        run(2,1200,31);
        step_wait();
        speed_down(2,50000);//(int ia,int CNT,u32 nus,s32 step)
        break;
    case 3://循环时的左移
//        F_flag=SortAndCal(1,5);
//        B_flag=SortAndCal(4,5);
        SetpMotor_SetStep(0,-26000);	//左移
        SetpMotor_SetStep(1,26000);
        SetpMotor_SetStep(2,-26000);
        SetpMotor_SetStep(3,26000);
        if(motor[0].target!=motor[0].step)
        going_wait=1;lCount = 0;
        while(going_wait)
        {   
            if(lCount>=619) going_wait=0;
            else if(L_front&&!L_rear)
            {
            SetpMotor_SetSpeed(0,value[lCount]);
            SetpMotor_SetSpeed(1,value[lCount]);
            SetpMotor_SetSpeed(2,value[lCount]);
            SetpMotor_SetSpeed(3,value[lCount]);
            delay_ms(4);
            lCount++;  
            if(L_front==0)
            {delay_ms(5);
                if(L_front==0)
            {
                while(L_front==0)
                {   PBout(8)=1;
                    SetpMotor_SetSpeed(0,value[lCount]);
                    SetpMotor_SetSpeed(1,value[lCount]);
                    SetpMotor_SetSpeed(2,value[lCount]);
                    SetpMotor_SetSpeed(3,value[lCount]);
                    delay_ms(4);
                    if(lCount<=619)lCount++;  
                }PBout(8)=0;
             motor[0].step=motor[0].target=0;
             motor[1].step=motor[1].target=0;
             motor[2].step=motor[2].target=0;
             motor[3].step=motor[3].target=0;
             going_wait=0;   
            } 
            }            
            }
            else if(!L_front&&L_rear)
            {
            SetpMotor_SetSpeed(0,value[lCount]);
            SetpMotor_SetSpeed(1,value[lCount]);
            SetpMotor_SetSpeed(2,value[lCount]);
            SetpMotor_SetSpeed(3,value[lCount]);
            delay_ms(4);
            lCount++;  
            if(L_rear==0)
            {delay_ms(5);
                if(L_rear==0)
            {
                while(L_rear==0)
                {   PBout(8)=1;
                    SetpMotor_SetSpeed(0,value[lCount]);
                    SetpMotor_SetSpeed(1,value[lCount]);
                    SetpMotor_SetSpeed(2,value[lCount]);
                    SetpMotor_SetSpeed(3,value[lCount]);
                    delay_ms(4);
                    if(lCount<=619)lCount++; 
                }PBout(8)=0;
             motor[0].step=motor[0].target=0;
             motor[1].step=motor[1].target=0;
             motor[2].step=motor[2].target=0;
             motor[3].step=motor[3].target=0;
             going_wait=0;   
            } 
            }   
            }
        }    
        run(2,553,value[lCount]);
        step_wait();
        speed_down_CNT_us(2,lCount,20,50000);//(int ia,int CNT,u32 nus,s32 step)
        break;
    case 4:
        while(1)//摆正
        {
            L=SortAndCal(4,5);//左后侧
            R=SortAndCal(0,5);//右后侧
            if(((L-R)>0&&(L-R)<5)||((L-R)>-10&&(L-R)<=0))
                break;
            else if(L_rear==1)break;
            else if(R>400)break;
            else if((L-R)>=10)speed_up_CNT_us(5,303,1,(L-R)*1.1);//逆旋
            else if((L-R)<=-10)speed_up_CNT_us(4,303,1,(R-L)*1.1);//正旋
        }
        while(1)//对中
        {
            R=SortAndCal(0,5);//右后侧
            if(R>45&&R<70)
                break;
            else if(L_rear==1)break;
            else if(R>400)break;
            else if(R<45&&R>30)
                speed_up_CNT_us(1,303,1,(R-30)*5);//前进
            else if(R>70)
                speed_up_CNT_us(0,303,1,(R-70)*5);//后退
        }
        break;
    case 5: //右移
        GO(4);
        if(L_rear==0)
        {
            speed_up(3,160000);
        }
        if(motor[0].target!=motor[0].step)
            going_wait=1;
        while(going_wait)
        {   L=SortAndCal(4,5);//左后侧
            R=SortAndCal(0,5);//右后侧
            if(L_rear==1)
            {   delay_ms(2);
                if(L_rear==1)
                {   going_wait=0;
                    motor[0].step=motor[0].target=0;
                    motor[1].step=motor[1].target=0;
                    motor[2].step=motor[2].target=0;
                    motor[3].step=motor[3].target=0;
//                    run(3,900,45);
//                    step_wait();
                    break;
                }
            }
            else if(R_front==0)
            {   delay_ms(10);
                if(R_front==0)
                {
                    motor[0].step=motor[0].target=0;
                    motor[1].step=motor[1].target=0;
                    motor[2].step=motor[2].target=0;
                    motor[3].step=motor[3].target=0;
                    speed_down_CNT_ms(3,240,1,50000);
                    GO(5);
                    going_wait=0;
                }
            }
            else if(going_wait&&(L<25||R<25))
            {
                motor[0].step=motor[0].target=0;
                motor[1].step=motor[1].target=0;
                motor[2].step=motor[2].target=0;
                motor[3].step=motor[3].target=0;
                speed_down_CNT_ms(3,240,3,50000);
                GO(5);
                going_wait=0;
            }
        }
    }
}

