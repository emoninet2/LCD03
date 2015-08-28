/* 
* twi.h
*
* Created: 27-Aug-15 10:37:53 PM
* Author: emon1
*/


#ifndef __TWI_H__
#define __TWI_H__

#include <avr/io.h>

class twi
{
//variables
public:
protected:
private:

//functions
public:
	twi();
	/**
	 * initialize the twi interface
	 */
	void init();
	/**
	 * wait
	 */
	void wait();
	/**
	 * send start
	 */
	void start();
	/**
	 * send stop
	 */
	void stop();
	/**
	 * send data
	 * @param data the data byte to be sent
	 */
	void send(uint8_t data);
	/**
	 * read with ack, send ack after read is complete
	 * return data byte received
	 */
	uint8_t read_with_ack();
	/**
	 * read without ack, do not send ack after read is complete
	 * return data byte received
	 */
	uint8_t read_without_ack();
	~twi();
protected:
private:
	twi( const twi &c );
	twi& operator=( const twi &c );

}; //twi

#endif //__TWI_H__
