#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"

#include "Statements\Statement.h"
;
class Input;
class Output;


//Main class that manages everything in the application.
class ApplicationManager
{

	friend class Run;
	friend class StepByStep;
	friend class Save;
	friend class Load;

	enum { MaxCount = 200 };	//Max no of statements/connectors in a single flowchart

private:
	int StatCount;		//Actual number of statements
	int ConnCount;		//Actual number of connectors
	Statement* StatList[MaxCount];	//List of all statements (Array of pointers)
	Connector* ConnList[MaxCount];	//List of all connectors (Array of pointers)
	
	Statement *pSelectedStat; //a pointer to the last selected statement
	Statement* AllSelectedStatments[MaxCount];
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	Statement *Copied;
	Statement*MultiCopied[200];
	bool MultiCopy;

public:	
	SimNode*NodesArray;
	int NodeCount;
	ApplicationManager(); 
	~ApplicationManager();
	int startCount,endCount;
	// -- Actions Related Functions
	//Reads the input command from the user and returns the corresponding action type

	Statement** GetAllSelectedStatements();  


	ActionType GetUserAction() const;
    bool search_stat (Statement*first);
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void AddStatement(Statement* pStat); //Adds a new Statement to the Flowchart
	Statement *GetStatement(Point P) const;	//search for a statement where point P belongs
	void DeleteStatement(Statement*);
	void deleteConnector(Connector*x);
	void AddConnector(Connector* pConn); //Adds a new Connector to the Flowchart
	Connector *GetConnector(Point P) const;	//search for a Connector where point P belongs
	void updateConnectors();
	void DeleteStatConnectors(Statement*stat);
	bool Search_Conn(Statement* s2);
	int getCcount ();
	int getScount ();
	Statement *GetSelectedStatement() const;	//Returns the selected Statement
	void SetSelectedStatement(Statement *pStat); //Set the Statement selected by the user
	void UnselectAllstat();
	void setCopyCondition(bool z);
	void SetCopied(Statement*,string str="");
	Statement* getCopied();
	void SetMultiCopied(Statement*,int i,string str="");
	Statement*getMultiCopied(int i);
	int numSelected();
	int numCopied();
	Statement*SearchId(int x);
	;
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	bool getCopyCondition();
;
    int getStatType(Statement*);
};

#endif