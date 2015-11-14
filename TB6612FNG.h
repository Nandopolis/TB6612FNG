#ifndef TB6612FNG_h
#define TB6612FNG_h

#include "Arduino.h"

class TB6612FNG {
	private:
		uint8_t pwmPin, in1Pin, in2Pin, stbyPin;
  		boolean dir;
	
	public:
  		TB6612FNG (uint8_t pwmA, uint8_t in1A, uint8_t in2A, uint8_t stby, bool d=1);
		const bool standby=0;
  		const bool normal=1;
		void Setup();
		void Move(int16_t velocity);
		void MoveRaw(bool in1, bool in2, uint8_t velocity);
		void Brake();
		void Mode(bool mode);
};

#endif