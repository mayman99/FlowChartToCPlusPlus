#ifndef RUN_H
#define RUN_H

#include "Action.h"
#include "..\Statements\Connector.h"
#include "..\Statements\Statement.h"
#include"ChartValidation.h"



class Run : public Action
{
private:
	Point Position;
	Statement * s;
	Statement * e;
	ChartValidation *h;
	
public:
	SimNode* x;
	int count ;
	Run(ApplicationManager *pAppManager) :Action(pAppManager)
	{}

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif