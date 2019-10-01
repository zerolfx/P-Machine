// LabelCenter.cpp

#include "labelcenter.h"
#include <iostream>

/** 
*	Constructor
*/
LabelCenter::LabelCenter() {}


/** 
*	Destructor
*/
LabelCenter::~LabelCenter() {}


/** 
*	Looks up the number of the instruction that is associated with the label
*	@return			int
*	@param kLabel	the label that you want to look up (const string&)
*	@exception		ExecutionError (if label is not-defined)
*/
int LabelCenter::getAddress(const string &kLabel)
{
	map<string, int>::iterator it = fLabels.find(kLabel);
	
	if(it == fLabels.end())
	{
		throw ExecutionError("label " + kLabel + " was not defined");
	}
	
	return fLabels[kLabel] - 1;	/* correction of "-1" because of the fact that the machine
						automatically increments the PC */
}


/** 
*	Adds a label and an associated "instructionnumber" to the map
*	@return			none
*	@param kLabel	the label you want to introduce (const string&)
*	@param location	the number of the first instruction associated with this code-fragment
*	@exception		CompileTimeError
*/
void LabelCenter::addAddress(const string &kLabel, int location)
{
	map<string, int>::iterator it = fLabels.find(kLabel);
	
	if(it != fLabels.end())
	{
		throw CompileTimeError("Label " + kLabel + " is being redeclared");
	}
	
	fLabels.insert(map<string, int>::value_type(kLabel, location));
}


/** 
*	Prints all label-instruction pairs to stdout: function mainly for debugging
*	@return			none
*	@exception		none
*/
void LabelCenter::print()
{
	for(map<string, int>::iterator it = fLabels.begin(); it != fLabels.end(); ++it)
	{
		std::cout << "pair: " << it->first << ", " << it->second << endl;
	}
}
	
