#include <reg52.h>
sbit led1 = P1^0; //LED1.0��sbit�Ƕ������⹦�ܼĴ�����λ����

int main(void)
{
	int i,j;
	led1=0; //�ڽ��������裬�͵�ƽ����
	for(i=0;i<1000;i++) //��ʱ1s
		for(j=0;j<110;j++);
	led1=1;
	for(i=0;i<1000;i++)
		for(j=0;j<110;j++);		
	
	return 1;
}