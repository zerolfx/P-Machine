// stackboolean.h


#ifndef STACKBOOLEAN_H
#define STACKBOOLEAN_H

#include "stackelement.h"


/**
*	@doc 	Container for boolean type
*	@author	Andy Zaidman
*/
class StackBoolean : public StackElement
{
	public:
		StackBoolean(bool boolean = false);
		~StackBoolean();
								
		bool equ(const StackElement *kOp) const;
		bool les(const StackElement *kOp) const;
		bool grt(const StackElement *kOp) const;
		
		void andi(const StackElement *kOp);
		void ori(const StackElement *kOp);
		void noti();
		
		bool getBoolean() const;
		
		void inc(int increment);

		ostream& print(ostream &os) const;
		
		char getType() const;
		
	private:
		int fBoolean;
};

#endif

