/**********************ʵ����Գ���************************
*  ƽ̨��BST-V51 + Keil U5 + STC89C52RC
*  ���ƣ����󰴼�ʵ��
*  ���ڣ�2019-9-8
*  ������ZhangHJ
*  ˵�������󰴼����������
*				 Ч����ʵ��4X4������������ʾ
***********************************************************/
#include<reg52.h>
#include"bstv51.h"

unsigned char led[]={  //�����ַ�����
                0x3F,  //"0"
                0x06,  //"1"
                0x5B,  //"2"
                0x4F,  //"3"
                0x66,  //"4"
                0x6D,  //"5"
                0x7D,  //"6"
                0x07,  //"7"
                0x7F,  //"8"
                0x6F,  //"9"
                0x77,  //"A"
                0x7C,  //"B"
                0x39,  //"C"
                0x5E,  //"D"
                0x79,  //"E"
                0x71,  //"F"
                0x76,  //"H"
                0x38,  //"L"
                0x37,  //"n"
                0x3E,  //"u"
                0x73,  //"P"
                0x5C,  //"o"
                0x40,  //"-"
                0x00,  //Ϩ��
								};

								
/**********************************************************
*  �������ƣ��������ʾ����
*  ���ڣ�2019-9-8
*  ������ZhangHJ
*  ˵��������num��ʾ��Ҫ��ʾ���ַ�
*				 ֻ�����˶�ѡ����,û�н���λѡ����
***********************************************************/
void display(int num)
{	
	P0 = led[num];
	DU = 1;
	DU = 0;
	FM = 0;
	delay_ms(60);
	FM = 1;
}



/**********************************************************
*  �������ƣ��������ɨ�躯��
*  ���ڣ�2019-9-8
*  ������ZhangHJ
*  ˵����������Ϊ�ĸ�����,�ֱ��Ӧ���м��̵�ɨ��
*				 
***********************************************************/
void keyscan4x4()
{
	uint temp,key;
	//////////////��һ��ɨ��////////////////////
	P3 = 0xfe;								//1111 1110 ��һ��ɨ��д�ߵ�ƽ
	temp = P3;								//������ʱ�����洢P3�Ĵ�������
	temp = temp&0xf0;					//1111 1110 & 1111 0000 �൱�ڸ���λ����,����λ��0(���ε���λ����)
	if(temp != 0xf0)					//���ݷ����ı�,˵�����̿��ܱ�����
	{
		delay_ms(10);						//��ʱ����
		temp = P3;							//���¶���P3����
		temp = temp&0xf0;
		if(temp != 0xf0)
		{
			temp = P3;						//���¶�������,���ǵ���λ����
			switch(temp){
				case 0xee:
					key = 0; break;		//1110 1110
				case 0xde:
					key = 1; break;		//1101 1110
				case 0xbe:
					key = 2; break;		//1011 1110
				case 0x7e:
					key = 3; break;		//0111 1110
			}
			while(temp != 0xf0)		//���̱�����ʱ,���������ѭ����,ֱ���ɿ�����,��ִ�н������ĳ���
			{
				temp = P3;
				temp = temp&0xf0;
			}
			display(key);					//��ʾ����������
		}
	}
	
	//////////////�ڶ���ɨ��////////////////////
	P3 = 0xfd;		//1111 1101
	temp = P3;
	temp = temp&0xf0;		//1111 1101 & 1111 0000 �൱�ڸ���λ����,����λ��0
	if(temp != 0xf0)
	{
		delay_ms(10);
		temp = P3;
		temp = temp&0xf0;
		if(temp != 0xf0)
		{
			temp = P3;
			switch(temp){
				case 0xed:
					key = 4; break;		//1110 1101
				case 0xdd:
					key = 5; break;		//1101 1101
				case 0xbd:
					key = 6; break;		//1011 1101
				case 0x7d:
					key = 7; break;		//0111 1101
			}
			while(temp != 0xf0)
			{
				temp = P3;
				temp = temp&0xf0;
			}
			display(key);
		}
	}
	
	//////////////������ɨ��////////////////////
	P3 = 0xfb;		//1111 1011
	temp = P3;
	temp = temp&0xf0;		//1111 1011 & 1111 0000 �൱�ڸ���λ����,����λ��0
	if(temp != 0xf0)
	{
		delay_ms(10);
		temp = P3;
		temp = temp&0xf0;
		if(temp != 0xf0)
		{
			temp = P3;
			switch(temp){
				case 0xeb:
					key = 8; break;		//1110 1011
				case 0xdb:
					key = 9; break;		//1101 1011
				case 0xbb:
					key = 10; break;		//1011 1011
				case 0x7b:
					key = 11; break;		//0111 1011
			}
			while(temp != 0xf0)
			{
				temp = P3;
				temp = temp&0xf0;
			}
			display(key);
		}
	}
	
	//////////////������ɨ��////////////////////
	P3 = 0xf7;		//1111 0111
	temp = P3;
	temp = temp&0xf0;		//1111 0111 & 1111 0000 �൱�ڸ���λ����,����λ��0
	if(temp != 0xf0)
	{
		delay_ms(10);
		temp = P3;
		temp = temp&0xf0;
		if(temp != 0xf0)
		{
			temp = P3;
			switch(temp){
				case 0xe7:
					key = 12; break;		//1110 0111
				case 0xd7:
					key = 13; break;		//1101 0111
				case 0xb7:
					key = 14; break;		//1011 0111
				case 0x77:
					key = 15; break;		//0111 0111
			}
			while(temp != 0xf0)
			{
				temp = P3;
				temp = temp&0xf0;
			}
			display(key);
		}
	}
}


void main()
{
	bstv51_init();	//���ӳ�ʼ��
	P0 = 0x00;			//λѡ8λ,�൱����λȫ��
	WE = 1;
	WE = 0;
	
	while(1)
	{
		keyscan4x4();	//���а���ɨ��
	}
}
