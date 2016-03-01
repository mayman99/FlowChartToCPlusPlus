#include "AddConnector.h"

#include"..\Statements\Connector.h"
#include"..\ApplicationManager.h"
#include"..\Statements\SmplAssign.h"
#include"../Statements/CondAssign.h"
#include"..\Statements\End.h"
#include"..\Statements\Start.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

AddConn::AddConn(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddConn::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Click on two statements to connect them");

	pIn->GetPointClicked(first);

	pIn->GetPointClicked(second);


	
	pOut->ClearStatusBar();		
}

void AddConn::Execute()
{
	
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	Statement*s1;
	Statement*s2;

	pOut->PrintMessage("Click on two statements to connect them");

		pIn->GetPointClicked(first);

		s1=pManager->GetStatement(first);

		
			
	pIn->GetPointClicked(second);

	s2=pManager->GetStatement(second);


	if (dynamic_cast<End*>(s1)!=NULL)
		{
			s1=NULL;
			pOut->PrintMessage("Error: End statement has no outlet");
			return;
		}

	//if (pManager->Search_Conn(s2)==true)
	//{
	//	pOut->PrintMessage("Error: statement has only one inlet");
	//	return;
	//}

	if (dynamic_cast<Start*>(s2)!=NULL)
		{
			s2=NULL;
			pOut->PrintMessage("Error: Start statement has no inlet");
			return;
		}


	if (s1!=NULL && s2!=NULL)
	{


		
	 Connector*ptr = new Connector(s1,s2);

	CondAssign* temp=dynamic_cast<CondAssign*>(s1);
	 if (temp!=NULL)
	 {
		 if (temp->GetYes()!=NULL)
		 {
			 if (temp->GetNo()==NULL)
			 {
			 ptr->setStartPoint(temp->GetOut2());
			 
			 ptr->setEndPoint(s2->GetIn());
			  temp->setNo(ptr);
			  ptr->type=2;
			  pManager->AddConnector(ptr);
			 }
			 else
			 {
				 delete ptr;
			 }
		 }
		 else 
		 {


			 
			 ptr->setStartPoint(s1->GetOut());
			  
			  ptr->setEndPoint(s2->GetIn());
			  temp->setYes(ptr);
			  ptr->type=1;
			   pManager->AddConnector(ptr);

		 }
	 }

	 else
	 {
		 if (s1->getConnector()==NULL)
		 {
			 
	         ptr->setStartPoint(s1->GetOut());
	         

	         ptr->setEndPoint(s2->GetIn());
			 ptr->type=0;
	 
	         s1->setConnector(ptr);
			  pManager->AddConnector(ptr);
		 }
		 else
		 {
			 pOut->PrintMessage("Error: this statement has only one outlet ");
			 delete ptr;
		 }
	 
	 }
	
	 
	pManager->UpdateInterface();
}

	 

	
}
