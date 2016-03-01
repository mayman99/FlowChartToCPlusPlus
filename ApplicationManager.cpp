#include "ApplicationManager.h"
#include<cmath>
#include "Actions\AddVarAssign.h"
#include "Actions\AddSmplAssign.h"
#include"Actions\AddOperatorAssign.h"
#include"Actions\AddCond.h"
#include"Actions\AddConnector.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Actions\select.h"
#include "Actions\Move.h"
#include "Actions\Copy.h"
#include "Actions\Cut.h"
#include "Actions\Delete.h"
#include "Actions\Edit.h"
#include "Actions\MultiSelect.h"
#include"Actions\AddEnd.h"
#include"Actions\AddStart.h"
#include"Actions\AddRead.h"
#include"Actions\AddWrite.h"
#include"Actions\Paste.h"
#include"Actions\Comment.h"
#include"Actions\Exit.h"
#include"Actions\SwitchToDes.h"
#include"Actions\SwitchToSim.h"
#include"Actions\Save.h"
#include"Actions\Load.h"
#include"Actions\Run.h"
#include"Actions\StepbyStep.h"
#include"Actions\ChartValidation.h"
#include"Actions\GenerateCode.h"
;
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	NodesArray=new SimNode[200];
	StatCount = 0;
	ConnCount = 0;
	startCount=0;
	endCount=0;
	NodeCount=0;
	LocalId=1;
	ConnLocalId=1;
	pSelectedStat = NULL;	//no Statement is selected yet
	Copied=NULL;
	MultiCopy=false;
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
		MultiCopied[i] =NULL;
	}
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	Point p;
	//According to ActioType, create the corresponding action object
	switch (ActType)
	{
		case ADD_SMPL_ASSIGN:
		    pAct = new AddSmplAssign(this);
			break;
		case ADD_VAR_ASSIGN:
			pAct= new AddVarAssign(this);
			break;
		case ADD_OP_ASSIGN:
			pAct= new AddOperatorAssign(this);
			break;
		case ADD_COND:
			pAct= new AddCond(this);
			
			break;
		case ADD_CONNECTOR:
			pAct= new AddConn(this);
			break;

		
		case ADD_END:
			if (endCount==0)
			{
				pAct=new AddEnd(this);
				endCount++;
			}
			else
			{
				pOut->PrintMessage("There is already one end statement Can't add more");
	        } 

			break;

		case ADD_START:
			if (startCount==0)
			{
				pAct=new AddStart(this);
				startCount++;
			}
			else {
				pOut->PrintMessage("There is already one start statement Can't add more");
			}
		
			break;
		case ADD_INPUT:
			pAct=new AddRead(this);
			break;
		case ADD_OUTPUT:
			pAct=new AddWrite(this);
			break;
		case SELECT:
			///create Select Action her
			pAct = new Select(this);
			break;
		case ADD_COMMENT:
			pAct= new Comment(this);
			break;
		case EDIT:
			pAct = new Edit(this);
			break;

		case MULTI_SELECT:
			pAct = new MultiSelect(this);
			break;

		case DEL:
			
			pAct = new Delete(this);
			break;

		case MOVE:
			pAct = new Move(this);
			break;

		case COPY:
			pAct = new Copy(this);
			break;
		case PASTE:
			pAct= new Paste(this);
			break;
		case CUT:
			pAct = new Cut(this);
			break;
		case SAVE:
			pAct=new Save (this);
			break;
		case LOAD:
			pAct=new Load(this);
		    break;
		case STATUS:
			return;

		case DSN_MODE:
			pAct=new SwitchToDes(this);
			break;
		case SIM_MODE:
			pAct=new SwitchToSim(this);
			break;
		case RUN:

			//pAct=new ChartValidation(this);
			//pOut->pWind->WaitMouseClick(p.x,p.y);
			pAct= new Run(this);
			break;
		case STEP:
			pAct=new StepByStep(this);
			break;
		case CODE:
			pAct=new GenerateCode(this);
			break;
		case EXIT:
			pAct=new Exit(this);	
			break;
		
		
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}



//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//
//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if(StatCount < MaxCount)
		StatList[StatCount++] = pStat;
		pStat->setId(LocalId);
	LocalId++;
	
}


