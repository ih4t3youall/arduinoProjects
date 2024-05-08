// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

int txPin = 12; 
int LED = 11;

void setup() {
  pinMode(LED, OUTPUT);
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
      toggleLED();  // Llama a la función que cambia el estado del LED
      send_radio_command();
    }
  }
}

void toggleLED() {
  int state = digitalRead(LED);  // Lee el estado actual del LED
  if (state == HIGH) {
    digitalWrite(LED, LOW);  // Cambia el estado del LED a bajo
    Serial.println("LED turned LOW");  // Envía un mensaje a la consola serial
  } else {
    digitalWrite(LED, HIGH);  // Cambia el estado del LED a alto
    Serial.println("LED turned HIGH");  // Envía un mensaje a la consola serial
  }
}

void send_radio_command() 
{
  const char *msg = "Hello World";
  rf_driver.send((uint8_t *)msg, strlen(msg));
  rf_driver.waitPacketSent();
  delay(1000);
}
