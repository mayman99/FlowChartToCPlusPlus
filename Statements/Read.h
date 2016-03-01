#ifndef READ_H
#define READ_H
#include"Statement.h"
#include"../GUI/Input.h"
#include"../ApplicationManager.h"
class Read:public Statement
{
private:
	virtual void UpdateStatementText();
	string variable;
	double value;
public:

	Point LeftCorner;
	Read(Point corner,string s);
	string getVariable();
	virtual Point GetIn();
	virtual bool WithIn(Point p);
	virtual void Draw(Output* pOut) const;
	//double GetValue();
	virtual void setStatCorner(Point corner);
	virtual Point getStatCorner();
	void setVariable(string s);
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