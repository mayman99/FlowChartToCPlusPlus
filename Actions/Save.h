#ifndef SAVE_H
#define SAVE_H
#include "Action.h"
#include<fstream>
using namespace std;
class Save:public Action
{
private:
	std::ofstream output;
public:
	Save(ApplicationManager *pAppManager):Action(pAppManager){}
	virtual void ReadActionParameters()
	{}
	virtual void Execute();

};
#endif