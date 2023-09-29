/*
  Copyright (c) 2011 Arduino.  All right reserved.
  Copyright (c) 2018 MCCI Corporation.  All rights reserved.

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
//PX_n,  //Dx
  PA_10,  //D0      D0_RX
  PA_9,   //D1      D1_TX
  PA_7,   //D2/A10  RF_MOSI (AF0)
  PA_6,   //D3/A9   RF_MISO (AF0)
  PB_3,   //D4      RF_SCK (AF0)
  PA_8,   //D5      D5
  PA_13,  //D6      D6_SWDIO
  PA_15,  //D7      RF_NSS (AF0)
  PB_2,   //D8      D8_RF_RESET
  PA_14,  //D9      D9_SWCLK
  PC_2,   //D10     D10
  PA_1,   //D11     D11
  PB_1,   //D12     D12
  PB_5,   //D13     D13_LED
  PA_0,   //D14/A0  A0
  PA_5,   //D15/A1
  PA_4,   //D16/A2
  PC_0,   //D17/A3
  PC_1,   //D18/A4
  PB_12,  //D19     D19_NSS
  PB_9,   //D20     SDA/SDA (AF3)
  PB_8,   //D21     SCL/SCL (AF3)
  PB_14,  //D22     MISO (AF0)
  PB_15,  //D23     MOSI (AF0)
  PB_13,  //D24     SCK (AF0)
  PB_4,   //D25     D25_RF_DIO0
  PB_6,   //D26     D26_RF_DIO1
  PB_7,   //D27     D27_RF_DIO2
  PC_13,  //D28     D28_ON1
  PB_10,  //D29     D29_RF_DIO4
  PB_11,  //D30     D30_ON2
  PH_0,   //D31     D31_EN
  PH_1,   //D32     D32
  PB_0,   //D33/A5  A5
  PA_11,  //D34     D_N
  PA_12,  //D35     D_P
  PA_2,   //D36/A11 A11_VBAT_MON
  PA_3,   //D37/A12 A12_VBUS_MON
};

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------