#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1205;
	UI.height = 700;
	UI.wx = 15;
	UI.wy =15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StBrWdth = 50;
	UI.TlBrWdth = 50;
	UI.MnItWdth = 50;       // design menu item width
	UI.SmItWdth = 100;      // simulation menu item width

	UI.DrawClr = BLUE;
	UI.HiClr = RED;
	UI.MsgClr = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	UI.COND_WDTH =200;
	UI.COND_HI = 75;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);
	//int te1,te2;
	//pWind->GetMouseClick(te1,te2);
		CreateDesignToolBar();
//	pWind->GetMouseClick(te1,te2);
CreateStatusBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StBrWdth, UI.width, UI.height-UI.StBrWdth);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the Design Menu

void Output::CreateDesignToolBar()
{
	UI.AppMode = DESIGN;	//Design Mode
	int i=0;	
	ClearToolBar();
	//fill the tool bar 
	//You can draw the tool bar icons in any way you want.
	pWind->DrawImage("images\\start.jpg", 0, 0);
	pWind->DrawImage("images\\Assign.jpg", 50, 0);
	pWind->DrawImage("images\\V_assign.jpg", 100, 0);
    pWind->DrawImage("images\\op_assign.jpg", 150, 0);
	pWind->DrawImage("images\\Condition.jpg", 200, 0);
	pWind->DrawImage("images\\connect.jpg", 250, 0);
	pWind->DrawImage("images\\input.jpg", 300, 0);
	pWind->DrawImage("images\\output.jpg", 350, 0);
	pWind->DrawImage("images\\End.jpg", 400, 0);
	pWind->DrawImage("images\\edit.jpg", 450, 0);
	pWind->DrawImage("images\\comment.jpg", 500, 0);
	pWind->DrawImage("images\\delete1.jpg", 550, 0);
	pWind->DrawImage("images\\select.jpg", 600, 0);
	pWind->DrawImage("images\\multi_select.jpg", 650, 0);
	pWind->DrawImage("images\\move.jpg", 700, 0);
	pWind->DrawImage("images\\copy.jpg", 750, 0);
	pWind->DrawImage("images\\cut.jpg", 800, 0);
	pWind->DrawImage("images\\paste.jpg", 850, 0);
	pWind->DrawImage("images\\Save.jpg", 900, 0);
	pWind->DrawImage("images\\load.jpg", 950, 0);
	pWind->DrawImage("images\\zoom_in.jpg", 1000, 0);
	pWind->DrawImage("images\\zoom_out.jpg", 1050, 0);	
	pWind->DrawImage("images\\simulation2.jpg", 1100, 0);
	pWind->DrawImage("images\\Exit.jpg", 1150, 0);

	
	

	
	
	
	
	//Draw a line under the toolbar
	pWind->SetPen(RED,1);
	pWind->DrawLine(0, UI.TlBrWdth, UI.width, UI.TlBrWdth);	

}


