#include "Arduino.h"
#include "TB6612FNG.h"

TB6612FNG::TB6612FNG (uint8_t pwmA, uint8_t in1A, uint8_t in2A, uint8_t stby, bool d=1) {
	pwmPin=pwmA;
	in1Pin=in1A;
	in2Pin=in2A;
	stbyPin=stby;
	dir=d;
}

void TB6612FNG::Setup() {
    	pinMode(stbyPin, OUTPUT);
    	pinMode(in1Pin, OUTPUT);
    	pinMode(in2Pin, OUTPUT);
    	pinMode(pwmPin, OUTPUT);

    	digitalWrite(stbyPin, normal);
    	digitalWrite(in1Pin, 0);
    	digitalWrite(in2Pin, 0);
    	analogWrite(pwmPin, 0);
}

void TB6612FNG::Move(int16_t velocity) {
    	if (dir) {
      		if (velocity < 0) MoveRaw(0, 1, (uint8_t)(-velocity));
      		else MoveRaw(1, 0, (uint8_t)velocity);
   	}
    	else {
      		if (velocity > 0) MoveRaw(0, 1, (uint8_t)(-velocity));
      		else MoveRaw(1, 0, (uint8_t)velocity);
    	}
}

void TB6612FNG::MoveRaw(bool in1, bool in2, uint8_t velocity) {
    	digitalWrite(in1Pin, in1);
    	digitalWrite(in2Pin, in2);
    	analogWrite(pwmPin, velocity);
}

void TB6612FNG::Brake(){
    	digitalWrite(in1Pin, 1);
    	digitalWrite(in2Pin, 1);
}

void TB6612FNG::Mode(bool mode){
    	digitalWrite(stbyPin, mode);
}