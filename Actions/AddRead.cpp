#include "AddRead.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddRead::AddRead(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddRead::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Read Statement: Click to add the statement");

	pIn->GetPointClicked(Position);


	
	pOut->ClearStatusBar();		


}


void AddRead::Execute()
{
	string s1,s2;

	double d1;

	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();


	ReadActionParameters();
		
	
	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH/2;
	Corner.y = Position.y ;
	
	pOut->PrintMessage(" Enter a Variable");
	s1=pIn->GetString(pOut);


	double x;
	stringstream convert(s1);
		convert>>x;
		bool z=false;
		 z=!convert.fail();
	while (z)
	{
	
			pOut->PrintMessage("Error! Enter a Variable ");
			s1=pIn->GetString(pOut);
			stringstream convert(s1);
			
		convert>>x;
		z=!convert.fail();
			
		
	}

	


	pOut->ClearStatusBar();

	
	Read *pAssign = new Read(Corner,s1);

	pManager->AddStatement(pAssign);
	pManager->UpdateInterface();
}

////void AddRead::ExecuteCp(const Read & C)
////{
////	ReadActionParameters();
////	Point Corner;
////	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
////	Corner.y = Position.y;
////	
////	Read *pAssign = new Read(Corner, C);
////	pManager->AddStatement(pAssign);
////}
