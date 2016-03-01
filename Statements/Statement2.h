#ifndef STATEMENT2_H
#define STATEMENT2_H

#include "..\defs.h"

#include "Connector.h"
//class Output;
#include "..\GUI\Output.h"
;
//Base class for all Statements
class Statement
{
protected:
	static int LocalID;			
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
	virtual void Draw(Output* pOut) const  = 0 ;	//Draw the statement
	virtual void setComment(string s);
	virtual string getComment();
	virtual Point GetIn()=0;
	virtual Point GetOut()=0;
	virtual void setStatCorner(Point corner)=0;

	virtual Point getStatCorner()=0;

	///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type	

	virtual bool WithIn(Point p)=0;
	//virtual void Save(ofstream &OutFile) = 0;	//Save the Statement parameters to a file
	//virtual void Load(ifstream &Infile) = 0;	//Load the Statement parameters from a file


	//virtual void Move() = 0;		//Move the Statement on the flowchart
	//virtual void Edit() = 0;		//Edit the Statement parameter

	//virtual void GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file
	//virtual void Simulate();	//Execute the statement in the simulation mode


	virtual void PrintInfo(Output* pOut) = 0;	//print all Statement info on the status bar
	
	///TODO: Add more functions if needed
};
 
#endif

////////////////////////////////////////////////////////
