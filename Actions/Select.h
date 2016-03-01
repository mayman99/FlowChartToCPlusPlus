#ifndef SELECT_H
#define SELECT_H
#pragma once
;
#include "Action.h"
#include"..\Statements\Statement.h"

;
class Select :public Action
	
{
	Point Position;	//Position where the user clicks to add the stat.
public:
	Select(ApplicationManager *);
	~Select();
	void ReadActionParameters();
	void Execute();
	virtual void ExecuteCopy(const Statement &);

};

#endif