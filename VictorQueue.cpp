#include "VictorQueue.h"

VictorQueue::VictorQueue(int cnt, Victor **vics)
{
	count = cnt;
	victors = vics;
}

void VictorQueue::checkQueue()
{
	if(currTime <= 0)
	{
		resetTimes();
	}

	decrementTimes();

	delayMicroseconds(updateRate);
}

void VictorQueue::resetTimes() 
{
	currTime = maxTime;
	
	for(int i = 0; i < count; i++)
	{
		victors[i]->resetTime();
	}
}

void VictorQueue::decrementTimes() 
{
	for(int i = 0; i < count; i++)
	{
		victors[i]->decrementTime(updateRate);
	}
}
