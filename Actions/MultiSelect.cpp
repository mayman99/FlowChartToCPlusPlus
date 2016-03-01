
#include "MultiSelect.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "Select.h"
MultiSelect::MultiSelect(ApplicationManager *pAppManager) :Action(pAppManager)
{}

MultiSelect::~MultiSelect()
{}
void MultiSelect::ReadActionParameters() {
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();

	pOut->PrintMessage("Tap to select statements");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}
void MultiSelect::Execute() {
	ReadActionParameters();
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
    Statement *s = pManager->GetStatement(Position);

	while (s!=NULL)
	{

		if (s->IsSelected() != true)
				{
					pManager->SetSelectedStatement(s);
					s->SetSelected(true);
					pOut->PrintMessage("you selected a statment");
					pManager->UpdateInterface();
				}
				else
				{
					s->SetSelected(false);
					pOut->PrintMessage("you Unselected a statment");
					pManager->UpdateInterface();
				}
		       pIn->GetPointClicked(Position);
			   s = pManager->GetStatement(Position);

				
	}

	pOut->ClearStatusBar();
		/*do
		{
			pIn->GetPointClicked(Position);

			if (s != nullptr)
			{
				if (s->IsSelected() != true)
				{
					pManager->SetSelectedStatement(s);
					s->SetSelected(true);
					pOut->PrintMessage("you selected a statment");
				}
				else
				{
					s->SetSelected(false);
					pOut->PrintMessage("you Unselected a statment");
				}
				pManager->UpdateInterface();
			}
		} while (s!=NULL);*/
}
void MultiSelect::ExecuteCopy(const Statement & s) {

}