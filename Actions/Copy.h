#ifndef COPY_H
#define COPY_H
#pragma once

//#include"Action.h"
//#include"..\Statements\Statement.h"
//
//class Copy :
//	public Action
//{
//	
//	Point Position;
//public:
//	Copy(ApplicationManager*);
//	~Copy();
//	void ReadActionParameters();
//	void Execute();
//	void ExecuteCopy(const Statement &);
//};


#include"Action.h"
#include "..\Statements\Statement.h"
class Copy:public Action
{
private:
	Statement *Data;
public:
	Copy(ApplicationManager *pAppManager):Action(pAppManager)
	{}
	virtual void ReadActionParameters();
	virtual void Execute();
};



#endif