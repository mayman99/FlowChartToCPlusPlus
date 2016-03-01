#ifndef CHARTVALIDATION_H
#define CHARTVALIDATION_H
#include"Action.h"
#include "..\Statements\Statement.h"
class ChartValidation :public Action
{
private:
	Output* pOut;
	Input* pIn;
	int ccount, scount;
public:
	ChartValidation(ApplicationManager *pAppManager) :Action(pAppManager)
	{}
	virtual void ReadActionParameters();
	virtual void Execute();
	int x;
};


#endif