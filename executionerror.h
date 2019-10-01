// executionerror.h

#ifndef EXECUTIONERROR_H
#define EXECUTIONERROR_H

#include <string>
using namespace std;


/**
* 	@doc		Standard exception object used for runtime-errors
*	@author 	Andy Zaidman
*/
class ExecutionError
{
	public:
		ExecutionError(const string &kMessage);
		~ExecutionError();
		
		string getMsg();
		
	private:
		string fMessage;
};

#endif

