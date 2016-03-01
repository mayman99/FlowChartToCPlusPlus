#ifndef PASTE_H
#define PASTE_H
#include"Action.h"
#include "..\Statements\Statement.h"


class Paste:public Action
{
private:
	Point P;
	Statement * stat;

public:
	Paste(ApplicationManager *pAppManager):Action(pAppManager)
	{}
	virtual void ReadActionParameters();
	virtual void Execute();
};


#endif