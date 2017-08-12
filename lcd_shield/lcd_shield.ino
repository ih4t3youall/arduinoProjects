/*  ----------------------------------------------------------------
    http://www.prometec.net
    Prog_84_1
    
    Usando un Arduino keypad Shield
    http://www.prometec.net/lcd-keypad-shield/
--------------------------------------------------------------------  
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// define some values used by the panel and buttons
int lcd_key     = 0;
int key  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

void setup()
{
 lcd.begin(16, 2);              // Inicializar el LCD
 lcd.setCursor(0,0);
 lcd.print("Prometec.net");     // print a simple message
 Serial.begin(9600);
}
 
void loop()
{
   lcd.setCursor(9,1);            // Cursor a linea 2, posicion 9
   lcd.print(millis()/1000);      // Imprime segundos
   lcd.setCursor(13, 0);          // Cursor a linea 1, posicion 13
   lcd.print(key);                // Imprime el valor leido en la puerta A0
   lcd.setCursor(0,1);            // Cursor a linea 2, posicion 1
 
   lcd_key = read_LCD_buttons();  
  
   if( lcd_key == btnRIGHT){
       lcd.print("RIGHT ");
   }
   else if ( lcd_key == btnLEFT ){
       lcd.print("LEFT   ");
   }
   else if ( lcd_key == btnUP){
       lcd.print("UP    ");
   }
   else if ( lcd_key == btnDOWN){
       lcd.print("DOWN  ");
   }
   else if ( lcd_key == btnSELECT){
       lcd.print("SELECT");
   }
   else if ( lcd_key == btnNONE){
       lcd.print("NONE  ");
   }
}

int read_LCD_buttons()  // Lee los botones y devuelve le valor pulsado
{
 key = analogRead(0);      // Leemos la puerta A0 
 // Mis botones dan:  0, 145, 329,507,743 ; Comprueba que tu shield devuelve valores parecidos
 // Y ahora los comparamos con un margen comodo

 if (key > 1000) return btnNONE; //Si no se pulsa nada salimos (el 99% de las veces) 
 if (key < 50)   return btnRIGHT;  
 if (key < 250)  return btnUP; 
 if (key < 450)  return btnDOWN; 
 if (key < 650)  return btnLEFT; 
 if (key < 850)  return btnSELECT;  

 return btnNONE;  // when all others fail, return this...
}
