#include "Victor.h"

Victor::Victor(int pinNumber)
{
	pin = pinNumber;
	pinMode(pin, OUTPUT);
}

void Victor::setSpeed(double speed)
{
	if(speed > 1) speed = 1;
	if(speed < -1) speed = -1;

	setTime(MEAN_TIME + (DIFF_TIME * speed));
}

void Victor::setTime(int time)
{
	//TODO bounds checking, make public?
	maxTime = time;
}

void Victor::decrementTime(unsigned int time)
{
	currTime -= time;
	if(currTime <= 0) setState(false);
}

void Victor::setState(bool on)
{
	isOn = on;
	if(isOn)
	{
		digitalWrite(pin, HIGH);
	}
	else
	{
		digitalWrite(pin, LOW);
	}
}

void Victor::resetTime()
{
	currTime = maxTime;
	setState(true);
}
