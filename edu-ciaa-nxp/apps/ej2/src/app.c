#include "sapi.h"

int main( void )
{
   boardConfig();
   uartConfig( UART_USB, 115200 );

   gpioMap_t teclas[4] = { TEC1, TEC2, TEC3, TEC4 };
   gpioMap_t leds[4]   = { CIAA_BOARD_LED, LED1, LED2, LED3 };
   bool_t estadoAnterior[4] = { ON, ON, ON, ON };
   bool_t estadoActual;

   int i;

   while( TRUE ) {

      for( i = 0; i < 4; i++ ) {

         estadoActual = gpioRead( teclas[i] );

         if( estadoActual == OFF && estadoAnterior[i] == ON ) {

            gpioToggle( leds[i] );

            printf( "BOTON%d\r\n", i + 1 );

            delay(50);
         }

         estadoAnterior[i] = estadoActual;
      }

      delay(10);
   }

   return 0;
}
