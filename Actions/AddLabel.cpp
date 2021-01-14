#include "AddLabel.h"
#include "..\ApplicationManager.h"
AddLabel::AddLabel(ApplicationManager* pApp,Component*SelComp) :Action(pApp)
{
	C = SelComp;
	Cancel = 0;
}

AddLabel::~AddLabel(void)
{
}

void AddLabel::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	while (C == NULL)
	{
		//Print Action Message
		pOut->PrintMsg("Click on a Component to Add a Label to it");

		//Wait for User Input
		pIn->GetPointClicked(Cx, Cy);

		//Ask Application manager if click if on component
		if (pManager->CheckCancel(Cx, Cy) == 0)
		{
			Cancel = 1;
			pOut->ClearStatusBar();
			return;
		}

		pManager->CheckWhichComponent(Cx, Cy, C);
		//Clear Status Bar
		pOut->ClearStatusBar();
	}
}

void AddLabel::Execute()
{
	ReadActionParameters();
	if (Cancel == 1)
		return;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string s;
	pOut->PrintMsg("Enter Label");
	s = pIn->GetSrting(pOut);
	C->Setmlabel(s);
}

void AddLabel::Undo()
{}

void AddLabel::Redo()
{}

