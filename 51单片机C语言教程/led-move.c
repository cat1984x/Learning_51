#include <reg52.h>

void delayms(unsigned int ms);

void main(void)
{
	unsigned char a= 0xfe;
	while(1){
		P1=a;
		delayms(200);//延时函数
		a=a<<1;//左移,不是循环左移
	}
}

void delayms(unsigned int ms)//延时函数
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
		for(j=0;j<110;j++);
}