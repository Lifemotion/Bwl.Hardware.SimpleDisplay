#define DEV_NAME "SimpleDisplay1.0"

#include "board/board.h"
#include "refs-avr/winstar1602.h"
#include "refs-avr/bwl_strings.h"

#include "sserial.h"
#include "adc.h"

void show_device_info()
{
	string_clear();
	string_add_string(DEV_NAME);
	lcd_stringbuffer_to_linebuffer(0);
	lcd_writebuffer();
}

void board_init()
{
	power_internal(0);
	var_delay_ms(500);
	power_internal(1);
	get_button_1();
	get_button_2();
	get_button_3();
	get_button_4();
}

int main(void)
{
	wdt_enable(WDTO_8S);
	board_init();
	sserial_init();
	lcd_init();
	show_device_info();
	while(1)
	{
		if (get_button_1()) {lcd_string_to_linebuffer("Button 1"); lcd_writebuffer();}
		if (get_button_2()) {lcd_string_to_linebuffer("Button 2"); lcd_writebuffer();}
		if (get_button_3()) {lcd_string_to_linebuffer("Button 3"); lcd_writebuffer();}
		if (get_button_4()) {lcd_string_to_linebuffer("Button 4"); lcd_writebuffer();}
		wdt_reset();
		sserial_poll_uart(0);
	}
}