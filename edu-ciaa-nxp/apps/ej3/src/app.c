#include "sapi.h"

int main( void )
{
   boardConfig();
   uartConfig( UART_USB, 115200 );

   bool_t estadoRojo  = OFF;
   bool_t estadoVerde = OFF;
   bool_t estadoAzul  = OFF;
   bool_t estadoMaestro = ON;
   bool_t tec1_ant = ON, tec2_ant = ON, tec3_ant = ON, tec4_ant = ON;
   bool_t tec1_act, tec2_act, tec3_act, tec4_act;

   while( TRUE ) {
      tec1_act = gpioRead( TEC1 );
      tec2_act = gpioRead( TEC2 );
      tec3_act = gpioRead( TEC3 );
      tec4_act = gpioRead( TEC4 );

      if( tec1_act == OFF && tec1_ant == ON ) {
         estadoMaestro = !estadoMaestro;
         if (estadoMaestro == ON) {
             printf( "RGB: ON\r\n" );
         } else {
             printf( "RGB: OFF\r\n" );
         }
         delay(50);
      }

      if( tec2_act == OFF && tec2_ant == ON ) {
         estadoRojo = !estadoRojo;
         printf( "Rojo: %d\r\n", estadoRojo );
         delay(50);
      }

      if( tec3_act == OFF && tec3_ant == ON ) {
         estadoVerde = !estadoVerde;
         printf( "Verde: %d\r\n", estadoVerde );
         delay(50);
      }

      if( tec4_act == OFF && tec4_ant == ON ) {
         estadoAzul = !estadoAzul;
         printf( "Azul: %d\r\n", estadoAzul );
         delay(50);
      }

      tec1_ant = tec1_act;
      tec2_ant = tec2_act;
      tec3_ant = tec3_act;
      tec4_ant = tec4_act;

      gpioWrite( LEDR, estadoRojo  && estadoMaestro );
      gpioWrite( LEDG, estadoVerde && estadoMaestro );
      gpioWrite( LEDB, estadoAzul  && estadoMaestro );

      delay(10);
   }

   return 0;
}
