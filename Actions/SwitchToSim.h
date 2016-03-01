#ifndef SWITCH_TO_SIM_H
#define SWITCH_TO_SIM_H

#include "Action.h"

class SwitchToSim : public Action
{
Point p;
public:
	SwitchToSim(ApplicationManager *pAppManager);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
};

#endif