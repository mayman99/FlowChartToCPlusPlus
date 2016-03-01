#include"Load.h"
#include<iostream>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Statements\Connector.h"
#include "..\Statements\Statement.h"
#include "..\ApplicationManager.h"
#include"..\Statements\SmplAssign.h"
#include"..\Statements\VarAssign.h"
#include"..\Statements\OperatorAssign.h"
#include"..\Statements\CondAssign.h"
#include "../Statements/Start.h"
#include "../Statements/End.h"
#include "../Statements/Write.h"
#include "../Statements/Read.h"
#include<fstream>
 using namespace std;


 void Load::Execute()
 { 
	 for(int i=0; i<pManager->getScount(); i++)
	 {
		delete pManager->StatList[i];
		pManager->StatCount=0;
	 }
	for(int i=0; i<pManager->getCcount(); i++)
	{
		delete pManager->ConnList[i];
		pManager->ConnCount=0;
	}
	 Statement *x;
	 int size;  string text;
	 input.open("chart.txt");
	 input>>size;
	 string s1,s2,s3,s4;
	 s1=s2=s3=s4="";
	 Point ptemp;
	 ptemp.x=ptemp.y=0;

	 for(int i=0;i<size;i++)
	 {
		 input>>text;
		 
		 if(text=="Start")
		 {
			 Start tempc(ptemp);
			 x = tempc.Load(input,text);
			 int k=x->getId();
			 pManager->startCount=1;
			 pManager->AddStatement(x);
			 x->setId(k);

		 }
		 if(text=="Read")
		 {
			 Read tempc(ptemp,s1);
			 x = tempc.Load(input,text);
			 int k=x->getId();
			 pManager->AddStatement(x);
			 x->setId(k);

		 }
		 if(text=="CondAssign")
		 {
			 CondAssign tempc(ptemp,s1,s2,s3);
			 x = tempc.Load(input,text);
			 int k=x->getId();
			 pManager->AddStatement(x);
			 x->setId(k);
		 }
		 if(text=="OperatorAssign")
		 {
			 OperatorAssign tempa(ptemp,s1,s2,s3,s4);
			 x = tempa.Load(input,text);
			 int k=x->getId();
			 pManager->AddStatement(x);
			 x->setId(k);

		 }
		  if(text=="SmplAssign")
		 {
			 SmplAssign tempa(ptemp,s1);
			 x = tempa.Load(input,text);
			 int k=x->getId();
			 pManager->AddStatement(x);
			 x->setId(k);

		 }
		   if(text=="VarAssign")
		 {
			 VarAssign tempa(ptemp,s1,s2);
			 x = tempa.Load(input,text);
			 int k=x->getId();
			 pManager->AddStatement(x);
			 x->setId(k);

		 }
		 if(text=="Write")
		 {
			 Write tempc(ptemp,s1);
			 x = tempc.Load(input,text);
			 int k=x->getId();
			 pManager->AddStatement(x);
			 x->setId(k);
		 }
		 if(text=="End")
		 {
			 End tempc(ptemp);
			 x = tempc.Load(input,text);
			 int k=x->getId();
			 pManager->endCount=1;
			 pManager->AddStatement(x);
			 x->setId(k);
		 }
	 }
	 input >> size;
	 for (int i = 0; i < size; i++)
	 {
		 Connector* y;
		 Connector z;
		 y = z.Load(input,pManager);
		 pManager->AddConnector(y);
	 }
	 Output* pOut = pManager->GetOutput();
	 pOut -> PrintMessage(" File Loaded from chart.txt ");
	 input.close();
	 pManager->setMaxId();
	 
	 pOut->ClearDrawArea();
 }