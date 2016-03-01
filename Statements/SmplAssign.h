#ifndef SMPL_ASSIGN_H
#define SMPL_ASSIGN_H

#include"Statement.h"


//Simple Assignment statement class
//The simple assignment statement assigns a variable to a value
class SmplAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	double RHS;	//Right Handside (Value)
	
	/*Connector *pConn;*/	//Simple Assignment Stat. has one Connector to next statement

	//Point Inlet;	//A point where connections enters this statement 
	//Point Outlet;	//A point a connection leaves this statement

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();
	
public:
	SmplAssign(Point Lcorner, string LeftHS="", double RightHS=0);
	SmplAssign(Point Lcorner,const SmplAssign & s);
	virtual Point GetIn();
	virtual Point GetOut();
	//virtual void setConnector(Connector*ptr);
	//virtual Connector* getConnector();
	void setLHS(const string &L);
	void setRHS(double R);
	string getLHS();
	double getdoubleRHS();
	string getRHS();
	virtual void Draw(Output* pOut) const;
	virtual bool WithIn(Point p);
	virtual void setStatCorner(Point corner);
	virtual Point getStatCorner();
	virtual void PrintInfo(Output* pOut);
	virtual void Edit(Output*,Input*);
	virtual void Simulate(SimNode *,int&,Output *,Input *,int );
	virtual Statement* getNextStatement();
	virtual void Save(ofstream &OutFile);
	virtual SmplAssign * Load(ifstream &InFile,string);
	virtual void GenerateCode(ofstream &OutFile, SimNode *, int &);


};

#endif


