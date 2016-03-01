#include "Comment.h"


#include "..\ApplicationManager.h"
#include "..\Statements\Statement.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

Comment::Comment(ApplicationManager *pAppManager):Action(pAppManager)
{}

void Comment :: ReadActionParameters()
{
}

void Comment :: Execute()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	Statement* s= pManager->GetSelectedStatement();
	if(s==NULL)
	{
		Output *pOut = pManager->GetOutput();
		pOut->PrintMessage("There is no Selected Statment");
		return;
	}
	pOut->PrintMessage("Enter the comment you want to add to the selected Statement ");
	com = pIn->GetString(pOut);
	s->setComment(com);
	pOut->ClearDrawArea();
	pOut->PrintMessage("Comment Added ");
} 