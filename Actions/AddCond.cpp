#include "AddCond.h"


#include"..\ApplicationManager.h"


#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddCond::AddCond(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddCond::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Conditional Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);


	
	pOut->ClearStatusBar();		


}

void AddCond::Execute()
{
	string s1;
	string s2;
	string s3;
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();


	ReadActionParameters();
		
	
	
	Point Corner;
	Corner.x = Position.x - UI.COND_WDTH/2;
	Corner.y = Position.y  ;
	
	pOut->PrintMessage("Enter The first Variable");
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
	pOut->PrintMessage("Enter The operation");
	s2=pIn->GetString(pOut);

	bool y=valid(s2);
	while(y==false)
	{
		pOut->PrintMessage("Invalid operation");
		s2=pIn->GetString(pOut);
		y=valid(s2);
	}


	pOut->PrintMessage("Enter a Variable or a Number");
	s3=pIn->GetString(pOut);
	pOut->ClearStatusBar();

	
	CondAssign *pAssign = new CondAssign(Corner,s2, s1, s3);

	pManager->AddStatement(pAssign);

	pManager->UpdateInterface();
}
bool AddCond:: valid(string s)
{
	bool x;

	if (s.compare("!=")==0)
	{
		x=true;
		return x; 
	}

	if (s.compare("==")==0)
	{
		x=true;
		return x; 
	}
	if (s.compare("<")==0)
	{
		x=true;
		return x; 
	}
	if (s.compare(">")==0)
	{
		x=true;
		return x; 
	}
	if (s.compare("<=")==0)
	{
		x=true;
		return x; 
	}
	if (s.compare(">=")==0)
	{
		x=true;
		return x; 
	}
	else 
	{
		return false;
	}

}
	