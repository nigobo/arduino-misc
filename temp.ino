/*
  Alexander

  Alexanders own led and button playground.

 */

int temp = 10;
int acctualTemp = 0;


// the setup routine runs once when you press reset:
void setup() {

  Serial.begin(9600) ;
  pinMode(temp, INPUT);

}

// the loop routine runs over and over again forever:
void loop() {

  acctualTemp = analogRead(temp);
  Serial.println(acctualTemp);
}
