// compiletimeerror.h

#ifndef COMPILETIMEERROR_H
#define COMPILETIMEERROR_H

#include <string>
using namespace std;


/**
* 	@doc		Standard exception object used for compiletime-errors
*	@author 	Andy Zaidman
*/
class CompileTimeError
{
	public:
		CompileTimeError(const string &kMessage);
		~CompileTimeError();
		
		string getMsg();
		
	private:
		string fMessage;
};

#endif

