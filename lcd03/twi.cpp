/* 
* twi.cpp
*
* Created: 27-Aug-15 10:37:53 PM
* Author: emon1
*/


#include "twi.h"

// default constructor
twi::twi()
{
} //twi
void twi::init(){
	TWBR = 32;
}
void twi::wait(){
	while(!(TWCR&(1<<TWINT)));
}
void twi::start(){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
}
void twi::stop(){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}
void twi::send(uint8_t data){
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	wait();
	
}
uint8_t twi::read_with_ack(){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	wait();
	return TWDR;
}
uint8_t twi::read_without_ack(){
	TWCR = (1<<TWINT) | (1<<TWEN) ;
	wait();
	return TWDR;
}
// default destructor
twi::~twi()
{
} //~twi
