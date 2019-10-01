// stackmachine.cpp

#include "stackmachine.h"


/** 
*	Constructor
*/
StackMachine::StackMachine() : fSP(-1), fPC(0), fNP(0), fMP(0), fEP(0), fHaltrequested(false), fStepping(false), fIC(0), fStepSize(0), fShowHeap(false), fStackSize(0), fStepCounter(1) {}


/** 
*	Destructor
*/
StackMachine::~StackMachine() {}


/** 
*	Insert an instruction into the stackmachine
*	@param	instruction		an instance of an Instruction-derived class (Instruction*)
*	@return					none
*	@exception				none
*/
void StackMachine::addInstruction(Instruction *instruction)
{
	fCode.push_back(instruction);
	++fIC;
}


/** 
*	Insert a label into the stackmachine, the label will be associated with the address of the first instruction after the label
*	@param	kLabel			name of the label you want to add (const string&)
*	@return					none
*	@exception				none
*/
void StackMachine::addLabel(const string &kLabel)
{
	fLabelCenter.addAddress(kLabel, fIC);
}


/** 
*	Run the machine
*	@return					none
*	@exception				ExecutionError
*/
void StackMachine::run()
{
	fPC = 0;
	while(fHaltrequested == false)
	{
		if(fPC >= fIC)
		{
			throw ExecutionError("PC has exceeded maximum number of instructions.");
			cerr << "End reached" << endl;
			return;
		}
		else
		{
			if(fStepping)
			{
				printCurrentInstruction();
			}
			fCode[fPC]->execute(this);
			if(fStepping)
			{
				showStack();
				showHeap();
				showParameters();
				continueStep();
			}
			++fPC;
			++fStepCounter;
		}
	}
	
	// print the execution-time
	cout << endl << "--> Execution time: " << fTime.getTime() << endl << endl;
	
}


/** 
*	When this is set, the machine will step (according to well-defined parameters) instead of running the whole program
*	@param	step			Set this value to true for steppingmode (bool)
*	@return					none
*	@exception				none
*/
void StackMachine::step(bool step)
{
	fStepping = step;
}


/** 
*	Procedure that waits for user-input before continuing with stepping
*	@return					none
*	@exception				none
*/
void StackMachine::continueStep()
{
	if(fStepCounter == fStepSize)
	{
		cout << "Press [c] + [Enter] to continue. Other key to end." << endl;
		char space;
		cin >> space;
		switch(space)
		{
			case 'c': 
			case 'C': break;
			default: exit(0);
		}
		fStepCounter = 0;
	}
}


/** 
*	Prints the current instruction to stdout
*	@return					none
*	@exception				none
*/
void StackMachine::printCurrentInstruction()
{
	cout << "--> " << *fCode[fPC] << endl;
}


/** 
*	Shows the contents of the stack, by default all, otherwise according to well-defined start-up parameters
*	@return					none
*	@exception				none
*/
void StackMachine::showStack()
{
	int beginvalue;
	
	if(fStackSize == 0)
	{
		beginvalue = 0;
	}
	else
	{
		if(fStore.size() - fStackSize < 0)
		{
			beginvalue = 0;
		}
		else
		{
			beginvalue = fStore.size() - fStackSize;
		}
	}
	
	for(int i = beginvalue; i < fStore.size(); ++i)
	{
		cout << "\t[" << i << "]\t\t" << "[" << fStore[i]->getType() << "]\t" << *fStore[i] << endl;
	}
	cout << endl;

}


/** 
*	Prints the entire (populated) heap-space to stdout
*	@return					none
*	@exception				none
*/
void StackMachine::showHeap()
{
	if(fShowHeap)
	{
		for(int i = -1; i >= fNP; --i)
		{
			cout << "\t[" << i << "]\t\t" << "[" << fHeap[-i-1]->getType() << "]\t" << *fHeap[-i-1] << endl;
		}
		cout << endl;
	}
}


/** 
*	Prints SP, NP, IC, EP, MP and PC to stdout
*	@param	kLabel			name of the label you want to add (const string&)
*	@return					none
*	@exception				none
*/
void StackMachine::showParameters()
{
	cout << "\tSP: " << fSP << ",\tNP: " << fNP << ",\tIC: " << fIC << "," << endl;
	cout << "\tEP: " << fEP << ",\tMP: " << fMP << ",\tPC: " << fPC << endl << endl;
}


/** 
*	When called, the heap will be printed at each stepping-interval
*	@return					none
*	@exception				none
*/
void StackMachine::setShowHeap()
{
	fShowHeap = true;
	step(true);
}


/** 
*	Sets the number of stackspaces that will be shown at each stepping-interval (when the number of stackelements < stacksize, then only the number of stackelements will be shown)
*	@param	stacksize		the number of stackelements (int)
*	@return					none
*	@exception				none
*/
void StackMachine::setStackSize(int stacksize)
{
	fStackSize = stacksize;
	step(true);
}


/** 
*	Sets the number of instructions to be executed before waiting for user-input to continue
*	@param	stepsize		stepsize (int)
*	@return					none
*	@exception				none
*/
void StackMachine::setStepSize(int stepsize)
{
	fStepSize = stepsize;
	step(true);
}


/** 
*	Function to determine an address when there is a difference in nesting depths
*	@param p	difference in nesting depths (int)
*	@param a	current value for MP (int)
*	@return					none
*	@exception				ExecutionError
*/
int StackMachine::base(int p, int a)
{
	if (p == 0)
		return a;
	else
	{
		if(a+1 > fSP)
		{
			strstream errormessage;
			errormessage << "base(" << p << "," << a << ") is trying to access a memorylocation above STORE[SP]";
			throw ExecutionError(errormessage.str());
		}
		else
		{
			return base(p - 1, fStore[a+1]->getValue());
		}
	}
}
