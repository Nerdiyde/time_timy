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

// == Bar graph ======================================================================================================================================

void init_bar_graph()
{
  bar.begin();
  clear_bar_graph();
  update_bar_graph();
}

void clear_bar_graph()
{
  bar.clear();
}

void check_bar_graph()
{

  if (regular_execution(&barGraphUpdateTimestamp, DISPLAY_UPDATE_INTERVAL) && timerDurationAtStart > 0) //timerDurationAtStart must be greater than zero because otherwise the map functions will return -1
  {
    uint8_t enlitLeds = map(remainingTimeInSeconds, 0, timerDurationAtStart * 60, 0, NUMPIXELS_BAR);
    uint8_t colorValueAsHue = map(remainingTimeInSeconds, 0, timerDurationAtStart * 60, 0, 122.0); //125.0 represents green in the color cycle, 0 represents red in the color cycle


    uint8_t red, green, blue = 0;
    hsvToRgb(colorValueAsHue, 100.0, BAR_GRAPH_BRIGHTNESS, &red, &green, &blue);
    clear_bar_graph();
    for (uint8_t i = 0; i < enlitLeds; i++)
    {
      bar.setPixelColor(i, bar.Color(red, green, blue));
    }
    update_bar_graph();
    
    Serial.print("colorValueAsHue: ");
    Serial.print(colorValueAsHue);
    Serial.print(" timerDurationAtStart:");
    Serial.print(timerDurationAtStart);
    Serial.print(" remainingTimeInSeconds:");
    Serial.print(remainingTimeInSeconds);
    Serial.print(" Enlit LED's:");
    Serial.print(enlitLeds);
    Serial.print(" of ");
    Serial.println(NUMPIXELS_BAR);
    
  }
}


void update_bar_graph()
{
  bar.show();
}
