#include"End.h"
#include<fstream>
End::End(Point p)
{
	Text="End";
	pConn=NULL;
	StatCorner=p;
	StatCorner.x=p.x;
	StatCorner.y=p.y;
	Inlet.x=StatCorner.x;
	Inlet.y=StatCorner.y-50;

}
void End::UpdateStatementText()
{

}
Point End::GetIn()
{
	return Inlet;
}
Point End::GetOut()
{
	Point t;
	t.x=-1;
	t.y=-1;
	return t;
}
bool End::WithIn(Point p)
{
	bool x=false;
	bool y=false;
	bool z=false;
	if(   StatCorner.x-50<=p.x && StatCorner.x+50>=p.x  )
	{
		x=true;
	}

	if  (   StatCorner.y-50<=p.y && StatCorner.y+50>=p.y )
	{
		y=true;
	}

	if (x==true && y==true )
	{
		z=true;
	}
	return z;
}

void End::Draw(Output* pOut) const
{
	pOut->DrawEnd(StatCorner,Selected);
}

void End::PrintInfo(Output* pOut)
{
	string info=Text + " // " + Comment;
	pOut->PrintMessage(info);

}

void End::setStatCorner(Point corner)
{
	StatCorner=corner;
		Inlet.x=StatCorner.x;
	Inlet.y=StatCorner.y-50;
}


Point End::getStatCorner()
{

	return StatCorner;
}

void End::Edit(Output *pOut, Input *I)
{
	pOut->PrintMessage("An End statement cannot be edited");
}

Statement* End::getNextStatement()
{
	return NULL;
}
void End::Simulate(SimNode * x, int& NodeCount, Output*o, Input* i,int flag)
{
}

void End::Save(ofstream &OutFile)
{
	OutFile << "End \t" << getId()<<"\t" << getStatCorner().x <<"\t"<< getStatCorner().y<<"\t"<<"\"" <<getComment()<<"\""<<endl;
}

Statement* End::Load(ifstream &InFile,string z)
{
	string type, comment;
	int id, x, y , typ;
	type=z;
	InFile >> id >> x >> y ;
	getline(InFile,comment);
	Point left(x, y);
		Statement * e = new End(left);
		e->setComment(comment);
		e->setId(id);
		return e;

}

void End::GenerateCode(ofstream &Outfile, SimNode* x, int &count)
{
	
		Outfile << "\n return 0; \n}\t\t" << (getComment() == "" ? "" : "//") << (getComment() == "" ? "" : getComment());
}