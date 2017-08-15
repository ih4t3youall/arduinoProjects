int pir= 2;
int pirLiving =3;

int relee = 13;
int releeLiving =12;
int pieza = 1;
int living =1;

unsigned long T1;
unsigned long T2;
int INTERVALO =15000;
int INTERVALOLIVING = 30000;
int flag = false;

     void setup(){
	pinMode(pir, INPUT);
	pinMode(pirLiving,fINPUT);

	pinMode(releeLiving,OUTPUT);
	pinMode(relee, OUTPUT); 
	for (int i = 7 ; i < 12 ; i++)
        	 pinMode(i, INPUT) ;
	Serial.begin(9600);
     } 


    void loop(void) {
        int pire= digitalRead(pir);
        int pire = digitalRead(pireLiving);
        readRemote();
	checkLiving();
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
            if (digitalRead(8)){ 
		living++;
			if(living == 4){
				living =1;
			}
		delay(500);
	    }
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


void checkLiving(){


        if(living == 1){

          if(pire == HIGH){
             digitalWrite(releeLiving,HIGH);
             T1 = millis();
           }

           if (millis() - T2 > INTERVALOLIVING) {
             digitalWrite(releeLiving,LOW);
           }

        }
	
	if(living == 2){ 
            digitalWrite(releeLiving,LOW);
        }

	if(living == 3){ 
            digitalWrite(releeLiving,HIGH);
        }

}