void ApplicationManager:: setLocalId(int x)
{
	LocalId=x;
}
void ApplicationManager:: setConnLocalId(int x)
{
	ConnLocalId=x;
}

int ApplicationManager:: getLocalId()
{
	return LocalId;
}

int ApplicationManager:: getConnLocalId()
{
	return ConnLocalId;
}
////////////////////////////////////////////////////////////////////////////////////
bool ApplicationManager::search_stat(Statement *start)
{

	bool z=false;
	for (int i=0;i<StatCount;i++)
	{
		if ((abs(StatList[i]->getStatCorner().x-start->getStatCorner().x))<150 && (abs(StatList[i]->getStatCorner().y-start->getStatCorner().y))<80 && StatList[i]!=start)
		{
			z=true;
		}
			
	}

return z;

}

void ApplicationManager::DeleteStatement(Statement* p) {
	if(p==NULL)
	{
		return;
	}

	/*int n=x->getId();*/
	int i=0;
	for (i;i<StatCount;i++)
	{
		if (StatList[i]==p) break;
	}
	for (i;i<StatCount-1;i++)
	{
		StatList[i]=StatList[i+1];
		
	}
	StatCount--;
	delete p;
}

void ApplicationManager::deleteConnector(Connector*x)
{
	if(x==NULL)
		return;
	int n=x->getId();int i=0;
	for (i;i<ConnCount;i++)
	{
		if (ConnList[i]->getId()==n) break;
	}
	for (i;i<ConnCount-1;i++)
	{
		ConnList[i]=ConnList[i+1];
	}
	ConnCount--;
	delete x;
}
///////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL
	Statement*ptr=NULL;
	for (int i=0;i<StatCount;i++)
	{
		if(StatList[i]->WithIn(P)==true)
		{
			 ptr=StatList[i];
			// break;

		}


	}


	

	return ptr;
}
/////////////////////////////////////////////////////////////////////////////////

Statement** ApplicationManager::GetAllSelectedStatements()
{
	for (int i = 0; i < MaxCount; i++)
	{
		AllSelectedStatments[i] = NULL;
	}
	int j = 0;
	for (int i = 0; i<MaxCount; i++)
	{
		if (StatList[i]!=NULL && StatList[i]->IsSelected()==true  )
		{
			AllSelectedStatments[j] = StatList[i];
			j++;
		}
		
	}
	return AllSelectedStatments;
}

////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}



void ApplicationManager:: UnselectAllstat()
	{
		for(int i=0; i<StatCount;i++)
			StatList[i]->SetSelected(false);
		for(int i=0; i<ConnCount; i++)
			//ConnList[i]->setSelected(false);
		pSelectedStat=NULL;
		pOut->ClearDrawArea();
		UpdateInterface();
	
	}

int ApplicationManager :: getScount()
{
	return StatCount;
}

int ApplicationManager :: getCcount ()
{
	return ConnCount;
}

void ApplicationManager::AddConnector(Connector *pConn)
{
	ConnList[ConnCount++]=pConn;
	pConn->setId(ConnLocalId);
	ConnLocalId++;
}


//int ApplicationManager::ConnNum()const
//{
//	return ConnCount;
//}

void ApplicationManager ::updateConnectors()
{
		for (int i = 0; i < ConnCount; i++)
		{
			Statement *x = ConnList[i]->getSrcStat();
			Point j; j = x->GetOut();
			
			
			ConnList[i]->setStartPoint(j);
			
			x = ConnList[i]->getDstStat();
			j = x->GetIn();
			ConnList[i]->setEndPoint(j);
		}

}



void ApplicationManager::DeleteStatConnectors(Statement*stat)
{
	
	for (int i = 0; i < ConnCount; i++)
	{
		if (ConnList[i]->getDstStat() == stat || ConnList[i]->getSrcStat() == stat)
		{
			/*if (ConnList[i]->getType() != 2)*/ 
			ConnList[i]->getSrcStat()->setConnector(NULL);
				deleteConnector(ConnList[i]); 
			i--;
		}
				
	}
		

}


