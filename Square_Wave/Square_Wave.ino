// Copyright © 2016 Daniel Porrey
//
// This file is part of the ATtiny @ 16MHz project
// on hackster.io.
//
// Square_Wave.ino is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Square_Wave.ino is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with ATtiny @ 16MHz project. If not, see http://www.gnu.org/licenses/.
//

/*
  Square_Wave.ino v1.00
  This sketch was created for the ATtiny @ 16MHz project on
  Hackster.io at https://www.hackster.io/porrey/attiny-16mhz-610d41
  to demonstrate test the difference in speed of the ATtiny85 running
  at 8 and 16 MHz.

  Created:        May 13th, 2016
  Last Modified:  May 13th, 2016
  Created By:     Daniel Porrey
  Site:           https://www.hackster.io/porrey
*/
void setup()
{
  // ***
  // *** Set PORTB3 to output.
  // ***
  DDRB = B00001000;

  while (true)
  {
    // ***
    // *** Set PORTB3 to HIGH.
    // ***
    PORTB = B00001000;

    // ***
    // *** Set PORTB3 to LOW.
    // ***
    PORTB = B00000000;
  }
}

void loop()
{
}
