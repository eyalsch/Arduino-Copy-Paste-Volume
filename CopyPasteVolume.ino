// Tools -> Board:
// SparkFun Pro Micro
// Pro Micro ATmega32U4 5V 16MHz
// Two buttons and one potentiometer

#include "HID-Project.h"

int ButtonGreen = 3;
int ButtonRed = 5;
int PotPin = A3;

int PotValue = 0;
int currVolume = 0;

void setup()
{
  pinMode(ButtonGreen, INPUT_PULLUP); // Common Ground. reverse logic.
  pinMode(ButtonRed, INPUT_PULLUP);
  digitalWrite(ButtonGreen, HIGH);
  digitalWrite(ButtonRed, HIGH);
  Keyboard.begin();
  delay(500);  // short delay to let outputs settle
  Consumer.begin();
  delay(500);
}

void loop()
{
  if (digitalRead(ButtonGreen) == LOW)
  {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('c');
    delay(100);
    Keyboard.releaseAll();
    delay(200);
  }

  if (digitalRead(ButtonRed) == LOW)
  {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('v');
    delay(100);
    Keyboard.releaseAll();
    delay(200);
  }

  PotValue = map(analogRead(PotPin), 0, 1023, 0, 50);
  if (currVolume < PotValue) {
    Consumer.write(MEDIA_VOLUME_UP);
    currVolume++;
  }
  if (currVolume > PotValue) {
    Consumer.write(MEDIA_VOLUME_DOWN);
    currVolume--;
  }
}
