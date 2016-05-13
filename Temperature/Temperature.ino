// Copyright © 2016 Daniel Porrey
//
// This file is part of the ATtiny @ 16MHz project
// on hackster.io.
//
// Temperature.ino is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Temperature.ino is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with ATtiny @ 16MHz project. If not, see http://www.gnu.org/licenses/.
//

/*
  Temperature.ino v1.00
  This sketch was created for the ATtiny @ 16MHz project on
  Hackster.io at https://www.hackster.io/porrey/attiny-16mhz-610d41
  to demonstrate the correct functionality of the ATtiny85 running
  at 16 MHz.

  Created:        May 13th, 2016
  Last Modified:  May 13th, 2016
  Created By:     Daniel Porrey
  Site:           https://www.hackster.io/porrey

  Requires DHT Library 0.1.13 or 0.1.20 (may not work
  against other versions of this library). Found at
  http://arduino.cc/playground/Main/DHTLib.

  Source code on Github at:
  https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib

  Also requires the Grove LCD library.
*/
#include <avr/power.h>
#include "dht.h"
#include "rgb_lcd_tiny.h"

// ***
// *** Connect the Dht22 to pin 6 on the ATtiny85.
// ***
#define DHT_PIN 1

// ***
// *** Connect an LED to pin 3 on the ATtiny85.
// ***
#define LED_PIN 3

// ***
// *** Create the DHT instance;
// ***
dht _dht;

// ***
// *** Crate the Grove LCD instance.
// ***
rgb_lcd _lcd;

void setup()
{
  // ***
  // *** Initialize the Grove LCD
  // ***
  _lcd.begin(16, 2);

  // ***
  // *** Set the LCD background color.
  // ***
  _lcd.setRGB(128, 128, 128);

  // ***
  // *** Set the LED pin to OUTPUT.
  // ***
  pinMode(LED_PIN, OUTPUT);

  // ***
  // *** Turn the LED off.
  // ***
  digitalWrite(LED_PIN, HIGH);
}

uint16_t i = 0;

void loop()
{
  // ***
  // *** Turn the LED on.
  // ***
  digitalWrite(LED_PIN, LOW);

  // ***
  // *** Read the temperature and humidity from the DHT22.
  // ***
  _dht.read22(DHT_PIN);

  // ***
  // *** Clear the LCD and update the display.
  // ***
  _lcd.clear();
  _lcd.setCursor(0, 0);
  _lcd.print(_dht.humidity, 1);
  _lcd.setCursor(0, 1);
  _lcd.print(_dht.temperature, 1);

  // ***
  // *** Display the counter.
  // ***
  _lcd.setCursor(10, 1);
  _lcd.print(i);

  // ***
  // *** Increment the counter.
  // ***
  i++;

  // ***
  // *** Delay 1/2 second.
  // ***
  delay(500);

  // ***
  // *** Turn the LED off.
  // ***
  digitalWrite(LED_PIN, HIGH);

  // ***
  // *** Delay 1/2 second.
  // ***
  delay(500);
}
