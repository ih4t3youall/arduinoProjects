int pir= 2;
int relee = 13;

int pin2 =2;
int pin3=3;
int pin4=4;
int pin5=5;
int pin6=6;

int pieza = 1;

const int led = 13;  // the pin with a LED
int ledState = LOW;    // El LED empieza apagado
unsigned long T1;
int INTERVALO =15000;
int flag = false;

     void setup(){
	pinMode(pir, INPUT);
	pinMode(relee, OUTPUT); 
	for (int i = 7 ; i < 12 ; i++)
        	 pinMode(i, INPUT) ;
	Serial.begin(9600);
     }



    void loop(void) {

        int pire = digitalRead(pir);
        readRemote();
        if(pieza == 1){

          if(pire == HIGH){
             digitalWrite(relee,HIGH);
             T1 = millis();
           }

           if (millis() - T1 > INTERVALO) {
             digitalWrite(relee,LOW);
           }

        }
	
	if(pieza == 2){ 
            digitalWrite(relee,LOW);
        }

	if(pieza == 3){ 
            digitalWrite(relee,HIGH);
        }
   }

   int readRemote(){
     if (digitalRead(7) ){
	    Serial.print("Valid trans. \t");
            if (digitalRead(8)) 
                Serial.print( "Boton B, pulsado");
            if (digitalRead(9)) 
                Serial.print( "Boton D, pulsado");
            if (digitalRead(10)) 
              { 
                   Serial.print( "Boton A, pulsado");
		   pieza++;
		   if(pieza == 4){
		      pieza =1;
		   }
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
