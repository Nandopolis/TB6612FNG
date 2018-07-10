/**
 * @brief An arduino library in order to control the TB6612FNG driver
 * 
 * @file TB6612FNG.h
 * @author Nandopolis
 * @date 2018-07-09
 * 
 * this library implements an abstraction to control the TB6612FNG driver
 * for dc motors.
 * implements brake and standby control, speed and direction are
 * extracted from a signed integer from -255 to 255
 */

#ifndef TB6612FNG_h
#define TB6612FNG_h

#include "Arduino.h"

/**
 * @brief TB6612FNG
 * 
 * A class for a H-bridge drive, TB6612FNG driver supports 2 H-bridges so
 * it is possible to have two instnces of this class for the same driver
 */
class TB6612FNG {
	private:
		uint8_t pwmPin;		/**< the pwm pin number */
		uint8_t in1Pin;		/**< the first direction pin number */
		uint8_t in2Pin;		/**< the second direction pin number */
		uint8_t stbyPin;	/**< the standby pin number */
  		boolean dir;		/**< a boolean to change direction logic */

		/**
		 * @brief MoveRaw function
		 * 
		 * indicates the pwm and direction at which the load is drived
		 * 
		 * @param in1 the first direction pin value
		 * @param in2 the second direction pin value
		 * @param velocity the pwm value, from 0 to 255 (8 bits)
		 */
		void MoveRaw(bool in1, bool in2, uint8_t velocity);

	public:
		/**
		 * @brief Construct a new TB6612FNG object
		 * 
		 * @param pwmA the pwm pin
		 * @param in1A the first pin for direction
		 * @param in2A the second pin for direction
		 * @param stby the standby pin
		 * @param d the direction logic
		 */
  		TB6612FNG (uint8_t pwmA, uint8_t in1A, uint8_t in2A, uint8_t stby, bool d=1);
		
		const bool standby=0;	/**< constant for the standby mode */
  		const bool normal=1;	/**< constant for the normal mode */
		
		/**
		 * @brief Setup function
		 * 
		 * sets OUTPUT pinMode for every pin
		 */
		void Setup();
		
		/**
		 * @brief Move function
		 * 
		 * sets the MoveRaw with the direction derived from the sign of velovity
		 * and the pwm as the absolute value of velocity 
		 * 
		 * @param velocity signed integer from -255 to 255
		 */
		void Move(int16_t velocity);
		
		/**
		 * @brief Brake function
		 * 
		 * sets in1 and in2 in order to do a fast brake
		 */
		void Brake();
		
		/**
		 * @brief Mode function
		 * 
		 * sets the stbyPin
		 * 
		 * @param mode 0 for standby, 1 for normal mode
		 */
		void Mode(bool mode);
};

#endif