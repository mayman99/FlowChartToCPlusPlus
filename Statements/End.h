#ifndef END_H
#define END_H
#include"Statement.h"

class End:public Statement
{
private:
	virtual void UpdateStatementText();
public:

	Point Center;
	End(Point p);
	virtual Point GetIn();
	virtual bool WithIn(Point p);
	virtual void Draw(Output* pOut) const;
	virtual Statement* getNextStatement();
	virtual void setStatCorner(Point corner);
	virtual Point getStatCorner();
	virtual void PrintInfo(Output* pOut);
	virtual Point GetOut();
	virtual void Edit(Output*,Input*);
	virtual void Simulate(SimNode *,int&,Output *,Input *,int );
	virtual void Save(ofstream &OutFile);
	virtual Statement * Load(ifstream &InFile,string);
	virtual void GenerateCode(ofstream &OutFile, SimNode *, int &);

};
#endif