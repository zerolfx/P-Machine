// lod.h


#ifndef LOD_H
#define LOD_H


#include <vector>
#include <string>
#include <typeinfo>
#include <strstream>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements loading for a given difference in nesting depths p and a given relative address q.
*	@author 	Andy Zaidman
*/
class Lod : public Instruction
{
	public:
		Lod(StackElementType type, int p, int q);
		~Lod();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;	
		
	private:
		StackElementType fType;
		int fP;
		int fQ;
};


#endif

