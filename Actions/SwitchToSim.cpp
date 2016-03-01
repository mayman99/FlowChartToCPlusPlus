#include "SwitchToSim.h"


#include "..\ApplicationManager.h"
#include "..\Statements\Statement.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

SwitchToSim::SwitchToSim(ApplicationManager *pAppManager):Action(pAppManager)
{}

void SwitchToSim :: ReadActionParameters()
{			
}

void SwitchToSim :: Execute()
{
	Output *pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
	pOut->CreateSimulationToolBar();
	pOut->PrintMessage(" Simulation Mode is active ");
	pOut->ClearDrawArea();
}