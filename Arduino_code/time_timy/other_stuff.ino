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

// == Other usefull stuff ==================================================================================================================================

boolean regular_execution(unsigned long *lastExecution, unsigned long REPEATING_INTERVAL)
{
  //does help to regular execute a repeating task like checking for a display update
  if ((millis() - *lastExecution) >= REPEATING_INTERVAL)
  {
    *lastExecution = millis();
    return true;
  }
  return false;
}

void update_last_action_timestamp()
{
  lastActionTimestamp=millis();
}


void time_run_out_animation()
{
  play_finish_tone();
  for (uint8_t i = 0; i < ANIMATION_BLINK_NUM; i++)
  {
    clear_digits();
    clear_bar_graph();
    
    show_digit(digits.Color(255, 0, 0), 0, 8);
    show_digit(digits.Color(255, 0, 0), 1, 8);
    bar.fill(bar.Color(100, 0, 0),0 ,NUMPIXELS_BAR);
    
    update_digit();
    update_bar_graph();
    
    delay(BLINK_DELAY_TIME);  
      
    clear_digits();
    clear_bar_graph();
    
    update_digit();
    update_bar_graph();
    
    delay(BLINK_DELAY_TIME);
  }

}

void hsvToRgb(uint16_t hue, uint8_t sat, uint8_t bri, uint8_t *red, uint8_t *green, uint8_t *blue)
{
  float r;
  float g;
  float b;

  if (hue > 360.0)
    hue = 360.0;
  if (sat > 100.0)
    sat = 100.0;
  if (bri > 100.0)
    bri = 100.0;

  float h = (float)hue / 360.0;
  float s = (float)sat / 100.0;
  float v = (float)bri / 100.0;
  
  if (h < 0.0f)
  {
    h += 1.0f;
  }
  else if (h >= 1.0f)
  {
    h -= 1.0f;
  }

  h *= 6.0f;
  int i = (int)h;
  float f = h - i;
  float q = v * (1.0f - s * f);
  float p = v * (1.0f - s);
  float t = v * (1.0f - s * (1.0f - f));

  switch (i)
  {
    case 0:
      r = v;
      g = t;
      b = p;
      break;
    case 1:
      r = q;
      g = v;
      b = p;
      break;
    case 2:
      r = p;
      g = v;
      b = t;
      break;
    case 3:
      r = p;
      g = q;
      b = v;
      break;
    case 4:
      r = t;
      g = p;
      b = v;
      break;
    default:
      r = v;
      g = p;
      b = q;
      break;
  }

  *red = (uint8_t)(r * 255.0f);
  *green = (uint8_t)(g * 255.0f);
  *blue = (uint8_t)(b * 255.0f);

}