void ApplicationManager :: SetCopied(Statement* x,string str)
{
	Point temp;
	 SmplAssign* a= dynamic_cast <SmplAssign*>(x);
	if(a!=NULL)
	{
		temp=x->getStatCorner();
		temp.x=temp.x+UI.ASSGN_WDTH/2;
		Copied=new SmplAssign(temp,a->getLHS(),a->getdoubleRHS());
		Copied->setComment(str);
	}

	 VarAssign* v= dynamic_cast <VarAssign*>(x);
	if(v!=NULL)
	{
		temp=x->getStatCorner();
		temp.x=temp.x+UI.ASSGN_WDTH/2;
		Copied=new VarAssign(temp,v->getLHS(),v->getRHS());
		Copied->setComment(str);
	}

	OperatorAssign* o= dynamic_cast <OperatorAssign*>(x);
	if(o!=NULL)
	{
		temp=x->getStatCorner();
		temp.x=temp.x+UI.ASSGN_WDTH/2;
		Copied=new OperatorAssign(temp,o->getLHS(),o->getoperation(),o->getRHS(),o->getRHS2());
		Copied->setComment(str);
	}
	CondAssign* c= dynamic_cast <CondAssign*>(x);
	if(c!=NULL)
	{
		temp=x->getStatCorner();
		temp.x=temp.x+UI.COND_WDTH/2;
		
		Copied = new CondAssign(temp,c->getoperation(),c->getLHS(),c->getRHS());
		Copied->setComment(str);
	}
	Start* s= dynamic_cast <Start*>(x);
	if(s!=NULL)
	{
		
			Copied=new Start(x->getStatCorner());
		Copied->setComment(str);
	}

	End* e= dynamic_cast <End*>(x);
	if(e!=NULL)
	{
		
			Copied=new Start(x->getStatCorner());
		Copied->setComment(str);
	}
	Read* r= dynamic_cast <Read*>(x);
	if(r!=NULL)
	{
				temp=x->getStatCorner();
		temp.x=temp.x+UI.ASSGN_WDTH/2;
		Copied=new Read(temp,r->getVariable());
		Copied->setComment(str);
	}
	Write* w= dynamic_cast <Write*>(x);
	if(w!=NULL)
	{
				temp=x->getStatCorner();
		temp.x=temp.x+UI.ASSGN_WDTH/2;
		Copied=new Write(temp,w->getVariable());
		Copied->setComment(str);
	}
}


Statement* ApplicationManager :: getCopied()
{
	return Copied;
}


Statement*	ApplicationManager:: getMultiCopied(int i)
	{
		Statement*str=MultiCopied[i];
		return str;
	}


void ApplicationManager::SetMultiCopied(Statement*s,int i,string str)
{

	Point temp;
	 SmplAssign* a= dynamic_cast <SmplAssign*>(s);
	if(a!=NULL)
	{
		temp=s->getStatCorner();
		temp.x=temp.x+UI.ASSGN_WDTH/2;
		MultiCopied[i]=new SmplAssign(temp,a->getLHS(),a->getdoubleRHS());
		MultiCopied[i]->setComment(str);
	}

	VarAssign* v= dynamic_cast <VarAssign*>(s);

	if(v!=NULL)
	{
		temp=s->getStatCorner();
		temp.x=temp.x+UI.ASSGN_WDTH/2;
		MultiCopied[i]=new VarAssign(temp,v->getLHS(),v->getRHS());
		MultiCopied[i]->setComment(str);
	}

	OperatorAssign* o= dynamic_cast <OperatorAssign*>(s);

	if(o!=NULL)
	{
		temp=s->getStatCorner();
		temp.x=temp.x+UI.ASSGN_WDTH/2;
		MultiCopied[i]=new OperatorAssign(temp,o->getLHS(),o->getoperation(),o->getRHS(),o->getRHS2());
		MultiCopied[i]->setComment(str);
	}

	CondAssign* c= dynamic_cast <CondAssign*>(s);

	if(c!=NULL)
	{
		temp=s->getStatCorner();
		temp.x=temp.x+UI.COND_WDTH/2;
		
		MultiCopied[i] = new CondAssign(temp,c->getoperation(),c->getLHS(),c->getRHS());
		MultiCopied[i]->setComment(str);
	}
	Start* st= dynamic_cast <Start*>(s);
	if(st!=NULL)
	{
		
			MultiCopied[i]=new Start(s->getStatCorner());
			MultiCopied[i]->setComment(str);
		
	}

	End* e= dynamic_cast <End*>(s);
	if(e!=NULL)
	{
		
			MultiCopied[i]=new Start(s->getStatCorner());
		MultiCopied[i]->setComment(str);
	}
	Read* r= dynamic_cast <Read*>(s);
	if(r!=NULL)
	{
				temp=s->getStatCorner();
		temp.x=temp.x+UI.ASSGN_WDTH/2;
		MultiCopied[i]=new Read(temp,r->getVariable());
		MultiCopied[i]->setComment(str);
	}
	Write* w= dynamic_cast <Write*>(s);
	if(w!=NULL)
	{
				temp=s->getStatCorner();
		temp.x=temp.x+UI.ASSGN_WDTH/2;
		MultiCopied[i]=new Write(temp,w->getVariable());
		MultiCopied[i]->setComment(str);
	}

}

