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
	while(1)//��̬ɨ�裬ͬʱ��ʾ4�������
		{
			P0=table[1];//��ʾ����
			SegDis1=0;//0Ϊ��
			delayms(1);//��ʱ1s
			SegDis1=1;//1Ϊ��

			P0=table[2];//��ʾ����
			SegDis2=0;//0Ϊ��
			delayms(1);//��ʱ1s
			SegDis2=1;//1Ϊ��

			P0=table[3];//��ʾ����
			SegDis3=0;//0Ϊ��
			delayms(1);//��ʱ1s
			SegDis3=1;//1Ϊ��

			P0=table[4];//��ʾ����
			SegDis4=0;//0Ϊ��
			delayms(1);//��ʱ1s
			SegDis4=1;//1Ϊ��
		}
}


void delayms(unsigned int ms)//��ʱ����
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
		for(j=0;j<110;j++);
}