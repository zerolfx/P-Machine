// fjp.h


#ifndef FJP_H
#define FJP_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements jump on false
*	@author 	Andy Zaidman
*/
class Fjp : public Instruction
{
	public:
		Fjp(string q);
		~Fjp();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
			
	private:
		string fQ;
};


#endif
