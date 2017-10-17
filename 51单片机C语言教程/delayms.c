#include <reg52.h>
sbit led1 = P1^0;// 定义LED
void delayms(unsigned int ms);

void main(void)
{
	led1=0;
	delayms(200);//延时函数
	led1=1;
	delayms(200);
}

void delayms(unsigned int ms)//延时函数
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
		for(j=0;j<110;j++);
}