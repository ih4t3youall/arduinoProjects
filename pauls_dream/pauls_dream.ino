struct pieza{
				int pirPieza=2;
				int releePieza=13;
				int modoPieza=1;
				unsigned long T1=0;
				int INTERVALOPIEZA =15000;

}pieza,*pPieza=&pieza;

struct living{
				int pirLiving=3;
				int releeLiving=12;
				int modoLiving=1;
				unsigned long T1=0;
				int INTERVALOLIVING = 30000;

}living,*pLiving=&living;

int led = 12;
int flag = false;
int buttonPieza = 6;

void setup(){

				pinMode(pLiving->releeLiving,OUTPUT);
				pinMode(pPieza->releePieza, OUTPUT); 
				pinMode(led,OUTPUT);
				pinMode(buttonPieza,INPUT);
				for (int i = 7 ; i < 12 ; i++)
								pinMode(i, INPUT) ;
				Serial.begin(9600);
} 

void loop(void) {
				readRemote();
				checkLiving();
				checkPieza();
				btnPieza();
}
int btnPieza(){

				if(digitalRead(buttonPieza)){
								pPieza->modoPieza++;
				}	
				if(pPieza->modoPieza == 4){

								pPieza->modoPieza=1;
				}
				delay(500);


}
int readRemote(){
				if (digitalRead(7) ){
								Serial.print("Valid trans. \t");
								if (digitalRead(8)){ 
												pLiving->modoLiving ++;
												if(pLiving->modoLiving == 4){
																pLiving->modoLiving =1;
												}
												delay(500);
								}
								if (digitalRead(9)) 
												Serial.print( "Boton D, pulsado");
								if (digitalRead(10)) 
								{ 
												Serial.print( "Boton A, pulsado");
												pPieza->modoPieza++;
												if(pPieza->modoPieza== 4){
																pPieza->modoPieza=1;
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
				int pire= digitalRead(pPieza->pirPieza);
				if(pPieza->modoPieza == 1){

								digitalWrite(led,LOW);
								if(pire == HIGH){
												digitalWrite(pPieza->releePieza,HIGH);
												pPieza->T1 = millis();
								}

								if (millis() - pPieza->T1 > pPieza->INTERVALOPIEZA) {
												digitalWrite(pPieza->releePieza,LOW);
								}

				}

				if(pPieza->modoPieza == 2){ 
								digitalWrite(pPieza->releePieza,LOW);
				}

				if(pPieza->modoPieza == 3){ 
								digitalWrite(pPieza->releePieza,HIGH);
								digitalWrite(led,HIGH);
				}
}

void checkLiving(){
				int pire = digitalRead(pLiving->pirLiving);
				if(pLiving->modoLiving== 1){

								if(pire == HIGH){
												digitalWrite(pLiving->releeLiving,HIGH);
												pLiving->T1 = millis();
								}

								if (millis() - pLiving->T1  > pLiving->INTERVALOLIVING) {
												digitalWrite(pLiving->releeLiving,LOW);
								}

				}

				if(pLiving->modoLiving== 2){ 
								digitalWrite(pLiving->releeLiving,LOW);
				}

				if(pLiving->modoLiving== 3){ 
								digitalWrite(pLiving->releeLiving,HIGH);
				}

}
