#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int main()
{
	while(1)
	    {
	        for (int i = 0; i <= 15; i++)
	        {
	            led1 = (i >> 0) & 1;
	            led2 = (i >> 1) & 1;
	            led3 = (i >> 2) & 1;
	            led4 = (i >> 3) & 1;
	            wait_us(1000000);
	        }
	    }
}
