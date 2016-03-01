#ifndef ADD_WRITE_H
#define ADD_WRITE_H

#include "Action.h"
#include"..\Statements\Write.h"

class AddWrite:public Action
{
private:
	Point Position;
public:
	AddWrite(ApplicationManager *pAppManager);

	
	virtual void ReadActionParameters();
	
	//Create and add an assignemnt statement to the list of statements
	virtual void Execute() ;
	//void ExecuteCp(const WRITE & C);


};

#endif