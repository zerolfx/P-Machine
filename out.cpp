//out.cpp

#include "out.h"


/** 
*	Constructor
*	@param	type				specifies which type is to be outputted (StackElementType)
*	@param	precisionmarker		set to true if the element at STORE[SP] is an integer which indicates the precision that is used to output the real at STORE[SP-1]
*/
Out::Out(StackElementType type, bool precisionmarker) : fType(type), fPrecisionMarker(precisionmarker) {}


/** 
*	Constructor
*	@param	type				specifies which type is to be outputted (StackElementType)
*/
Out::Out(StackElementType type) : fType(type), fPrecisionMarker(false) {}


/** 
*	Destructor
*/
Out::~Out() {}


/** 
*	Checks whether the element at STORE[SP] agrees with the type of the instruction and then outputs STORE[SP].
*	@return			none
*	@param stack	the machine on which the addition is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Out::execute(StackMachine *stack) 
{	
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction out: SP does not point to element of type integer.");
			
			cout << *stack->fStore[stack->fSP];
			
			// SP := SP + 1
			delete stack->fStore[stack->fSP];
			stack->fStore.pop_back();
			--stack->fSP;
		
			break;
		}
		case character:
		{
			StackCharacter p1;
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction out: SP does not point to element of type character.");
			
			cout << *stack->fStore[stack->fSP];
			
			// SP := SP + 1
			delete stack->fStore[stack->fSP];
			stack->fStore.pop_back();
			--stack->fSP;
		
			break;
		}
		case boolean:
		{
			StackBoolean p1;
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction out: SP does not point to element of type boolean.");
			
			cout << *stack->fStore[stack->fSP];
			
			// SP := SP + 1
			delete stack->fStore[stack->fSP];
			stack->fStore.pop_back();
			--stack->fSP;
		
			break;
		}
		case address:
		{
			StackAddress p1;
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction out: SP does not point to element of type boolean.");

			cout << *stack->fStore[stack->fSP];
			
			// SP := SP + 1
			delete stack->fStore[stack->fSP];
			stack->fStore.pop_back();
			--stack->fSP;
		
			break;
		}	
		case real:
		{
			StackInteger p1;
			StackReal p2;
				
			if(fPrecisionMarker)
			{
				// check if the two uppermost stackentries are of type integer and real respectively
				if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
					throw ExecutionError("instruction out: SP does not point to element of type integer.");
				if(typeid(p2) != typeid(*(stack->fStore[stack->fSP - 1])))
					throw ExecutionError("instruction out: SP - 1 does not point to element of type real.");
								
				cout.precision(stack->fStore[stack->fSP]->getValue());
				cout << *stack->fStore[stack->fSP - 1];
				
				delete stack->fStore[stack->fSP];
				delete stack->fStore[stack->fSP - 1];
				stack->fStore.pop_back();
				stack->fStore.pop_back();
				stack->fSP -= 2;
			}
			else
			{
				if(typeid(p2) != typeid(*(stack->fStore[stack->fSP])))
					throw ExecutionError("instruction out: SP does not point to element of type real.");
				
				cout << *stack->fStore[stack->fSP];
				
				delete stack->fStore[stack->fSP];
				stack->fStore.pop_back();
				--stack->fSP;
			}			
			break;
		}
	}

	// adding cost of this instruction
	stack->fTime.count("out");
}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Out::print(ostream &os) const
{
	if(fPrecisionMarker)
		os << "out r i";
	else
		os << "out " << printStackElementType(fType);
	return os;
}


