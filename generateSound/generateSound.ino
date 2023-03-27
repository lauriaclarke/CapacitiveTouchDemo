/*

CAPACITIVE TOUCH DEMO 

This sketch demonstrates the generation of a simple tone.

You should have a small plastic speaker or peizio buzzer connected 
between pin 2 and ground.

Please refer to the tone() fucntion for more info:
https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/

*/

//---------------------------
// PINOUT

// connect the speaker between this pin and ground (GND)
#define SPEAKER_PIN    2


//---------------------------
// TONE PARAMETERS

// frequency in Hz of the tone
#define TONE_FREQUENCY 500

// length of the tone in ms
#define TONE_LENGTH    2000


//---------------------------
// SETUP

void setup() {
  
  // setup the speaker pin as output
  pinMode(SPEAKER_PIN, OUTPUT);
  
}

//---------------------------
// SETUP

void loop() {
  
  // call the tone function
  tone(SPEAKER_PIN, TONE_FREQUENCY, TONE_LENGTH);
  
  delay(TONE_LENGTH * 1.5);
  
  noTone(SPEAKER_PIN);

}
