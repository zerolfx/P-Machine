// stackelement.h


#ifndef STACKELEMENT_H
#define STACKELEMENT_H

#include <iostream>
using namespace std;

/** 
*	@doc	Used for communicating internal types in the parser, but is also used to specify to instructions
*	@doc	on which type(s) to perform the operation.
*	@author Andy Zaidman
*/
enum StackElementType {real, integer, boolean, character, address, none};

class StackElement
{
	public:
		StackElement();
		~StackElement();
		
		/// virtual function: no specific implementation
		virtual void add(StackElement *op);
		/// virtual function: no specific implementation
		virtual void sub(StackElement *op);
		/// virtual function: no specific implementation
		virtual void mul(StackElement *op);
		/// virtual function: no specific implementation
		virtual void div(StackElement *op);
		/// virtual function: no specific implementation
		virtual void neg();

		/// virtual function: no specific implementation
		virtual void andi(const StackElement *kOp);
		/// virtual function: no specific implementation
		virtual void ori(const StackElement *kOp);
		/// virtual function: no specific implementation
		virtual void noti();
		
		/// virtual function: no specific implementation
		virtual bool equ(const StackElement *kOp) const;
		/// virtual function: no specific implementation
		virtual bool les(const StackElement *kOp) const;
		/// virtual function: no specific implementation
		virtual bool grt(const StackElement *kOp) const;
		
		/// virtual function: no specific implementation
		virtual int getValue() const;
		/// virtual function: no specific implementation
		virtual bool getBoolean() const;
		/// virtual function: no specific implementation
		virtual double getReal() const;
		
		/// virtual function: no specific implementation
		virtual void inc(int increment);
		
		/// virtual function: no specific implementation
		virtual bool heapAddress();
		
		/// virtual function: no specific implementation
		virtual bool isZero();
		
		/// virtual function: no specific implementation
		virtual ostream& print(ostream &os) const;
		
		/// virtual function: no specific implementation
		virtual char getType() const;
		
		friend ostream& operator<<(ostream &os, const StackElement &kOutput);
		
		// comparison operators
		friend bool operator==(const StackElement &kOp1, const StackElement &kOp2);
		friend bool operator!=(const StackElement &kOp1, const StackElement &kOp2);
		friend bool operator>=(const StackElement &kOp1, const StackElement &kOp2);
		friend bool operator<=(const StackElement &kOp1, const StackElement &kOp2);
		friend bool operator<(const StackElement &kOp1, const StackElement &kOp2);
		friend bool operator>(const StackElement &kOp1, const StackElement &kOp2);
};


#endif

