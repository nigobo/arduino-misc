int led1 = 10;
int led2 = 11;
int led3 = 12;
int led4 = 13;

int btn = 8 ;

int strength = 0 ;
int bounce = 0 ;
int tmp = 0;
int ledstatus = 0;

void setup() {
 // Setup LCD

  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);

  pinMode (btn, INPUT);

  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Obogin!");  // prints hello with ending line break
}

void loop(){
 Serial.println("begin variable light");

 tmp = digitalRead(btn);

 if (tmp == HIGH){

   if(ledstatus == 0){
     analogWrite(led2, 220);
      ledstatus = 1;
   }else{
     digitalWrite(led2,LOW);
     ledstatus = 0;
   }


   delay(600);


 }


//analogWrite(led1,10);
//digitalWrite(led2, LOW);
//delay(1000);
//analogWrite(led1, 200);
//digitalWrite(led2, HIGH);
//delay(1000);
}
