/*
  Copyright (c) 2011 Arduino.  All right reserved.
  Copyright (c) 2023 MCCI Corporation.  All rights reserved.

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

#include "variant.h"
#include "stm32l0xx_ll_rcc.h"

#ifdef __cplusplus
extern "C" {
#endif

// Pin number
// This array allows to map Arduino pin number(Dx or x)
// to STM32 PinName (PX_n) -- don't forget to also change variant.h
const PinName digitalPin[] = {
//PX_n, //Dx
  PA10, //D0      D0_UART_RX
  PA9,  //D1      D1_UART_TX
  PA7,  //D2      RADIO_MOSI   Murata internal
  PA6,  //D3      RADIO_MISO   Murata internal
  PB3,  //D4      RADIO_SCK    Murata internal
  PB6,  //D5      D5_RE
  PA13, //D6      D6_SWDIO
  PA15, //D7      RADIO_NSS    Murata internal
  PC0,  //D8      RADIO_RESET  Murata internal
  PA14, //D9      D9_SWCLK
  PA4,  //D10     D10_DE
  PB5,  //D11     D11_nCS
  PB7,  //D12     D12_BOOST_EN
  PB2,  //D13     D13_LED
  PA0,  //D14/A0  A0_VBUS_MON
  PA5,  //D15/A1  A1_VBAT_MON
  PA3,  //D17/A3  A3_RS485_TX
  PA2,  //D18/A4  A4_RS485_RX
  PB12, //D19     D19_NSS
  PB9,  //D20     SDA
  PB8,  //D21     SCL
  PB14, //D22     MISO
  PB15, //D23     MOSI
  PB13, //D24     SCK
  PB4,  //D25     RADIO_DIO_0
  PB1,  //D26     RADIO_DIO_1
  PB0,  //D27     RADIO_DIO_2
  PC13, //D28     RADIO_DIO_3
  PA1,  //D29     RADIO_ANT_SWITCH_RX       CRF1
  PC1,  //D30     RADIO_ANT_SWITCH_TX_BOOST CRF3
  PC2,  //D31     RADIO_ANT_SWITCH_TX_RFO   CRF2
  NC_1, //D32     Flash Write-Protect (not supported these platforms)
  PA8,  //D33     RADIO_TCXO      TCXO VDD, possibly VDD boost enable.
  PEND
};

#ifdef __cplusplus
}
#endif