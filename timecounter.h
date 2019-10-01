// TimeCounter.h


#ifndef TIMECOUNTER_H
#define TIMECOUNTER_H

#include <map>
#include <string>
using namespace std;


/**
* 	@doc		Object that manages the weight of each instruction. Encapsulates all functions to count the weight of each instruction/the whole program.
*	@author 	Andy Zaidman
*/
class TimeCounter
{
	public:
		TimeCounter();
		~TimeCounter();
		void count(const string &kInstruction);
		int getTime();
	
	private:
		map<string, int> fWeights;
		int fCounter;
};


#endif

