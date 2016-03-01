#ifndef GENERATECODE_H
#define GENERATECODE_H

#include "Action.h"
#include "..\Statements\Connector.h"
#include "..\Statements\Statement.h"

#include<fstream>

class GenerateCode : public Action
{
private:

	Statement * s,*temp;
public:
	SimNode* x;
	int count;
	ofstream outfile;

	GenerateCode(ApplicationManager *pAppManager) :Action(pAppManager)
	{}

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif