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

// == Configuration ======================================================================================================================================

//Pin configuration
#define DIGITS_PIN            5
#define BAR_PIN            6
#define ENCODER_LINKS_PIN 3
#define ENCODER_RECHTS_PIN 2
#define ENCODER_TASTER_PIN 4
#define TONE_GENERATOR_GND_PIN 15
#define TONE_GENERATOR_VCC_PIN 16

//Serial
#define BAUDRATE 115200

//Encoder
#define ENCODER_BUTTON_DEBOUNCE_TIME 100

//Bargraph
#define NUMPIXELS_DIGITS      14
#define NUM_DIGITS      2
#define NUMPIXELS_BAR      90
#define BAR_GRAPH_BRIGHTNESS 10.0 //Warning: Do not change this until you are sure that the circuit can handle the drawn current

//Tone generator/buzer
#define TONE_FREQUENCY_FINISH 2000
#define TONE_DURATION_FINISH 3000
#define TONE_FREQUENCY_ENCODER 2000
#define TONE_DURATION_ENCODER 100

//Seven segment digits
#define DIGIT_DISPLAY_MINUTES_COLOR_R 170
#define DIGIT_DISPLAY_MINUTES_COLOR_G 170
#define DIGIT_DISPLAY_MINUTES_COLOR_B 170

#define DIGIT_DISPLAY_SECONDS_COLOR_R 255
#define DIGIT_DISPLAY_SECONDS_COLOR_G 0
#define DIGIT_DISPLAY_SECONDS_COLOR_B 0

#define DIGIT_STAYS_ENLIT_AFTER_LAST_ACTION_DELAY 30000

//Misc
#define TIMER_POLL_INTERVAL 1000
#define ANIMATION_BLINK_NUM 5
#define BLINK_DELAY_TIME 500
#define MAX_TIME_VALUE 90
#define MIN_TIME_VALUE 0
#define DISPLAY_UPDATE_INTERVAL 1000
