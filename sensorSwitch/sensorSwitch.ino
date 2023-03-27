/*

CAPACITIVE TOUCH DEMO

This sketch changes the state of an output depending on whether a touch
sensor has been activated.

Adjusting AVERAGE_COUNT, SENSOR_RESOLUTION, and SENSOR_THERSHOLD will 
change the sensitivity and accuracy of your switch.

You should first adjust the calibration of the sensor and to
understand the baseline values read when the sensor is "on" and "off".

Please refer to the CapacitiveSensor library for more info on its 
builtin functionlities: https://playground.arduino.cc/Main/CapacitiveSensor/

*/

#include <CapacitiveSensor.h>

//---------------------------
// PINOUT

// plain resistor side
#define SENSOR_PIN_A 8

// side that your "sensor" is connected to
#define SENSOR_PIN_B 12


//---------------------------
// SENSOR MATH VALUES

// number of samples to average for a reading
#define AVERAGE_COUNT 30

// value above which we register a change in state
// should be experimentally determied from baseline sketch
#define SENSOR_THRESHOLD 1000


//---------------------------
// SENSOR INSTANTIATION

// defines how many sampels the sensor takes internally to computer capacitance
// will effect the amount of time required for a reading, but also the scale of values
#define SENSOR_RESOLUTION 30

// this is where we define our sensor
// make sure the "sensor" side of your sensor is the second argument, ie. SENSOR_PIN_B
CapacitiveSensor mySensor = CapacitiveSensor(SENSOR_PIN_A, SENSOR_PIN_B); 


//---------------------------
// SETUP

void setup() {
  
  // start serial communications
  Serial.begin(9600); 
  
  // turn off autocalibration for this sensor 
  mySensor.set_CS_AutocaL_Millis(0xFFFFFFFF);
  
  // setup the builtin LED
  pinMode(LED_BUILTIN, OUTPUT);
  
}


//---------------------------
// LOOP

void loop() {

  // if the function returns true, switch the state of the LED
  if(readSensor()){
    // get the state of the LED
    int ledState = digitalRead(LED_BUILTIN);
    // write the opposite
    digitalWrite(LED_BUILTIN, !ledState);
  }
  
}


//---------------------------
// SENSOR FUNCTIONALITY

bool readSensor(){
  
  // a value to store our average
  long sensorSum = 0;
  
  // collect sensor values and sum them up t ocalcualte an average
  for(int i = 0; i < AVERAGE_COUNT; i++){
    long sensorValue =  mySensor.capacitiveSensor(SENSOR_RESOLUTION);
    sensorSum += sensorValue;
  }
  
  // get the average value of the sensor over AVERAGE_COUNT samples
  long sensorAverage = sensorSum / AVERAGE_COUNT;

  // if the average is greather than the desired threshold return true
  if(sensorAverage > SENSOR_THRESHOLD){
    Serial.println(sensorAverage);
    return true; 
  }
  
  return false;
  
}
