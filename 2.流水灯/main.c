/**********************ʵ����Գ���************************
*  ƽ̨��BST-V51 + Keil U5 + STC89C52RC
*  ���ƣ���ˮ��ʵ��
*  ���ڣ�2019-9-7
*  ������ZhangHJ
***********************************************************/
#include<reg52.h>
#include<intrins.h>
#define ON 0
#define OFF 1
#define DELAYTIME 100		//��ʱʱ��

//�ֱ���8λLEDλ
sbit led0 = P1^0;
sbit led1 = P1^1;
sbit led2 = P1^2;
sbit led3 = P1^3;
sbit led4 = P1^4;
sbit led5 = P1^5;
sbit led6 = P1^6;
sbit led7 = P1^7;


/**********************************************************
*  �������ƣ��;�����ʱ����
*  ���ڣ�2019-9-7
*  ������ZhangHJ
*  ˵����Ƕ��ѭ����ʱ
***********************************************************/
void delay_ms(unsigned int mstime)
{
	int i,j;
	for(i=mstime; i>=0; i--)
		for(j=112; j>=0; j--);
}



/**********************************************************
*  �������ƣ�λ������ˮ�ƺ���
*  ���ڣ�2019-9-7
*  ������ZhangHJ
*  ˵�������ηֱ��������ʱ8��LED
***********************************************************/
liushui_fun1(void)
{
	while(1)
	{
		led0 = ON;
		delay_ms(DELAYTIME);
		led0 = OFF;
		
		led1 = ON;
		delay_ms(DELAYTIME);
		led1 = OFF;
		
		led2 = ON;
		delay_ms(DELAYTIME);
		led2 = OFF;
		
		led3 = ON;
		delay_ms(DELAYTIME);
		led3 = OFF;

		led4 = ON;
		delay_ms(DELAYTIME);
		led4 = OFF;
		
		led5 = ON;
		delay_ms(DELAYTIME);
		led5 = OFF;

		led6 = ON;
		delay_ms(DELAYTIME);
		led6 = OFF;
		
		led7 = ON;
		delay_ms(DELAYTIME);
		led7 = OFF;
	}
}



/**********************************************************
*  �������ƣ���λ��ʽ��ˮ�ƺ���
*  ���ڣ�2019-9-7
*  ������ZhangHJ
*  ˵����P1ѭ����λ8��,Ȼ��ʹP1��ʼ��������ѭ��
***********************************************************/
liushui_fun2()
{
	int i = 0;
	while(1)
	{
		P1 = 0xfe;				//1111 1110 LED0��
		for(i=0; i<8; i++)
		{
			delay_ms(DELAYTIME);
			P1 <<= 1;				//P1����һλ
			P1 = P1|0x01;		//��֤P1���һλΪ 1
		}
	}
}



/**********************************************************
*  �������ƣ�ѭ����λ��ʽ��ˮ�ƺ���
*  ���ڣ�2019-9-7
*  ������ZhangHJ
*  ˵����ʹ��_crol_����,ʹP1ѭ����λ(��������������)
***********************************************************/
liushui_fun3()
{
	P1 = 0Xfe;							//��ʼ��LED0��
	while(1)
	{
		delay_ms(DELAYTIME);
		P1 = _crol_(P1,1);		//P1ѭ������1λ
	}
}

int main()
{
	//�ֱ�����ַ�ʽ���в���
	//liushui_fun1();
	//liushui_fun2();
	liushui_fun3();
	return 0;
}
