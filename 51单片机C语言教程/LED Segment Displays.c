#include <reg52.h>
sbit SegDis1=P2^0;
sbit SegDis2=P2^1;
sbit SegDis3=P2^2;
sbit SegDis4=P2^3;

void delayms(unsigned int ms);


//��Ƭ����RAM���ޣ������Ѳ�����������ROM�У�code������������á�
//����������ܣ�0Ϊ������Ӧλ��
unsigned char code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,
                        0xf8,0x80,0x90};


void main(void)
{
	int i;
	P2=0xf0;//����ȫ��4�������	
	for(i=0;i<10;i++)
	{
		P0=table[i];//��ʾ����
		delayms(1000);//��ʱ1s
	}
}


void delayms(unsigned int ms)//��ʱ����
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
		for(j=0;j<110;j++);
}