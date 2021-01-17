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

// == Timer ======================================================================================================================================

void check_timer()
{
  if (timerStartedTimestamp > 0)
  {
    if (regular_execution(&timerPolledTimestamp, TIMER_POLL_INTERVAL))
    {
      remainingTimeInSeconds = timerDurationAtStart * 60 - ((millis() - timerStartedTimestamp) / 1000);
      remainingTimeInMinutes = remainingTimeInSeconds / 60;
      Serial.print("Timer running: remaining time: ");
      Serial.print(remainingTimeInMinutes);
      Serial.print(":");
      Serial.println(remainingTimeInSeconds % 60);
      update_timer_duration(remainingTimeInMinutes);
      if (remainingTimeInSeconds == 0)
      {
        stop_timer();        
        time_run_out_animation();
      }
    }
    update_last_action_timestamp();
  }
}


void start_timer()
{
  timerStartedTimestamp = millis();
  timerDurationAtStart = timerDuration;
  Serial.println("Timer started.");
  remainingTimeInSeconds = timerDurationAtStart * 60 - ((millis() - timerStartedTimestamp) / 1000);
}


void stop_timer()
{
  update_timer_duration(0);
  timerDurationAtStart = 0;
  timerStartedTimestamp = 0;
  remainingTimeInSeconds = 0;
  remainingTimeInMinutes = 0;
  Serial.println("Timer stopped.");
  clear_digits();
  clear_bar_graph();

  update_digit();
  update_bar_graph();
}

void update_timer_duration(uint8_t value)
{
  timerDuration = value;
}
