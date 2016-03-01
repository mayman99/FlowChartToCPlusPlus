#ifndef ADD_START_H
#define ADD_START_H

#include "Action.h"
#include"..\Statements\Start.h"

class AddStart:public Action
{
private:
	Point Position;
public:
	AddStart(ApplicationManager *pAppManager);

	
	virtual void ReadActionParameters();
	
	//Create and add an assignemnt statement to the list of statements
	virtual void Execute() ;
	void ExecuteCp(const Start & C);


};

#endif