#include"OperatorAssign.h"
#include<fstream>
OperatorAssign::OperatorAssign(Point Lcorner, string LeftHS, string op, string RightHS, string RightHS2 )
{
	LHS = LeftHS;
	RHS = RightHS;
	operation=op;
	RHS2=RightHS2;
	

	UpdateStatementText();

	LeftCorner = Lcorner;
	StatCorner=Lcorner;
	pConn = NULL;	//No connectors yet

	Inlet.x = StatCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = StatCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = StatCorner.y + UI.ASSGN_HI;

}
void OperatorAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void OperatorAssign::setoperation(string &op)
{
	operation = op;
	UpdateStatementText();
}

void OperatorAssign::setRHS(string &R)
{
	RHS = R;
	UpdateStatementText();
}
void OperatorAssign::setRHS2(string &R)
{
	RHS2 = R;
	UpdateStatementText();
}

Statement* OperatorAssign ::getNextStatement()
{
	return getConnector()->getDstStat();
}

string OperatorAssign:: getLHS()
{
	return LHS;
}
string OperatorAssign:: getoperation()
	{
		return operation;
	}
string OperatorAssign:: getRHS()
	{
		return RHS;
	}
string OperatorAssign::getRHS2()
	{
		return RHS2;
	}
Point OperatorAssign::GetIn()
{
	return Inlet;
}
Point OperatorAssign::GetOut()
{
	return Outlet;
}
//void OperatorAssign::setConnector(Connector*ptr)
//{
//	pConn=ptr;
//}

 /*Connector* OperatorAssign::getConnector()
 {
	 return pConn;
 }*/

void OperatorAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(StatCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}

void OperatorAssign::PrintInfo(Output* pOut)
{
	string info=Text + " // " + Comment;
	pOut->PrintMessage(info);

}

bool OperatorAssign::WithIn(Point p)
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


void OperatorAssign::setStatCorner(Point corner)
{
	StatCorner=corner;
	Inlet.x = StatCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = StatCorner.y;
	Outlet.x = Inlet.x;
	Outlet.y = StatCorner.y + UI.ASSGN_HI;
}

Point OperatorAssign::getStatCorner()
{

	return StatCorner;
}

void OperatorAssign::UpdateStatementText()
{
	double x,y;

	

	if(LHS=="")	//No left handside ==>statement have no valid text yet
	{Text = "    = ";}
	
		

	else
	{
		
		ostringstream T;
		T<<LHS<<" = "<<RHS<<operation<<RHS2;	
		Text = T.str();	 
	}
}

bool OperatorAssign::valid(string s)
{
	bool x;

	if (s.compare("+")==0)
	{
		x=true;
		return x; 
	}

	if (s.compare("-")==0)
	{
		x=true;
		return x; 
	}
	if (s.compare("*")==0)
	{
		x=true;
		return x; 
	}
	if (s.compare("/")==0)
	{
		x=true;
		return x; 
	}
	
	else 
	{
		return false;
	}

}

void OperatorAssign::Edit(Output*pOut,Input*pIn)
{
	pOut->PrintMessage(" Enter (1) to change Left handside or (2) to change first Right handside or (3) to change the operator or (4) to change the seocnd right handside  ");
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
		case 3:
			{
			pOut->PrintMessage("Now Enter the new operation");
			s=pIn->GetString(pOut);
			bool z=valid(s);
			while (z==false)
			{
			pOut->PrintMessage("Please Enter a valid operation");
			s=pIn->GetString(pOut);
			z=valid(s);
			}
			setoperation(s);
			break;
			}
			case 4:
			pOut->PrintMessage("Now Enter the new RHS2 ");
			s=pIn->GetString(pOut);
			setRHS2(s);
			break;

			default: 
				pOut->PrintMessage("Wrong input");
				return;
		}
			UpdateStatementText();
			pOut->PrintMessage("Single Operator Statement Edited Successfully");

}

void OperatorAssign::Simulate(SimNode* x,int & NodeCount,Output*pOut,Input* pIn,int flag)		//efred el variable fel Vrbl aw el SnglOp mesh mawgood
{
	int index = search(x, getLHS(), NodeCount);
	if (index == -1)
	{
		x[NodeCount].name = getLHS();
		double operand_1, operand_2;
		string s1,s2;
		s1=getRHS();
		s2=getRHS2();

			double d1,d2;
			bool z1=false; 
			bool z2=false;
			stringstream convert(s1);
			convert>>d1;
			z1=convert.fail();
				 //////////////////////
			stringstream convert2(s2);
			convert2>>d2;
			z2=convert2.fail();	

		if (z1==true && z2==true)
			{
				int temp1 = search(x, s1, NodeCount);
				operand_1 = x[temp1].value;
				int temp2 = search(x, s2, NodeCount);
				operand_2 = x[temp2].value;
			}

		if (z1==false && z2==false)
			{
				operand_1 = d1;
				operand_2 = d2;
			}

		if (z1==false && z2==true)
			{
				operand_1 = d1;
				int temp2 = search(x, s2, NodeCount);
				operand_2 = x[temp2].value;
			}

		if (z1==true && z2==false)
			{
				int temp1 = search(x, s1, NodeCount);
				operand_1 = x[temp1].value;
				operand_2 = d2;
			}
		//////////////////////////////////////////////////////////
			if (getoperation() == "+")
			{
				x[NodeCount].value = operand_1 + operand_2;
			}
			if (getoperation() == "-")
			{
				x[NodeCount].value = operand_1 - operand_2;
			}
			if (getoperation() == "/")
			{
				x[NodeCount].value = operand_1 / operand_2;
			}
			if (getoperation() == "*")
			{
				x[NodeCount].value = operand_1 * operand_2;
			}

		NodeCount++;
	}

	else
	{

		double operand_1, operand_2;
		string s1,s2;
		s1=getRHS();
		s2=getRHS2();

			double d1,d2;
			bool z1=false; 
			bool z2=false;
			stringstream convert(s1);
			convert>>d1;
			z1=convert.fail();
				 //////////////////////
			stringstream convert2(s2);
			convert2>>d2;
			z2=convert2.fail();	

		if (z1==true && z2==true)
			{
				int temp1 = search(x, s1, NodeCount);
				operand_1 = x[temp1].value;
				int temp2 = search(x, s2, NodeCount);
				operand_2 = x[temp2].value;
			}

		if (z1==false && z2==false)
			{
				operand_1 = d1;
				operand_2 = d2;
			}

		if (z1==false && z2==true)
			{
				operand_1 = d1;
				int temp2 = search(x, s2, NodeCount);
				operand_2 = x[temp2].value;
			}

		if (z1==true && z2==false)
			{
				int temp1 = search(x, s1, NodeCount);
				operand_1 = x[temp1].value;
				operand_2 = d2;
			}
		//////////////////////////////////////////////////////////


		if (getoperation() == "+")
			{
				x[index].value = operand_1 + operand_2;
			}
			if (getoperation() == "-")
			{
				x[index].value = operand_1 - operand_2;
			}
			if (getoperation() == "/")
			{
				x[index].value = operand_1 / operand_2;
			}
			if (getoperation() == "*")
			{
				x[index].value = operand_1 * operand_2;
			}


	}

}

void OperatorAssign::Save(ofstream &OutFile)
{
	string op;
		if (getoperation() == "+")	op = "PLS";
		if (getoperation() == "-")	op = "MNS";
		if (getoperation() == "*")	op = "MUL";
		if (getoperation() == "/")	op = "DIV";

		OutFile << "OperatorAssign\t" << getId() << "\t" << getStatCorner().x << "\t" << getStatCorner().y << "\t" << getLHS() << "\t" 
			<< getRHS() << "\t" << op << "\t" << getRHS2() << "\t\"" << getComment() << "\"" << endl;
}

OperatorAssign* OperatorAssign::Load(ifstream &Infile,string text)
{
	string type, LHS, RHS, operation, RHS2, comment,Operator;
	int id, x, y;
	type =text;
	Infile >> id >> x >> y >> LHS >> RHS >> operation >>RHS2 ;
	Point left(x, y);

	
		getline(Infile,comment);
		if (operation == "MUL")	Operator = "*";
		if (operation == "PLS")	Operator = "+";
		if (operation == "MNS")	Operator = "-";
		if (operation == "DIV")	Operator = "/";
		OperatorAssign * OpAssign = new OperatorAssign(left, LHS, Operator, RHS, RHS2);
		OpAssign->setComment(comment);
		OpAssign->setId(id);
		return OpAssign;
}

void OperatorAssign::GenerateCode(ofstream &OutFile, SimNode * ss, int & count)
{
OutFile << getLHS() << "=" << getRHS() << getoperation () << getRHS2() << ";\t\t" << (getComment() == "" ? "" : "//") << (getComment() == "" ? "" : getComment())<<endl;
}


	