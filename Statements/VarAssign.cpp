#include"VarAssign.h"
#include<fstream>

VarAssign::VarAssign(Point Lcorner, string LeftHS, string RightHS)
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

VarAssign::VarAssign(Point Lcorner,const VarAssign & s)
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
void VarAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void VarAssign::setRHS(string &R)
{
	RHS = R;
	UpdateStatementText();
}

bool VarAssign::WithIn(Point p)
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
Point VarAssign::GetIn()
{
	return Inlet;
}

Point VarAssign::GetOut()
{
	return Outlet;
}

//void VarAssign::setConnector(Connector*ptr)
//{
//	pConn=ptr;
//}

 //Connector* VarAssign::getConnector()
 //{
	// return pConn;
 //}
void VarAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(StatCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}

Statement* VarAssign ::getNextStatement()
{
	return getConnector()->getDstStat();
}

void VarAssign::setStatCorner(Point corner)
{
	StatCorner=corner;
	Inlet.x = StatCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = StatCorner.y;
	Outlet.x = Inlet.x;
	Outlet.y = StatCorner.y + UI.ASSGN_HI;
}

Point VarAssign::getStatCorner()
{

	return StatCorner;
}

string VarAssign::getLHS()
{
	return LHS;
}
string VarAssign::getRHS()
{
	return RHS;
}

void VarAssign::PrintInfo(Output* pOut)
{
	string info=Text + " // " + Comment;
	pOut->PrintMessage(info);

}
void VarAssign::UpdateStatementText()
{
	

	if(LHS=="")	//No left handside ==>statement have no valid text yet
	{Text = "    = ";}
	
		

	
	
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T<<LHS<<" = "<<RHS;	
		Text = T.str();	 
	}
}

void VarAssign::Edit(Output*pOut,Input*pIn)
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
			{
			pOut->PrintMessage("Now Enter the new RHS");
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

			setRHS(s);
			break;
			}
		default: 
				pOut->PrintMessage("Wrong input");
				return;

		}
			UpdateStatementText();
			pOut->PrintMessage("Variable Statement Edited Successfully");

}


void VarAssign::Simulate(SimNode* x,int & NodeCount,Output*pOut,Input* pIn,int flag)		//efred el variable fel Vrbl aw el SnglOp mesh mawgood
{
	int index = search(x, getLHS(), NodeCount);
	if (index == -1)
	{
		x[NodeCount].name = getLHS();

		int temp = search(x, getRHS(), NodeCount);
		x[NodeCount].value = x[temp].value;
		
		NodeCount++;
	}
	else
	{
		
			int temp = search(x, getRHS(), NodeCount);
			x[index].value = x[temp].value;
	}
}

void VarAssign::Save(ofstream &OutFile)
{
	OutFile << "VarAssign\t" << getId() << "\t" << getStatCorner().x << "\t" << getStatCorner().y << "\t" << getLHS() 
			<< "\t" << getRHS() << "\t\"" << getComment() << "\"" << endl;
}

VarAssign * VarAssign::Load(ifstream & Infile,string text)
{
	string type, LHS ,RHS, comment;
	int id, x, y;
	type =text;
	Infile >> id >> x >> y >> LHS >> RHS;
	Point left(x, y);

		getline(Infile,comment);
		VarAssign * Var = new VarAssign(left, LHS, RHS);
		Var->setComment(comment);
		Var->setId(id);
		return Var;
}


void VarAssign::GenerateCode(ofstream &OutFile, SimNode * ss, int & count)
{
OutFile << getLHS() << "=" << getRHS() << ";\t\t" << (getComment() == "" ? "" : "//") << (getComment() == "" ? "" : getComment())<<endl;
}