int ApplicationManager::getStatType(Statement*x)
{
	int i;
	 SmplAssign* a= dynamic_cast <SmplAssign*>(x);
	if(a!=NULL)
	{
		i=0;
	}

	VarAssign* v= dynamic_cast <VarAssign*>(x);

	if(v!=NULL)
	{
		i=1;
	}

	OperatorAssign* o= dynamic_cast <OperatorAssign*>(x);

	if(o!=NULL)
	{
		i=2;
	}

	CondAssign* c= dynamic_cast <CondAssign*>(x);

	if(c!=NULL)
	{
		i=3;
	}
	Start* st= dynamic_cast <Start*>(x);

	if(st!=NULL)
	{
		i=4;		
	}

	End* e= dynamic_cast <End*>(x);

	if(e!=NULL)
	{
		i=5;
	}
	Read* r= dynamic_cast <Read*>(x);
	
	if(r!=NULL)
	{
		i=6;
	}
	Write* w= dynamic_cast <Write*>(x);

	if(w!=NULL)
	{
		i=7;
	}
	return i;

}

int ApplicationManager::numSelected()
{
	int count=0;
	for (int i=0;i<StatCount;i++)
	{
		if (StatList[i]->IsSelected()==true)
		{
			count++;
		}

	}
	
	return count;
}
void ApplicationManager::setCopyCondition(bool z)
{
	MultiCopy=z;
}
bool ApplicationManager::getCopyCondition()
{
	return MultiCopy;
}
int ApplicationManager::numCopied()
{
	int count=0;
	int i=0;
	while(MultiCopied[i]!=NULL)
	{
		count++;
		i++;
	}
	return count;
}
bool ApplicationManager:: Search_Conn(Statement* s2)
{
	bool z=false;
	for (int i=0;i<ConnCount;i++)
	{
		if(s2==ConnList[i]->getDstStat())
		{
			z=true;
			
		}
		
	}
	return z;
}
Statement* ApplicationManager ::SearchId(int x)  ///////////////////////
{
	for(int i=0;i<StatCount;i++)
	{
		if(StatList[i]->getId()==x)
			return StatList[i];
	}
	return NULL;
}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;	}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	//Draw all statements
	for(int i=0; i<StatCount; i++)
		StatList[i]->Draw(pOut);
	
	//Draw all connections
	for(int i=0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////


//Destructor

void ApplicationManager::setMaxId()
{
		int max=0;
		if(StatList[0]!=NULL)
		{max=StatList[0]->getId();}

		for(int i=0;i<StatCount;i++)
		{
			if(StatList[i]->getId() > max)
				max =StatList[i]->getId();

		}
		LocalId=max+1;

		for(int i=0;i<ConnCount;i++)
		{
			if(ConnList[i]->getId() > max)
				max =ConnList[i]->getId();

		}
		ConnLocalId=max+1;
	

}

int ApplicationManager :: search(SimNode * x, string y, int NodeCount)
{
	for (int i = 0; i < NodeCount; i++)
	{
		if (x[i].name == y)
			return i;
	}
	return -1;
}
int ApplicationManager::getCondnum()
 {
		 int count=0;
		 for(int i=0;i<StatCount;i++)
		 {
			 CondAssign*cond=dynamic_cast<CondAssign*>(StatList[i]);
			 if(cond!=NULL)
			 { count++;}
		 }
		 return count;
	 }
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
	
}
