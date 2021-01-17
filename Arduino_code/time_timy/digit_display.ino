/*                                 _   _                 _  _               _
                                 | \ | |               | |(_)             | |
  __      ____      ____      __ |  \| |  ___  _ __  __| | _  _   _     __| |  ___
  \ \ /\ / /\ \ /\ / /\ \ /\ / / | . ` | / _ \| '__|/ _` || || | | |   / _` | / _ \
   \ V  V /  \ V  V /  \ V  V /_ | |\  ||  __/| |  | (_| || || |_| | _| (_| ||  __/
    \_/\_/    \_/\_/    \_/\_/(_)|_| \_| \___||_|   \__,_||_| \__, |(_)\__,_| \___|
                                                               __/ |
                                                              |___/
     time_timy by Fabian Steppat
     Infos on https://www.Nerdiy.de/en/time_timy

     This program is free software: you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation, either version 3 of the License, or
     (at your option) any later version.

     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.

     You should have received a copy of the GNU General Public License
     along with this program.  If not, see <http://www.gnu.org/licenses/>.

     You can find additional infos about the licensing here: https://nerdiy.de/en/lizenz/
     
     Credits:
      - Adafruit: A big thank you to the awesome ladies and gentleman at adafruit.com who made many awesome and important libraries and products.
                  If you want to thank/support them, buy one(or more) of their products on www.adafruit.com.
*/

// == digit control ======================================================================================================================================

void init_digits()
{
  digits.begin();
}


void check_digit_display()
{
  //this function checks periodically if there is an update for the digit-display
  if (regular_execution(&displayUpdateTimestamp, DISPLAY_UPDATE_INTERVAL) || displayedTimerDuration != timerDuration || displayedRemainingTimeInSeconds != remainingTimeInSeconds)
  {
    clear_digits();
    if ((millis() - lastActionTimestamp) <= DIGIT_STAYS_ENLIT_AFTER_LAST_ACTION_DELAY)
    {
      if (remainingTimeInSeconds < 60)
      {
        //this part is executed if the rest time is smaler than one minute so the rest seconds are displayed
        show_digit(digits.Color(DIGIT_DISPLAY_SECONDS_COLOR_R, DIGIT_DISPLAY_SECONDS_COLOR_G, DIGIT_DISPLAY_SECONDS_COLOR_B), 0, remainingTimeInSeconds % 10);
        if (remainingTimeInSeconds > 9)
        {
          show_digit(digits.Color(DIGIT_DISPLAY_SECONDS_COLOR_R,DIGIT_DISPLAY_SECONDS_COLOR_G, DIGIT_DISPLAY_SECONDS_COLOR_B), 1, remainingTimeInSeconds / 10);
        }
        displayedRemainingTimeInSeconds = remainingTimeInSeconds;
      } else
      {
        //this part is executed if the rest time is bigger than one minute so the rest minutes are displayed
        show_digit(digits.Color(DIGIT_DISPLAY_MINUTES_COLOR_R, DIGIT_DISPLAY_MINUTES_COLOR_G, DIGIT_DISPLAY_MINUTES_COLOR_B), 0, timerDuration % 10);
        if (timerDuration > 9)
          show_digit(digits.Color(DIGIT_DISPLAY_MINUTES_COLOR_R, DIGIT_DISPLAY_MINUTES_COLOR_G, DIGIT_DISPLAY_MINUTES_COLOR_B), 1, timerDuration / 10);
      }
    }
    update_digit();
    displayedTimerDuration = timerDuration;
  }
}

void clear_digits()
{
  digits.clear();
}

void update_digit()
{
  digits.show();
}

void show_digit(uint32_t color, uint8_t digit, uint8_t value)
{
  if (value == 2 || value == 3 || value == 5 || value == 6 || value == 7 || value == 8 || value == 9 || value == 0)
  {
    top(color, digit);
  }

  if (value == 4 || value == 5 || value == 6 || value == 8 || value == 9 || value == 0)
  {
    top_left(color, digit);
  }

  if (value == 1 || value == 2 || value == 3 || value == 4 || value == 7 || value == 8 || value == 9 || value == 0)
  {
    top_right(color, digit);
  }

  if (value == 2 || value == 3 || value == 4 || value == 5 || value == 6 || value == 8 || value == 9)
  {
    middle(color, digit);
  }

  if (value == 2 || value == 6 || value == 8 || value == 0)
  {
    bottom_left(color, digit);
  }

  if (value == 2 || value == 3 || value == 5 || value == 6 || value == 8 || value == 9 || value == 0)
  {
    bottom(color, digit);
  }

  if (value == 1 || value == 3 || value == 4 || value == 5 || value == 6 || value == 7 || value == 8 || value == 9 || value == 0)
  {
    bottom_right(color, digit);
  }


}

void bottom(uint32_t color, uint8_t digit)
{
  digits.setPixelColor((digit * NUMPIXELS_DIGITS) + 0, color);
  digits.setPixelColor((digit * NUMPIXELS_DIGITS) + 1, color);
}

void bottom_right(uint32_t color, uint8_t digit)
{
  digits.setPixelColor((digit * NUMPIXELS_DIGITS) + 2, color);
  digits.setPixelColor((digit * NUMPIXELS_DIGITS) + 3, color);
}

void top_right(uint32_t color, uint8_t digit)
{
  digits.setPixelColor((digit * NUMPIXELS_DIGITS) + 4, color);
  digits.setPixelColor((digit * NUMPIXELS_DIGITS) + 5, color);
}

void top(uint32_t color, uint8_t digit)
{
  digits.setPixelColor((digit * NUMPIXELS_DIGITS) + 6, color);
  digits.setPixelColor((digit * NUMPIXELS_DIGITS) + 7, color);
}

void top_left(uint32_t color, uint8_t digit)
{
  digits.setPixelColor((digit * NUMPIXELS_DIGITS) + 8, color);
  digits.setPixelColor((digit * NUMPIXELS_DIGITS) + 9, color);
}

void middle(uint32_t color, uint8_t digit)
{
  digits.setPixelColor((digit * NUMPIXELS_DIGITS) + 10, color);
  digits.setPixelColor((digit * NUMPIXELS_DIGITS) + 11, color);
}

void bottom_left(uint32_t color, uint8_t digit)
{
  digits.setPixelColor((digit * NUMPIXELS_DIGITS) + 12, color);
  digits.setPixelColor((digit * NUMPIXELS_DIGITS) + 13, color);
}
