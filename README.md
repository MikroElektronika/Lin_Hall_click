![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Lin_Hall Click

---

- **CIC Prefix**  : LINHALL
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Sep 2018.

---

### Software Support

We provide a library for the Lin_Hall Click on our [LibStock](https://libstock.mikroe.com/projects/view/1083/lin-hall-click-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control Lin Hall Click board. 
Library performs the communication with the device via SPI driver by writting to registers and by reading from registers.
Library read and write 12-bit data from the MCP3201 chip
and send results via UART.

Key functions :

- ``` void linhall_writeData( uint16_t writeData ) ``` - Generic write 12-bit data function
- ``` uint16_t linhall_readData() ``` - Generic read 12-bit data function

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes SPI and LOG structures, set CS (chip select) pin as output.
- Application Initialization - Initialization driver enable's - SPI and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of Lin Hall Click board.
     Read 12-bit ADC value from the MCP3201 chip.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart for aproximetly every 100 ms when the ADC value changes.


```.c

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

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1083/lin-hall-click-example) page.

Other mikroE Libraries used in the example:

- SPI
- UART
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
