// stackinteger.h


#ifndef STACKINTEGER_H
#define STACKINTEGER_H

#include "stackelement.h"

/**
*	@doc 	Container for integer type
*	@author	Andy Zaidman
*/
class StackInteger : public StackElement
{
	public:
		StackInteger(int integer = 0);
		~StackInteger();
						
		void add(StackElement *op);
		void sub(StackElement *op);
		void mul(StackElement *op);
		void div(StackElement *op);
		void neg();
		
		bool equ(const StackElement *kOp) const;
		bool les(const StackElement *kOp) const;
		bool grt(const StackElement *kOp) const;
		
		int getValue() const;
		
		void inc(int increment);

		bool isZero();
		
		ostream& print(ostream &os) const;
		
		char getType() const;
		
	private:
		int fInteger;
};

#endif

