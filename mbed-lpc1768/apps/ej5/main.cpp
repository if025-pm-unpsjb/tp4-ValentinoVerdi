#include "mbed.h"
#include <string>
#include <stdlib.h>

Serial pc(USBTX, USBRX);

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

char serialBuffer[10];
int bufferIndex = 0;

int main()
{
    volatile int intervalo_ms = 1000;

    while(1)
    {
        for (int i = 0; i <= 15; i++)
        {
            led1 = (i >> 0) & 1;
            led2 = (i >> 1) & 1;
            led3 = (i >> 2) & 1;
            led4 = (i >> 3) & 1;

            while (pc.readable()) {
                char c = pc.getc();
                pc.putc(c);

                if (c == '\r') {
                    pc.printf(" ");

                    serialBuffer[bufferIndex] = '\0';

                    int nuevo_intervalo = atoi(serialBuffer);

                    if (nuevo_intervalo > 0){
                        intervalo_ms = nuevo_intervalo;
                    }

                    bufferIndex = 0;

                } else if (bufferIndex < 9) {
                    serialBuffer[bufferIndex] = c;
                    bufferIndex++;
                }
            }
            wait_ms(intervalo_ms);
        }
    }
}
