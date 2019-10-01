//instruction.h


#ifndef INSTRUCTION_H
#define INSTRUCTION_H


#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "stackmachine.h"
#include "stackelement.h"
#include "stackinteger.h"
#include "stackreal.h"
#include "stackaddress.h"
#include "stackboolean.h"
#include "stackcharacter.h"
#include "timecounter.h"

class Stackmachine;


/**
* 	@doc		Abstract base class from which all instruction-classes are derived
*	@author 	Andy Zaidman
*/
class Instruction
{
	public:
		friend class StackMachine;

		Instruction();
		virtual ~Instruction();
		/// virtual function which will be overridden in non-abstract derived classes
		virtual void execute(StackMachine *stack) = 0;
		/// virtual function which will be overridden in non-abstract derived classes
		virtual ostream& print(ostream &os) const = 0;
		friend ostream& operator<<(ostream &os, const Instruction &kOutput);
};


// function prototype
string printStackElementType(StackElementType type);


#endif

