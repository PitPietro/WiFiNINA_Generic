/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  Copyright (c) 2018, Adafruit Industries (adafruit.com)

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
// Thanks to great work of [Miguel Alexandre Wisintainer](https://github.com/tcpipchip). 
// See [u-blox nina b](https://github.com/khoih-prog/WiFiNINA_Generic/issues/1)

#include "variant.h"
#include "wiring_constants.h"
#include "wiring_digital.h"
#include "nrf.h"

const uint32_t g_ADigitalPinMap[] =
{
  // D0 .. D13
  29,  // D0  is P0.29 (UART TX)
  45,  // D1  is P1.13 (UART RX 
  44,  // D2  is P1.12 (NFC2)
  31,  // D3  is P0.31 (LED1)
  13,  // D4  is P0.13 (LED2)
  11,  // D5  is P0.11
   9,  // D6  is P0.09
  10,  // D7  is P0.10 (Button)
  41,  // D8  is P1.09 (NeoPixel)
  12,  // D9  is P0.12
  14,  // D10 is P0.14
  15,  // D11 is P0.15
  32,  // D12 is P1.00
   7,  // D13 is P0.07

  // D14 .. D21 (aka A0 .. A7)
   4,  // D14 is P0.04 (A0)
  30,  // D15 is P0.30 (A1)
   5,  // D16 is P0.05 (A2)
   2,  // D17 is P0.02 (A3)
  28,  // D18 is P0.28 (A4)
   3,  // D19 is P0.03 (A5)
  29,  // D20 is P0.29 (A6, Battery) ????
  31,  // D21 is P0.31 (A7, ARef)    ????

  // D22 .. D23 (aka I2C pins)
  16,  // D22 is P0.16 (SDA)
  24,  // D23 is P0.24 (SCL)

  // D24 .. D26 (aka SPI pins)
  32,  // D24 is P1.00 (SPI MISO)
  15,  // D25 is P0.15 (SPI MOSI)
   7,  // D26 is P0.07 (SPI SCK )

  // QSPI pins (not exposed via any header / test point)
  19,  // D27 is P0.19 (QSPI CLK)
  17,  // D28 is P0.17 (QSPI CS)
  20,  // D29 is P0.20 (QSPI Data 0)
  21,  // D30 is P0.21 (QSPI Data 1)
  22,  // D31 is P0.22 (QSPI Data 2)
  23,  // D32 is P0.23 (QSPI Data 3)

  // The remaining NFC pin
   9,  // D33 is P0.09 (NFC1, exposed only via test point on bottom of board)

  // Thus, there are 34 defined pins

  // The remaining pins are not usable:
  //
  //
  // The following pins were never listed as they were considered unusable
  //  0,      // P0.00 is XL1   (attached to 32.768kHz crystal)
  //  1,      // P0.01 is XL2   (attached to 32.768kHz crystal)
  // 18,      // P0.18 is RESET (attached to switch)
  // 32,      // P1.00 is SWO   (attached to debug header)
  // 
  // The remaining pins are not connected (per schematic)
  // 33,      // P1.01 is not connected per schematic
  // 35,      // P1.03 is not connected per schematic
  // 36,      // P1.04 is not connected per schematic
  // 37,      // P1.05 is not connected per schematic
  // 38,      // P1.06 is not connected per schematic
  // 39,      // P1.07 is not connected per schematic
  // 43,      // P1.11 is not connected per schematic
  // 44,      // P1.12 is not connected per schematic
  // 45,      // P1.13 is not connected per schematic
  // 46,      // P1.14 is not connected per schematic
};

void initVariant()
{
  // LED1 & LED2
  pinMode(PIN_LED1, OUTPUT);
  ledOff(PIN_LED1);

  pinMode(PIN_LED2, OUTPUT);
  ledOff(PIN_LED2);
}

