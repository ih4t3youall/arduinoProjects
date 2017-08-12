

int pin2 =2;
int pin3=3;
int pin4=4;
int pin5=5;
int pin6=6;


void setup()
   {  Serial.begin (9600);
      pinMode (13, OUTPUT) ;
      pinMode (12, OUTPUT) ;
      for (int i = 7 ; i < 12 ; i++)
           pinMode(i, INPUT) ;
   }

void loop() 
   {   
      if (digitalRead(7) )     // Si hay dato valido
         {  Serial.print("Valid trans. \t");
            if (digitalRead(8)) 
                Serial.print( "Boton B, pulsado");
            if (digitalRead(9)) 
                Serial.print( "Boton D, pulsado");
            if (digitalRead(10)) 
              { 
                   Serial.print( "Boton A, pulsado");
                   digitalWrite (12, ! digitalRead(12)) ;
                   delay (500) ;
               }
            if (digitalRead(11))
               { 
                   Serial.print( "Boton C, pulsado");
                   digitalWrite (13, ! digitalRead(13)) ;
                   delay (500) ;
               }
            Serial.println("\t");
         } 
   }


