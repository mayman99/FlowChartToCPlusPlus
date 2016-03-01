#ifndef EXIT_H
#define EXIT_H
#include "..\ApplicationManager.h"
#include "..\Statements\Statement.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
#include "Action.h"
using namespace std;


class Exit : public Action
{
	Point p;
public:
	Exit(ApplicationManager *pAppManager):Action(pAppManager)
	{ 
	
	}

	virtual void ReadActionParameters()
	{
	}
	
	virtual void Execute() 
	{ 
		Input * pIn= pManager->GetInput();
		Output * pOut= pManager->GetOutput();
		pOut->PrintMessage("PT PROJECT TERMINATING .. THANKS FOR USING ");
		pIn->GetPointClicked(p);
	}	

};

#endif