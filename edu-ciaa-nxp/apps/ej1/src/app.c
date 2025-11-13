#include "app.h"
#include "sapi.h"
#include "string.h"

#define BUFFER_SIZE 100

int main( void )
{
    boardConfig();

    uartConfig( UART_USB, 115200 );

    char buffer[BUFFER_SIZE];
    uint8_t datoRecibido;
    int indice = 0;

    while( TRUE ) {

        if( uartReadByte( UART_USB, &datoRecibido ) ) {

            uartWriteByte( UART_USB, datoRecibido );

            if( indice < BUFFER_SIZE - 1 ) {
                buffer[indice] = datoRecibido;
                indice++;
            }

            if( datoRecibido == '\n' || datoRecibido == '\r' ) {

                buffer[indice] = '\0';

                uartWriteString( UART_USB, "\r\n" );
                uartWriteString( UART_USB, buffer );
                uartWriteString( UART_USB, "\r\n" );

                indice = 0;
            }
        }
    }
}
