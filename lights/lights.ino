#define __DEBUG__
 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
// Definir constantes
#define ANCHO_PANTALLA 128 // ancho pantalla OLED
#define ALTO_PANTALLA 64 // alto pantalla OLED
 
// Objeto de la clase Adafruit_SSD1306
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);

int tres = 4;
int dos = 6;
int cuatro = 7;
int uno = 5;

int relee1 = 8;
int relee2 = 9;
int relee3 = 10;
int relee4 = 11;

int relee1status = 0;
int relee2status = 0;
int relee3status = 0;
int relee4status = 0;
 
void setup() {

  Serial.begin(9600);
  delay(100);
  Serial.println("Iniciando pantalla OLED");

  pinMode(uno,INPUT);
  pinMode(dos,INPUT);
  pinMode(tres,INPUT);
  pinMode(cuatro,INPUT);

  pinMode(relee1,OUTPUT);
  pinMode(relee2,OUTPUT);
  pinMode(relee3,OUTPUT);
  pinMode(relee4,OUTPUT);
 
  // Iniciar pantalla OLED en la dirección 0x3C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
#ifdef __DEBUG__
    Serial.println("No se encuentra la pantalla OLED");
#endif
    while (true);
  }
 
  // Limpiar buffer
  display.clearDisplay();
 
  // Tamaño del texto
  display.setTextSize(1);
  // Color del texto
  display.setTextColor(SSD1306_WHITE);
  // Posición del texto
  display.setCursor(10, 32);
  // Escribir texto
  display.println("Barber sos\n un pelotudo");
 
  // Enviar a pantalla
  display.display();
 
}

 void draw(String palabra){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 32);
  display.println(palabra);
  display.display();
   }
 
void loop() {

  if (digitalRead(uno)){
    draw("uno");
    if (relee1status == 0){
      digitalWrite(relee1,HIGH);
      relee1status = 1;
    }else{
      digitalWrite(relee1,LOW);
      relee1status = 0;
    }
    delay(400);
  }

  if (digitalRead(dos)){
    draw("dos");
    if (relee2status == 0 ){
      digitalWrite(relee2,HIGH);
      relee2status  =1;
    }else{
      digitalWrite(relee2,LOW);
      relee2status  =0;
    }
    delay(400);
  }

  if (digitalRead(tres)){
    draw("tres");
    if (relee3status == 0){
      digitalWrite(relee3,HIGH);
      relee3status  = 1;
    }else {
      digitalWrite(relee3,LOW);
      relee3status  = 0;
    }
    delay(400);
  }

  if (digitalRead(cuatro)){
    draw("cuatro");
    if (relee4status == 0){
      digitalWrite(relee4,HIGH);
      relee4status  = 1;
    }else{
      digitalWrite(relee4,LOW);
      relee4status  = 0;
    }
    delay(400);
  }

}
