#ifndef ADD_CONNECTOR_H
#define ADD_CONNECTOR_H
#include"Action.h"
#include"../Statements/Connector.h"
class AddConn:public Action
{
private:
	Point first;
	Point second;
public:
		AddConn(ApplicationManager *pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();
	
	//Create and add an assignemnt statement to the list of statements
	virtual void Execute() ;

}


#endif