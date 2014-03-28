/// @file stepper_motor_control.ino
/// @brief Control a single stepper motor using "Arduino Leonardo" and stepper motor driver "Pololu A4988 Stepper Motor Driver Carrier, Black Edition"
/// @author Sarah Lindner
/// @date 03/28/2014

/**
each stepper motor is associated with 2 end buttons

simple A4988 connection:
jumper reset and sleep together
connect  VDD to Arduino 5v
connect  GND to Arduino GND (GND near VDD)
connect  1A and 1B to stepper coil 1
connect 2A and 2B to stepper coil 2
connect VMOT to power source 
connect GRD to power source

connect pin 10 to dirPin
connect pin 11 to stepPin
connect pin 12 to sleepPin
connect pin 8 to MS1
connect pin 9 to MS2


connect pin 7 to end buttons, forward
connect pin 6 to end buttons, backward
**/

#include "Step.h"



// function prototypes (not actually needed for Arduino, because they are created by the compiler, but good coding practice)
//print standard directions
void print_directions();





// pin declaration---------------------------------------------------

// pins for motor control
const int dir_pin = 10;  
const int step_pin = 11;  
const int sleep_pin = 12;

//pins for microstepping
const int micro_step1 = 8;
const int micro_step2 = 9;

//pins for end button control
const int end_forward = 7; 
const int end_backward = 6;






// global variables-------------------------------------------------

// input variable from serial monitor
// char state = '~';
// char state_old = '~';

//initialize Step class
Step Stepping;

// delay time 
// int delay_time = 50;








void setup(){

while(!Serial){;}       // needed for Ardiuno Leonardo to wait with executing until terminal is open
Serial.begin(9600);           // set up Serial library at 9600 bps  


Serial.println("Beginning stepper motor configuration.");               



//set pin mode for all motor pins
pinMode(dir_pin, OUTPUT);
pinMode(step_pin, OUTPUT);
pinMode(sleep_pin, OUTPUT);



//set pin mode for all end button pins 
pinMode(end_forward, INPUT);
pinMode(end_backward, INPUT);


//set pin mode for microstepping
pinMode(micro_step1, OUTPUT);   
pinMode(micro_step2, OUTPUT);   


Stepping.SetIntermediateDelayTime( 10 );



Serial.println("Enter delay time.");

// send data only when you receive data:
if (Serial.available() > 0) { //check for incoming data

	Stepping.SetDelayTime( Serial.read() ); // read the incoming byte:

}




print_directions();

}










void loop(){

// send data only when you receive data:
if (Serial.available() > 0) { //check for incoming data

	Stepping.Movement ( Serial.read() ); // read the incoming byte:

}


}










//print standard directions
void print_directions(){

  Serial.println("To run motor forward, enter 'F'.");
  Serial.println("To run motor backward, enter 'B'.");
  Serial.println("To stop motor, enter 's'.");
  Serial.println("To make a small movement forward, enter 'f'.");
  Serial.println("To make a small movement backward, enter 'b'.");
  Serial.println("To toggle microsep mode Half, enter '2'.");
  Serial.println("To toggle microsep mode Quarter, enter '4'.");
  Serial.println("To toggle microsep mode Eighth, enter '8'.");


}






