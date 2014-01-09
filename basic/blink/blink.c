#include "blink.h"
#include "bcm2835.h"

#define BLINK_PIN	RPI_V2_GPIO_P1_11

int blink_init(void)
{
	if(!bcm2835_init())
		return 0;
	bcm2835_gpio_fsel(BLINK_PIN, BCM2835_GPIO_FSEL_OUTP);
	return 1;
}

void blink_start(float fre,int times)
{
	unsigned int ms = 0;
	ms = 1/fre*1000;
	
	while(times--)
	{
		bcm2835_gpio_write(BLINK_PIN,1);
		bcm2835_delay(ms);
		bcm2835_gpio_write(BLINK_PIN,0);
		bcm2835_delay(ms);
	}
}

void blink_end(void)
{
	bcm2835_close();
}
