#include<reg52.h>

sbit led0 = P1^0;			//����8������λ�������ֱ��ʾ8��LED
sbit led1 = P1^1;
sbit led2 = P1^2;
sbit led3 = P1^3;
sbit led4 = P1^4;
sbit led5 = P1^5;
sbit led6 = P1^6;
sbit led7 = P1^7;

int main()
{
		while(1)
		{
				P1 = 0xe6;	//λ������ͬʱ�ı��λ��� 1110 0110  LED0��LED3��LED4��
				led6 = 0;		//LED6��
				led7 = 0;		//LED7��
		}
}