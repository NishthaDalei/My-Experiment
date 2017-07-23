#include <reg51.h>
# define port P1
# define dataport P2
# define key P3
# define sec 100
sbit rs=port^0;
sbit rw=port^2;
sbit e=port^1;
sbit col1= key^4;
sbit col2= key^5;
sbit col3= key^6;
sbit row1= key^0;
sbit row2= key^1;
sbit row3= key^2;
sbit row4= key^3;
int i=0x00;
int j=0;
int x=0;
char y=1;
char arr[10];
char pwd[10]={'1','2','3','4','\0'};
void delay (unsigned int msec)
{
int i,j;
for(i=0;i<msec;i++)
for(j=0;j<1275;j++ );
}
void lcdcmd(unsigned char item)
{
dataport =item;
	rs=0;
	rw=0;
	e=1;
	delay(1);
	e=0;
}

	void lcddata(unsigned char item)
{
dataport =item;
	rs=1;
	rw=0;
	e=1;
	delay(1);
	e=0;
}
void lcdstring(unsigned char *disp)
{
int x;
	for(x=0;disp[x]!=0;x++)
	{
lcddata(disp[x]);
}

}
void save (unsigned char *disp)
{
int x;
	for(x=0;disp[x]!=0;x++)
	{
   if (pwd[x]==disp[x])
		continue;
		else
		{	y=0;
			break;
    }
	}
	if(y==1)
	{
		P0=0x00;
		delay(45);
 lcdcmd(0x01);
		lcdcmd(0x80);
		lcdstring("PWD correct");
		lcdcmd(0xC0);
		lcdstring("Door open");
		delay(300);
		lcdcmd(0x01);
		P0=0x01;
		delay(45);
}
else if(y==0)
{
lcdcmd(0x01);
	lcdcmd(0x80);
		lcdstring("PWD wrong");
		lcdcmd(0xC0);
		lcdstring("Door closed");
		delay(300);
	lcdcmd(0x01);
	y=1;
}
for(x=0;x<10;x++)
{
		arr[x]=0;
}
}
void lcd(unsigned char str[10])
{
	
		if(j<4)
	{
		arr[j]=str[0];
lcdcmd(0x38);
	lcdcmd(0x0C);
	lcdcmd(0x80+i);
	lcdstring(" * ");
	delay(100);
	i=i+3;
		j++;
}
	else if((j==4)&&(str[0]!='#'))
	{
	delay(50);
		lcdcmd(0x01);
		lcdcmd(0x80);
		lcdstring("Press PWD");
				lcdcmd(0xC0);
		lcdstring("of 4chars");
		delay(300);
		lcdcmd(0x01);
		j=0;
		i=0x00;
}
	else if	((j==4)&&(str[0]=='#'))
	{
		lcdcmd(0x01);
		lcdcmd(0x80);
		lcdstring("Saving....");
		delay(200);
		lcdcmd(0x01);
		save(arr);
		j=0;
		i=0x01;
}

	
}
void display(int a)
{
switch(a)
	{
		case 1: lcd("1");
					break;
		case 2: lcd("2");
					break;
		case 3: lcd("3");
					break;
		case 4: lcd("4");
					break;
		case 5: lcd("5");
					break;
		case 6: lcd("6");
					break;
		case 7: lcd("7");
					break;
		case 8: lcd("8");
					break;
		case 9: lcd("9");
					break;
		case 0: lcd("0");
					break;
		case 11: lcd("*");
					break;
		case 12: lcd("#");
					break;
		
}
}
void check_col1()
{
row1=row2=row3=row4=1;
	row1=0;
	
if(col1==0)
		display(1);
	row1=1;
	row2=0;
	if(col1==0)
		display(4);
	row2=1;
	row3=0;
	if(col1==0)
		display(7);
	row3=1;
	row4=0;
	if(col1==0)
		display(11);
	row4=1;
}
void check_col2()
{
row1=row2=row3=row4=1;
	row1=0;
	
if(col2==0)
		display(2);
	row1=1;
	row2=0;
	if(col2==0)
		display(5);
	row2=1;
	row3=0;
	if(col2==0)
		display(8);
	row3=1;
	row4=0;
	if(col2==0)
		display(0);
	row4=1;
}
void check_col3()
{
row1=row2=row3=row4=1;
	row1=0;
	
if(col3==0)
		display(3);
	row1=1;
	row2=0;
	if(col3==0)
		display(6);
	row2=1;
	row3=0;
	if(col3==0)
		display(9);
	row3=1;
	row4=0;
	if(col3==0)
		display(12);
	row4=1;
}
void main()
{
	
	
		col1=col2=col3=1;
	while(1)
	{
	row1=row2=row3=row4=0;
		if(col1==0)
			check_col1();
		else if(col2==0)
			check_col2();
		else if(col3==0)
			check_col3();
}
}






