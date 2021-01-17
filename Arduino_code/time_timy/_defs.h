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

// == Variable & Object Defintions ===========================================================================================================================

//Create led-strip objects
Adafruit_NeoPixel digits = Adafruit_NeoPixel(NUM_DIGITS*NUMPIXELS_DIGITS, DIGITS_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel bar = Adafruit_NeoPixel(NUMPIXELS_BAR, BAR_PIN, NEO_GRB + NEO_KHZ800);

//Create rotary encoder object
Rotary encoder = Rotary(ENCODER_LINKS_PIN, ENCODER_RECHTS_PIN);

//Timestamp variables
unsigned long encoderButtonDebounceTimestamp = 0;
unsigned long timerPolledTimestamp = 0;
unsigned long displayUpdateTimestamp = 0;
unsigned long timerStartedTimestamp = 0;
unsigned long barGraphUpdateTimestamp = 0;
unsigned long lastActionTimestamp = 0;

//Timer variables
unsigned long remainingTimeInSeconds = 0;
uint8_t remainingTimeInMinutes = 0;
uint8_t timerDuration = 0;
uint8_t displayedTimerDuration = 0;
uint8_t timerDurationAtStart = 0;
uint8_t displayedRemainingTimeInSeconds=0;

boolean rotaryEncoderButtonStateOld = false;
