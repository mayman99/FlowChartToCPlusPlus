#ifndef EDIT_STATMENT_H
#define EDIT_STATMENT_H

#include "Action.h"

class Edit : public Action
{
private:
	Point Position;	
public:
	Edit(ApplicationManager *pAppManager);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
};

#endif