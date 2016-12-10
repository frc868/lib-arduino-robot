#include "Arduino.h"

#define DIFF_TIME 475
#define MEAN_TIME 1500

#ifndef VICTOR
#define VICTOR

class Victor
{
	public:
		Victor(int pinNumber);
		//sets the speed, -1 to 1
		void setSpeed(double speed);
		//used with master queue delay
		void decrementTime(unsigned int time);
		//used when master queue time reaches 0
		void resetTime();
		//TODO get functions
	private:
		int pin;
		int maxTime = 1500;
		int currTime = 1500;
		bool isOn = true;
		void setTime(int time);
		void setState(bool on);
};

#endif
