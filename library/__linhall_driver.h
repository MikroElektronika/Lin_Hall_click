/*
    __linhall_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __linhall_driver.h
@brief    Lin_Hall Driver
@mainpage Lin_Hall Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   LINHALL
@brief      Lin_Hall Click Driver
@{

| Global Library Prefix | **LINHALL** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Sep 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _LINHALL_H_
#define _LINHALL_H_

/** 
 * @macro T_LINHALL_P
 * @brief Driver Abstract type 
 */
#define T_LINHALL_P    const uint8_t*

/** @defgroup LINHALL_COMPILE Compilation Config */              /** @{ */

   #define   __LINHALL_DRV_SPI__                            /**<     @macro __LINHALL_DRV_SPI__  @brief SPI driver selector */
//  #define   __LINHALL_DRV_I2C__                            /**<     @macro __LINHALL_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __LINHALL_DRV_UART__                           /**<     @macro __LINHALL_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup LINHALL_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup LINHALL_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup LINHALL_INIT Driver Initialization */              /** @{ */

#ifdef   __LINHALL_DRV_SPI__
void linhall_spiDriverInit(T_LINHALL_P gpioObj, T_LINHALL_P spiObj);
#endif
#ifdef   __LINHALL_DRV_I2C__
void linhall_i2cDriverInit(T_LINHALL_P gpioObj, T_LINHALL_P i2cObj, uint8_t slave);
#endif
#ifdef   __LINHALL_DRV_UART__
void linhall_uartDriverInit(T_LINHALL_P gpioObj, T_LINHALL_P uartObj);
#endif


/** @defgroup LINHALL_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic write 12-bit data function
 *
 * @param[in] writeCommand    12-bit data command to write
 *
 * Function write 12-bit data via SPI
 * on the MCP3201 chip.
 */
void linhall_writeData( uint16_t writeData );

/**
 * @brief Generic read 12-bit data function
 *
 * @return
 * 12-bit data ( 0 - 4095 ) from MCP3201 chip
 *
 * Function read 12-bit ADC value from
 * the MCP3201 chip.
 */
uint16_t linhall_readData();





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Lin_Hall_STM.c
    @example Click_Lin_Hall_TIVA.c
    @example Click_Lin_Hall_CEC.c
    @example Click_Lin_Hall_KINETIS.c
    @example Click_Lin_Hall_MSP.c
    @example Click_Lin_Hall_PIC.c
    @example Click_Lin_Hall_PIC32.c
    @example Click_Lin_Hall_DSPIC.c
    @example Click_Lin_Hall_AVR.c
    @example Click_Lin_Hall_FT90x.c
    @example Click_Lin_Hall_STM.mbas
    @example Click_Lin_Hall_TIVA.mbas
    @example Click_Lin_Hall_CEC.mbas
    @example Click_Lin_Hall_KINETIS.mbas
    @example Click_Lin_Hall_MSP.mbas
    @example Click_Lin_Hall_PIC.mbas
    @example Click_Lin_Hall_PIC32.mbas
    @example Click_Lin_Hall_DSPIC.mbas
    @example Click_Lin_Hall_AVR.mbas
    @example Click_Lin_Hall_FT90x.mbas
    @example Click_Lin_Hall_STM.mpas
    @example Click_Lin_Hall_TIVA.mpas
    @example Click_Lin_Hall_CEC.mpas
    @example Click_Lin_Hall_KINETIS.mpas
    @example Click_Lin_Hall_MSP.mpas
    @example Click_Lin_Hall_PIC.mpas
    @example Click_Lin_Hall_PIC32.mpas
    @example Click_Lin_Hall_DSPIC.mpas
    @example Click_Lin_Hall_AVR.mpas
    @example Click_Lin_Hall_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __linhall_driver.h

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