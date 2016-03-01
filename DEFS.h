#ifndef DEFS_H
#define DEFS_H

//This file contais some global constants and definitions to be used in the project.

enum ActionType //The actions supported (you can add more if needed)
{
	ADD_SMPL_ASSIGN,//Add simple assignment statement
	ADD_VAR_ASSIGN,	//Add variable assignment statement
	ADD_OP_ASSIGN,
	ADD_COND, //Add a conditional statement (for if and while-loop statements)
	ADD_START,
	ADD_END,
	ADD_CONNECTOR, //Add a connector between two statements
	ADD_COMMENT,
	EDIT,	//Edit a statement
	SELECT,
	DrawingArea,	//Select a statement, a connector
	MULTI_SELECT,
	DEL,		//Delete a figure(s)
	MOVE,		//Move a figure(s)
	RESIZE,		//Resize a figure(s)
	COPY,
	PASTE,
	CUT,
	ADD_INPUT,
	ADD_OUTPUT,
	SAVE,		//Save the whole graph to a file
	LOAD,		//Load a graph from a file
	EXIT,		//Exit the application
	ZOOM_IN,
	ZOOM_OUT,
	STATUS,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar
	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to simulatiom mode
	RUN,
	STEP,
	CODE

};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you change the menu items order, change the order here too
	ITM_START,
	ITM_SMPL_ASSIGN,//simple assignment statement
	ITM_VAR_ASSIGN,
	ITM_OP_ASSIGN,
	ITM_COND,		//conditional statement
	ITM_CONNECTOR,
	ITM_INP,
	ITM_OUT,
	ITM_END,
	ITM_EDIT,
	ITM_COMMENT,
	ITM_DEL,
	ITM_SELECT,
	ITM_MULTI_SELECT,
	ITM_MOVE,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_SAVE,
	ITM_LOAD,
	ITM_ZOOM_IN,
	ITM_ZOOM_OUT,
	ITM_SIMULATION,
	ITM_EXIT,		//Exit
	
	//TODO: Add more items names here
	
	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum
	
};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_RUN,	//Run
	ITM_STP,	//Step by step
	//TODO:Add more items names here
	ITM_CODE,
	ITM_DESIGN_MODE,
	ITM_EXIT_SM=11,
	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
};




#ifndef NULL
#define NULL 0
#endif

#endif