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

sbit  RS=P2^0;
sbit  RW=P2^1;
sbit  EN=P2^2;

/********* FUNCTIONS  ************************************/
void lcd_4init(void);
void lcd_4cmd(u8 cmd);
void lcd_4data(u8 dat);

/*********************************************************/


void lcd_4cmd(u8 cmd)
{
	LCD_PORT=(LCD_PORT &0xF0)|(cmd & 0xF0);
	RS=0;
	RW=0;
	EN=1;
	delay_ms(2);
	EN=0;
	delay_ms(4);
	LCD_PORT=(LCD_PORT & 0xF0) | (cmd<<4);
	EN=1;
	delay_ms(2);
	EN=0;
	delay_ms(4);
}
	
void lcd_4init(void)
{
	lcd_cmd(CMD_LCD_RETURN_HOME);
	lcd_cmd(CMD_DISPLAY_ON_CURSOR_ON);
	lcd_cmd(CMD_LCD_FOUR_BIT_MODE);
	// lcd_cmd(CMD_DISPLAY_ON_CURSOR_BLINK);
}

void lcd_4data(u8 dat)
{
LCD_PORT=(LCD_PORT &0xF0)|(dat & 0xF0);
	RS=1;
	RW=0;
	EN=1;
	delay_ms(2);
	EN=0;
	delay_ms(4);
	LCD_PORT=(LCD_PORT & 0xF0) | (dat<<4);
	EN=1;
	delay_ms(2);
	EN=0;
	delay_ms(4);
}


	