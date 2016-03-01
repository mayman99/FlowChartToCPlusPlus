#include "AddWrite.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddWrite::AddWrite(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddWrite::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Write Statement: Click to add the statement");

	pIn->GetPointClicked(Position);


	
	pOut->ClearStatusBar();		


}


void AddWrite::Execute()
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

	
	Write *pAssign = new Write(Corner,s1);

	pManager->AddStatement(pAssign);
	pManager->UpdateInterface();
}

////void AddWrite::ExecuteCp(const Write & C)
////{
////	ReadActionParameters();
////	Point Corner;
////	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
////	Corner.y = Position.y;
////	
////	Write *pAssign = new Write(Corner, C);
////	pManager->AddStatement(pAssign);
////}
