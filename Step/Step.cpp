/// @file Step.cpp
/// @brief Class for basic tasks for a stepper motor and stepper motor driver "Pololu A4988 Stepper Motor Driver Carrier, Black Edition"
/// @author Sarah Lindner
/// @date 03/28/2014

#include "Step.h"


int Step::SetDelayTime( int time ) {

	delay_time = time;
}



void Step::SetIntermediateDelayTime( int intermediate_time ) {

	intermediate_delay_time = intermediate_time;

}



void Step::StepPinSignals( ) {

	digitalWrite( stepPin, HIGH ); //step!  
	delayMicroseconds( intermediate_delay_time );               
	digitalWrite( stepPin, LOW );  
	delayMicroseconds( delay_time );

}


void Step::SetMovement( ) {

	// send data only when you receive data:
	if ( Serial.available() > 0 ) { //check for incoming data

		step_state = Serial.read() ; // read the incoming byte:

	} 


	switch ( step_state ) {

		case 'F':





		
	}


}



void Step::Movement(  ) {



}

