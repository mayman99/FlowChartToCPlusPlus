#include"Write.h"
#include<fstream>
Write::Write(Point corner,string s)
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

void Write::UpdateStatementText()
{
	
		ostringstream T;
		T<<"Write " <<variable;
		Text = T.str();	 
	
}
//double Write::GetValue()
//{
//	return value;
//}


Point Write::GetIn()
{
	return Inlet;
}

Point Write::GetOut()
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

void Write::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawWrite(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}
void Write::setVariable(string s)
{
	variable=s;
}
string Write::getVariable()
{
	return variable;
}
void Write::setStatCorner(Point corner)
{
	StatCorner=corner;
	Inlet.x = StatCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = StatCorner.y;
	Outlet.x = Inlet.x;
	Outlet.y = StatCorner.y + UI.ASSGN_HI;
}

Point Write::getStatCorner()
{

	return StatCorner;
}

bool Write::WithIn(Point p)
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

void Write::PrintInfo(Output* pOut)
{
	string info=Text + " // " + Comment;
	pOut->PrintMessage(info);

}
void Write::Edit(Output*pOut,Input*pIn)
{

	pOut->PrintMessage("Enter your new Write statement's text");
	string s = pIn->GetString(pOut);
	setVariable(s);
	UpdateStatementText();
}

void Write::Simulate(SimNode * x, int& NodeCount, Output*pOut, Input* i,int flag)
{
	int index = search(x, getVariable(), NodeCount);

				value= x[index].value;

				double y=value;
	string s1,s2;
	stringstream convert;
		convert<<y;
		s1=convert.str();
		
		s2=getVariable()+" = " +s1;
		pOut->PrintMessage(s2);

}

Statement* Write ::getNextStatement()
{
	return getConnector()->getDstStat();
}

void Write::Save(ofstream &OutFile)
{
	OutFile << "Write \t" << getId() << "\t" << getStatCorner().x << "\t" << getStatCorner().y << "\t" << getVariable()<<"\t"<<"\"" <<getComment()<<"\""<<endl;
}

Write * Write::Load(ifstream &InFile,string z)
{
	string type, variable,comment;
	int id, x, y;
	type =z;
	InFile  >> id >> x >> y >> variable;
	getline(InFile,comment);
	Point left(x, y);
	Write * write = new Write(left, variable);
	write->setComment(comment);
	write->setId(id);
	return write;
}

void Write::GenerateCode(ofstream & OutFile, SimNode*, int &)
{
	OutFile << "cout<<" << getVariable() << ";\t\t" << (getComment() == "" ? "" : "//") << (getComment() == "" ? "" : getComment())<<endl;
}