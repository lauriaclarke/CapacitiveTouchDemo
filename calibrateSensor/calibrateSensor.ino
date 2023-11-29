/*

CAPACITIVE TOUCH DEMO 

This sketch prints the value of a capacitive sensor connected 
between two pins of the Arduino.

It should be used to adjust the calibration of the sensor and to
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
#define SENSOR_PIN_B 9

//---------------------------
// MATH VALUES
#define AVERAGE_COUNT 100

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
  
}

//---------------------------
// LOOP

void loop() {
  
  // a value to store our average
  long sensorSum = 0;
  
  // collect sensor values and sum them up t ocalcualte an average
  for(int i = 0; i < AVERAGE_COUNT; i++){
    long sensorValue =  mySensor.capacitiveSensor(SENSOR_RESOLUTION);
    sensorSum += sensorValue;
  }
  
  // get the average value of the sensor over AVERAGE_COUNT samples
  long sensorAverage = sensorSum / AVERAGE_COUNT;

  // prin the values
  Serial.println(sensorAverage);         

}
