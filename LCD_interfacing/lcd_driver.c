#include <reg51.h>
#include "header.h"
/****************MACROS  **********************/
#define ON 1
#define OFF 0
#define CMD_LCD_CLEAR                0x01u
#define CMD_LCD_RETURN_HOME          0x02u
#define CMD_DISPLAY_ON_CURSOR_OFF    0x0Cu
#define CMD_DISPLAY_ON_CURSOR_ON     0x0Eu
#define CMD_DISPLAY_ON_CURSOR_BLINK  0x0Fu
#define CMD_LCD_FOUR_BIT_MODE        0x28u
#define CMD_LCD_EIGHT_BIT_MODE       0x38u
#define CMD_LCD_FIRST_LINE           0x80u
#define CMD_LCD_SECOND_LINE          0xC0u
#define CMD_SHIFT_DISPLAY_RIGHT      0x05u
#define CMD_SHIFT_DISPLAY_LEFT       0x07u
#define LCD_PORT                      P0
/***********************************************************/
sbit RS=P2^0;
sbit 	RW=P2^1;
sbit EN=P2^2;


/************************FUNCTIONS  *************************/
void lcd_init(void);
void lcd_cmd(u8 cmd);
void lcd_data(u8 dat);
void  lcd_string(const char *msg);
void lcd_gotoXY(u8 x,u8 y);
void lcd_scroll(u8 shift);
void lcd_digit(u16 num);
/*************************************************************/
void lcd_cmd(u8 cmd)
{
	RS=0;
	LCD_PORT=cmd;
	RW=0;
	EN=1;
	delay_ms(2);
	EN=0;
}

void lcd_data(u8 dat)
{
		RS=1;
	LCD_PORT=dat;
	RW=0;
	EN=1;
	delay_ms(2);
	EN=0;
}

void lcd_init(void)
{
	lcd_cmd(CMD_LCD_CLEAR);
	lcd_cmd(CMD_LCD_EIGHT_BIT_MODE);
//	lcd_cmd(CMD_DISPLAY_ON_CURSOR_ON);
lcd_cmd(CMD_DISPLAY_ON_CURSOR_BLINK);
	lcd_cmd(CMD_LCD_FIRST_LINE);
}


void lcd_string(const char *str)
{
	while(*str!='\0')
	{
		lcd_data(*str);
		str++;
	}
}

void lcd_gotoXY(u8 x,u8 y)
{
	if(x==1)
	{
		if(y>0 && y<16)
			lcd_cmd(0x80+y);
		
	}
	else if(x==2)
	{
		if(y>0 && y<16)
			 lcd_cmd(0xC0+y);
		
	}
}

void lcd_scroll(u8 shift)
{
	u8 i;
	for(i=0;i<shift;i++)
	{
		lcd_cmd(0x18); // shift the entire display to left  side 
		delay_ms(200);
	}
}

void lcd_digit(u16 num)
{
	u16 temp;
	u16 sd[6]={0};
  u16 j=0;
   while(num!=0)
	 {
		 temp=num%10;
		 sd[j]=temp;
		 num=num/10;
		 j++;
	 }
	 while(j--)
	 {
		 lcd_data(0x30+sd[j]);
	 }
 }
 
 
 void lcd_float(float num)
 {
	 u32 temp;
	 temp=(u32) num;
	   lcd_digit(temp);
	 lcd_data('.');
	 num=num-temp;
	 temp=num*1000;
	 lcd_digit(temp);
 }
 