void Output::CreateSimulationToolBar()
{
	ClearToolBar();

	

	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar


	pWind->DrawImage("images\\run.jpg", 0, 0);
	pWind->DrawImage("images\\stepbystep.jpg", 100, 0);
	pWind->DrawImage("images\\code.jpg", 200, 0);
	pWind->DrawImage("images\\design.jpg", 300, 0);
	pWind->DrawImage("images\\exit2.jpg", 1080, 0);
	pWind->SetPen(BLACK,1);
	pWind->DrawLine(0, UI.TlBrWdth, UI.width, UI.TlBrWdth);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar()
{
	
pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0,0, UI.width,UI.TlBrWdth);
}
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StBrWdth, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.TlBrWdth, UI.width, UI.height - UI.StBrWdth);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStArea()
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 2*UI.TlBrWdth, UI.StBrWdth,2*UI.StBrWdth);

}
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgClr, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StBrWdth/1.5), msg);
}
void Output::Dragging(Point Postion)
{

	int iX, iY;
	/*pWind->FlushMouseQueue();
	pWind->FlushKeyQueue();

	pWind->SetFont(20, BOLD, BY_NAME, "Arial");

	pWind->SetBuffering(true);

	*/
	int RectULX = 100;
	int RectULY = 100;
	int RectWidth = 20;
	bool bDragging = false;
	iX = Postion.x;
	iY = Postion.y;
	int iXOld = Postion.x;
	int iYOld = Postion.y;
	char cKeyData;
	// Loop until there escape is pressed
	while (pWind->GetKeyPress(cKeyData) != ESCAPE)
	{
		pWind->SetPen(BLACK);
		pWind->SetBrush(BLACK);
		pWind->DrawRectangle(60,0, RectULX, RectULY);
		// Dragging voodoo
		if (bDragging == false)
		{
			if (pWind->GetButtonState(LEFT_BUTTON, iX, iY) == BUTTON_DOWN)
			{
				if (((iX > RectULX) && (iX < (RectULX + RectWidth))) && ((iY > RectULY) && (iY < (RectULY + RectWidth))))
				{
					bDragging = true;
					iXOld = iX; iYOld = iY;
				}
			}
		}
		else
		{
			if (pWind->GetButtonState(LEFT_BUTTON, iX, iY) == BUTTON_UP)
			{
				bDragging = false;
			}
			else
			{
				if (iX != iXOld)
				{
					RectULX = RectULX + (iX - iXOld);
					iXOld = iX;
				}
				if (iY != iYOld)
				{
					RectULY = RectULY + (iY - iYOld);
					iYOld = iY;
				}
			}
		}
	}
}
//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);
		
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width/4, Left.y + height/4, Text);

}
void Output::DrawCondition(Point Left, int width , int height ,string Text ,bool Selected)
{
	int*x=new int[4];
	int*y= new int[4];
	x[0]=Left.x;
    x[1]=Left.x+(width/2);
    x[2]=Left.x+width;
	x[3]=Left.x+(width/2);
	///////////////////////
	y[0]=Left.y;
    y[1]=Left.y-(height/2);
	y[2]=Left.y;
	y[3]=Left.y+(height/2);
	//////////////////////////////
	
	if(Selected)	//if stat is selected, it should be highlighted
	{pWind->SetPen(UI.HiClr,3);}	//use highlighting color
	else 
		{pWind->SetPen(UI.DrawClr,3);}
	
	pWind->DrawPolygon(x,y,4,FRAME);

	pWind->DrawString(Left.x-50,Left.y-20 , "False");
	pWind->DrawString(x[2]+10,y[2]-20 , "True");

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width/3, Left.y-5 , Text);
}
void Output::DrawStart(Point P,bool Selected)
{
		if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr,3);	//use normal color
		//Draw Start Statement
		/*pWind->DrawEllipse(P.x/4,P.y/4,P.x/16,P.y/16);*/
		pWind->DrawCircle(P.x,P.y,50);
		pWind->SetPen(BLACK, 2);
		pWind->DrawString(P.x-20,P.y-5,"Start");
}
void Output::DrawEnd(Point P,bool Selected)
{
	
		if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr,3);	//use normal color
		//Draw End Statement
		pWind->DrawCircle(P.x,P.y,50);
		pWind->SetPen(BLACK, 2);
		pWind->DrawString(P.x-10,P.y-5,"End");
}
enum type
	{
		left_right,
		right_left,
		up_down,
		down_up,
		right_up,
		right_down,
		left_up,
		left_down,
		None

	};
type get_type(Point p1,Point p2)
	{
	if ((p1.x-p2.x <-150) && (p1.y==p2.y))
	{
	return left_right;
	}

	if ((p1.x-p2.x > 150) && (p1.y==p2.y))
	{

		return right_left;
	}

	if ((p1.x==p2.x) && (p1.y-p2.y<-50))
	{

		return up_down;
	}
	
	if ((p1.x==p2.x) && (p1.y-p2.y>50))
	{

		return down_up;
	}

	if (/*(p1.x-p2.x <-150) &&*/ (p1.y-p2.y>50))
	{

		return right_up;
	}
	if (/*(p1.x-p2.x <-150) &&*/ (p1.y-p2.y<-50))
	{
		return right_down;
	}

	if (/*(p1.x-p2.x > 150) &&*/ (p1.y-p2.y>50))
	{
		return left_up;
	}
	if (/*(p1.x-p2.x > 150) && */(p1.y-p2.y<-50))
	{
		return left_down;
	}
	else
	{
		return None;
	}

	}
