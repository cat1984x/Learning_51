#include <reg52.h>
sbit led1 = P1^0; //LED1.0，sbit是定义特殊功能寄存器的位变量
sbit tens_seg=P2^0;//十位
sbit units_seg=P2^1;//各位

unsigned int num=0;
unsigned int num_sec=0;
unsigned int sec=0;


//单片机中RAM有限，尽量把不变的数组存在ROM中，code就是起这个作用。
//共阳极数码管，0为开启对应位置
unsigned char code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,
                        0xf8,0x80,0x90};

void display(unsigned int sec);
void delayms(unsigned int ms);
												
void main(void)
{
	TMOD=0x11;		//定时器0、1为工作方式1
	TH0=(65536-45872)/256;		//装初值50ms数为45872
	TL0=(65536-45872)%256;
	TH1=(65536-45872)/256;		//装初值50ms数为45872
	TL1=(65536-45872)%256;
	EA=1;		//开总中断
	ET0=1;	//定时器0中断
	ET1=1;	//定时器1中断
	TR0=1;	//启动定时器0
	TR1=1;	//启动定时器1
	
	while(1)
		display(sec);
}

void display(unsigned int sec)//显示时间函数
{
	unsigned int tens,units;
	tens=sec/10;
	units=sec%10;	
	
	P0=table[tens];//显示十位
	tens_seg=0;//0为开
	delayms(1);//延时1s
	tens_seg=1;//1为关

	P0=table[units];//显示个位
	units_seg=0;//0为开
	delayms(1);//延时1s
	units_seg=1;//1为关
}

void delayms(unsigned int ms)//延时函数
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
		for(j=0;j<110;j++);
}


void T0_time(void) interrupt 1 //定时器0实现led1以200ms闪烁。
{
	TH0=(65536-45872)/256;		//装初值50ms数为45872
	TL0=(65536-45872)%256;
	num++;
	if(num==4)
	{
		num=0;
		led1=~led1;
	}
}


void T1_time(void) interrupt 3 //定时器0实现计时间
{
	TH1=(65536-45872)/256;		//装初值50ms数为45872
	TL1=(65536-45872)%256;
	num_sec++;
	if(num_sec==5)
	{
		num_sec=0;//要把num_sec清零，开始计数，不然会停住不动
		sec++;
		if(sec==60)
			sec=0;
	}
}


