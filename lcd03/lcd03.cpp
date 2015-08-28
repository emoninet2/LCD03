/* 
* lcd03.cpp
*
* Created: 27-Aug-15 11:05:39 AM
* Author: emon1
*/


#include "lcd03.h"
#include "twi.h"

// default constructor
lcd03::lcd03(COMM_MODE_t mode,LCD_SIZE_t type,LCD03_I2C_ADDRESS_t addr)
{
	
	
	if(mode == LCD03_I2C){
		psend = &lcd03::send_via_i2c;
		lcd03_twi.init();
	}
	else if (mode == LCD03_SERIAL){
		psend = &lcd03::send_via_serial;
	}
} //lcd03
void lcd03::send_via_i2c(uint8_t data){
	lcd03_twi.start();
	lcd03_twi.wait();
	lcd03_twi.send(i2c_addr);
	lcd03_twi.wait();
	lcd03_twi.send(0);
	lcd03_twi.wait();
	lcd03_twi.send(data);
	lcd03_twi.wait();
	lcd03_twi.send(0);
	lcd03_twi.stop();
	
}
void lcd03::send_via_serial(uint8_t data){}
void lcd03::send_command(LCD03_COMMAND_t cmd){
	(this->*psend) (cmd);
}
void lcd03::send_data(uint8_t data){
	(this->*psend) (data);
}
void lcd03::cursor_home(){
	send_command(LCD03_CMD_CURSOR_HOME);
}
void lcd03::set_cursor_pos(uint8_t pos){
	send_command(LCD03_CMD_SET_CURSOR_POS);
}
void lcd03::set_cursor_coordinate(uint8_t line, uint8_t col){
	send_command(LCD03_CMD_SET_CURSOR_COORDINATE);
}
void lcd03::cursor_display_mode(LCD03_CURSOR_DISP_t mode){
	switch(mode){
		case 	LCD03_CURSOR_HIDE		:	send_command(LCD03_CMD_HIDE_CURSOR);break;
		case	LCD03_CURSOR_UNDERLINE	:	send_command(LCD03_CMD_SHOW_UNDERLINE_CURSOR);break;
		case	LCD03_CURSOR_BLINKING	:	send_command(LCD03_CMD_SHOW_BLINKING_CURSOR);break;
		default							:	break;
	}
}
void lcd03::backspace(){
	send_command(LCD03_CMD_BACKSPACE);
}
void lcd03::tab(){
	send_command(LCD03_CMD_HORIZONTAL_TAB);
}
void lcd03::smart_line_feed(){
	send_command(LCD03_CMD_SMART_LINE_FEED);
}
void lcd03::vertical_tab(){
	send_command(LCD03_CMD_VERTICAL_TAB);
}
void lcd03::clear_screen(){
	send_command(LCD03_CMD_CLEAR_SCREEN);
}
void lcd03::carriage_return(){
	send_command(LCD03_CMD_CARRIAGE_RETURN);
}
void lcd03::clear_column(){
	send_command(LCD03_CMD_CLEAR_COLUMN);
}
void lcd03::tab_set_size(uint8_t size){
	send_command(LCD03_CMD_TAB_SET);
	send_data(size);
}
void lcd03::backlight(bool mode){
	if(mode) {send_command(LCD03_CMD_BACKLIGHT_ON);}
	else {send_command(LCD03_CMD_BACKLIGHT_OFF);}
}
void lcd03::startup_message_mode(bool mode){
	if(mode) {send_command(LCD03_CMD_ENABLE_STARTUP_MESSAGE);}
	else {send_command(LCD03_CMD_DISABLE_STARTUP_MESSAGE);}
}
void lcd03::change_i2c_addr(LCD03_I2C_ADDRESS_t addr){
	if(psend == (&lcd03::send_via_i2c)){
		send_command(LCD03_CMD_CHANGE_ADDRESS);
		send_data(0xA0);
		send_data(0xAA);
		send_data(0xA5);
		send_data(addr);
	}
}
uint8_t lcd03::get_fifo_status(){}
uint8_t lcd03::get_software_version(){}
void lcd03::custom_char_ger(){}



// default destructor
lcd03::~lcd03()
{
} //~lcd03
