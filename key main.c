#include<stdio.h>

#include<reg51.h>

#include"LCD.h"

#include"keypad.h"

void result(char);
int c=0;
int ct=0;

void result(char d)
{
	unsigned int arr[5],i=0;
	int res;
	char op[3];
	char str[10]; 
	if(d >= '0' && d <= '9')
	{
			LCD_Data(d);
			arr[c]= arr[c]*10+(d - '0');
	}
	else if(d == '+' || d == '-' || d == '*' || d == '/')
	{
			LCD_Data(d);
			op[ct]=d;
		  ct++;
			c++;
	}
	else if(d == '=')
	{
		LCD_Data(d);
		res=arr[0];
		for(i=0;i<ct;i++)
		{
					switch(op[i])
					{
							case '+':
									res = res + arr[i+1];
									break;
							case '-':
									res = res - arr[i+1];
									break;
							case '*':
									res = res * arr[i+1];
									break;
							case '/':
								  if(arr[i+1]==0)
									{
										LCD_Command(0xC0);
										LCD_String("undefined");
										delay(20);
									}
									else
									{							
										res = res / arr[i+1];
									}

									break;
							default:
									LCD_Command(0xC0);
									LCD_String("Syntax error");
									delay(20);
									LCD_Command(0x01);
									break;
					}
			}
		if(res<0)//displaying negitive results
		{
			res=res*(-1);
			sprintf(str,"%u",res);
			LCD_Command(0xc0);
			LCD_Data('-');
			LCD_String(str);
			
		}
		else//displaying positive results
		{
			sprintf(str,"%u",res);
			LCD_Command(0xc0);
			LCD_String(str);
		}
	}
	else if(d == 'c')//clearing the operands and operators
	{
		for(i=0;i<=c;i++)
		{
			arr[i]=0;
		}
		c=0;
		for(i=0;i<=ct;i++)
		{
			op[i]=0;
		}
		ct=0;
	}
}


void main()
{
  char d=0;
	LCD_Init();
	while(1)
	{
		d = keypad();
		result(d);
	}	
}