#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
#include "step.h"
#include "wave.h"
#include "infrared_INIT.h"
#include "self_control.h"
extern float Left_dist;
extern float Front_dist;
extern float Right_dist;
extern float BackLeft_dist;
extern float BackRight_dist;
void WIFI_INIT(void)
{
    printf("AT+RST\r\n");//复位
    delay_ms(300);
    printf("AT+CWMODE=2\r\n");//模式2，AP
    delay_ms(1000);
    printf("AT+CWSAP=\"655666565\",\"12345678\",11,3\r\n");//设置由模块发出的WIFI
    delay_ms(1800);
    printf("AT+CIPSTART=\"TCP\",\"192.168.4.2\",8080\r\n");//填写要连接的手机地址，端口
    delay_ms(1800);
    printf("AT+CIPMODE=1\r\n");//开启透传模式
    delay_ms(1001);
    printf("AT+CIPSEND\r\n");//单路连接
    delay_ms(1001);
   printf("开始调节\r\n");
}
int main(void)
{   int LX=0;//计数
    delay_init();	    	 //延时函数初始化
    infrared_INIT();         //红外端口初始化
    uart_init(115200);	     //串口初始化为115200
    TIM2_Int_Init(12,10);    //TIM2初始化
    TIM6_Int_Init(999,71);   //TIM6初始化
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
    //WIFI_INIT();//wifi模块初始化     
    GO(2);
    GO(1);
    GO(0);
    GO(3);
    while(1)
       {
           if(SortAndCal(0,5)<400&&SortAndCal(4,5)<400)
               if(SortAndCal(1,5)>600)
               {
                  GO(1);GO(3);LX++; 
               }
           if(SortAndCal(0,5)>600&&SortAndCal(4,5)>600)
               if(SortAndCal(1,5)<400)
               {
                  GO(0);if(LX!=3)GO(3);LX++; 
               } 
            if(LX==4)
            {GO(5);break;}              
       }speed_up_CNT_ms(3,226,3,600);      
}

