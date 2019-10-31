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
    printf("AT+RST\r\n");//��λ
    delay_ms(300);
    printf("AT+CWMODE=2\r\n");//ģʽ2��AP
    delay_ms(1000);
    printf("AT+CWSAP=\"655666565\",\"12345678\",11,3\r\n");//������ģ�鷢����WIFI
    delay_ms(1800);
    printf("AT+CIPSTART=\"TCP\",\"192.168.4.2\",8080\r\n");//��дҪ���ӵ��ֻ���ַ���˿�
    delay_ms(1800);
    printf("AT+CIPMODE=1\r\n");//����͸��ģʽ
    delay_ms(1001);
    printf("AT+CIPSEND\r\n");//��·����
    delay_ms(1001);
   printf("��ʼ����\r\n");
}
int main(void)
{   int LX=0;//����
    delay_init();	    	 //��ʱ������ʼ��
    infrared_INIT();         //����˿ڳ�ʼ��
    uart_init(115200);	     //���ڳ�ʼ��Ϊ115200
    TIM2_Int_Init(12,10);    //TIM2��ʼ��
    TIM6_Int_Init(999,71);   //TIM6��ʼ��
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
    //WIFI_INIT();//wifiģ���ʼ��     
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

