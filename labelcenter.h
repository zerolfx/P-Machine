// LabelCenter.h


#ifndef LABELCENTER_H
#define LABELCENTER_H

#include "compiletimeerror.h"
#include "executionerror.h"

#include <map>
#include <string>
using namespace std;


/**
* 	@doc		Object to manage all labels that are introduced in the programtext. It associates the labelname with the internal number of the instruction following the label
*	@author 	Andy Zaidman
*/
class LabelCenter
{
	public:
		LabelCenter();
		~LabelCenter();
		int getAddress(const string &kLabel);
		void addAddress(const string &kLabel, int location);
		void print();
	
	private:
		map<string, int> fLabels;
};


#endif

