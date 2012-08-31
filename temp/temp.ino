//declare variables
float tempC;
int tempPin = 0;
int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 11;
int ledPin4 = 10;
int ledPin5 = 9;

void setup()
{
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(ledPin4, OUTPUT);
    pinMode(ledPin5, OUTPUT);
    Serial.begin(9600); //opens serial port, sets data rate to 9600 bps
}



void loop()
{
    tempC = analogRead(tempPin);            //read the value from the sensor
    tempC = (5.0 * tempC * 100.0)/1024.0;   //convert the analog data to temperature
    Serial.println((byte)tempC);            //send the data to the computer
    delay(1000);                            //wait one second before sending new data
    if (tempC > 30){
        digitalWrite(ledPin1,HIGH);
    }else{
        digitalWrite(ledPin1,LOW);
    }
    if (tempC > 29){
        digitalWrite(ledPin2,HIGH);
    }else{
        digitalWrite(ledPin2,LOW);
    }
    if (tempC > 28){
        digitalWrite(ledPin3,HIGH);
    }else{
        digitalWrite(ledPin3,LOW);
    }
    if (tempC > 27){
        digitalWrite(ledPin4,HIGH);
    }else{
        digitalWrite(ledPin4,LOW);
    }
    if (tempC > 26){
        digitalWrite(ledPin5,HIGH);
    }else{
        digitalWrite(ledPin5,LOW);
    }
}