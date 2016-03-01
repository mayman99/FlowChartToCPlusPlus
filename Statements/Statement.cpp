#include "Statement.h"

//int Statement::LocalID=0;
Statement::Statement()	
{ 
	//LocalID++;
	//ID=LocalID;
	Text = "";
	Selected = false;
	pConn=NULL;
	Connector*t;

}


void Statement::setId(int id)
{ ID = id; }

int Statement :: getId()
{
	return ID;
}


void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }
 void Statement::setConnector(Connector*ptr)
 {
	 pConn=ptr;
 }
Connector* Statement::getConnector()
{
	return pConn;
}
void Statement::setComment(string s)
{
	Comment=s;
}
string Statement::getComment()
{
	return Comment;
}
int Statement :: search(SimNode * x, string y, int NodeCount)
{
	for (int i = 0; i < NodeCount; i++)
	{
		if (x[i].name == y)
			return i;
	}
	return -1;
}
