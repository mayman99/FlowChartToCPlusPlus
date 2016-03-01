#ifndef OUPTUT_H
#define OUPTUT_H

#include "Input.h"
#include<sstream>
class Output	//The application manager should have a pointer to this class
{
	friend class Move;
	friend class Run;
	friend class StepByStep;
	friend class ApplicationManager;
	
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	
	Output();	

	window* CreateWind(int, int, int , int);
	void ClearToolBar();
	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar();//Tool bar of the simulation mode
	void CreateStatusBar();
	void Dragging(Point Postion);
	Input* CreateInput(); //creates a pointer to the Input object	
	void ClearStatusBar();	//Clears the status bar
	void ClearDrawArea();	//Clears the drawing area
	void ClearStArea();
	// -- Statements Drawing Functions
	void DrawAssign(Point Left, int width, int height, string Text, bool Selected=false);
	void DrawCondition(Point Left, int width , int height ,string Text ,bool Selected=false);
	//TODO: Add similar functions for drawing all other statements.
	//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
	//		Decide the parameters that should be passed to each of them
	void DrawStart(Point P,bool selected=false);
	void DrawEnd(Point P,bool selected=false);
	/*void DrawConnector(Point p1,Point p2);*/
	void DrawConnector(Point  start ,Point end, bool Selected=false);
	void DrawRead(Point Left, int width , int height ,string Text ,bool Selected=false);
	void DrawWrite(Point Left, int width , int height ,string Text ,bool Selected=false);
	void PrintMessage(string msg);	//Prints a message on Status bar
	string convert_merge(double d,string s,string Operator);
	~Output();
};

#endif