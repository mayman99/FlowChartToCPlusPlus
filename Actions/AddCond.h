#ifndef ADD_COND_ASSIGN_H
#define ADD_COND_ASSIGN_H

#include "Action.h"
#include"..\Statements\CondAssign.h"

//This class is responsible for 
// 1 - Getting Assignment stat. coordinates from the user
// 2 - Creating an object of Assignment class and fill it parameters
// 3 - Adding the created object to the list of statements
class AddCond : public Action
{
	
private:
	Point Position;	//Position where the user clicks to add the stat.
public:
	AddCond(ApplicationManager *pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();
	
	//Create and add an assignemnt statement to the list of statements
	virtual void Execute() ;
	bool valid(string s);
};




#endif