/*
Example for Lin_Hall Click

    Date          : Sep 2018.
    Author        : Nenad Filipovic

Test configuration TIVA :
    
    MCU              : TM4C129XNCZAD
    Dev. Board       : EasyMx PRO v7 for TIVA ARM
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes SPI and LOG structures, set CS (chip select) pin as output.
- Application Initialization - Initialization driver enable's - SPI and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of Lin Hall Click board.
     Read 12-bit ADC value from the MCP3201 chip.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart for aproximetly every 100 ms when the ADC value changes.

Additional Functions :

- UART
- Conversions

*/

#include "Click_Lin_Hall_types.h"
#include "Click_Lin_Hall_config.h"


char logText[50];
uint16_t valueADC;
uint16_t valueADCOld = 0;
uint16_t sensitivity = 30;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS1, &_LINHALL_SPI_CFG[0] );
    mikrobus_logInit( _MIKROBUS2, 9600 );
    Delay_100ms();
}

void applicationInit()
{
    linhall_spiDriverInit( (T_LINHALL_P)&_MIKROBUS1_GPIO, (T_LINHALL_P)&_MIKROBUS1_SPI );

    mikrobus_logWrite("  Lin Hall click",_LOG_LINE);
    mikrobus_logWrite("-------------------", _LOG_LINE);
    Delay_100ms();
}

void applicationTask()
{
    valueADC = linhall_readData();

    if ( ( ( valueADC - valueADCOld ) > sensitivity ) && ( ( valueADCOld - valueADC ) > sensitivity ) )
    {
        mikrobus_logWrite( " ADC Value: ", _LOG_TEXT );
        IntToStr( valueADC, logText );
        mikrobus_logWrite( logText, _LOG_LINE );
        mikrobus_logWrite("-------------------", _LOG_LINE);

        valueADCOld = valueADC;
        Delay_100ms();
     }
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}