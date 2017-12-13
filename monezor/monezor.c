/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include "inc/display.h"
#include "inc/buttons.h"

int main(void)
{
	//uint16_t 
	setup();
	oledInit();
	oledRefresh();
	
	
		
	while (1){
		
	oledClear();
	
	if (gpio_port_read(GPIOC))
	{
		oledDrawBitmap(10, 12, &bmp_logo64);
		oledDrawStringRight(120, 21, "Monezor HW");
		oledDrawStringRight(110, 35, "wallet");
		oledDrawStringRight(120, 49, "version .0.0.1");
	}
	

	if (!gpio_get(GPIOC, GPIO2))
	{
		oledClear();
		oledDrawStringRight(122, 21, "Right");	
		oledDrawStringRight(120, 35, "button");
	}
	
	if (!gpio_get(GPIOC, GPIO5))
	{
		oledClear();
		oledDrawStringRight(21, 21, "Left");	
		oledDrawStringRight(35, 35, "button");
	}
	
	
	oledRefresh();
	delay(300);
		
	}

	return 0;
}
