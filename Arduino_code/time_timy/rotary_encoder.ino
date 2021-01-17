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

// == Rotary encoder ======================================================================================================================================

void init_encoder()
{
  pinMode(ENCODER_TASTER_PIN, INPUT_PULLUP);
  pinMode(ENCODER_LINKS_PIN, INPUT_PULLUP);
  pinMode(ENCODER_RECHTS_PIN, INPUT_PULLUP);
}

void check_rotary_encoder()
{
  unsigned char result = encoder.process();
  if (result)
  {
    if (result == DIR_CW)
    {
      //Rechts
      Serial.println("Knob turned right. Timer-duration increased to: ");
      if (timerDuration < MAX_TIME_VALUE)
        timerDuration++;
      else
        timerDuration = MIN_TIME_VALUE;
      Serial.println(timerDuration);

    } else
    {
      //Links
      Serial.println("Knob turned left. Timer-duration decreased to: ");
      if (timerDuration > MIN_TIME_VALUE)
        timerDuration--;
      else
        timerDuration = MAX_TIME_VALUE;
      Serial.println(timerDuration);

    }
    start_timer();
    check_bar_graph();
    check_digit_display();
    update_digit();
    update_bar_graph();

    update_last_action_timestamp();

    if (timerDuration == 0) //if timerDuration is changed manual to zero timer must be stopped to avoid animation
      stop_timer();
  }

  if (regular_execution(&encoderButtonDebounceTimestamp, ENCODER_BUTTON_DEBOUNCE_TIME))
  {
    boolean rotaryEncoderTasterStatusNeu = digitalRead(ENCODER_TASTER_PIN); //nur bei einer gemeinsamen ffnungslfanke einschalten und nur bei einer gemeinsamen schließflanke schließen

    if (!rotaryEncoderTasterStatusNeu && rotaryEncoderButtonStateOld)
    {
      Serial.println("Encoder button pressed! Timer will be stopped.");
      stop_timer();
      play_encoder_clicked_tone();
    }
    rotaryEncoderButtonStateOld = rotaryEncoderTasterStatusNeu;
  }

}
