// compiletimeerror.cpp

#include "compiletimeerror.h"

/** 
*	Constructor
*	@param kMessage		message that contains information about error (const string&)
*/
CompileTimeError::CompileTimeError(const string &kMessage) : fMessage(kMessage) {}


/** 
*	Destructor
*/
CompileTimeError::~CompileTimeError() {}


/** 
*	Returns the errormessage
*	@return			string
*	@exception		none
*/
string CompileTimeError::getMsg()
{
	return fMessage;
}
