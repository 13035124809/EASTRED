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
    3571,3571,3571,3571,3571,3571,3571,3571,3125,3125,
    3125,3125,3125,3125,3125,2778,2778,2778,2778,2778,
    2500,2500,2500,2500,2273,2273,2273,2083,2083,2083,
    1923,1923,1923,1786,1786,1667,1667,1562,1562,1471,
    1471,1389,1316,1316,1250,1190,1190,1136,1087,1042,
    1000,962,926,893,862,833,806,781,758,714,
    694,658,641,625,595,568,556,532,510,490,
    472,455,439,424,410,397,385,368,357,342,
    333,321,312,301,291,281,272,263,258,250,
    240,234,227,221,216,210,205,198,194,189,
    184,180,176,172,168,164,161,158,155,152,
    150,146,144,142,140,137,135,133,131,130,
    128,126,124,123,121,120,119,118,117,116,
    115,114,113,112,111,110,109,108,108,107,
    106,106,105,105,104,104,103,103,102,102,
    102,101,101,100,100,100,100,99,99,99,
    98,98,98,98,98,98,97,97,97,97,
    97,97,97,97,96,96,96,96,96,96,
    96,95,95,95,95,95,95,95,95,95,
    95,95,95,95,95,95,95,95,95,95,
    95,95,95,94,93,92,91,90,89,88,
    87,86,85,84,82,80,78,76,74,72,
    70,68,66,64,62,60,58,56,54,53,
    52,51,50,49,48,47,46,45,45,45,
    44,44,44,44,43,43,43,43,43,43,
    42,42,42,42,42,42,42,41,41,41,
    41,41,41,41,40,40,40,40,40,40,
    40,40,39,39,39,39,39,39,39,39,
    39,38,38,38,38,38,38,38,38,38,
    38,37,37,37,37,37,37,37,37,37,
    37,37,36,36,36,36,36,36,36,36,
    36,36,36,36,35,35,35,35,35,35,
    35,35,35,35,35,35,35,34,34,34,
    34,34,34,34,34,34,34,34,34,34,
    34,33,33,33,33,33,33,33,33,33,
    33,33,33,33,33,33,32,32,32,32,
    32,32,32,32,32,32,32,32,32,32,
    32,32,31,31,31,31,31,31,31,31,
    31,31,31,31,31,31,31,31,31,30,
    30,30,30,30,30,30,30,30,30,30,
    30,30,30,30,30,30,30,30,29,29,
    29,29,29,29,29,29,29,29,29,29,
    29,29,29,29,29,29,29,28,28,28,
    28,28,28,28,28,28,28,28,28,28,
    28,28,28,28,28,28,28,27,27,27,
    27,27,27,27,27,27,27,27,27,27,
    27,27,27,27,27,27,27,27,26,26,
    26,26,26,26,26,26,26,26,26,26,
    26,26,26,26,26,26,26,26,26,26,
    26,25,25,25,25,25,25,25,25,25,
    25,25,25,25,25,25,25,25,25,25
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
        SetpMotor_SetStep(0,step);	//左移
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,-step);
        break;
    case 3:
        SetpMotor_SetStep(0,-step);	//右移
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,step);
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


    for(Count = 0; Count<509; Count++)//每隔2ms重复设定速度值，越小越快
    {
        Speed=value[Count];
        delay_ms(2);//2ms时步数需要>1700；
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
        SetpMotor_SetStep(0,step);	//左移
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,-step);
        break;
    case 3:
        SetpMotor_SetStep(0,-step);	//右移
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,step);
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
        SetpMotor_SetStep(0,step);	//左移
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,-step);
        break;
    case 3:
        SetpMotor_SetStep(0,-step);	//右移
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,step);
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
        SetpMotor_SetStep(0,step);	//左移
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,-step);
        break;
    case 3:
        SetpMotor_SetStep(0,-step);	//右移
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,step);
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
        SetpMotor_SetStep(0,step);	//左移
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,-step);
        break;
    case 3:
        SetpMotor_SetStep(0,-step);	//右移
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,step);
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
    for(Count = 509; Count>0; Count--)//每隔2ms重复设定速度值，越大越慢
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
        SetpMotor_SetStep(0,step);	//左移
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,-step);
        break;
    case 3:
        SetpMotor_SetStep(0,-step);	//右移
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,step);
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
        SetpMotor_SetStep(0,step);	//左移
        SetpMotor_SetStep(1,-step);
        SetpMotor_SetStep(2,step);
        SetpMotor_SetStep(3,-step);
        break;
    case 3:
        SetpMotor_SetStep(0,-step);	//右移
        SetpMotor_SetStep(1,step);
        SetpMotor_SetStep(2,-step);
        SetpMotor_SetStep(3,step);
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
    int GO_CONT;
    int IFx;
    s32 DOWN_speed;
