#include <stdio.h>

sfr LCD_Port=0xB0;
sbit rs=P3^0;
sbit en=P3^1;
 
void delay(unsigned int);

void LCD_Command(char);

void LCD_Data(char);

void LCD_String(char *str);

void LCD_Init(void);

void delay(unsigned int count)
{
   int i,j;
   for(i=0;i<count;i++)
   {
      for(j=0;j<922;j++); //provides us a delay of 1ms
   }
}
 
void LCD_Command(char cmd)
{
	 LCD_Port = cmd;
   rs=0;
   en=1;
   delay(1);
   en=0;
   delay(1);
}

void LCD_Data(char cmd)
{
	 LCD_Port = cmd;
   rs=1;
   en=1;
   delay(1);
   en=0;
   delay(1);
}

void LCD_String(char *str)
{
   int i;
   for(i=0;str[i]!=0;i++)
   {
      LCD_Data(str[i]);
   }
}
void LCD_Init()
{
   delay(20);
   //LCD_Command(0x02);
   LCD_Command(0x38);		//Command to set 8bit and 2 line
   LCD_Command(0x0E);		//command Fisplay on and cusor blinking
   LCD_Command(0x06);		//entry mode set
   LCD_Command(0x01);		//Clear disly
   LCD_Command(0x80);		//set to position to 0
}
 