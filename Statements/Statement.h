#ifndef STATEMENT_H
#define STATEMENT_H

#include "..\defs.h"

#include "Connector.h"
//class Output;
#include "..\GUI\Output.h"
;
//Base class for all Statements
struct SimNode;
class Statement
{

protected:
	//static int LocalID;			
	int ID;           //Each Statement has an ID
	string Text;	//Statement text (e.g.  "X = 5" OR "if(salary > 3000)" and so on )
	bool Selected;	//true if the statement is selected on the folwchart
	string Comment;
	Point Inlet;	//A point where connections enters this statement 
	Point Outlet;
	Point StatCorner;
	Connector* pConn;

	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:
	Statement();
	void setId(int);
	int getId();
	void SetSelected(bool s);
	bool IsSelected() const;
    void setConnector(Connector*ptr);
	Connector* getConnector();
	virtual Statement* getNextStatement()=0;
	virtual void Draw(Output* pOut) const  = 0 ;	//Draw the statement
	virtual void setComment(string s);
	virtual string getComment();
	virtual Point GetIn()=0;
	virtual Point GetOut()=0;
	virtual void setStatCorner(Point corner)=0;
	virtual Point getStatCorner()=0;
	int search(SimNode * x, string y, int NodeCount);
	virtual void Simulate(SimNode *,int&,Output *,Input *,int ) =0;


	///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type	

	virtual bool WithIn(Point p)=0;
	virtual void Save(ofstream &OutFile) = 0;	//Save the Statement parameters to a file
	virtual Statement* Load(ifstream &Infile,string) = 0;	//Load the Statement parameters from a file
	virtual void GenerateCode(ofstream &OutFile, SimNode *, int &) = 0;

	
	virtual void Edit(Output*,Input*) = 0;		//Edit the Statement parameter

	
	


	virtual void PrintInfo(Output* pOut) = 0;	//print all Statement info on the status bar
	

};
 
struct SimNode
{
	string name;
	double value;
};

#endif



////////////////////////////////////////////////////////
