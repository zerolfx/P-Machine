 //main.cpp


#include "stackmachine.h"
#include "stackelement.h"
#include "stackinteger.h"
#include "instruction.h"
#include <iostream>
#include <typeinfo>
#include <stdio.h>
using namespace std;

extern int yyparse();
extern FILE *yyin;
extern StackMachine Pmachine;


void usage()
{
	cout << "USAGE: Pmachine [filename] <-s [numeric value]> <-t [numeric value]> <-h>" << endl << endl;
	cout << "\t -s: stepsize" << endl;
	cout << "\t -t: number of stackplaces to show\t(by default all)" << endl;
	cout << "\t -h: show heap" << endl << endl;
}

int main(int argc, char *argv[])
{
	try
	{
		if(argc < 2)
		{
			usage(); 
			exit(0);
		}
				
		for(int i = 0; i < argc; ++i)
		{
			if(argv[i][0] == '-')
			{
				switch(argv[i][1])
				{
					case 's':
					{
						if(argv[i+1] == 0)
						{
							cerr << "switch -s expects a numeric value" << endl;
							usage();
							exit(0);
						}
						
						Pmachine.setStepSize(atoi(argv[i+1]));
						break;
					}
					case 't': 
					{
						if(argv[i+1] == 0)
						{
							cerr << "switch -t expects a numeric value" << endl;
							usage();
							exit(0);
						}
						
						Pmachine.setStackSize(atoi(argv[i+1]));
						break;
					}
					case 'h':
					{
						Pmachine.setShowHeap();
						break;
					}
					default:
					{
						cerr << "unrecognized switch" << endl;
						usage();
						exit(0);
					}
				}
			}
		}

		
		
		FILE *file = fopen(argv[1], "r");
		if(file != NULL)
		{
			yyin = file;
		}
		else
		{
			cerr << "File " << argv[1] << " niet beschikbaar" << endl;
			usage();
			exit(0);
		}
		
		yyparse();
		
		fclose(file);
		
		Pmachine.run();
	}
	catch(ExecutionError e)
	{
		cerr << e.getMsg() << endl;
	}
	catch(CompileTimeError e)
	{
		cerr << e.getMsg() << endl;
	}
	catch(...)
	{
		cerr << "unknown error" << endl;
	}
}


