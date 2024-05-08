// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
const int buzzer = 8;
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
 
void setup()
{
  // Initialize ASK Object
  rf_driver.init();
  // Setup Serial Monitor
  Serial.begin(115200);
  pinMode(buzzer,OUTPUT);
}
 
void loop()
{
    // Set buffer to size of expected message
    uint8_t buf[11];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      // Message received with valid checksum
      Serial.print("Message Received: ");
      Serial.println((char*)buf);         
      digitalWrite(buzzer, HIGH);
    }
}
