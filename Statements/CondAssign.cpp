#include"CondAssign.h"
#include"Statement.h"
#include<fstream>
#include"End.h"
CondAssign::CondAssign(Point Lcorner,string op, string LeftHS, string RightHS)
{
	LHS = LeftHS;
	RHS = RightHS;
	operation=op;

	UpdateStatementText();

	LeftCorner = Lcorner;
	StatCorner=Lcorner;
	pConn = NULL;	//No connectors yet
	Yes = NULL;
	No=NULL;
	Inlet.x = StatCorner.x + UI.COND_WDTH /2;
	Inlet.y = StatCorner.y - UI.COND_HI/2;

	Outlet.x = Inlet.x + UI.COND_WDTH /2;
	Outlet.y = StatCorner.y ;
	Outlet2.x = Inlet.x - UI.COND_WDTH /2;
	Outlet2.y = StatCorner.y;


}
void CondAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void CondAssign::setRHS(string &R)
{
	RHS = R;
	UpdateStatementText();
}
void CondAssign::setOP(string &op)
{
	operation = op;
	UpdateStatementText();
}
Point CondAssign::GetIn()
{
	return Inlet;
}

Point CondAssign::GetOut()
{
	return Outlet;
}
Point CondAssign::GetOut2()
{
	return Outlet2;
}



string CondAssign:: getLHS()
{
	return LHS;
}
string CondAssign:: getoperation()
	{
		return operation;
	}
string CondAssign:: getRHS()
	{
		return RHS;
	}

Statement* CondAssign ::getNextStatement()
{
	return TrueStatement;
}

void CondAssign::setYes(Connector*ptr)
{
	Yes=ptr;
}

Connector* CondAssign::GetYes()
{
		return Yes;
}


void CondAssign::setNo(Connector*ptr)
{
	No=ptr;
}

Connector* CondAssign::GetNo()
{
		return No;
}

 
void CondAssign::Draw(Output* pOut) const
{
	//Call Output::DrawCondition function to draw conditional statement 	
	pOut->DrawCondition(StatCorner, UI.COND_WDTH , UI.COND_HI , Text , Selected);
	
	
}

void CondAssign::PrintInfo(Output* pOut)
{
	string info=Text + " // " + Comment;
	pOut->PrintMessage(info);

}

bool CondAssign::WithIn(Point p)
{
	bool x=false;
	bool y=false;
	bool z=false;
	if(   StatCorner.x<=p.x && StatCorner.x+UI.COND_WDTH>=p.x  )
	{
		x=true;
	}

	if  (   (StatCorner.y-(UI.COND_HI/2))<=p.y && (StatCorner.y+(UI.COND_HI/2))>=p.y )
	{
		y=true;
	}

	if (x==true && y==true )
	{
		z=true;
	}
	return z;
}

void CondAssign::UpdateStatementText()
{
	
	

	if(LHS=="")	//No left handside ==>statement have no valid text yet
	{Text = "    = ";
	
	
	}
	
	
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T<<LHS<<operation<<RHS;	
		Text = T.str();	 
	}
}

void CondAssign::setStatCorner(Point corner)
{
	StatCorner=corner;
	Inlet.x = StatCorner.x + UI.COND_WDTH /2;
	Inlet.y = StatCorner.y - UI.COND_HI/2;

	Outlet.x = Inlet.x - UI.COND_WDTH /2;
	Outlet.y = StatCorner.y ;
	Outlet2.x = Inlet.x + UI.COND_WDTH /2;
	Outlet2.y = StatCorner.y;
}

Point CondAssign::getStatCorner()
{

	return StatCorner;
}

bool CondAssign:: valid(string s)
{
	bool x;

	if (s.compare("!=")==0)
	{
		x=true;
		return x; 
	}

	if (s.compare("==")==0)
	{
		x=true;
		return x; 
	}
	if (s.compare("<")==0)
	{
		x=true;
		return x; 
	}
	if (s.compare(">")==0)
	{
		x=true;
		return x; 
	}
	if (s.compare("<=")==0)
	{
		x=true;
		return x; 
	}
	if (s.compare(">=")==0)
	{
		x=true;
		return x; 
	}
	else 
	{
		return false;
	}

}

void CondAssign::Edit(Output*pOut,Input*pIn)
{
	pOut->PrintMessage(" Enter (1) to change Left handside or (2) to change first Right handside or (3) to change the operator or ");
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
			s=pIn->GetString(pOut);
			setRHS(s);
			break;
		
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
			setOP(s);
			break;
			}
			default: 
				pOut->PrintMessage("Wrong input");
				return;
		}
			UpdateStatementText();
			pOut->PrintMessage("Conditional Statement Edited Successfully");

}


void CondAssign::Simulate(SimNode* x,int & NodeCount,Output*pOut,Input* pIn,int flag)		//efred el variable fel Vrbl aw el SnglOp mesh mawgood
{
	int index = search(x, getLHS(), NodeCount);
	 
	
		x[NodeCount].name = getLHS();
		double operand;
		string s1;
		 s1=getRHS();
			double d1;
			bool z1=false; 
			stringstream convert(s1);
			convert>>d1;
			z1=convert.fail();
				 //////////////////////	
		if (z1==true)
			{
				int temp1 = search(x, s1, NodeCount);
				operand = x[temp1].value;
				x[NodeCount].value=x[temp1].value;
			}

		if (z1==false )
			{
				operand = d1;
				x[NodeCount].value=d1;
			}

		//////////////////////////////////////////////////////////
			
	if (getoperation() == "==")
	{
		if (x[index].value == operand)
			TrueStatement = GetYes()->getDstStat();
		else

			TrueStatement =GetNo()->getDstStat();
	}
	if (getoperation() == "!=")
	{
		if (x[index].value != operand)
			TrueStatement = GetYes()->getDstStat();
		else

			TrueStatement =GetNo()->getDstStat();
	}
	if (getoperation() == "<")
	{
		if (x[index].value < operand)
			TrueStatement = GetYes()->getDstStat();
		else

			TrueStatement =GetNo()->getDstStat();
	}
	if (getoperation() == "<=")
	{
		if (x[index].value <= operand)
			TrueStatement = GetYes()->getDstStat();
		else

			TrueStatement =GetNo()->getDstStat();
	}
	if (getoperation() == ">")
	{
		if (x[index].value > operand)
			TrueStatement = GetYes()->getDstStat();
		else
			TrueStatement =GetNo()->getDstStat();
	}
	if (getoperation() == ">=")
		{
		if (x[index].value >= operand)
			TrueStatement = GetYes()->getDstStat();
		else

			TrueStatement =GetNo()->getDstStat();
	}
}

Statement * CondAssign::getDstStatement()
{
	Statement * Ystat = GetYes()->getDstStat();
	End* e=dynamic_cast<End*>(Ystat);
	while (e==NULL)
	{
		
		Statement * Nstat = GetNo()->getDstStat();
		End* e2=dynamic_cast<End*>(Nstat);
		while (Ystat != Nstat && e2==NULL)
		{
			Nstat = Nstat->getNextStatement();
			e2=dynamic_cast<End*>(Nstat);
		}
		if (Ystat == Nstat)
			return Ystat;
		Ystat = Ystat->getNextStatement();
		e=dynamic_cast<End*>(Ystat);
	}
	return Ystat;
}

void CondAssign::Save(ofstream &OutFile)
{

string op;
	if (getoperation() == "<")		op = "LES";
	if (getoperation() == ">")		op = "GRT";
	if (getoperation() == "<=")		op = "LES/EQL";
	if (getoperation() == "<=")		op = "GRT/EQL";
	if (getoperation() == "==")		op = "EQL";
	if (getoperation() == "!=")		op = "NOTEQL";


	
	
		OutFile << "CondAssign\t" << getId() << "\t" << getStatCorner().x << "\t" << getStatCorner().y << "\t" << getLHS() << "\t"
			<< op << "\t" << getRHS() << "\t\"" << getComment() << "\"" << endl;
		
}

CondAssign* CondAssign::Load(ifstream &Infile,string text)
{
	string type, LHS, RHS, operation, comment,Operator;
	int id, x, y;
	type =text;
	Infile >> id >> x >> y >> LHS >> operation >>RHS ;
	Point left(x, y);

	
		getline(Infile,comment);

	
	
		if (operation == "GRT")			Operator = ">";
		if (operation == "LES")			Operator = "<";
		if (operation == "LES/EQL")		Operator = "<=";
		if (operation == "GRT/EQL")		Operator = ">=";
		if (operation == "EQL")			Operator = "==";
		if (operation == "NOTEQL")		Operator = "!=";

		CondAssign * cond = new CondAssign(left, Operator, LHS, RHS);
		cond->setComment(comment);
		cond->setId(id);
		return cond;
	
}

void CondAssign::GenerateCode(ofstream &OutFile, SimNode* ss, int & count)
{
	if (GetYes()->getEndPoint().y < GetYes()->getStartPoint().y)
	{
		OutFile << "while(" << getLHS() << getoperation() << getRHS() << ")\t\t" << (getComment() == "" ? "" : "//")
			<< (getComment() == "" ? "" : getComment()) << "\n{\n";
		Statement *Ystatement = GetYes()->getDstStat();
		while (Ystatement != this)
		{
			Ystatement->GenerateCode(OutFile,ss,count);
			Ystatement->getNextStatement();
		}
	}

	if (GetNo()->getEndPoint().y < GetNo()->getStartPoint().y)
	{
		OutFile << "while(!(" << getLHS() << getoperation() << getRHS() << ")\t\t" << (getComment() == "" ? "" : "//")
			<< (getComment() == "" ? "" : getComment()) << "\n{\n";
		Statement *Nstatement = GetNo()->getDstStat();
		while (Nstatement != this)
		{
			Nstatement->GenerateCode(OutFile, ss, count);
			Nstatement->getNextStatement();
		}
	}
	else
	{
		OutFile << "if (" << getLHS() << getoperation() << getRHS() << ")\t\t" << (getComment() == "" ? "" : "//")
			<< (getComment() == "" ? "" : getComment()) << "\n{\n";
		Statement *Ystatement = GetYes()->getDstStat();
		Statement *Nstatement = GetNo()->getDstStat();
		while (Ystatement != getDstStatement())
		{
			if(dynamic_cast<CondAssign*>(Ystatement)!=NULL)
			{
				Ystatement->GenerateCode(OutFile,ss,count);
				Ystatement=dynamic_cast<CondAssign*>(Ystatement)->getDstStatement();
			}
			else
			{
			Ystatement->GenerateCode(OutFile,ss,count);
			Ystatement = Ystatement->getNextStatement();
			}
		}
		OutFile << "\n}\nelse\n{\n";
		while (Nstatement != getDstStatement())
		{
			if(dynamic_cast<CondAssign*>(Nstatement)!=NULL)
			{
				Nstatement->GenerateCode(OutFile,ss,count);
				Nstatement=dynamic_cast<CondAssign*>(Nstatement)->getDstStatement();
			}
			else
			{
			Nstatement->GenerateCode(OutFile, ss, count);
			Nstatement = Nstatement->getNextStatement();
			}
		}
		OutFile << "\n}\n";
	}

}
