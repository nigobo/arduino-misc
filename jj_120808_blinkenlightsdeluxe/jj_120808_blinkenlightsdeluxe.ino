int blinkenlightmode = 3 ;
int knightriderflow = 0 ;
int btnvalue = 0 ;
int btn = 2 ;

void setup() {

  // Set up serial
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Obogin!");  // prints hello with ending line break

  // set outputs
  for (int thisPin = 4; thisPin < 14; thisPin++) { 
    pinMode(thisPin, OUTPUT);    
  }

  // Set button pin
  pinMode (btn, INPUT);

}

void loop(){

  btnvalue = digitalRead(btn);

  if(btnvalue == 1){
    btnvalue = 0 ;
    blinkenlightmode++ ;
    delay(10);
    Serial.println(blinkenlightmode);
    if(blinkenlightmode >=4){
      blinkenlightmode = 0 ;
    }
  }

  switch (blinkenlightmode) {
    case 1:
      
      // FlowOne Mode
      for (int thisPin = 4; thisPin < 14; thisPin++) { 
        // set outputs
        digitalWrite(thisPin, HIGH);

        delay(50);

        // off
        digitalWrite(thisPin, LOW);

      }

      break;
    case 2:
      // Bounce Mode
  
      if(knightriderflow == 0){
        
        for (int thisPin = 4; thisPin < 14; thisPin++) { 

          digitalWrite(thisPin, HIGH);

          delay(thisPin*thisPin);

          // off
          digitalWrite(thisPin, LOW);

          if(thisPin == 13){
            knightriderflow = 1 ;
          }
        }
      }else{
        for (int thisPin = 13; thisPin > 3; thisPin--) { 

          digitalWrite(thisPin, HIGH);

          delay(thisPin*thisPin);

          // off
          digitalWrite(thisPin, LOW);

          if(thisPin == 4){
            knightriderflow = 0 ;
          }
         
        }
      }
      break;
    case 3:
      // Knigtrider Mode
  
      if(knightriderflow == 0){
        
        for (int thisPin = 4; thisPin < 14; thisPin++) { 

          digitalWrite(thisPin, HIGH);

          delay(40);

          // off
          digitalWrite(thisPin, LOW);

          if(thisPin == 13){
            knightriderflow = 1 ;
          }
        }
      }else{
        for (int thisPin = 13; thisPin > 3; thisPin--) { 

          digitalWrite(thisPin, HIGH);

          delay(40);

          // off
          digitalWrite(thisPin, LOW);

          if(thisPin == 4){
            knightriderflow = 0 ;
          }
         
        }
      }
      break;

    default: 

      // TheAllLed Mode
      for (int thisPin = 4; thisPin < 14; thisPin++) { 
        // set outputs
        digitalWrite(thisPin, HIGH);
      }

      delay(400);

      for (int thisPin = 4; thisPin < 14; thisPin++) { 

        // off
        digitalWrite(thisPin, LOW);
      }

      delay(400);


      break;
   
  }
  
}

