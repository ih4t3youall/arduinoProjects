#include <LiquidCrystal.h> //Funciones del LCD
#include <SoftwareSerial.h>  //bluethoot
//Indica a la librería los pines de conexión del shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 

//Varables para leer las teclas y el ADC
int lcd_key     = 0;
int adc_key_in  = 0;
//variables bluthoot
SoftwareSerial BT1(4,2);//RX,TX

//Contantes para identificar las teclas
#define btnDERECHA      0
#define btnARRIBA      1
#define btnABAJO       2
#define btnIZQUIERDA   3
#define btnSELECT      4
#define btnNADA        5

  String GetLine()  
  {   String S = "" ;
    if (Serial.available())
    {    char c = Serial.read(); ;  
      while ( c != '\n')                           //Hasta que el character sea intro
      {     S = S + c ;               
	delay(25) ;                     
	c = Serial.read();              
      }
      return( S + '\n') ;             
    }
  }
//Función que lee las teclas
int read_LCD_buttons()
{
  adc_key_in = analogRead(0);      // Leer la entrada analógica

  //Las teclas se conectan a un divisor resistivo que produce distintos valores de tensión según la tecla pulsada

  if (adc_key_in > 1000) return btnNADA; //Si no hay ninguna tecla pulsada, sale para demorar menos tiempo

  if (adc_key_in < 50)   return btnDERECHA;  
  if (adc_key_in < 195)  return btnARRIBA; 
  if (adc_key_in < 380)  return btnABAJO; 
  if (adc_key_in < 555)  return btnIZQUIERDA; 
  if (adc_key_in < 790)  return btnSELECT;   


  return btnNADA;  // No debería llegar aquí, pero por las dudas retorna este valor.
}



void setup() {
  // Inicializaciones

  lcd.begin(16, 2);                 //LCD de 16 columnas y 2 filas
  lcd.clear();                      //Borrar la pantalla
  lcd.setCursor(0, 0);              //Llevar el cursor al inicio
  lcd.print("Prueba de teclas:"); 
  //inicializacion bluethoot
  Serial.begin(9600);
  Serial.println("Enter AT commands:");

}

void loop() {
  // Bucle principal del programa

  lcd.setCursor(0,1);            // Lleva el cursor al inicio de la segunda linea
  lcd_key = read_LCD_buttons();  // Lee las teclas




       if(BT1.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(BT1.read());
  }
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BT1.write(Serial.read());
  }

  switch (lcd_key)               // Imprime un texto según el valor de la tecla detectada
  {
    case btnDERECHA:
      {
	lcd.print("DERECHA  ");
	break;
      }
    case btnIZQUIERDA:
      {
	lcd.print("IZQUIERDA");
	break;
      }
    case btnARRIBA:
      {
	lcd.print("ARRIBA   ");
	break;
      }
    case btnABAJO:
      {
	lcd.print("ABAJO    ");
	break;
      }
    case btnSELECT:
      {
	lcd.print("SELECT   ");
	break;
      }
    case btnNADA:
      {
	break;
      }






  }







}
