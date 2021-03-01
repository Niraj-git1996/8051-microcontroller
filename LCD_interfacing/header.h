

typedef unsigned char u8;
typedef signed char  s8;
typedef unsigned int u16;
typedef signed int s16;
typedef unsigned long int u32;
typedef signed long int s32;


 extern void io_write(u8 port_num,u8 pin_num,u8 val);
 extern u8 io_read(u8 port_num,u8 pin_num);
 extern void delay_ms(u8 );
   extern void lcd_cmd(u8 cmd);
	 extern void lcd_init(void);
	 extern void lcd_data(u8 dat);
	 extern void lcd_string(const char *str);
	  extern void lcd_gotoXY(u8 x,u8 y);
		extern void lcd_scroll(u8 shift);
		extern void lcd_digit(u16 num);
		extern void lcd_float(float num);
		extern void lcd_4data(u8 dat);
		extern void lcd_4init(void);
		extern void lcd_4cmd(u8 cmd);