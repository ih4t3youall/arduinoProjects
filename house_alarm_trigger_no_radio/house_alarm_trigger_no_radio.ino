// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

int txPin = 12; 
int RELEE = 8;

void setup() {
  pinMode(RELEE, OUTPUT);
  Serial.begin(115200);
  rf_driver.init();
}

void loop() {
  handleSerialCommunication();
}

void handleSerialCommunication() {

  if (Serial.available() > 0) {  // Comprueba si hay datos disponibles para leer
    String data = Serial.readString();  // Lee los datos entrantes hasta encontrar un salto de línea
    data.trim();  // Elimina espacios blancos y caracteres de nueva línea al inicio y final

    Serial.print("Received: ");  // Imprime lo recibido para depuración
    Serial.println(data);

    if (data == "trig") {  // Comprueba si los datos recibidos son "trigger"
      send_radio_command();
    }
  }
}

void send_radio_command() 
{
  digitalWrite(RELEE, HIGH);
  delay(1000);
  digitalWrite(RELEE, LOW);
}
