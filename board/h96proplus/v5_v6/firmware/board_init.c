
/*
 * board/amlogic/gxb_p201_v1/firmware/board_init.c
 *
 * Copyright (C) 2015 Amlogic, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "power.c"

/* bl2 customer code */
void board_init(void)
{
	unsigned int reg;

	power_init(0);

	/* BLUE LED ON GPIOAO_9*/
	reg = readl(AO_GPIO_O_EN_N);
	reg &= ~(1 << 9);
	writel(reg, AO_GPIO_O_EN_N);

	/* RED LED OFF GPIODV_28*/
	reg = readl(PREG_PAD_GPIO0_EN_N);
	reg |= (1 << 28);
	writel(reg, PREG_PAD_GPIO0_EN_N);
}