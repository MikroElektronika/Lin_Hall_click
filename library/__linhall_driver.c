/*
    __linhall_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__linhall_driver.h"
#include "__linhall_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __LINHALL_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __LINHALL_DRV_SPI__

void linhall_spiDriverInit(T_LINHALL_P gpioObj, T_LINHALL_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet(0);
}

#endif
#ifdef   __LINHALL_DRV_I2C__

void linhall_i2cDriverInit(T_LINHALL_P gpioObj, T_LINHALL_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __LINHALL_DRV_UART__

void linhall_uartDriverInit(T_LINHALL_P gpioObj, T_LINHALL_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif



/* ----------------------------------------------------------- IMPLEMENTATION */


/* Generic write 12-bit data function */
void linhall_writeData( uint16_t writeData )
{
     uint8_t buffer[ 2 ];

     buffer[ 1 ] = ( uint8_t ) ( writeData & 0x001F );
     buffer[ 0 ] = writeData  >> 7;

     hal_gpio_csSet( 0 );
     hal_spiWrite( buffer, 2);
     hal_gpio_csSet( 1 );
}

/* Generic read 12-bit data function */
uint16_t linhall_readData()
{
    uint16_t result;
    uint8_t buffer[ 2 ];

    hal_gpio_csSet( 0 );
    hal_spiRead( buffer, 2 );
    hal_gpio_csSet( 1 );

    result = ( uint8_t ) ( buffer[ 0 ] & 0x1F );
    result <<= 7;
    result |= buffer[ 1 ] >> 1;

    return result;
}





/* -------------------------------------------------------------------------- */
/*
  __linhall_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */