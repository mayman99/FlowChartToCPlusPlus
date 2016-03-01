#ifndef WRITE_H
#define WRITE_H
#include"Statement.h"

class Write:public Statement
{
private:
	virtual void UpdateStatementText();
	string variable;
	double value;
public:

	Point LeftCorner;
	Write(Point corner,string s);
	virtual Point GetIn();
	virtual bool WithIn(Point p);
	string getVariable();
	void setVariable(string s);
	virtual void Draw(Output* pOut) const;
	virtual void setStatCorner(Point corner);
	virtual Point getStatCorner();
	//double GetValue();
	
	virtual void Edit(Output*,Input*);
	virtual Point GetOut();
	virtual void PrintInfo(Output* pOut);
	virtual void Simulate(SimNode *,int&,Output *,Input *,int );
	virtual Statement* getNextStatement();
	virtual void Save(ofstream &OutFile);
	virtual Write* Load(ifstream &Infile,string);
	virtual void GenerateCode(ofstream &OutFile, SimNode *, int &);
};
#endif