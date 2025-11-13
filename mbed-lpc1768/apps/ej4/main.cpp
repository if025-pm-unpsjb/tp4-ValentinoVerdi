#include "mbed.h"
#include <map>

Serial pc(USBTX, USBRX);

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

std::map<char, DigitalOut*> ledMap;

int main()
{
    led1 = 0;
    led2 = 0;
    led3 = 0;
    led4 = 0;

    ledMap['1'] = &led1;
    ledMap['2'] = &led2;
    ledMap['3'] = &led3;
    ledMap['4'] = &led4;

    DigitalOut* activeLed = &led1;

    while(1)
    {

        if (pc.readable()) {
            char c = pc.getc();

            pc.putc(c);
            pc.printf(" ");

            if (ledMap.find(c) != ledMap.end()) {
                *activeLed = 0;
                activeLed = ledMap[c];
            }
        }
        *activeLed = !(*activeLed);

        wait_us(250000);
    }
}
