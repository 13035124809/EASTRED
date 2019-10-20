#include "step.h"
#include "self_control.h"
#include "sys.h"
#include "timer.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"
#include "wave.h"
#include "infrared_INIT.h"
extern int value[];
void self_control(void)
{int out=1;
    while(out)
    {   int ix;
        float LEFT,RIGHT;
        s32 B_step;
        //�Ϸ��ĸ�����ȫ��
        if(L_above_C==0&&L_below_C==0&&R_above_C==0&&R_below_C==0)
        {   delay_ms(10);
            if(L_above_C==0&&L_below_C==0&&R_above_C==0&&R_below_C==0) ix=0;
        }
        //���Ͻǲ���������ȫ��
        if(L_above_C==1&&L_below_C==0&&R_above_C==0&&R_below_C==0)
        {   delay_ms(10);
            if(L_above_C==1&&L_below_C==0&&R_above_C==0&&R_below_C==0) ix=1;
        }
        //���½ǲ���������ȫ��
        if(L_above_C==0&&L_below_C==1&&R_above_C==0&&R_below_C==0)
        {   delay_ms(10);
            if(L_above_C==0&&L_below_C==1&&R_above_C==0&&R_below_C==0) ix=2;
        }
        //���Ͻǲ���������ȫ��
        if(L_above_C==0&&L_below_C==0&&R_above_C==1&&R_below_C==0)
        {   delay_ms(10);
            if(L_above_C==0&&L_below_C==0&&R_above_C==1&&R_below_C==0) ix=3;
        }
        //���½ǲ���������ȫ��
        if(L_above_C==0&&L_below_C==0&&R_above_C==0&&R_below_C==1)
        {   delay_ms(10);
            if(L_above_C==0&&L_below_C==0&&R_above_C==0&&R_below_C==1) ix=4;
        }
        //��߲������ұ���
        if(L_above_C==1&&L_below_C==1&&R_above_C==0&&R_below_C==0)
        {   delay_ms(10);
            if(L_above_C==1&&L_below_C==1&&R_above_C==0&&R_below_C==0) ix=5;
        }
        //��������ұ߲���
        if(L_above_C==0&&L_below_C==0&&R_above_C==1&&R_below_C==1)
        {   delay_ms(10);
            if(L_above_C==0&&L_below_C==0&&R_above_C==1&&R_below_C==1) ix=6;
        }
        //���ϽǺ����½ǲ��������½Ǻ����Ͻ���
        if(L_above_C==1&&L_below_C==0&&R_above_C==0&&R_below_C==1)
        {   delay_ms(10);
            if(L_above_C==1&&L_below_C==0&&R_above_C==0&&R_below_C==1) ix=7;
        }
        //���ϽǺ����½��������½Ǻ����Ͻǲ���
        if(L_above_C==0&&L_below_C==1&&R_above_C==1&&R_below_C==0)
        {   delay_ms(10);
            if(L_above_C==0&&L_below_C==1&&R_above_C==1&&R_below_C==0) ix=8;
        }
        switch(ix)
        {
        case 0:
            out=0;
            break;
        case 1:
            speed_up_CNT_us(4,200,1,20);//����
            break;
        case 2:
            speed_up_CNT_us(5,200,1,20);//����
            break;
        case 3:
            speed_up_CNT_us(5,200,1,20);//����
            break;
        case 4:
            speed_up_CNT_us(4,200,1,20);//����
            break;
        case 5:LEFT=SortAndCal(2,5);
            if(LEFT>=110&&LEFT<=250)
            {
                B_step=(LEFT-115)*5.6;
            }
            else {
                B_step=80;
            }
            speed_up_CNT_us(3,200,2,B_step);//����
            step_wait();
            break;
        case 6:RIGHT=SortAndCal(3,5);
            if(RIGHT>=110&&RIGHT<=250)
            {
                B_step=(RIGHT-115)*5.6;
            }
            else {
                B_step=80;
                
            }
            speed_up_CNT_us(2,200,2,B_step);//����
            step_wait();
            break;
         case 7:
            speed_up_CNT_us(4,200,1,160);//����
            break;
         case 8:
            speed_up_CNT_us(5,200,1,160);//����
            break;
       default : 
            out=0;
            break;           
        }
    }
}

