#ifndef __STEP_H
#define __STEP_H
#include "sys.h"
void speed_up(int ia,s32 step);
void speed_up_CNT_ms(int ia,int CNT,u16 nms,s32 step);
void speed_up_CNT_us(int ia,int CNT,u32 nus,s32 step);
void run(int ia,s32 step,s32 Speed);
void speed_down(int ia,int step);
void speed_down_CNT_us(int ia,int CNT,u32 nus,s32 step);
void speed_down_CNT_ms(int ia,int CNT,u16 nms,s32 step);
void step_wait(void);
void GO(int ib);
#endif

