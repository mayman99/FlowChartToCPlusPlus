#ifndef COMMENT_H
#define COMMENT_H

#include "Action.h"

class Comment : public Action
{
private:
	Point Position;
	string com;
public:
	Comment(ApplicationManager *pAppManager);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
};

#endif