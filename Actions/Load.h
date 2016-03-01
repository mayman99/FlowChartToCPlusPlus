#ifndef LOAD_H
#define LOAD_H
#include<fstream>
#include "../GUI\UI_Info.h"
#include "../GUI\output.h"
#include "Action.h"
using namespace std;

class Load:public Action
{
private:
	std::ifstream input;
public:
	Load(ApplicationManager *pAppManager):Action(pAppManager)
	{}
	virtual void ReadActionParameters()
	{}
	virtual void Execute();
};

#endif