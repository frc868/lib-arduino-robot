#include <Arduino.h>
#include "Victor.h"

#ifndef VICTOR_QUEUE
#define VICTOR_QUEUE

class VictorQueue
{
	public:
		VictorQueue(int cnt, Victor **vics);
		void checkQueue();
	private:
		void resetTimes();
		void decrementTimes();

		int updateRate = 50;
		int maxTime = 3000;
		int currTime = 3000;
		int count = 0;
		Victor **victors;
};

#endif
