#include "Select.h"
#include "..\ApplicationManager.h"
#include "Move.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Statements\SmplAssign.h"
#include "..\Statements\VarAssign.h"
#include "..\Statements\OperatorAssign.h"
#include "..\Statements\CondAssign.h"
#include"..\Statements\End.h"
#include"..\Statements\Start.h"
#include"..\Statements\Read.h"
#include"..\Statements\Write.h"

Select::Select(ApplicationManager *pAppManager):Action(pAppManager)
{}
Select::~Select()
{}
void Select::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();

	pOut->PrintMessage("tap to select a statement");

	/*pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();*/
}

void Select::Execute()
{
	ReadActionParameters();
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	pIn->GetPointClicked(Position);
	Statement *s=pManager->GetStatement(Position);
	if (s != nullptr)
	{
		if (s->IsSelected() != true)
		{
			//string comm=s->getComment();
			//string LHS;
			//string RHS="";
			//string op="";
			//string op2="";
			//string RHS2="";
			//string All;
			//if (pManager->getStatType(s)==0 )
			//{
			//	double d1;
			//	LHS= dynamic_cast <SmplAssign*>(s)->getLHS();
			//	op=" = ";
			//	d1= dynamic_cast <SmplAssign*>(s)->getRHS();
			//	stringstream ss;
			//	ss<<d1;
			//	RHS=ss.str();
			//	
			//}
			//if (pManager->getStatType(s)==1 )
			//{
			//	LHS= dynamic_cast <VarAssign*>(s)->getLHS();
			//	op=" = ";
			//	RHS= dynamic_cast <VarAssign*>(s)->getRHS();
			//}

			//if (pManager->getStatType(s)==2 )
			//{
			//	LHS= dynamic_cast <OperatorAssign*>(s)->getLHS();
			//	op=" = ";
			//	RHS= dynamic_cast <OperatorAssign*>(s)->getRHS();
			//	op2= dynamic_cast <OperatorAssign*>(s)->getoperation();
			//	RHS2=dynamic_cast <OperatorAssign*>(s)->getRHS2();
			//}

			//if (pManager->getStatType(s)==3 )
			//{
			//	LHS= dynamic_cast <CondAssign*>(s)->getLHS();
			//	RHS= dynamic_cast <CondAssign*>(s)->getRHS();
			//	op= dynamic_cast <CondAssign*>(s)->getoperation();
			//}
			//if (pManager->getStatType(s)==4)
			//{
			//	LHS="Start Statement";
			//}

			//if (pManager->getStatType(s)==5)
			//{
			//	LHS="End Statement";
			//}

			//if (pManager->getStatType(s)==6)
			//{
			//	LHS="Read ";
			//	RHS= dynamic_cast <Read*>(s)->getVariable();
			//}

			//if (pManager->getStatType(s)==7)
			//{
			//	LHS="Write ";
			//	RHS= dynamic_cast <Write*>(s)->getVariable();
			//}

			//All=LHS+op+RHS+op2+RHS2;


			pManager->UnselectAllstat();
			pManager->SetSelectedStatement(s);
			s->SetSelected(true);
			s->PrintInfo(pOut);

			//
			//string st=All+"  // "+ comm;
			//pOut->PrintMessage(st);

			
		}
		else
		{
			s->SetSelected(false);
			pOut->PrintMessage("you Unselected a statement");
		}
	}
	else
	{
		pOut->PrintMessage("No statement was selected or unselected");

	}
}
void Select::ExecuteCopy(const Statement &) {}