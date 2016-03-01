#include"Run.h"
#include<iostream>
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Statements\Connector.h"
#include "..\Statements\Statement.h"

void Run:: ReadActionParameters()
{
	s=NULL;
	e=NULL;
	for (int i = 0; i < pManager->getScount(); i++)
	{
		if(pManager->getStatType(pManager->StatList[i])==4)
		
		{
			s = pManager->StatList[i];
			
		}
	}



	for (int i = 0; i < pManager->getScount(); i++)
	{
		if(pManager->getStatType(pManager->StatList[i])==5)
		
		{
			e = pManager->StatList[i];
			return;
		}
	}

	
}

void Run::Execute()
{
	Point p;
	Output* pOut = pManager->GetOutput();
	h=new ChartValidation(pManager);
	h->Execute();
	pOut->pWind->WaitMouseClick(p.x,p.y);
	
	if (h->x!=0)
	{
		return;
	}
	x=pManager->NodesArray;
	count=pManager->NodeCount;
	
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if(s==NULL)
	{
		pOut->PrintMessage("chart invaild no start statement");
		return;
	}
	if (e==NULL)

	{
		pOut->PrintMessage("chart invaild no End statement");
		
		return;
	}
	pOut->PrintMessage("The FlowChart is now Running ");
	while (pManager->getStatType(s)!=5)
	{
		s = s->getNextStatement();
		s->Simulate(x,count,pOut,pIn,1);
	}
	//pOut->ClearDrawArea();
	//pOut->ClearStArea();
	for (int i = 0; i < count; i++)
	{
		
		
			
			pOut->pWind->DrawString(20, 60+(i*15), x[i].name);////////////////////
			pOut->pWind->DrawDouble(100,60+(i*15), x[i].value);///////////////////
			
			
	}

	pOut->PrintMessage("Simulation complete click anywhere to stop running");
	Point ps;
	pIn->GetPointClicked(ps);
	pManager->UpdateInterface();
	pOut->ClearStatusBar();

}