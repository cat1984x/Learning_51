#include <reg52.h >
sbit  LED1 = P1^0;//按位操作1
sbit  LED3 = P1^2;//按位操作3
sbit  LED5 = P1^4;//按位操作5
sbit  LED7 = P1^6;//按位操作7

void main(){
	LED1 = 0; //按位操作1  
	LED3 = 0; //按位操作3
	LED5 = 0; //按位操作5  
	LED7 = 0; //按位操作7
//	P1=0xfe; //总线操作1
//	P1=0xfb; //总线操作3
}
