/* io_driver.c */
#include <reg51.h>

#include "header.h"



void io_write(unsigned char port_num,unsigned char pin_num,unsigned char val)
{
	//unsigned char g;
   	switch(port_num)
	{
		case 0:
		          if(val==1)
                 P0|=(1<<pin_num);
               else
                 P0&=~(1<<pin_num);
                 break;							 
		case 1:
		             if(val==1)
                    P1|=(1<<pin_num);
                  else
                     P1&=~(1<<pin_num);										
		              break;
		case 2:
			           if(val==1)
                    P2|=(1<<pin_num);
                  else
                     P2&=~(1<<pin_num);										
		              break;
		
		case 3:
			      if(val==1)
                    P3|=(1<<pin_num);
                  else
                     P3&=~(1<<pin_num);										
		              break;
		
	}
}