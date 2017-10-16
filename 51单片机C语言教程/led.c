#include <reg52.h>
sbit led1 = P1^0; //LED1.0，sbit是定义特殊功能寄存器的位变量

int main(void)
{
	led1=0; //内接上拉电阻，低电平点亮
	return 1;
}