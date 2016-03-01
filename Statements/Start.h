#ifndef START_H
#define START_H
#include"Statement.h"

class Start:public Statement
{
private:
	virtual void UpdateStatementText();
public:

	Point Center;
	Start(Point p);
	virtual Point GetIn();
	virtual bool WithIn(Point p);
	virtual void Draw(Output* pOut) const;

	virtual void setStatCorner(Point corner);
	virtual Point getStatCorner();

	virtual Point GetOut();
	virtual void PrintInfo(Output* pOut);
	virtual void Edit(Output*,Input*);
	virtual void Simulate(SimNode *,int&,Output *,Input *,int );
	virtual Statement* getNextStatement();
	virtual void Save(ofstream &OutFile);
	virtual Statement * Load(ifstream &InFile,string);
	virtual void GenerateCode(ofstream &OutFile, SimNode *, int &);
};
#endif