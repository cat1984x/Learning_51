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
	while(1)//动态扫描，同时显示4个数码管
		{
			P0=table[1];//显示数字
			SegDis1=0;//0为开
			delayms(1);//延时1s
			SegDis1=1;//1为关

			P0=table[2];//显示数字
			SegDis2=0;//0为开
			delayms(1);//延时1s
			SegDis2=1;//1为关

			P0=table[3];//显示数字
			SegDis3=0;//0为开
			delayms(1);//延时1s
			SegDis3=1;//1为关

			P0=table[4];//显示数字
			SegDis4=0;//0为开
			delayms(1);//延时1s
			SegDis4=1;//1为关
		}
}


void delayms(unsigned int ms)//延时函数
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
		for(j=0;j<110;j++);
}