/*
 * LCD03Port.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: emon1
 */

#include "../LCD03Port.h"
#include "../LCD03PortConfig.h"


#if (LCD03Port_mbed == 1)

#include "mbed.h"


Serial _lcd_uart(PA_9, PA_10); // tx, rx

LCD03Port::LCD03Port() {
	// TODO Auto-generated constructor stub

}

LCD03Port::~LCD03Port() {
	// TODO Auto-generated destructor stub
}

int LCD03Port::portSerialInit(){

	

}
int LCD03Port::portSerialTransmit(uint8_t data){
	_lcd_uart.putc(data);
}


int LCD03Port::portI2CInit(){
	

}
int LCD03Port::portI2CTransmit(uint8_t data){
	
}

#endif


