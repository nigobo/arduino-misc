/*
  Alexander

  Alexanders own led and button playground.

 */

int ledPins[] = { 4, 5, 6, 7, 8, 9,10,11,12,13 };
int function = 3 ;
int button = 2 ;

// light modifier
int lightModifier = 0 ;

char action;


// the setup routine runs once when you press reset:
void setup() {

  Serial.begin(9600) ;
  ledControl(action='setup') ;
  pinMode(button, INPUT);

  attachInterrupt(0,kicker,RISING) ;

}

// the loop routine runs over and over again forever:
void loop() {

  switch (function) {

    case 0:
      ledControl(action='blink') ;
    break;

    case 1:
      ledControl(action='runningLight') ;
    break;

    case 2:
      ledControl(action='flash') ;
    break;

    case 3:
      ledControl(action='knightrider') ;
    break;

    case 4:
      ledControl(action='clappinghands') ;
    break;

    case 5:
      ledControl(action='jumpside') ;
    break;

    case 6:
      ledControl(action='knightriderinverted') ;
    break;

    default:
      // Reset the function-var
      function = 0 ;
    break;
  }

}

void kicker() {
  if(digitalRead(button) == HIGH) {
    function++ ;
  }
}

void ledControl(char action) {

  int numberOfLeds = sizeof(ledPins)/2;

  switch (action) {

    case 'setup':

      for (int thisPin = 0 ; thisPin < numberOfLeds ; thisPin ++) {
        pinMode(ledPins [thisPin], OUTPUT) ;
      }

    break;

    case 'blink':

      for (int thisPin = 0 ; thisPin < numberOfLeds ; thisPin ++) {
        digitalWrite(ledPins [thisPin], HIGH);
      }

      delay(800);

      for (int thisPin = 0 ; thisPin < numberOfLeds ; thisPin ++) {
        digitalWrite(ledPins [thisPin], LOW);
      }
      delay(800);

    break;

    case 'flash':

      for (int thisPin = 0 ; thisPin < numberOfLeds ; thisPin ++) {
        digitalWrite(ledPins [thisPin], HIGH);
      }

      delay(30);

      for (int thisPin = 0 ; thisPin < numberOfLeds ; thisPin ++) {
        digitalWrite(ledPins [thisPin], LOW);
      }

      delay(1500);

    break;

    case 'runningLight':

      for (int thisPin = 0 ; thisPin < numberOfLeds ; thisPin ++) {
        digitalWrite(ledPins [thisPin], HIGH);
        delay (50) ;
      }

      delay (200);

      for (int thisPin = 0 ; thisPin < numberOfLeds ; thisPin ++) {
        digitalWrite(ledPins [thisPin], LOW);
        delay (50) ;
      }

      delay (700);

    break;

    case 'knightrider':

    Serial.println(lightModifier);
      if(lightModifier == 0){

        for (int thisPin = 0 ; thisPin < numberOfLeds ; thisPin ++) {

          digitalWrite(ledPins [thisPin], HIGH);

          delay(100);

          digitalWrite(ledPins [thisPin], LOW);

          if(thisPin < numberOfLeds){
            lightModifier = 1 ;
          }
        }

      }else{

        // thisPin = (numberOfLeds-1) because it starts at 10
        // thisPin >= 0 because otherwise the animations stops to early
        for (int thisPin = (numberOfLeds-1); thisPin >= 0 ; thisPin --) {

          digitalWrite(ledPins [thisPin], HIGH);

          delay(100);

          // off
          digitalWrite(ledPins [thisPin], LOW);

          if(thisPin > 0){
            lightModifier = 0 ;
          }

        }
      }
    break;

    case 'knightriderinverted':

      for (int thisPin = 0 ; thisPin < numberOfLeds ; thisPin ++) {
        digitalWrite(ledPins [thisPin], HIGH);
      }

      if(lightModifier == 0){

        for (int thisPin = 0 ; thisPin < numberOfLeds ; thisPin ++) {

          digitalWrite(ledPins [thisPin], LOW);

          delay(60);

          digitalWrite(ledPins [thisPin], HIGH);

          if(thisPin < numberOfLeds){
            lightModifier = 1 ;
          }
        }

      }else{

        // thisPin = (numberOfLeds-1) because it starts at 10
        // thisPin >= 0 because otherwise the animations stops to early
        for (int thisPin = (numberOfLeds-1); thisPin >= 0 ; thisPin --) {

          digitalWrite(ledPins [thisPin], LOW);

          delay(60);

          // off
          digitalWrite(ledPins [thisPin], HIGH);

          if(thisPin > 0){
            lightModifier = 0 ;
          }

        }
      }
    break;

    case 'clappinghands':

        Serial.println("startloop");
        Serial.println("");

        for (int thisPin = 0 ; thisPin < numberOfLeds ; thisPin ++) {

          lightModifier = 9-thisPin;

          digitalWrite(ledPins [lightModifier], HIGH);
          digitalWrite(ledPins [thisPin], HIGH);

          delay(50);

          digitalWrite(ledPins [thisPin], LOW);
          digitalWrite(ledPins [lightModifier], LOW);

        }


    break;

    case 'jumpside':

        int sideSelector = 1 ;

        for (int thisPin = 0 ; thisPin < numberOfLeds ; thisPin ++) {

          lightModifier = 9-thisPin;

          if(sideSelector == 1){
            digitalWrite(ledPins [lightModifier], HIGH);
          }else{
            digitalWrite(ledPins [thisPin], HIGH);
          }

          delay(400);

          if(sideSelector == 1){
            digitalWrite(ledPins [lightModifier], LOW);
            sideSelector = 0 ;
          }else{
            digitalWrite(ledPins [thisPin], LOW);
            sideSelector = 1 ;
          }

        }

    break;

  }
}
