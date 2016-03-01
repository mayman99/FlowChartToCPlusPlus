#include"Start.h"
#include<fstream>
Start::Start(Point p)
{
	Text="Start";
	pConn=NULL;
	StatCorner=p;
	StatCorner.x=p.x;
	StatCorner.y=p.y;
	Outlet.x=StatCorner.x;
	Outlet.y=StatCorner.y+50;

}
void Start::UpdateStatementText()
{

}

void Start::PrintInfo(Output* pOut)
{
	string info=Text + " // " + Comment;
	pOut->PrintMessage(info);

}
Point Start::GetIn()
{
	Point t;
	t.x=-1;
	t.y=-1;
	return t;
	
}
Point Start::GetOut()
{
	return Outlet;
}
bool Start::WithIn(Point p)
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

Statement* Start ::getNextStatement()
{
	return getConnector()->getDstStat();
}

void Start::Draw(Output* pOut) const
{
	pOut->DrawStart(StatCorner,Selected);
}
void Start::setStatCorner(Point corner)
{
	StatCorner=corner;
	Outlet.x=StatCorner.x;
	Outlet.y=StatCorner.y+50;

}

Point Start::getStatCorner()
{

	return StatCorner;
}
void Start::Edit(Output *pOut, Input *I)
{
	pOut->PrintMessage("A start statement cannot be edited");
}

void Start::Simulate(SimNode * x, int& NodeCount, Output*o, Input* i,int flag)
{
}

void Start::Save(ofstream &OutFile)
{
	OutFile << "Start \t" << getId()<<"\t" << getStatCorner().x <<"\t"<< getStatCorner().y<<"\t"<<"\"" <<getComment()<<"\""<<endl;
}

Statement* Start::Load(ifstream &InFile,string z)
{
	string type, comment;
	int id, x, y , typ;
	type=z;
	InFile >> id >> x >> y ;
	getline(InFile,comment);
	Point left(x, y);
		Statement * s = new Start(left);
		s->setComment(comment);
		s->setId(id);
		return s;

}

void Start::GenerateCode(ofstream &Outfile, SimNode* x, int &count)
{
		Outfile << "#include<iostream>\nusing namespace std;\t\t" << (getComment() == "" ? "" : "//")
			<< (getComment() == "" ? "" : getComment()) << "\n int main()\n{ \n" << endl;
		Outfile << "double ";
		for (int i = 0; i < count - 1; i++)
			Outfile << x[i].name << ",";
		Outfile << x[count - 1].name << ";" << endl;
	
}