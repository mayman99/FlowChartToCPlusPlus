#ifndef MOVE_H
#define MOVE_H
#include<fstream>
#include "../GUI\UI_Info.h"
#include "../GUI\output.h"
#include"../Statements\Statement.h"
#include "Action.h"
#include"../ApplicationManager.h"

class Move :public Action
{
private:
	Statement*stat;
	Input *pIn;
	Output *pOut;
	Connector *cnnct;
public:
	Move(ApplicationManager *pAppManager) :Action(pAppManager)
	{}
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif