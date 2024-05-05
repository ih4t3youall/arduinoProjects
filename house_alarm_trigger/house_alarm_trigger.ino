int LED = 11;
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}



void loop() {
  
//	handleSerialCommunication();

if (Serial.available() > 0) {
  String data = Serial.readStringUntil('\n');
  data.trim();
  Serial.print("walowski");
  }

  }


void handleSerialCommunication() {
  if (Serial.available() > 0) {  // Comprueba si hay datos disponibles para leer
    String data = Serial.readStringUntil('\n');  // Lee los datos entrantes hasta encontrar un salto de línea
    data.trim();  // Elimina espacios blancos y caracteres de nueva línea al inicio y final

    Serial.print("Received: ");  // Imprime lo recibido para depuración
    Serial.println(data);

    if (data == "trigger") {  // Comprueba si los datos recibidos son "trigger"
      toggleLED();  // Llama a la función que cambia el estado del LED
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
