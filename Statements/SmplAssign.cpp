#include "SmplAssign.h"
#include <sstream>
#include<fstream>

using namespace std;

SmplAssign::SmplAssign(Point Lcorner, string LeftHS, double RightHS)
{
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;
	StatCorner=Lcorner;
	pConn = NULL;	//No connectors yet

	Inlet.x = StatCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = StatCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = StatCorner.y + UI.ASSGN_HI;	
}

SmplAssign::SmplAssign(Point Lcorner,const SmplAssign & s)
{
	LHS = s.LHS;
	RHS = s.RHS;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void SmplAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void SmplAssign::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}
Point SmplAssign::GetIn()
{
	return Inlet;
}

Point SmplAssign::GetOut()
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

void SmplAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(StatCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}

void SmplAssign::PrintInfo(Output* pOut)
{
	string info=Text + " // " + Comment;
	pOut->PrintMessage(info);

}
Statement* SmplAssign ::getNextStatement()
{
	return getConnector()->getDstStat();
}


string SmplAssign::getLHS()
{
	return LHS;
}
double SmplAssign::getdoubleRHS()
{
	return RHS;
}

string SmplAssign::getRHS()
{
	double x=RHS;
	string s1;
	stringstream convert;
		convert<<x;
		s1=convert.str();
		
		return s1;
}
void SmplAssign::setStatCorner(Point corner)
{
	StatCorner=corner;
	Inlet.x = StatCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = StatCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = StatCorner.y + UI.ASSGN_HI;	

}

Point SmplAssign::getStatCorner()
{

	return StatCorner;
}


bool SmplAssign::WithIn(Point p)
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
//This function should be called when LHS or RHS changes
void SmplAssign::UpdateStatementText()
{
	if(LHS=="")	//No left handside ==>statement have no valid text yet
		Text = "    = ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T<<LHS<<" = "<<RHS;	
		Text = T.str();	 
	}
}



void SmplAssign::Edit(Output*pOut,Input*pIn)
{
	pOut->PrintMessage(" Enter (1) to change Left handside or (2) to change Right handside ");
		int n =pIn->GetValue(pOut);
		double l;
		string s;
		switch (n)
		{
		case 1:
			{
			pOut->PrintMessage("Enter the new LHS");
			s=pIn->GetString(pOut);

				double x;
				stringstream convert(s);
				convert>>x;
				bool z=false;
				 z=!convert.fail();
				while (z)
					{
						pOut->PrintMessage("Error! Enter a Variable ");
						s=pIn->GetString(pOut);
						stringstream convert(s);
			
						convert>>x;
						z=!convert.fail();
					}


			setLHS(s);
			break;
			}
		case 2:
			pOut->PrintMessage("Now Enter the new RHS");
			l=pIn->GetValue(pOut);
			setRHS(l);
			break;
			default: 
				pOut->PrintMessage("Wrong input");
				return;
		}
			UpdateStatementText();
			pOut->PrintMessage("Simple Assignment Statement Edited Successfully");

}

void SmplAssign::Simulate(SimNode* x,int & NodeCount,Output*pOut,Input* pIn,int flag)		//efred el variable fel Vrbl aw el SnglOp mesh mawgood
{
	int index = search(x, getLHS(), NodeCount);
	if (index == -1)
	{
		x[NodeCount].name = getLHS();
		
		x[NodeCount].value = getdoubleRHS();
		
		NodeCount++;
	}
	else
	{
		
			x[index].value = getdoubleRHS();
	}
}

void SmplAssign::Save(ofstream &OutFile)
{
	OutFile << "SmplAssign\t" << getId() << "\t" << getStatCorner().x << "\t" << getStatCorner().y << "\t" << getLHS() 
			<< "\t" << getRHS() << "\t\"" << getComment() << "\"" << endl;
}

SmplAssign * SmplAssign::Load(ifstream & Infile,string text)
{
	string type, LHS ,RHS, comment;
	int id, x, y;
	type =text;
	Infile >> id >> x >> y >> LHS >> RHS;
	Point left(x, y);

				double dd;
				stringstream convert(RHS);
				convert>>dd;

		getline(Infile,comment);
		SmplAssign * Smpl = new SmplAssign(left, LHS, dd);
		Smpl->setComment(comment);
		Smpl->setId(id);
		return Smpl;
}

void SmplAssign::GenerateCode(ofstream &OutFile, SimNode * ss, int & count)
{
OutFile << getLHS() << "=" << getRHS() << ";\t\t" << (getComment() == "" ? "" : "//") << (getComment() == "" ? "" : getComment())<<endl;
}