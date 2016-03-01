#include"ChartValidation.h"
#include<iostream>
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Statements\Connector.h"
#include "..\Statements\Statement.h"

void ChartValidation::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	ccount = 0; scount = 0;
	ccount = pManager->getCcount();
	scount = pManager->getScount();

}

void ChartValidation::Execute()
{
	ReadActionParameters();
	 x = 0;
	if (pManager->endCount != 1 || pManager->startCount != 1)
	{
		pOut->PrintMessage("Chart Validation Unsuccessful");
		x--;
	}
	/*if (ccount != scount - pManager->getWhiles() - 1 + pManager->getCond())
	{
		pOut->PrintMessage("Chart is invalid");
		x--;
	}*/
	if (ccount != scount - 1 + pManager->getCondnum())
	{
		pOut->PrintMessage("Chart Validation Unsuccessful");
		x--;
	}
	if (x == 0)
		pOut->PrintMessage("Chart Validation Successful click anywhere to continue");
}