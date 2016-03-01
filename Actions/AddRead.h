#ifndef ADD_READ_H
#define ADD_READ_H

#include "Action.h"
#include"..\Statements\Read.h"

class AddRead:public Action
{
private:
	Point Position;
public:
	AddRead(ApplicationManager *pAppManager);

	
	virtual void ReadActionParameters();
	
	//Create and add an assignemnt statement to the list of statements
	virtual void Execute() ;
	//void ExecuteCp(const Read & C);


};

#endif