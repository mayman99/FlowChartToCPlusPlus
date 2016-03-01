#ifndef VAR_ASSIGN_H
#define VAR_ASSIGN_H

#include"Statement.h"
class VarAssign:public Statement
{


	private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string RHS;	//Right Handside (Value)
	
	/*Connector *pConn;*/	//Simple Assignment Stat. has one Connector to next statement

	//Point Inlet;	//A point where connections enters this statement 
	//Point Outlet;	//A point a connection leaves this statement

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

	
public:
	VarAssign(Point Lcorner, string LeftHS="", string RightHS="");
	VarAssign(Point Lcorner,const VarAssign & s);
	void setLHS(const string &L);
	void setRHS(string &R);
	string getLHS();
	string getRHS();
	virtual Point GetIn();
	virtual Point GetOut();
	//virtual void setConnector(Connector*ptr);
	//virtual Connector* getConnector();
	virtual void Draw(Output* pOut) const;
	virtual bool WithIn(Point p);
	virtual void setStatCorner(Point corner);
	virtual Point getStatCorner();
	virtual void PrintInfo(Output* pOut);
	virtual void Edit(Output*,Input*);
	virtual void Simulate(SimNode *,int&,Output *,Input *,int );
	virtual Statement* getNextStatement();
	virtual void Save(ofstream &OutFile);
	virtual VarAssign * Load(ifstream &InFile,string);
	virtual void GenerateCode(ofstream &OutFile, SimNode *, int &);

};

#endif