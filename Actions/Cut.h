#ifndef CUT_H
#define CUT_H
#pragma once
#include"Action.h"
#include"..\Statements\Statement.h"

class Cut :
	public Action
{
	Statement* stat;
	Connector* in;
	Connector* out;

public:
	Cut(ApplicationManager*);
	~Cut();
	void ReadActionParameters();
	void Execute();
    void ExecuteCopy(const Statement &);
};

#endif