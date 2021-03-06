#include "Edit.h"
#include "..\ApplicationManager.h"
Edit::Edit(ApplicationManager* pApp,Component* SelComp) :Action(pApp)
{
	C = SelComp;
	Cancel = 0;
}

Edit::~Edit(void)
{
}

void Edit::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	while (C == NULL)
	{
		//Print Action Message
		pOut->PrintMsg("Click on a component to edit it");

		//Wait for User Input
		pIn->GetPointClicked(Cx, Cy);

		if (pManager->CheckCancel(Cx, Cy) == 0)
		{
			Cancel = 1;
			pOut->ClearStatusBar();
			return;
		}

		//Ask Application manager if click if on component
		pManager->CheckWhichComponent(Cx, Cy, C);

		//Clear Status Bar
		pOut->ClearStatusBar();
	}
}

void Edit::Execute()
{
	ReadActionParameters();
	if (Cancel == 1)
		return;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string s = C->get_mlabel();
	pOut->PrintMsg("Enter New Label");
	s = pIn->GetSrting(pOut , s);
	C->Setmlabel(s);
}

void Edit::Undo()
{}

void Edit::Redo()
{}

