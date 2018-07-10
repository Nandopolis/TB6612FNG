#include "Arduino.h"
#include "TB6612FNG.h"

TB6612FNG::TB6612FNG (uint8_t pwmA, uint8_t in1A, uint8_t in2A, uint8_t stby, bool d=1) {
	this->pwmPin=pwmA;
	this->in1Pin=in1A;
	this->in2Pin=in2A;
	this->stbyPin=stby;
	this->dir=d;
}

void TB6612FNG::Setup() {
    	pinMode(this->stbyPin, OUTPUT);
    	pinMode(this->in1Pin, OUTPUT);
    	pinMode(this->in2Pin, OUTPUT);
    	pinMode(this->pwmPin, OUTPUT);

    	digitalWrite(this->stbyPin, this->normal);
    	digitalWrite(this->in1Pin, 0);
    	digitalWrite(this->in2Pin, 0);
    	analogWrite(this->pwmPin, 0);
}

void TB6612FNG::Move(int16_t velocity) {
    	if (dir) {
      		if (velocity < 0) this->MoveRaw(0, 1, (uint8_t)(-velocity));
      		else this->MoveRaw(1, 0, (uint8_t)velocity);
   	}
    	else {
      		if (velocity > 0) this->MoveRaw(0, 1, (uint8_t)(-velocity));
      		else this->MoveRaw(1, 0, (uint8_t)velocity);
    	}
}

void TB6612FNG::MoveRaw(bool in1, bool in2, uint8_t velocity) {
    	digitalWrite(this->in1Pin, in1);
    	digitalWrite(this->in2Pin, in2);
    	analogWrite(this->pwmPin, velocity);
}

void TB6612FNG::Brake(){
    	digitalWrite(this->in1Pin, 1);
    	digitalWrite(this->in2Pin, 1);
}

void TB6612FNG::Mode(bool mode){
    	digitalWrite(this->stbyPin, mode);
}