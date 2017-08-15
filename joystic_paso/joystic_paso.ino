int xPin = A1;
int yPin = A0;
int buttonPin = 2;

int x = 0;
int y = 0;
int buttonState = 0;


//motor 2
#define motorPin1  7    // 28BYJ48 In1
#define motorPin2  6    // 28BYJ48 In2
#define motorPin3  5   // 28BYJ48 In3
#define motorPin4  4   // 28BYJ48 In4
//motor 2


#define IN1  12
#define IN2  11
#define IN3  10
#define IN4  9

int steps_left=4095;
int steps_left2=4095;
boolean Direction = true;
boolean Direction2 = true;
int Steps = 0;
int steps2 = 0;

int Paso [ 8 ][ 4 ] =
    {   {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {1, 0, 0, 1}
     };




void setup() {
  // inicializar las comunicaciones en serie a 9600 bps:
  Serial.begin(9600); 
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  //activar resistencia pull-up en el pin pulsador 
  pinMode(buttonPin, INPUT_PULLUP); 
  
  // Para las versiones anteriores a 1.0.1 Arduino 
  // pinMode (buttonPin, INPUT); 
  // digitalWrite (buttonPin, HIGH);
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 

  //motor 2
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  //motor2
  
}

void loop() {
  x = analogRead(xPin);
  y = analogRead(yPin);
  buttonState = digitalRead(buttonPin);

  if((0 <= y) && (y < 50) && (450 <x) && (x <550)){
  
      Direction2= false;
      stepper2();
    
    }

    if((1050 > y)&&(y > 900) && (450<x)&&(x<550)){
     
      Direction2= true;
      stepper2();
     
    }

  if((450 < y)&&(y < 550)&& (1050 > x)&&(x > 900)){
     Direction=false;
     stepper() ;    // Avanza un paso
    }

  if((0 <= x) && (x < 50) && (450 <y) && (y <550)){
     Direction=true;
     stepper();
    }
  
  delay(5);
}


void stepper()            //Avanza un paso
{
  digitalWrite( IN1, Paso[Steps][ 0] );
  digitalWrite( IN2, Paso[Steps][ 1] );
  digitalWrite( IN3, Paso[Steps][ 2] );
  digitalWrite( IN4, Paso[Steps][ 3] );
  
  SetDirection();
}


void stepper2()            //Avanza un paso
{
  digitalWrite( motorPin1, Paso[steps2][ 0] );
  digitalWrite( motorPin2, Paso[steps2][ 1] );
  digitalWrite( motorPin3, Paso[steps2][ 2] );
  digitalWrite( motorPin4, Paso[steps2][ 3] );
  
  SetDirection2();
}


void SetDirection()
{
    if(Direction){
        Steps++;
    }
    else{ 
        Steps--; 
    }
     
    Steps = ( Steps + 7 ) % 7 ;
}


void SetDirection2()
{
    if(Direction2)
        steps2++;
    else 
        steps2--; 
     
    steps2= ( steps2+ 7 ) % 7 ;
}




