#include "SwitchToDes.h"


#include "..\ApplicationManager.h"
#include "..\Statements\Statement.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

SwitchToDes::SwitchToDes(ApplicationManager *pAppManager):Action(pAppManager)
{}

void SwitchToDes :: ReadActionParameters()
{			
}

void SwitchToDes :: Execute()
{
	Output *pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
	pOut->CreateDesignToolBar();
	pOut->PrintMessage("Design Mode is active");
	pOut->ClearDrawArea();

}