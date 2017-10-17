#include <reg52.h>
sbit led1 = P1^0; //LED1.0��sbit�Ƕ������⹦�ܼĴ�����λ����
unsigned char num;


int main(void)
{
	TMOD=0x01;		//��ʱ��0Ϊ������ʽ1
	TH0=(65536-45872)/256;		//װ��ֵ50ms��Ϊ45872
	TL0=(65536-45872)%256;
	EA=1;		//�����ж�
	ET0=1;	//��ʱ��0�ж�
	TR0=1;	//������ʱ��0
	while(1);
	return 1;
}

void T0_time(void) interrupt 1
{
	TH0=(65536-45872)/256;		//װ��ֵ50ms��Ϊ45872
	TL0=(65536-45872)%256;
	num++;
	if(num==20)
	{
		num=0;
		led1=~led1;
	}
}