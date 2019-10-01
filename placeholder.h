// placeholeder.h


#ifndef PLACEHOLDER_H
#define PLACEHOLDER_H

#include "stackelement.h"

class HeapPlaceHolder : public StackElement
{
	public:
		HeapPlaceHolder();
		~HeapPlaceHolder();
		
		ostream& print(ostream &os) const;
};

#endif