void Output::DrawConnector(Point  start ,Point end, bool Selected)
{
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr,3);	//use highlighting color
	else
			pWind->SetPen(BLACK,5);
	pWind->SetBrush(BLACK);
	int x=end.x-start.x;  int y=end.y-start.y;
	//Draw the statement block line+triangle
	if (start.y<end.y)

	{

		//if (cond == true)
		//{
		//	pWind->DrawLine(end.x, start.y, end.x, end.y);
		//	pWind->DrawLine(start.x, start.y, end.x, start.y);
		//	if (end.y>start.y)
		//	{
		//		//pWind->DrawTriangle(end.x - 10, end.y - 10, end.x + 10, end.y - 10, end.x, end.y);
		//		pWind->DrawTriangle(end.x-10,end.y-10,end.x+10,end.y-10,end.x,end.y);
		//	}
		//	else
		//	{
		//		//pWind->DrawTriangle(end.x - 10, end.y + 10, end.x + 10, end.y + 10, end.x, end.y);
		//		pWind->DrawTriangle(end.x-10,end.y-10,end.x+10,end.y-10,end.x,end.y);
		//	}
		
		
		
			int x = abs(start.x - end.x); int y = abs(start.y - end.y);
			pWind->DrawLine(start.x, start.y, start.x, start.y + (y / 2));
			pWind->DrawLine(start.x, start.y + (y / 2), end.x, start.y + (y / 2));
			pWind->DrawLine(end.x, start.y + (y / 2), end.x, end.y);
			//pWind->DrawTriangle(end.x - 10, end.y - 10, end.x + 10, end.y - 10, end.x, end.y);
			pWind->DrawTriangle(end.x-10,end.y-10,end.x+10,end.y-10,end.x,end.y);
		
	}
	else
	{

		if (end.x>start.x)
		{
			if(end.x-start.x>150)
			{
			pWind->DrawLine(start.x, start.y, start.x, start.y + 30);
			pWind->DrawLine(start.x, start.y + 30, start.x + 150, start.y + 30);
			pWind->DrawLine(start.x + 150, start.y + 30, start.x + 150, end.y - 20);
			pWind->DrawLine(start.x + 150, end.y - 20, end.x , end.y-20 );
			pWind->DrawLine(end.x,end.y-20,end.x,end.y);
			}
			else
			{
			pWind->DrawLine(start.x, start.y, start.x, start.y + 30);
			pWind->DrawLine(start.x, start.y + 30, start.x - 150, start.y + 30);
			pWind->DrawLine(start.x - 150, start.y + 30, start.x - 150, end.y - 20);
			pWind->DrawLine(start.x - 150, end.y - 20, end.x , end.y-20 );
			pWind->DrawLine(end.x,end.y-20,end.x,end.y);

			}
			//pWind->DrawTriangle(end.x - 20, end.y , end.x - 20, end.y - 20, end.x-10 , end.y - 10);
			//pWind->DrawTriangle(end.x-10,end.y+10,end.x+10,end.y+10,end.x,end.y);
			pWind->DrawTriangle(end.x-10,end.y-10,end.x+10,end.y-10,end.x,end.y);
		}
		else
		{
			if (start.x-end.x>150)
			{
			pWind->DrawLine(start.x, start.y, start.x, start.y + 30);
			pWind->DrawLine(start.x, start.y + 30, start.x - 150, start.y + 30);
			pWind->DrawLine(start.x - 150, start.y + 30, start.x - 150, end.y - 20);
			pWind->DrawLine(start.x - 150, end.y - 20, end.x , end.y-20 );
			pWind->DrawLine(end.x,end.y-20,end.x,end.y);
			}
			else
			{
			pWind->DrawLine(start.x, start.y, start.x, start.y + 30);
			pWind->DrawLine(start.x, start.y + 30, start.x + 150, start.y + 30);
			pWind->DrawLine(start.x + 150, start.y + 30, start.x + 150, end.y - 20);
			pWind->DrawLine(start.x + 150, end.y - 20, end.x , end.y-20 );
			pWind->DrawLine(end.x,end.y-20,end.x,end.y);
			}


		//	pWind->DrawTriangle(end.x + 20, end.y - 20, end.x + 20, end.y, end.x + 10, end.y - 10);
			pWind->DrawTriangle(end.x-10,end.y-10,end.x+10,end.y-10,end.x,end.y);
		}

	}
}
//void Output::DrawConnector(Point p1, Point p2)
//{
//	type x;
//	
//	x=get_type(p1,p2);
//	pWind->SetPen(BLACK,5);
//	pWind->SetBrush(BLACK);
//	switch(x)
//	{
//	case left_right:
//		pWind->DrawLine(p1.x,p1.y,p2.x,p2.y);
//		pWind->DrawTriangle(p2.x,p2.y+10,p2.x,p2.y-10,p2.x+10,p2.y);
//		break;
//	case right_left: 
//		pWind->DrawLine(p1.x,p1.y,p2.x,p2.y);
//	    pWind->DrawTriangle(p2.x,p2.y+10,p2.x,p2.y-10,p2.x-10,p2.y);
//		break;
//	case up_down:
//		pWind->DrawLine(p1.x,p1.y,p2.x,p2.y);
//		pWind->DrawTriangle(p2.x-10,p2.y,p2.x+10,p2.y,p2.x,p2.y+10);
//		break;
//	case down_up:
//		pWind->DrawLine(p1.x,p1.y,p2.x,p2.y);
//		pWind->DrawTriangle(p2.x-10,p2.y,p2.x+10,p2.y,p2.x,p2.y-10);
//        break;
//	case right_up:
//		pWind->DrawLine(p1.x,p1.y,p2.x,p1.y);
//		pWind->DrawLine(p2.x,p1.y,p2.x,p2.y);
//		pWind->DrawTriangle(p2.x-10,p2.y+10,p2.x+10,p2.y+10,p2.x,p2.y);
//		break;
//	case right_down:
//		pWind->DrawLine(p1.x,p1.y,p2.x,p1.y);
//		pWind->DrawLine(p2.x,p1.y,p2.x,p2.y);
//		pWind->DrawTriangle(p2.x-10,p2.y-10,p2.x+10,p2.y-10,p2.x,p2.y);
//		break;
//	case left_up:
//		pWind->DrawLine(p1.x,p1.y,p2.x,p1.y);
//		pWind->DrawLine(p2.x,p1.y,p2.x,p2.y);
//		pWind->DrawTriangle(p2.x-10,p2.y+10,p2.x+10,p2.y+10,p2.x,p2.y);
//		break;
//	case left_down:
//		pWind->DrawLine(p1.x,p1.y,p2.x,p1.y);
//		pWind->DrawLine(p2.x,p1.y,p2.x,p2.y);
//		pWind->DrawTriangle(p2.x-10,p2.y-10,p2.x+10,p2.y-10,p2.x,p2.y);
//		break;
//	case None:
//		break;
//
//
//	}
//
//
//}
void Output::DrawRead(Point Left, int width , int height ,string Text ,bool Selected)
{
	int*x=new int[4];
	int*y= new int[4];
	x[0]=Left.x;
    x[1]=Left.x+width;
    x[2]=Left.x+(width-15);
	x[3]=Left.x-15;
	///////////////////////
	y[0]=Left.y;
    y[1]=Left.y;
	y[2]=Left.y+height;
	y[3]=Left.y+height;
	//////////////////////////////
	if(Selected)	//if stat is selected, it should be highlighted
	{pWind->SetPen(UI.HiClr,3);}	//use highlighting color
	else 
		{pWind->SetPen(UI.DrawClr,3);}
	
	pWind->DrawPolygon(x,y,4,FRAME);

	pWind->SetPen(BLACK, 2);
	pWind->DrawString((Left.x+width/2)-50, Left.y+20, Text);
}
void Output::DrawWrite(Point Left, int width , int height ,string Text ,bool Selected)
	{
	int*x=new int[4];
	int*y= new int[4];
	x[0]=Left.x;
    x[1]=Left.x+width;
    x[2]=Left.x+(width-15);
	x[3]=Left.x-15;
	///////////////////////
	y[0]=Left.y;
    y[1]=Left.y;
	y[2]=Left.y+height;
	y[3]=Left.y+height;
	//////////////////////////////
	if(Selected)	//if stat is selected, it should be highlighted
	{pWind->SetPen(UI.HiClr,3);}	//use highlighting color
	else 
		{pWind->SetPen(UI.DrawClr,3);}
	
	pWind->DrawPolygon(x,y,4,FRAME);

	pWind->SetPen(BLACK, 2);
	pWind->DrawString((Left.x+width/2)-20, Left.y+20, Text);
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

string Output::convert_merge(double d,string s,string Operator)
{ string temp,str;
	stringstream convert;
	convert<<d;
	temp=convert.str();
	str=s+Operator+temp;
	return str;
}

