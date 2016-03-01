#ifndef COND_ASSIGN_H
#define COND_ASSIGN_H
#include"Statement.h"

class CondAssign:public Statement
{


	private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string operation;
	string RHS;	//Right Handside (Value)
	Statement* TrueStatement;
	Connector* Yes;
	Connector* No;
	//Connector *pConn2;	//cond Assignment Stat. has two Connectors to next statement

	//Point Inlet;	//A point where connections enters this statement 
	//Point Outlet1,Outlet2;	// points a connection leaves this statement
	Point Outlet2;
	Point LeftCorner;	//left corenr of the statement block.
	
	virtual void UpdateStatementText();
	
public:
	CondAssign(Point Lcorner,string op, string LeftHS="", string RightHS="");
	
	void setLHS(const string &L);
	void setRHS(string &R);
	void setOP(string &op);
	string getLHS();
	string getRHS();
	string getoperation();
	virtual Point GetIn();
	virtual Point GetOut();
	Point GetOut2();
	 virtual void setStatCorner(Point corner);
	virtual Point getStatCorner();
	Connector* GetYes();
	Connector* GetNo();
	//virtual void setConnector(Connector*ptr);
    void setYes(Connector*ptr);
    void setNo(Connector*ptr);
    virtual void PrintInfo(Output* pOut);
	virtual void Draw(Output* pOut) const;
	virtual bool WithIn(Point p);
	virtual void Edit(Output*pOut,Input*pIn);
	bool valid(string s);
	virtual void Simulate(SimNode *,int&,Output *,Input *,int );
	virtual Statement* getNextStatement();
	virtual void Save(ofstream &OutFile);
   
	
};
	
#endif