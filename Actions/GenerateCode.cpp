#include "GenerateCode.h"
#include<iostream>
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Statements\Connector.h"
#include "..\Statements\Statement.h"
#include"..\Statements\CondAssign.h"


void GenerateCode::ReadActionParameters()
{
	for (int i = 0; i < pManager->getScount(); i++)
	{
		if(pManager->getStatType(pManager->StatList[i])==4)
		{
			s = pManager->StatList[i];
			break;
		}
	}
	temp = s;
}

void GenerateCode::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	x = pManager->NodesArray;
	while (pManager->getStatType(temp)!=5)
	{
		temp = temp->getNextStatement();
		temp->Simulate(x, pManager->NodeCount, pOut, pIn, 0);
	}
	
	count = pManager->NodeCount;
	pOut->PrintMessage("The code has been generated");
	
	outfile.open("Code.cpp");
	do
	{
		s->GenerateCode(outfile,x, count);
		if (pManager->getStatType(s)!=3)
		{
			s = s->getNextStatement();
		}
		else
		{
			CondAssign*cond=dynamic_cast<CondAssign*>(s);
			s = cond->getDstStatement();
		}
	} 
	while (pManager->getStatType(s)!=5);
	outfile << "\nreturn 0;\n}";
	outfile.close();
}