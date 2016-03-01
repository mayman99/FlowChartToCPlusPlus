#ifndef MULTI_H
#define MULTI_H

#pragma once
#include "Action.h"
#include"..\Statements\Statement.h"

class MultiSelect :
	public Action
{
	Point Position;
public:
	MultiSelect(ApplicationManager *	);
	~MultiSelect();
	void ReadActionParameters();
	void Execute();
	void ExecuteCopy(const Statement & s);

};
#endif