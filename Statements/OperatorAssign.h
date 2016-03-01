#ifndef OPERATOR_ASSIGN_H
#define OPERATOR_ASSIGN_H

#include"Statement.h"
class OperatorAssign:public Statement
{


	private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string operation;
	string RHS;	//Right Handside (Value)
	string RHS2;
	
	
	/*Connector *pConn;*/	//Simple Assignment Stat. has one Connector to next statement

	//Point Inlet;	//A point where connections enters this statement 
	//Point Outlet;	//A point a connection leaves this statement

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();
	
public:
	OperatorAssign(Point Lcorner, string LeftHS, string op, string RightHS, string RightHS2="" );
	
	void setLHS(const string &L);
	void setoperation(string &op);
	void setRHS(string &R);
	void setRHS2(string &R);
	string getLHS();
	string getoperation();
	string getRHS();
	string getRHS2();
	virtual Point GetIn();
	virtual Point GetOut();
	//virtual void setConnector(Connector*ptr);
	//virtual Connector* getConnector();
	bool valid(string s);
	virtual void Draw(Output* pOut) const;
	virtual bool WithIn(Point p);
	virtual void setStatCorner(Point corner);
	virtual Point getStatCorner();
	virtual void PrintInfo(Output* pOut);
	virtual void Edit(Output*,Input*);
	virtual void Simulate(SimNode *,int&,Output *,Input *,int );
	virtual Statement* getNextStatement();
	virtual void Save(ofstream &OutFile);
	virtual OperatorAssign * Load(ifstream &InFile,string);
	virtual void GenerateCode(ofstream &OutFile, SimNode *, int &);
	

};

#endif