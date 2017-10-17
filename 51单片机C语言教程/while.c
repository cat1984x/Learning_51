#include <reg52.h>
sbit led1 = P1^0; //LED1.0，sbit是定义特殊功能寄存器的位变量

int main(void)
{
	int i,j;
	led1=0; //内接上拉电阻，低电平点亮
	for(i=0;i<1000;i++) //延时1s
		for(j=0;j<110;j++);
	led1=1;
	for(i=0;i<1000;i++)
		for(j=0;j<110;j++);		
	
	return 1;
}