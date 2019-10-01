// stackmachine.h


#ifndef STACKMACHINE_H
#define STACKMACHINE_H

#include <vector>
#include <typeinfo>
#include <strstream>
using namespace std;
class StackMachine;

#include "instruction.h"
#include "stackelement.h"
#include "stackinteger.h"
#include "labelcenter.h"
#include "timecounter.h"


class StackMachine
{
	public:
		friend class Instruction;
		friend class Add; //p11		// tested
		friend class Sub;			// tested
		friend class Mul;			// tested
		friend class Div;			// tested
		friend class Neg;			// tested

		friend class And;			// tested
		friend class Or;			// tested
		friend class Not;			// tested
		
		friend class Equ;			// tested
		friend class Geq;			// tested
		friend class Leq;			// tested
		friend class Les;			// tested
		friend class Grt;			// tested
		friend class Neq;			// tested
		
		friend class Ldo; //p12		// tested
		friend class Ldc;			// tested
		friend class Ind;			// tested
		friend class Sro;			// tested
		friend class Sto;			// tested
		
		friend class Ujp; //p14
		friend class Fjp;
		
		friend class Ixj; //p17
		
		friend class Ixa; //p22		// tested
		
		friend class Inc; //p23
		friend class Dec;
		friend class Chk;
		
		friend class Dpl; //p27		// tested
		friend class Ldd;
		friend class Sli;			// tested
		
		friend class New; //p29
		
		friend class Lod; //p42
		friend class Lda;
		friend class Str;
		
		friend class Mst; //p47
		friend class Cup;
		friend class Ssp;
		friend class Sep;
		
		friend class Ent;
		
		friend class Retf; //p48
		friend class Retp;
		
		friend class Movs; //p50
		friend class Movd; //p50
		
		friend class Smp;  //p55
		friend class Cupi;
		friend class Mstf;
		
		friend class In;   //undocumented instructions
		friend class Out;
		friend class Hlt;
		friend class Conv;
		
		StackMachine();
		~StackMachine();
		
		void addInstruction(Instruction *instruction);
		void addLabel(const string &kLabel);
		
		void run();
		void step(bool step);
		
		void printCurrentInstruction();
		
		void showStack();
		void showHeap();
		void showParameters();
		void continueStep();
		
		void setShowHeap();
		void setStackSize(int stacksize);
		void setStepSize(int stepsize);



		
		
	private:
		vector<Instruction*> fCode;			// contains instructions
		vector<StackElement*> fStore;		// stack
		vector<StackElement*> fHeap;		// heap
		LabelCenter fLabelCenter;			// contains defined labels
		TimeCounter fTime;					// manages the "cost" of the program
		
		int fPC;							// program counter
		int fSP;							// stack pointer
		int fNP;							// new pointer
		int fEP;							// extreme pointer
		int fMP;							// marks stack frame
		
		// internal variables
		bool fHaltrequested;
		int fIC;							// instruction counter
		
		// variables to control stepping
		bool fStepping;
		bool fShowHeap;
		int fStepSize;
		int fStackSize;
		int fStepCounter;

		// private operations
		int base(int a, int p);		
		
};


#endif
