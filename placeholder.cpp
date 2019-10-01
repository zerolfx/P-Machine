// placeholder.cpp

#include "placeholder.h"

HeapPlaceHolder::HeapPlaceHolder() {}

HeapPlaceHolder::~HeapPlaceHolder() {}

ostream& HeapPlaceHolder::print(ostream &os) const
{
	os << "empty heap position" << endl;
	return os;
}
