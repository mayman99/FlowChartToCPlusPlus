#include"StepByStep.h"
#include<iostream>
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Statements\Connector.h"
#include "..\Statements\Statement.h"
#include"..\Statements\CondAssign.h"

void StepByStep:: ReadActionParameters()
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

void StepByStep::Execute()
{

	x=pManager->NodesArray;
	count=pManager->NodeCount;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if(s==NULL)
	{
		pOut->PrintMessage("char invaild no start statement");
		return;
	}
	if (e==NULL)

	{
		pOut->PrintMessage("chart invaild no End statement");
		return;
	}
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	pOut->PrintMessage("Step by Step mode click to start");
	pIn->GetPointClicked(Position);
	Statement* temp=s;
	pManager->UnselectAllstat();
	s->SetSelected(true);
	pManager->UpdateInterface();
	while (pManager->getStatType(s)!=5)
	{
		s = s->getNextStatement();
		s->Simulate(x,count,pOut,pIn,0);
	}
	for(int i=0;i<count; i++)
	{x[i].value=0;}


	int j=0;
	while (pManager->getStatType(temp)!=5)
	{    
		pOut->PrintMessage("Click to move to the next statement");
		pIn->GetPointClicked(Position);
		pManager->UnselectAllstat();
		temp = temp->getNextStatement();
		temp->SetSelected(true);
		temp->Simulate(x,count,pOut,pIn,1);
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
		/*for (int i = 0; i < count; i++)
		{*/
			pOut->ClearStArea();
			
			
	
		

			
			pOut->pWind->DrawString(20, 60+(j*15), x[j].name);////////////////////

			CondAssign* cond=dynamic_cast<CondAssign*>(temp);
			if(cond!=NULL)
			{
				pOut->pWind->DrawString(70, 60+(j*15), cond->getoperation());
			}
			pOut->pWind->DrawDouble(120,60+(j*15), x[j].value);///////////////////
			
		
		
			j++;
	}
	pOut->PrintMessage("Step by Step done");
}