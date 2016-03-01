#include"AddEnd.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;
AddEnd::AddEnd(ApplicationManager *pAppManager):Action(pAppManager)
{

}


void AddEnd::ReadActionParameters()
{

	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Click to add the End");

	pIn->GetPointClicked(Position);


	
	pOut->ClearStatusBar();		

}

void AddEnd::Execute()
{
	

	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();


	ReadActionParameters();
		
	
	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x;
	Corner.y = Position.y ;


	pOut->ClearStatusBar();

	
	End *pAssign = new End(Corner);

	pManager->AddStatement(pAssign);
	pManager->UpdateInterface();
}