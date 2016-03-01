#include "AddVarAssign.h"


#include"..\ApplicationManager.h"


#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddVarAssign::AddVarAssign(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddVarAssign::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	pOut->PrintMessage(" Variable Value Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);


	
	pOut->ClearStatusBar();		


}

void AddVarAssign::Execute()
{
	string s1;
	string s2;
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();

	double x,y;

	
	ReadActionParameters();
		
	
	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH/2;
	Corner.y = Position.y ;
	
	pOut->PrintMessage("Enter The first Variable");
	s1=pIn->GetString(pOut);

	stringstream convert(s1);
	convert>>x;
	bool z=false;
 z=!convert.fail();
 while (z)
 {
	 pOut->PrintMessage("Error Enter a  Variable");
	 s1=pIn->GetString(pOut);
	 stringstream convert(s1);
	convert>>x;
	z=!convert.fail();
 }



	pOut->PrintMessage("Enter The second Variable");
	s2=pIn->GetString(pOut);



	stringstream convert2(s2);
	convert2>>y;
	 z=false;
 z=!convert2.fail();
 while (z)
 {
	 pOut->PrintMessage("Error Enter a  Variable");
	 s2=pIn->GetString(pOut);
	 stringstream convert2(s2);
	convert2>>y;
	z=!convert2.fail();
 }
	pOut->ClearStatusBar();
	
	
	VarAssign *pAssign = new VarAssign(Corner, s1, s2);

	pManager->AddStatement(pAssign);

	pManager->UpdateInterface();
}
void AddVarAssign::ExecuteCp(const VarAssign & C)
{
	ReadActionParameters();
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;
	
	VarAssign *pAssign = new VarAssign(Corner, C);
	pManager->AddStatement(pAssign);
}


