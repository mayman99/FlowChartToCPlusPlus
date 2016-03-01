#include "Delete.h"
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI/input.h"
#include "..\GUI/Output.h"
#include"..\Statements\End.h"
#include"..\Statements\Start.h"

Delete::Delete(ApplicationManager*pAppManager) :Action(pAppManager)
{}


Delete::~Delete()
{}
void Delete::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	stat=pManager->GetSelectedStatement();
	if(stat==NULL)
		return ;
}
void Delete::Execute()
{
	Output *pOut = pManager->GetOutput();
	if (pManager->numSelected()==1)
	{

	ReadActionParameters();
	if(stat==NULL)
	{
		pOut->PrintMessage("No Selected Statement to delete");
		return ;
	}
	pManager->DeleteStatConnectors(stat);
	
	pOut->PrintMessage("Statement deleted");

	End*e= dynamic_cast <End*>(stat);
	if (e!=NULL)
		{
			
			pManager->endCount--;
		}

	Start*s= dynamic_cast <Start*>(stat);
	if (s!=NULL)
		{
			
			pManager->startCount--;
		}


	pManager->DeleteStatement(stat);
	pManager->UnselectAllstat();
	pOut->ClearDrawArea();
	}


	else
	{
		Statement**statments=pManager->GetAllSelectedStatements();
		int num=pManager->numSelected();
		for (int i=0;i<num;i++)
		{  


				End*e= dynamic_cast <End*>(statments[i]);
					if (e!=NULL)
						{
			
							pManager->endCount--;
						}

					Start*s= dynamic_cast <Start*>(statments[i]);
					if (s!=NULL)
						{
			
							pManager->startCount--;
						}
		pManager->DeleteStatConnectors(statments[i]);
		pManager->DeleteStatement(statments[i]);
	}
	pOut->PrintMessage("Statements deleted");
	pManager->UnselectAllstat();
	pOut->ClearDrawArea();

	}


}





	/*Output *pOut = pManager->GetOutput();	
	Statement *sel = pManager->GetSelectedStatement();

	if (sel != NULL && sel->IsSelected())
	{
		pManager->DeleteStatement(sel);
		pOut->PrintMessage("you deleted an object");
		pOut->ClearDrawArea();
	}
}*/
void Delete::ExecuteCopy(const Statement &) {}