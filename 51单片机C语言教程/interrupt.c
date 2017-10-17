#include <reg52.h>
sbit led1 = P1^0; //LED1.0，sbit是定义特殊功能寄存器的位变量
unsigned char num;


int main(void)
{
	TMOD=0x01;		//定时器0为工作方式1
	TH0=(65536-45872)/256;		//装初值50ms数为45872
	TL0=(65536-45872)%256;
	EA=1;		//开总中断
	ET0=1;	//定时器0中断
	TR0=1;	//启动定时器0
	while(1);
	return 1;
}

void T0_time(void) interrupt 1
{
	TH0=(65536-45872)/256;		//装初值50ms数为45872
	TL0=(65536-45872)%256;
	num++;
	if(num==20)
	{
		num=0;
		led1=~led1;
	}
}