//    float F_flag,B_flag;
    float L,R;
    switch(ib)
    {
    case 0:
        if(SortAndCal(0,5)<600||SortAndCal(4,5)<600)//判断起步模块
        {
           speed_up_CNT_ms(0,226,1,50000);
           IFx=1; 
        }else if(SortAndCal(0,5)>=600||SortAndCal(4,5)>=600)
              {
               speed_up(0,50000);//后退起步
               IFx=0;
              }
            if(motor[0].target!=motor[0].step)//当距离<600的时候开始减速到60
            going_wait=1;
        while(going_wait)
        {
         if((R_above==0||L_above==0)&&SortAndCal(0,5)>600)
            {
                if(SortAndCal(2,5)<60||SortAndCal(3,5)<60)
                {
                    speed_down_CNT_ms(0,240,3,50000);
                    self_control();
                    GO(0);going_wait=0;
                }
            }
         else if(SortAndCal(0,5)<600&&SortAndCal(4,5)<600&&SortAndCal(1,5)>800&&IFx==0)//快速起步时的减速模块
            {
                delay_ms(2);
                if(SortAndCal(0,5)<600&&SortAndCal(4,5)<600&&SortAndCal(1,5)>800&&IFx==0)
                {
                    for(GO_CONT = 509; GO_CONT>225; GO_CONT--)//每隔200us重复设定速度值，越大越慢
                    {
                        DOWN_speed=value[GO_CONT];
                        delay_us(2);
                        SetpMotor_SetSpeed(0,DOWN_speed);
                        SetpMotor_SetSpeed(1,DOWN_speed);
                        SetpMotor_SetSpeed(2,DOWN_speed);
                        SetpMotor_SetSpeed(3,DOWN_speed);
                    }
                    IFx=2;
                }
            }
         else if((SortAndCal(0,5)<80||SortAndCal(4,5)<80)&&SortAndCal(1,5)>800)
            {   delay_ms(2);
                if((SortAndCal(0,5)<80||SortAndCal(4,5)<80)&&SortAndCal(1,5)>800)
                {
                    for(GO_CONT = 225; GO_CONT>0; GO_CONT--)//每隔200us重复设定速度值，越大越慢
                    {
                        DOWN_speed=value[GO_CONT];
                        delay_us(2);
                        SetpMotor_SetSpeed(0,DOWN_speed);
                        SetpMotor_SetSpeed(1,DOWN_speed);
                        SetpMotor_SetSpeed(2,DOWN_speed);
                        SetpMotor_SetSpeed(3,DOWN_speed);
                    }
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
        if(SortAndCal(1,5)<600&&(SortAndCal(0,5)>800||SortAndCal(4,5)>800))
        {
            speed_up_CNT_ms(1,226,1,50000);
            IFx=1;
        }else if(SortAndCal(1,5)>=600) 
        {
            speed_up(1,50000);
            IFx=0;
        }
        if(motor[0].target!=motor[0].step)//当距离<600的时候开始减速到60
            going_wait=1;
while(going_wait)
        {
            if((R_above==0||L_above==0)&&SortAndCal(1,5)>600)
            {
                if(SortAndCal(2,5)<60||SortAndCal(3,5)<60)
                {
                    speed_down_CNT_ms(1,240,3,50000);
                    self_control();
                    GO(1);going_wait=0;
                }
            }
           else if(SortAndCal(0,5)>800&&SortAndCal(4,5)>800&&SortAndCal(1,5)<600&&IFx==0)
            {   delay_ms(2);
                if(SortAndCal(0,5)>800&&SortAndCal(4,5)>800&&SortAndCal(1,5)<600&&IFx==0)
                {
                    for(GO_CONT = 509; GO_CONT>225; GO_CONT--)//每隔200us重复设定速度值，越大越慢
                    {
                        DOWN_speed=value[GO_CONT];
                        delay_us(2);
                        SetpMotor_SetSpeed(0,DOWN_speed);
                        SetpMotor_SetSpeed(1,DOWN_speed);
                        SetpMotor_SetSpeed(2,DOWN_speed);
                        SetpMotor_SetSpeed(3,DOWN_speed);
                    }
                    IFx=2;
                }
            }
            else if(SortAndCal(0,5)>800&&SortAndCal(4,5)>800&&SortAndCal(1,5)<125)
            {   delay_ms(2);
                if(SortAndCal(0,5)>800&&SortAndCal(4,5)>800&&SortAndCal(1,5)<125)
                {
                    for(GO_CONT = 225; GO_CONT>0; GO_CONT--)//每隔200us重复设定速度值，越大越慢
                    {
                        DOWN_speed=value[GO_CONT];
                        delay_us(2);
                        SetpMotor_SetSpeed(0,DOWN_speed);
                        SetpMotor_SetSpeed(1,DOWN_speed);
                        SetpMotor_SetSpeed(2,DOWN_speed);
                        SetpMotor_SetSpeed(3,DOWN_speed);
                    }
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
        speed_up_CNT_ms(2,240,6,1600);//320  35  240 45
        step_wait();
        run(2,50000,35);
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
        run(2,2000,35);
        step_wait();
        speed_down_CNT_ms(2,240,1,50000);//(int ia,int CNT,u32 nus,s32 step)
        break;
    case 3://循环时的左移
//        F_flag=SortAndCal(1,5);
//        B_flag=SortAndCal(4,5);
        speed_up_CNT_ms(2,210,3,16000);//320  35  240 45
        if(motor[0].target!=motor[0].step)
            going_wait=1;
        while(1)
        {
            if(L_front&&!L_rear)
            {
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
                break;
            }
            if(!L_front&&L_rear)
            {
                while(going_wait)
                {
                    if(L_rear==0)
                    {   delay_ms(5);
                        if(L_rear==0)
                        {
                            motor[0].step=motor[0].target=0;
                            motor[1].step=motor[1].target=0;
                            motor[2].step=motor[2].target=0;
                            motor[3].step=motor[3].target=0;
                            going_wait=0;
                        }
                    }
                }
                break;
            }
        }
        run(2,553,60);
        step_wait();
        run(2,553,45);
        step_wait();
        run(2,553,35);
        step_wait();
        speed_down_CNT_ms(2,340,1,50000);//(int ia,int CNT,u32 nus,s32 step)
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
            else if((L-R)>=10)speed_up_CNT_us(5,200,10,(L-R)*1.1);//逆旋
            else if((L-R)<=-10)speed_up_CNT_us(4,200,10,(R-L)*1.1);//正旋
        }
        while(1)//对中
        {
            R=SortAndCal(0,5);//右后侧
            if(R>45&&R<70)
                break;
            else if(L_rear==1)break;
            else if(R>400)break;
            else if(R<45&&R>30)
                speed_up_CNT_us(1,200,10,(R-30)*5);//前进
            else if(R>70)
                speed_up_CNT_us(0,200,10,(R-70)*5);//后退
        }
        break;
    case 5: //右移
        GO(4);
        if(L_rear==0)
        {
            speed_up_CNT_ms(3,340,6,160000);
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
                    GO(5);going_wait=0;
                }
            }
           else if(L<25||R<25)
            {
                motor[0].step=motor[0].target=0;
                motor[1].step=motor[1].target=0;
                motor[2].step=motor[2].target=0;
                motor[3].step=motor[3].target=0;
                speed_down_CNT_ms(3,240,3,50000);
                GO(5);going_wait=0;
            }
        }
    }
}

