// stackreal.h

#ifndef STACKREAL_H
#define STACKREAL_H

#include "stackelement.h"

/**
*	@doc 	Container for real type (implemented via C++ double type, precision is platform dependant)
*	@author	Andy Zaidman
*/
class StackReal : public StackElement
{
	public:
		StackReal(double real = 0);
		~StackReal();
		
		void add(StackElement *op);
		void sub(StackElement *op);
		void mul(StackElement *op);
		void div(StackElement *op);
		void neg();
		
		bool equ(const StackElement *kOp) const;
		bool les(const StackElement *kOp) const;
		bool grt(const StackElement *kOp) const;

		double getReal() const;

		void inc(int increment);

		bool isZero();
		
		ostream& print(ostream &os) const;
		
		char getType() const;

	private:
		double fReal;
};

#endif

