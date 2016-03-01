#include "Cut.h"
#include "Action.h"
#include"..\Statements\Start.h"
#include"..\Statements\End.h"
#include "..\ApplicationManager.h"
#include "..\GUI/input.h"
#include "..\GUI/Output.h"
#include "AddSmplAssign.h"


Cut::Cut(ApplicationManager*app) :Action(app)
{}


Cut::~Cut()
{}

void Cut::ReadActionParameters() {

	stat= pManager->GetSelectedStatement();
	if(stat==NULL)
	{	return;}

	out = stat->getConnector();
	

}
void Cut::Execute()
{

	Output* pOut = pManager->GetOutput();
	if (pManager->numSelected()==1)
	{
		pManager->setCopyCondition(false);
		ReadActionParameters();

		if( stat== NULL )
	{
		pOut->PrintMessage("No Selected Statement to cut");
		return;
	}


	
		pManager->SetCopied(stat,stat->getComment());
	pManager->DeleteStatConnectors(stat);


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
	pOut->ClearDrawArea();
	pOut->PrintMessage("Selected Stamtent Cut");


	}

	else
	{
		pManager->setCopyCondition(true);
		Statement**statments=pManager->GetAllSelectedStatements();
		int num=pManager->numSelected();
		for (int i=0;i<pManager->numSelected();i++)
		{
			pManager->SetMultiCopied(statments[i],i,statments[i]->getComment());
			pManager->DeleteStatConnectors(statments[i]);

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

				
				pManager->UpdateInterface();
		}

		for (int i=0;i<num;i++)
		{
			pManager->DeleteStatement(statments[i]);
		}
		pOut->PrintMessage("Selected Statments Cut");


	}




pOut->ClearDrawArea();



}
void Cut::ExecuteCopy(const Statement &) {}
