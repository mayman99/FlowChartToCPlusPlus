#include "Save.h"
#include <iostream>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Statements\Connector.h"
#include "..\ApplicationManager.h"
#include "..\Statements\Statement.h"
#include<fstream>
using namespace std;

void Save::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut -> PrintMessage(" File Saved to chart.txt ");
	output.open ("chart.txt");
	output<<(pManager->getScount())<<endl;
	for(int i=0;i<pManager->getScount();i++)
	{
		pManager-> StatList[i]->Save(output);
	}
	output<<(pManager->ConnCount)<<endl;
	for(int i=0;i<pManager->getCcount();i++)
	{
		pManager->ConnList[i]->Save(output);
	}
	output.close();
	pOut->ClearDrawArea();
}