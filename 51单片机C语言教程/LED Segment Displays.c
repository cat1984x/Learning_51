#include <reg52.h>
sbit SegDis1=P2^0;
sbit SegDis2=P2^1;
sbit SegDis3=P2^2;
sbit SegDis4=P2^3;

void delayms(unsigned int ms);


//单片机中RAM有限，尽量把不变的数组存在ROM中，code就是起这个作用。
//共阳极数码管，0为开启对应位置
unsigned char code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,
                        0xf8,0x80,0x90};


void main(void)
{
	int i;
	P2=0xf0;//开启全部4个数码管	
	for(i=0;i<10;i++)
	{
		P0=table[i];//显示数字
		delayms(1000);//延时1s
	}
}


void delayms(unsigned int ms)//延时函数
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
		for(j=0;j<110;j++);
}