#include "AddOperatorAssign.h"


#include"..\ApplicationManager.h"


#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddOperatorAssign::AddOperatorAssign(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddOperatorAssign::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	pOut->PrintMessage(" Variable Value Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);


	
	pOut->ClearStatusBar();		


}

bool AddOperatorAssign::valid(string s)
{
	bool x;

	if (s.compare("+")==0)
	{
		x=true;
		return x; 
	}

	if (s.compare("-")==0)
	{
		x=true;
		return x; 
	}
	if (s.compare("*")==0)
	{
		x=true;
		return x; 
	}
	if (s.compare("/")==0)
	{
		x=true;
		return x; 
	}
	
	else 
	{
		return false;
	}

}

void AddOperatorAssign::Execute()
{
	string lhs;
	string operation;
	string rhs1;
	string rhs2;

	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();


	ReadActionParameters();
		
	
	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH/2;
	Corner.y = Position.y ;
	
	double x,y;

	pOut->PrintMessage("Enter The first Variable");
	lhs=pIn->GetString(pOut);
	
	stringstream convert(lhs);
		convert>>x;
		bool z=false;
		 z=!convert.fail();
	while (z)
	{
	
			pOut->PrintMessage("Error! Enter a Variable ");
			lhs=pIn->GetString(pOut);
			stringstream convert(lhs);
			
		convert>>x;
		z=!convert.fail();
			
		
	}
	pOut->PrintMessage("Enter The second Variable");
	rhs1=pIn->GetString(pOut);

	
	stringstream convert2(rhs1);
	convert2>>y;
	 z=false;
 z=!convert2.fail();
 while (z)
 {
	 pOut->PrintMessage("Error Enter a  Variable");
	 rhs1=pIn->GetString(pOut);
	 stringstream convert2(rhs1);
	convert2>>y;
	z=!convert2.fail();
 }

	pOut->PrintMessage("Enter The operation");
	operation=pIn->GetString(pOut);


	
	bool v=valid(operation);
	while(v==false)
	{
		pOut->PrintMessage("Invalid operation");
		operation=pIn->GetString(pOut);
		v=valid(operation);
	}

	pOut->PrintMessage("Enter The third Variable");
	rhs2=pIn->GetString(pOut);
	pOut->ClearStatusBar();

	
	OperatorAssign *pAssign = new OperatorAssign(Corner, lhs,operation,rhs1,rhs2);

	pManager->AddStatement(pAssign);

	pManager->UpdateInterface();
}

