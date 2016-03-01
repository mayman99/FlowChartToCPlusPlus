#include"Move.h"
#include<iostream>
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Statements\Connector.h"
#include "..\Statements\Statement.h"

void Move::ReadActionParameters()
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
	pOut->PrintMessage("Please Select Statement to Move");
	Point P;   pOut->pWind->WaitMouseClick(P.x,P.y);
	stat = pManager->GetStatement(P);
}

void Move::Execute()
{

	if (pManager->numSelected()==1)
	{

	this->ReadActionParameters();
	if (stat == NULL)
	{
		pOut->PrintMessage("No Statement Selected Operation terminated");
		return;
	}
	pOut->PrintMessage(" Click anywhere to drop ");
	Point j; Point k;

	while (1)
	{
		
		pOut->pWind->GetMouseCoord(j.x, j.y);

		if (j.y<UI.TlBrWdth)
		{
			pOut->PrintMessage("Cannot move here");
			continue;
		}
		stat->setStatCorner(j);
		pManager->updateConnectors();
		pOut->pWind->GetMouseCoord(k.x, k.y);
		if (k.x - j.x != 0 || k.y - j.y != 0)
		{
			pOut->ClearDrawArea();
			pOut->ClearStatusBar();
			pOut->PrintMessage(" Click anywhere to drop ");
//			pOut->CreateDesignToolBar();

			pManager->UpdateInterface();
		}
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
					
				if (pManager->search_stat(stat))
				{
					pOut->PrintMessage(" Cannot drop here ");
					continue;
				}
				
				stat->SetSelected(false);
				pManager->updateConnectors();
				break;
		}

		
		
	}
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	pOut->PrintMessage("Statement Moved");
	
	}


	else
	{
		pIn = pManager->GetInput();
		pOut = pManager->GetOutput();
		Statement**statments=pManager->GetAllSelectedStatements();
		int i=0;

		while (statments[i]!=NULL)
		{

				pOut->PrintMessage(" Click anywhere to drop ");
				Point j; Point k;
				while (1)
				{
					pOut->pWind->GetMouseCoord(j.x, j.y);
							if (j.y<UI.TlBrWdth)
							{

								pOut->PrintMessage("Cannot move here");
								
								continue;
							}
					statments[i]->setStatCorner(j);
					pManager->updateConnectors();
					pOut->pWind->GetMouseCoord(k.x, k.y);
					if (k.x - j.x != 0 || k.y - j.y != 0)
					{
						pOut->ClearDrawArea();
						pOut->ClearStatusBar();
						pOut->PrintMessage(" Click anywhere to drop ");
//						pOut->CreateDesignToolBar();

						pManager->UpdateInterface();
					}
					if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
						{
					
							if (pManager->search_stat(statments[i]))
							{
								pOut->PrintMessage(" Cannot drop here ");
								continue;
							}
				
							statments[i]->SetSelected(false);
							pManager->updateConnectors();
							break;
					}

				}
				i++;
		}
	}
}