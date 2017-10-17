#include <reg52.h>
sbit led1 = P1^0; //LED1.0��sbit�Ƕ������⹦�ܼĴ�����λ����
sbit tens_seg=P2^0;//ʮλ
sbit units_seg=P2^1;//��λ

unsigned int num=0;
unsigned int num_sec=0;
unsigned int sec=0;


//��Ƭ����RAM���ޣ������Ѳ�����������ROM�У�code������������á�
//����������ܣ�0Ϊ������Ӧλ��
unsigned char code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,
                        0xf8,0x80,0x90};

void display(unsigned int sec);
void delayms(unsigned int ms);
												
void main(void)
{
	TMOD=0x11;		//��ʱ��0��1Ϊ������ʽ1
	TH0=(65536-45872)/256;		//װ��ֵ50ms��Ϊ45872
	TL0=(65536-45872)%256;
	TH1=(65536-45872)/256;		//װ��ֵ50ms��Ϊ45872
	TL1=(65536-45872)%256;
	EA=1;		//�����ж�
	ET0=1;	//��ʱ��0�ж�
	ET1=1;	//��ʱ��1�ж�
	TR0=1;	//������ʱ��0
	TR1=1;	//������ʱ��1
	
	while(1)
		display(sec);
}

void display(unsigned int sec)//��ʾʱ�亯��
{
	unsigned int tens,units;
	tens=sec/10;
	units=sec%10;	
	
	P0=table[tens];//��ʾʮλ
	tens_seg=0;//0Ϊ��
	delayms(1);//��ʱ1s
	tens_seg=1;//1Ϊ��

	P0=table[units];//��ʾ��λ
	units_seg=0;//0Ϊ��
	delayms(1);//��ʱ1s
	units_seg=1;//1Ϊ��
}

void delayms(unsigned int ms)//��ʱ����
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
		for(j=0;j<110;j++);
}


void T0_time(void) interrupt 1 //��ʱ��0ʵ��led1��200ms��˸��
{
	TH0=(65536-45872)/256;		//װ��ֵ50ms��Ϊ45872
	TL0=(65536-45872)%256;
	num++;
	if(num==4)
	{
		num=0;
		led1=~led1;
	}
}


void T1_time(void) interrupt 3 //��ʱ��0ʵ�ּ�ʱ��
{
	TH1=(65536-45872)/256;		//װ��ֵ50ms��Ϊ45872
	TL1=(65536-45872)%256;
	num_sec++;
	if(num_sec==5)
	{
		num_sec=0;//Ҫ��num_sec���㣬��ʼ��������Ȼ��ͣס����
		sec++;
		if(sec==60)
			sec=0;
	}
}


