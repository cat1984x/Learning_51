#include <reg52.h>
sbit led1 = P1^0; //LED1.0��sbit�Ƕ������⹦�ܼĴ�����λ����

int main(void)
{
	led1=0; //�ڽ��������裬�͵�ƽ����
	return 1;
}