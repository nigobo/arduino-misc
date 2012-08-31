/*****************************************************
 * Setup all the vars
 *****************************************************/

int ledPins[] = { 4, 5, 6, 7, 8, 9,10,11,12,13 };
int button = 3 ;
int lightModifier = 0 ;
int digit = 0 ;
char stringOne[] = "Bananaking" ;

/*****************************************************
 * Do the setup
 *****************************************************/

void setup() {

	int numberOfLeds = sizeof(ledPins)/2;

	for (int thisPin = 0 ; thisPin < numberOfLeds ; thisPin ++) {
		pinMode(ledPins [thisPin], OUTPUT) ;
	}

	Serial.begin(9600) ;

	pinMode(button, INPUT);

	attachInterrupt(1,kicker,RISING) ;

}

/*****************************************************
 * Enter the void
 *****************************************************/

void loop() {

	showDigit(digit);
	delay(100);
	Serial.println(stringOne.length());

}

/*****************************************************
 * Create the kickerfunctions
 *****************************************************/

void kicker() {
	digit = 8;
}

/*****************************************************
 * Function showDigit
 *****************************************************/

void showDigit(int digit) {

	for (int thisPin = 0 ; thisPin < digit ; thisPin ++) {
		digitalWrite(ledPins [thisPin], HIGH);
	}

}
