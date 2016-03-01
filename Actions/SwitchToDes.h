#ifndef SWITCH_TO_DES_H
#define SWITCH_TO_DES_H

#include "Action.h"

class SwitchToDes : public Action
{
	Point p;
public:
	SwitchToDes(ApplicationManager *pAppManager);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
};

#endif