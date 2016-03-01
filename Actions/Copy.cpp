
#include"Copy.h"
#include<iostream>
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Statements\Connector.h"
#include "..\Statements\Statement.h"

void Copy::ReadActionParameters()
{
	Data=pManager->GetSelectedStatement();
}

void Copy::Execute()
{
	if (pManager->numSelected()==1)
	{

	ReadActionParameters();
	Output* pOut= pManager->GetOutput();
	if(Data == NULL)
	{
		pOut->PrintMessage("No Selected Statment nothing Copied");
		return;
	}
	pManager->setCopyCondition(false);
	pOut->PrintMessage("Selected Statment Copied");
	pManager ->SetCopied(Data);
	pOut->ClearDrawArea();
	}
	else
	{
		Output* pOut= pManager->GetOutput();
		Statement**statments=pManager->GetAllSelectedStatements();
		pOut->PrintMessage("Selected Statments Copied");
		for (int i=0;i<pManager->numSelected();i++)
		{
			pManager->SetMultiCopied(statments[i],i);
			pOut->ClearDrawArea();
		}

		pManager->setCopyCondition(true);


	}

}







//#include "Copy.h"
//#include "..\Statements\SmplAssign.h"
//#include "..\Statements\VarAssign.h"
//#include "..\ApplicationManager.h"
//#include "..\GUI\input.h"
//#include "AddSmplAssign.h"
//#include "AddVarAssign.h"
//#include "..\GUI\Output.h"
//#include <sstream>
//
//
//Copy::Copy(ApplicationManager*pAppManger) :Action(pAppManger)
//{}
//
//
//Copy::~Copy()
//{}
//
//void Copy::ReadActionParameters() {
//
//}
//void Copy::Execute() {
//	Input *pIn = pManager->GetInput();
//	Output *pOut = pManager->GetOutput();
//	//Statement** Allselected = pManager->GetAllSelectedStatements();
//	Statement *s = pManager->GetSelectedStatement();
//	int i = 0;
//	if (s!=nullptr)
//	{
//			pIn->GetPointClicked(Position);
//			const SmplAssign *l = dynamic_cast<SmplAssign*>(s);//Allselected[i]); /// Conditional and connectors to be added
//			if (l != NULL)
//			{
//				AddSmplAssign *pAct = NULL;
//				pAct = new AddSmplAssign(pManager);
//				pAct->ExecuteCp(*l);	
//				delete pAct;
//			}
//
//			const VarAssign *v = dynamic_cast<VarAssign*>(s);//Allselected[i]); /// Conditional and connectors to be added
//			if (v != NULL)
//			{
//				AddVarAssign *pAct = NULL;
//				pAct = new AddVarAssign(pManager);
//				pAct->ExecuteCp(*v);	
//				delete pAct;
//			}
//
//
//
//
//
//
//
//
//
//
//	//	i++;
//	}
//}
//void Copy::ExecuteCopy(const Statement &)
//{}



