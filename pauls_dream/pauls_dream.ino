int pirPieza= 2;
int pirLiving =3;

int releePieza = 13;
int releeLiving =12;

int modoPieza = 1;
int modoLiving =1;

unsigned long T1;
unsigned long T2;

int INTERVALOPIEZA =15000;
int INTERVALOLIVING = 30000;
int flag = false;

void setup(){
				pinMode(pirPieza, INPUT);
				pinMode(pirLiving,INPUT);

				pinMode(releeLiving,OUTPUT);
				pinMode(releePieza, OUTPUT); 

				for (int i = 7 ; i < 12 ; i++)
								pinMode(i, INPUT) ;
				Serial.begin(9600);
} 


void loop(void) {
				readRemote();
				checkLiving();
				checkPieza();
}

int readRemote(){
				if (digitalRead(7) ){
								Serial.print("Valid trans. \t");
								if (digitalRead(8)){ 
												modoLiving ++;
												if(modoLiving  == 4){
																modoLiving =1;
												}
												delay(500);
								}
								if (digitalRead(9)) 
												Serial.print( "Boton D, pulsado");
								if (digitalRead(10)) 
								{ 
												Serial.print( "Boton A, pulsado");
												modoPieza++;
												if(modoPieza == 4){
																modoPieza =1;
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

void checkPieza(){
				int pire= digitalRead(pirPieza);
				if(modoPieza == 1){

								if(pire == HIGH){
												digitalWrite(releePieza,HIGH);
												T1 = millis();
								}

								if (millis() - T1 > INTERVALOPIEZA) {
												digitalWrite(releePieza,LOW);
								}

				}

				if(modoPieza == 2){ 
								digitalWrite(releePieza,LOW);
				}

				if(modoPieza == 3){ 
								digitalWrite(releePieza,HIGH);
				}
}

void checkLiving(){
				int pire = digitalRead(pirLiving);
				if(modoLiving == 1){

								if(pire == HIGH){
												digitalWrite(releeLiving,HIGH);
												T1 = millis();
								}

								if (millis() - T2 > INTERVALOLIVING) {
												digitalWrite(releeLiving,LOW);
								}

				}

				if(modoLiving == 2){ 
								digitalWrite(releeLiving,LOW);
				}

				if(modoLiving == 3){ 
								digitalWrite(releeLiving,HIGH);
				}

}

