#include <reg52.h >
sbit  LED1 = P1^0;//��λ����1
sbit  LED3 = P1^2;//��λ����3
sbit  LED5 = P1^4;//��λ����5
sbit  LED7 = P1^6;//��λ����7

void main(){
	LED1 = 0; //��λ����1  
	LED3 = 0; //��λ����3
	LED5 = 0; //��λ����5  
	LED7 = 0; //��λ����7
//	P1=0xfe; //���߲���1
//	P1=0xfb; //���߲���3
}
