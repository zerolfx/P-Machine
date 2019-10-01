// stackcharacter.h

#ifndef STACKCHARACTER_H
#define STACKCHARACTER_H

#include "stackelement.h"

class StackCharacter : public StackElement
{
	public:
		StackCharacter(char character = 'a');
		~StackCharacter();
								
		bool equ(const StackElement *kOp) const;
		bool les(const StackElement *kOp) const;
		bool grt(const StackElement *kOp) const;
		
		void inc(int increment);
		
		int getValue() const;
		
		ostream& print(ostream &os) const;
		char getType() const;
		
	private:
		char fCharacter;
};

#endif
