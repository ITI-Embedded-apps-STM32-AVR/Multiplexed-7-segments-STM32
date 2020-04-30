// libs
#include "STD_TYPES.h"
#include "BIT_MAN.h"
#include "Delay_interface.h"
// MCAL
#include "RCC_interface.h"
#include "DIO_interface.h"
// HAL
#include "SevenSeg_interface.h"

#define PORT_SEG 'A'
#define PIN_EN1   8
#define PIN_EN2   9

void main(void)
{
	/* init clocks */
	RCC_init();

	/* set PLL config: source = HSE, multiplication = 9, HSE/2 = no */
	/* SysClock now = 72MHz */
	RCC_setClockState(RCC_CLOCK_HSE, 1);
	RCC_setPLLsource(RCC_PLL_SOURCE_HSE);
	RCC_setPLLmul(RCC_PLL_MUL9);
	RCC_setPLLHSEdiv2(0);
	RCC_changeSysClock(RCC_CLOCK_PLL);
	RCC_setClockState(RCC_CLOCK_HSI, 0);

	/* enable clock on port A */
	RCC_setPeripheralClock(RCC_BUS_APB2, RCC_PERI_GPIOA, 1);

	/* set pins A0-6,7,8,9 mode to output push-pull 10MHz */
	for (u8 i = 0 ; i < 10; i++)
	{
		DIO_setPinMode(PORT_SEG, i, DIO_PIN_MODE_OUT_PUSH_PULL_10MHZ);
	}

	/* configure delay function */
	delay_setCPUclockFactor(72000000);

	/* disable both 7-seg */
	SevenSeg_disable(1);
	SevenSeg_disable(2);

	u8 up    = 5;
	u8 down  = 5;
	u16 time = 0;

	while (1)
	{
		/* up counter */
		SevenSeg_disable(1);
		SevenSeg_disable(2);

		SevenSeg_setNum(up, 1);

		SevenSeg_enable(1);
		delay_ms(5);

		/* down counter */
		SevenSeg_disable(1);
		SevenSeg_disable(2);

		SevenSeg_setNum(down, 2);

		SevenSeg_enable(2);
		delay_ms(5);

		time +=10;

		if (time >= 1000)
		{
			time = 0;

			if (up == 9)
			{
				up = 0;
			}
			else
			{
				up++;
			}

			if (down == 0)
			{
				down = 9;
			}
			else
			{
				down--;
			}
		}
	}
}
