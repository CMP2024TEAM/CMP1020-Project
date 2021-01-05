#include "Edit.h"
#include "..\ApplicationManager.h"
Edit::Edit(ApplicationManager* pApp) :Action(pApp)
{
	C = NULL;
}

Edit::~Edit(void)
{
}

void Edit::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	do
	{
		//Print Action Message
		pOut->PrintMsg("Click on a component to edit it");

		//Wait for User Input
		pIn->GetPointClicked(Cx, Cy);

		//Ask Application manager if click if on component
		pManager->CheckWhichComponent(Cx, Cy, C);

		//Clear Status Bar
		pOut->ClearStatusBar();
	} while (C == NULL);
}

void Edit::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string s;
	pOut->PrintMsg("Enter New Label");
	s = pIn->GetSrting(pOut);
	C->SetLabel(s);
}

void Edit::Undo()
{}

void Edit::Redo()
{}

