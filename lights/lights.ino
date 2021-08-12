#define __DEBUG__
 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
// Definir constantes
#define ANCHO_PANTALLA 128 // ancho pantalla OLED
#define ALTO_PANTALLA 64 // alto pantalla OLED
 
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
  //Serial.println("Iniciando pantalla OLED");

  pinMode(uno,INPUT);
  pinMode(dos,INPUT);
  pinMode(tres,INPUT);
  pinMode(cuatro,INPUT);

  pinMode(relee1,OUTPUT);
  pinMode(relee2,OUTPUT);
  pinMode(relee3,OUTPUT);
  pinMode(relee4,OUTPUT);
 
 
}

 
void loop() {


  if (Serial.available()){
    char recibido = Serial.read();
    if (recibido == 'a'){
      relee1status = 1;
    }
    if (recibido == 'b'){
      relee1status = 0;
    }

    if (recibido == 'c'){
      relee2status = 1;
    }
    if (recibido == 'd'){
      relee2status = 0;
    }

    if (recibido == 'e'){
      relee3status = 1;
    }
    if (recibido == 'f'){
      relee3status = 0;
    }

    if (recibido == 'g'){
      relee4status = 1;
    }
    if (recibido == 'h'){
      relee4status = 0;
    }


  }

  if (relee1status == 1){
    digitalWrite(relee1,HIGH);
    }
  if (relee1status == 0 ){
    digitalWrite(relee1,LOW);
    }

  if (relee2status == 1){
    digitalWrite(relee2,HIGH);
    }
  if (relee2status == 0 ){
    digitalWrite(relee2,LOW);
    }

  if (relee3status == 1){
    digitalWrite(relee3,HIGH);
    }
  if (relee3status == 0 ){
    digitalWrite(relee3,LOW);
    }

  if (relee4status == 1){
    digitalWrite(relee4,HIGH);
    }
  if (relee4status == 0 ){
    digitalWrite(relee4,LOW);
    }

  if (digitalRead(uno)){
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
