/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _VARIANT_ARDUINO_CATENA_513x_
#define _VARIANT_ARDUINO_CATENA_513x_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
#include "PeripheralPins.h"

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/
extern const PinName digitalPin[];

// Enum defining pin names to match digital pin number --> Dx
// !!!
// !!! Copy the digitalPin[] array in variant.cpp
// !!! and remove all '_': PX_n --> PXn
// !!! For NC, suffix by _x where x is the number of NC:
// !!!   NC_1, NC_2,...
// !!! For duplicated pin name, suffix by _x where x is the number of pin:
// !!! PA7, PA7_2, PA7_3,...
enum {
  PA10, //D0      D0_RX
  PA9,  //D1      D1_TX
  PA7,  //D2/A10  RF_MOSI (AF0)
  PA6,  //D3/A9   RF_MISO (AF0)
  PB3,  //D4      RF_SCK (AF0)
  PA8,  //D5      D5
  PA13, //D6      D6_SWDIO
  PA15, //D7      RF_NSS (AF0)
  PB2,  //D8      D8_RF_RESET
  PA14, //D9      D9_SWCLK
  PC2,  //D10     D10
  PA1,  //D11     D11
  PB1,  //D12     D12
  PB5,  //D13     D13_LED
  PA0,  //D14/A0  A0
  PA5,  //D15/A1
  PA4,  //D16/A2
  PC0,  //D17/A3
  PC1,  //D18/A4
  PB12, //D19     D19_NSS
  PB9,  //D20     SDA/SDA (AF3)
  PB8,  //D21     SCL/SCL (AF3)
  PB14, //D22     MISO (AF0)
  PB15, //D23     MOSI (AF0)
  PB13, //D24     SCK (AF0)
  PB4,  //D25     D25_RF_DIO0
  PB6,  //D26     D26_RF_DIO1
  PB7,  //D27     D27_RF_DIO2
  PC13, //D28     D28_ON1
  PB10, //D29     D29_RF_DIO4
  PB11, //D30     D30_ON2
  PH0,  //D31     D31_EN
  PH1,  //D32     D32
  PB0,  //D33/A5  A5
  PA11, //D34     D_N
  PA12, //D35     D_P
  PA2,  //D36/A11 A11_VBAT_MON
  PA3,  //D37/A12 A12_VBUS_MON
  PEND
};

// This must be a literal with the same value as PEND
#define NUM_DIGITAL_PINS        38
// This must be a literal with a value less than or equal to to MAX_ANALOG_INPUTS
#define NUM_ANALOG_INPUTS       10
#define NUM_ANALOG_FIRST        14

//On-board LED pin number
#define LED_BUILTIN             D13
#define LED_RED                 LED_BUILTIN

//On-board user button
//#define USER_BTN                NC


//SPI definitions
#define RADIO_SS                D7
#define RADIO_MOSI              D2
#define RADIO_MISO              D3
#define RADIO_SCK               D4
#define RADIO_RESET             D8
#define RADIO_DIO_0             D25
#define RADIO_DIO_1             D26
#define RADIO_DIO_2             D27
#define RADIO_DIO_4             D29

#define FLASH_SS                D19
#define FLASH_MOSI              D23
#define FLASH_MISO              D22
#define FLASH_SCK               D24

#define PIN_SPI_SS              RADIO_SS   // Default for Arduino connector compatibility
#define PIN_SPI_MOSI            RADIO_MOSI // Default for Arduino connector compatibility
#define PIN_SPI_MISO            RADIO_MISO // Default for Arduino connector compatibility
#define PIN_SPI_SCK             RADIO_SCK  // Default for Arduino connector compatibility

//I2C Definitions
#define PIN_WIRE_SDA            D20 // Default for Arduino connector compatibility
#define PIN_WIRE_SCL            D21 // Default for Arduino connector compatibility

//Timer Definitions
//Do not use timer used by PWM pins when possible. See PinMap_PWM in PeripheralPins.c
#define TIMER_TONE              TIM3

//Do not use basic timer: OC is required
#define TIMER_SERVO             TIM2  //TODO: advanced-control timers don't work

// UART Definitions

#ifdef __cplusplus
} // extern "C"
#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#include "../mcci_common_uart.h"

#endif /* _VARIANT_ARDUINO_CATENA_513x_ */