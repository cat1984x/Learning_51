#include <reg52.h>
sbit led1 = P1^0;// ����LED
void delayms(unsigned int ms);

void main(void)
{
	led1=0;
	delayms(200);//��ʱ����
	led1=1;
	delayms(200);
}

void delayms(unsigned int ms)//��ʱ����
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
		for(j=0;j<110;j++);
}