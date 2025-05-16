#include <stdio.h>

sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;

sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;
sbit c4=P1^7;
 
char keypad();

char keypad()
{
	c1=1;
	c2=1;
	c3=1;
	c4=1;
	r1=0;
	r2=1;
	r3=1;
	r4=1;
	if(c1==0)
	{
		while(c1==0);
		return '7';
	}
	else if(c2==0)
	{
		while(c2==0);
		return '8';
	}
	else if(c3==0)
	{
		while(c3==0);
		return '9';
	}
	else if(c4==0)
	{
		while(c4==0);
		return '/';
	}	
	r1=1;
	r2=0;
	r3=1;
	r4=1;
	if(c1==0)
	{
		while(c1==0);
		return '4';
	}
	else if(c2==0)
	{
		while(c2==0);
		return '5';
	}
	else if(c3==0)
	{
		while(c3==0);
		return '6';
	}
	else if(c4==0)
	{
		while(c4==0);
		return '*';
	}
	r1=1;
	r2=1;
	r3=0;
	r4=1;
	if(c1==0)
	{
		while(c1==0);
	  return '1';
	}
	else if(c2==0)
	{
		while(c2==0);
		return '2';
	}
	else if(c3==0)
	{
		while(c3==0);
		return '3';
	}
	else if(c4==0)
	{
		while(c4==0);
		return '-';
	}
	r1=1;
	r2=1;
	r3=1;
	r4=0;
	if(c1==0)
	{
		while(c1==0);
		LCD_Command(0x01);
		LCD_String("clear all");
		delay(20);
		LCD_Command(0x01);
	  return 'c';//sending character c to clear the values
	}
	else if(c2==0)
	{
		while(c2==0);
		return '0';
	}
	else if(c3==0)
	{
		while(c3==0);
		return '=';
	}
	else if(c4==0)
	{
		while(c4==0);
		return '+';
	}
}