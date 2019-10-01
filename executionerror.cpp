// executionerror.cpp

#include "executionerror.h"

/** 
*	Constructor
*	@param kMessage		message that contains information about error (const string&)
*/
ExecutionError::ExecutionError(const string &kMessage) : fMessage(kMessage) {}


/** 
*	Destructor
*/
ExecutionError::~ExecutionError() {}


/** 
*	Returns the errormessage
*	@return			string
*	@exception		none
*/
string ExecutionError::getMsg()
{
	return fMessage;
}
