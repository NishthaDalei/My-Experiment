#include<reg51.h>
sbit sw=P1^4;

delay_ms(int time)
{
int i,j;
for(i=0;i<time;i++)
for(j=0;j<1275;j++);
}
void main ()
{
	int c=0;
char num[]={0x40,0x79,0X24,0X30,0X19,0X12,0X02,0x78,0x00,0x18 };
	
	while(1)
	{
		if(c>=10)
			c=0;
		P2=num[c];
			delay_ms(50);
	if(sw==0)
	{
		c++;
}
}
	
}