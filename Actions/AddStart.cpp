#include"AddStart.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;
AddStart::AddStart(ApplicationManager *pAppManager):Action(pAppManager)
{

}


void AddStart::ReadActionParameters()
{

	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Click to add the Start");

	pIn->GetPointClicked(Position);


	
	pOut->ClearStatusBar();		

}

void AddStart::Execute()
{
	

	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();


	ReadActionParameters();
		
	
	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x;
	Corner.y = Position.y ;


	pOut->ClearStatusBar();

	
	Start *pAssign = new Start(Corner);

	pManager->AddStatement(pAssign);
	pManager->UpdateInterface();
}