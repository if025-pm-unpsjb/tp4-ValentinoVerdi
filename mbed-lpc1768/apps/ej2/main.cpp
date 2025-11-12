#include "mbed.h"
PwmOut led1(LED1);
PwmOut led2(LED2);
PwmOut led3(LED3);
PwmOut led4(LED4);

void cambiarIntensidad(PwmOut& led)
{
    for (float brillo = 0.0f; brillo<= 1.0f; brillo+= 0.05f)
    {
        led = brillo;
        wait_us(25000);
    }

    for (float brillo = 1.0f; brillo >= 0.0f; brillo -= 0.05f)
    {
        led = brillo;
        wait_us(25000);
    }
    led = 0.0f;
}


int main()
{
    while(1)
    {
    	cambiarIntensidad(led1);
    	cambiarIntensidad(led2);
    	cambiarIntensidad(led3);
    	cambiarIntensidad(led4);
    }
}
