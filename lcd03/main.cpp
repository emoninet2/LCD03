/*
 * lcd03.cpp
 *
 * Created: 27-Aug-15 10:32:42 PM
 *  Author: emon1
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "twi.h"
#include "lcd03.h"

int main(void)
{
	twi lcd03_twi;
	
	lcd03_twi.init();
	
	lcd03 mylcd(LCD03_I2C,LCD03_20_4,LCD03_I2C_ADDRESS_0xc8) ;
	
	mylcd.clear_screen();
	
	
	mylcd.print_string("my name is emon and i am awesome and i am testing this message on the lcd  ",80);
	
	
    while(1)
    {
// 		
			mylcd.backlight(false);
			_delay_ms(1000);
			mylcd.backlight(true);
			_delay_ms(1000);
// 		
//         	mytwi.start();
//         	mytwi.wait();
//         	mytwi.send(0xc8);
//         	mytwi.wait();
//         	mytwi.send(0);
//         	mytwi.wait();
//         	mytwi.send(0x13);
//         	mytwi.wait();
//         	mytwi.send(0);
//         	mytwi.stop();
// 			
// 			_delay_ms(200);
// 			
// 			mytwi.start();
// 			mytwi.wait();
// 			mytwi.send(0xc8);
// 			mytwi.wait();
// 			mytwi.send(0);
// 			mytwi.wait();
// 			mytwi.send(0x14);
// 			mytwi.wait();
// 			mytwi.send(0);
// 			mytwi.stop();
// 				
// 			_delay_ms(200);
    }
}