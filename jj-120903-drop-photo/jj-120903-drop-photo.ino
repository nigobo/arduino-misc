/*********************************************
 *
 * THE DROP PHOTO MACHINE
 *
 * Made by Peter Adermark & Joakim Jacobsson
 *
 ********************************************/

// PINS
const int valve = 0 ;
const int changeView = 0 ;
const int buttonValueUp = 0 ;
const int buttonValueDown = 0 ;

// VARIABLES

    // Used to keep track of what the input value is set to
    int buttonValue = 0 ;

    // This var is used to determine what view we are in
    int view = 0 ;

    // Number of drops
    int drops = 0 ;

    // The array for the drop size
    int dropSize[] ;

    // The array for the drop delay
    int dropDelay[] ;

// The setup routineo
void setup(){
    // Do some fancy drippsetup
}

// The setup routino
void void(){
    // Do some fancy dripping
}

// The button that switches the view
void viewChanger() {
    if(digitalRead(changeView) == HIGH) {
        view++ ;
    }
}