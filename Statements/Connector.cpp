#include "Connector.h"
#include<fstream>
#include"Statement.h"
#include"CondAssign.h"
#include "../ApplicationManager.h"
using namespace std;

//int Connector::LocalID=0;

//class Statement;
Connector::Connector(Statement* Src	, Statement* Dst)	
//When a connector is created, it must have a source statement and a destination statement
//There are no free connectors in the folwchart
{
	
	SrcStat = Src;
	DstStat = Dst;
	//LocalID++;
	//ID=LocalID;
}

void Connector::setSrcStat(Statement *Src)
{	SrcStat = Src;	}

Statement* Connector::getSrcStat()
{	return SrcStat;	}

void Connector::setDstStat(Statement *Dst)
{	DstStat = Dst;	}

Statement* Connector::getDstStat()
{	return DstStat;	}

void Connector::setStartPoint(Point P)
{	Start = P;	}

Point Connector::getStartPoint()
{	return Start;	}


void Connector::setId(int id)
{ ID = id; }

int Connector :: getId()
{
	return ID;
}





void Connector::setEndPoint(Point P)
{
	End = P;
	
}

Point Connector::getEndPoint()
{	return End;	}

void Connector::Draw(Output* pOut) const
{
	///TODO: Call output to draw a connector from SrcStat to DstStat on the output window

	pOut->DrawConnector(Start,End);
	
}


void Connector::Save(ofstream & OutFile)
{
	OutFile << SrcStat->getId() <<"  "<<DstStat->getId()<<"  "<< type <<endl;
}

Connector *Connector:: Load(ifstream &InFile,ApplicationManager*pManager)
{
	string temp; int src; int dest,type;
	InFile >> src >> dest>>type  ;
	Statement*Src = pManager->SearchId(src);	
	Statement*Dest = pManager->SearchId(dest);
	Connector *x = new Connector(Src, Dest);
	x->type=type;
		if(type==2)
		{
		CondAssign*cond=dynamic_cast<CondAssign*>(Src);
		Point l=cond->GetOut2(); 
		x->setStartPoint(l);
		cond->setNo(x);
		

		}

		if (type==1)
		{
			CondAssign*cond=dynamic_cast<CondAssign*>(Src);
			Point l=Src->GetOut();
			x->setStartPoint(l);
			cond->setYes(x);
		}
		else
		{
	Point l=Src->GetOut();
	x->setStartPoint(l);
		}
	
	x->setEndPoint(Dest->GetIn());
	  ////////////////////////

	if(x->type==0)
		{Src->setConnector(x); } ////////////////////////
	return x;
	
}
