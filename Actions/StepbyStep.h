#ifndef STEP_BY_STEP_H
#define STEP_BY_STEP_H

#include "Action.h"
#include "..\Statements\Connector.h"
#include "..\Statements\Statement.h"



class StepByStep : public Action
{
private:
	Point Position;
	Statement * s;
	Statement * e;
	
public:
	SimNode* x;
	int count ;
	StepByStep(ApplicationManager *pAppManager) :Action(pAppManager)
	{}

	virtual void ReadActionParameters();

	virtual void Execute();

};
#endif