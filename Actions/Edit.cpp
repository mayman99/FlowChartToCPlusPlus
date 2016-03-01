#include "Edit.h"


#include "..\ApplicationManager.h"
#include "..\Statements\Statement.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

Edit::Edit(ApplicationManager *pAppManager):Action(pAppManager)
{}

void Edit :: ReadActionParameters()
{
	
}

void Edit :: Execute()
{

	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	Statement* s= pManager->GetSelectedStatement();
	if(s==NULL)
	{
		pOut->PrintMessage("There is no Selected Statment");
		return;
	}
	s->Edit(pOut,pIn);
	pOut->ClearDrawArea();
}