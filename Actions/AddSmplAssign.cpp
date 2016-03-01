#include "AddSmplAssign.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddSmplAssign::AddSmplAssign(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddSmplAssign::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Simple Value Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);


	
	pOut->ClearStatusBar();		


}


void AddSmplAssign::Execute()
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

	pOut->PrintMessage("Now Enter a Number");
	d1=pIn->GetValue(pOut);
	
	



	/*pOut->PrintMessage("Now Enter a Number");
	s2=pIn->GetString(pOut);
	double y;
	stringstream convert2(s2);

		convert2>>y;
		 z=false;
		 z=convert2.fail();
	while (z)
	{
	
			pOut->PrintMessage("Error! Enter a Number ");
			s2=pIn->GetString(pOut);
			stringstream convert2(s2);
			
		convert2>>y;
		z=convert2.fail();
			
		
	}
*/


	pOut->ClearStatusBar();

	
	SmplAssign *pAssign = new SmplAssign(Corner, s1, d1);

	pManager->AddStatement(pAssign);
	pManager->UpdateInterface();
}

void AddSmplAssign::ExecuteCp(const SmplAssign & C)
{
	ReadActionParameters();
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;
	
	SmplAssign *pAssign = new SmplAssign(Corner, C);
	pManager->AddStatement(pAssign);
}
