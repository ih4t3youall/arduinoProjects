#include <TimerOne.h>
const int led = 13;  // the pin with a LED


void setup(void)
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}


void loop(void)
{
  Serial.print("blinkCount = ");
  Serial.println(millis());
  delay(100);
}
