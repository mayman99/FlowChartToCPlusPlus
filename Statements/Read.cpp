#include"Read.h"
#include<fstream>
Read::Read(Point corner,string s)
{
	
	variable=s;
	
	UpdateStatementText();
	pConn=NULL;
	LeftCorner=corner;
	StatCorner=corner;
	Inlet.x = StatCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = StatCorner.y;
	Outlet.x = Inlet.x;
	Outlet.y = StatCorner.y + UI.ASSGN_HI;

	

	/*ApplicationManager*pMan;
	Input*pIn=pMan->GetInput();
	Output*pOut=pMan->GetOutput();
	variable=pIn->GetValue(pOut);*/
}

void Read::UpdateStatementText()
{
	
		ostringstream T;
		T<<"Read " <<variable;
		Text = T.str();	 
	
}
//double Read::GetValue()
//{
//	return value;
//}


Point Read::GetIn()
{
	return Inlet;
}

Point Read::GetOut()
{
	return Outlet;
}
// void SmplAssign::setConnector(Connector*ptr)
//{
//	pConn=ptr;
//}

 /* Connector* SmplAssign::getConnector()
 {
	 return pConn;
 }*/

void Read::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawRead(StatCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}

bool Read::WithIn(Point p)
{
	bool x=false;
	bool y=false;
	bool z=false;
	if(   StatCorner.x<=p.x && StatCorner.x+UI.ASSGN_WDTH>=p.x  )
	{
		x=true;
	}

	if  (   StatCorner.y<=p.y && StatCorner.y+UI.ASSGN_HI>=p.y )
	{
		y=true;
	}

	if (x==true && y==true )
	{
		z=true;
	}
	return z;
}
string Read::getVariable()
{
	return variable;
}

void Read::PrintInfo(Output* pOut)
{
	string info=Text + " // " + Comment;
	pOut->PrintMessage(info);

}

void Read::setStatCorner(Point corner)
{
	StatCorner=corner;
	Inlet.x = StatCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = StatCorner.y;
	Outlet.x = Inlet.x;
	Outlet.y = StatCorner.y + UI.ASSGN_HI;
}

Point Read::getStatCorner()
{

	return StatCorner;
}


Statement* Read ::getNextStatement()
{
	return getConnector()->getDstStat();
}
void Read::setVariable(string s)
{
	variable=s;
}

void Read::Edit(Output*pOut,Input*pIn)
{

	pOut->PrintMessage("Enter your new Read statement's text");
	string s = pIn->GetString(pOut);
	setVariable(s);
	UpdateStatementText();
}
void Read::Simulate(SimNode * x, int& NodeCount, Output*o,Input* i,int flag)
{
	int index = search(x, getVariable(), NodeCount);
	if (index == -1)
	{
		x[NodeCount].name = getVariable();
		if(flag == 1)
		{
		o->PrintMessage("enter the value of the variable");
		x[NodeCount].value = i->GetValue(o);
		}
		NodeCount++;
	}
	else
	{
		if(flag==1)
		{
		o->PrintMessage("enter the value of the variable");
		x[index].value = i->GetValue(o);
		}

	}
}

void Read::Save(ofstream &OutFile)
{
	OutFile << "Read \t" << getId() << "\t" << getStatCorner().x << "\t" << getStatCorner().y << "\t" << getVariable()<<"\t"<<"\"" <<getComment()<<"\""<<endl;
}

Statement * Read::Load(ifstream &InFile,string z)
{
	
	string type, var, comment;
	type=z;
	int id, x, y;
	InFile  >> id >> x >> y >> var ;
	getline(InFile,comment);
	Point left(x, y);
	Statement *r = new Read(left,var);
	r->setComment(comment);
	r->setId(id);
	return r;
}

void Read::GenerateCode(ofstream &OutFile, SimNode *, int & count)
{
	OutFile << "cin>> " << getVariable() << ";\t\t" << (getComment() == "" ? "" : "//") << (getComment() == "" ? "" : getComment()) << endl;
}