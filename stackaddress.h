// stackaddress.h

#ifndef STACKADDRESS_H
#define STACKADDRESS_H

#include "stackelement.h"


/**
*	@doc 	Container for address type
*	@author	Andy Zaidman
*/
class StackAddress : public StackElement
{
	public:
		StackAddress(int address = 0);
		~StackAddress();
		
		void add(StackElement *op);
		void sub(StackElement *op);
		void mul(StackElement *op);
		void div(StackElement *op);
		void neg();
		
		int getValue() const;

		bool equ(const StackElement *kOp) const;
		bool les(const StackElement *kOp) const;
		bool grt(const StackElement *kOp) const;
		
		void inc(int increment);
		
		bool heapAddress();

		ostream& print(ostream &os) const;
		
		char getType() const;

	private:
		int fAddress;
};

#endif

