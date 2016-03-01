#include"Paste.h"
#include<iostream>
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Statements\Connector.h"
#include "..\Statements\Statement.h"

void Paste::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	if(pManager->getCopied() == NULL )
	{
		pOut->PrintMessage("No copied Statement");
		return ;
	}
	pOut->PrintMessage("Please Click to Paste Last Copied Statement");
	pIn->GetPointClicked(P);
	pOut->PrintMessage("Statement Pasted");
}

void Paste::Execute()
{
	if (pManager->getCopyCondition()==false)
	{


	Output *pOut = pManager->GetOutput();
	this->ReadActionParameters();
	if(pManager->getCopied() == NULL )
	{
		return ;
	}
	stat=pManager->getCopied();
	pManager->AddStatement(stat);
	P.x=P.x-UI.ASSGN_WDTH/2;
	stat->setStatCorner(P);
	stat->SetSelected(false);
	
	pManager->SetCopied(NULL);
	pManager->UnselectAllstat();
	pOut->ClearDrawArea();

	}

	if (pManager->getCopyCondition()==true)
	{
		Output *pOut = pManager->GetOutput();
		Input *pIn = pManager->GetInput();
		for (int i=0;i<pManager->numCopied();i++)
		{
	         pOut->PrintMessage("Please Click to Paste Last Copied Statement");
	         pIn->GetPointClicked(P);
			 stat=pManager->getMultiCopied(i);
			 pManager->AddStatement(stat);
			 P.x=P.x-UI.ASSGN_WDTH/2;
	         stat->setStatCorner(P);
	         stat->SetSelected(false);
	         pOut->PrintMessage("Statement Pasted");
			 pManager->UpdateInterface();
		}

		for (int i=0;i<=200;i++)
		{
			pManager->SetMultiCopied(NULL,i);

		}
	    pManager->UnselectAllstat();
	    pOut->ClearDrawArea();
	 		


	}
	
}