struct abitacion{
				int pir=2;
				int relee=13;
				int modo=1;
				unsigned long T1=0;
				int INTERVALO =15000;

};

int led = 12;
struct abitacion *pPieza;
struct abitacion *pLiving;
int flag = false;
int buttonPieza = 6;

void setup(){
				pPieza= malloc(sizeof(struct abitacion));
				pLiving= malloc(sizeof(struct abitacion));
				initAll();
				pinMode(led,OUTPUT);
				pinMode(buttonPieza,INPUT);
				pinMode(pLiving->relee,OUTPUT);
				pinMode(pPieza->relee, OUTPUT); 
				for (int i = 7 ; i < 12 ; i++)
								pinMode(i, INPUT) ;
				Serial.begin(9600);
} 

void initAll(){
				//inicializo la pieza
				pPieza->pir=2;
				pPieza->relee=13;
				pPieza->modo=1;
				pPieza->T1=0;
				pPieza->INTERVALO=15000;
				//inicializo el living
				pLiving->pir=3;
				pLiving->relee=12;
				pLiving->modo=1;
				pLiving->T1=0;
				pLiving->INTERVALO=30000;
}


void loop(void) {
				readRemote();
				checkLiving();
				checkPieza();
				btnPieza();
}
int btnPieza(){

				if(digitalRead(buttonPieza)){
								pPieza->modo++;
				}	
				if(pPieza->modo== 4){

								pPieza->modo=1;
				}
				delay(250);


}
int readRemote(){
				if (digitalRead(7) ){
								Serial.print("Valid trans. \t");
								if (digitalRead(8)){ 
												pLiving->modo++;
												if(pLiving->modo== 4){
																pLiving->modo=1;
												}
												delay(500);
								}
								if (digitalRead(9)) 
												Serial.print( "Boton D, pulsado");
								if (digitalRead(10)) 
								{ 
												Serial.print( "Boton A, pulsado");
												pPieza->modo++;
												if(pPieza->modo== 4){
																pPieza->modo=1;
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
				int pire= digitalRead(pPieza->pir);
				if(pPieza->modo== 1){

								digitalWrite(led,LOW);
								if(pire == HIGH){
												digitalWrite(pPieza->relee,HIGH);
												pPieza->T1 = millis();
								}

								if (millis() - pPieza->T1 > pPieza->INTERVALO) {
												digitalWrite(pPieza->relee,LOW);
								}

				}

				if(pPieza->modo== 2){ 
								digitalWrite(pPieza->relee,LOW);
				}

				if(pPieza->modo== 3){ 
								digitalWrite(pPieza->relee,HIGH);
								digitalWrite(led,HIGH);
				}
}

void checkLiving(){
				int pire = digitalRead(pLiving->pir);
				if(pLiving->modo == 1){

								if(pire == HIGH){
												digitalWrite(pLiving->relee,HIGH);
												pLiving->T1 = millis();
								}

								if (millis() - pLiving->T1  > pLiving->INTERVALO) {
												digitalWrite(pLiving->relee,LOW);
								}

				}

				if(pLiving->modo == 2){ 
								digitalWrite(pLiving->relee,LOW);
				}

				if(pLiving->modo == 3){ 
								digitalWrite(pLiving->relee,HIGH);
				}

}
