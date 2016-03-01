#ifndef DEL_H
#define DEL_H
#pragma once
#include"Action.h"
#include"..\Statements\Statement.h"

#include <sstream>
class Delete :
	public Action
{
	Statement *stat;
	Connector *incnnct;
	Connector *outcnnct;
public:
	Delete(ApplicationManager*);
	~Delete();
	void ReadActionParameters();
	virtual void ExecuteCopy(const Statement &);

	void Execute();
};
#endif
