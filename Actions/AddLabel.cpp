#include "AddLabel.h"
#include "..\ApplicationManager.h"
AddLabel::AddLabel(ApplicationManager* pApp,Component*SelComp) :Action(pApp)
{
	C = SelComp;
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
		pOut->PrintMsg("Click on a component to add a label to it");

		//Wait for User Input
		pIn->GetPointClicked(Cx, Cy);

		//Ask Application manager if click if on component
		pManager->CheckWhichComponent(Cx, Cy, C);

		//Clear Status Bar
		pOut->ClearStatusBar();
	}
}

void AddLabel::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string s;
	pOut->PrintMsg("Enter Label");
	s = pIn->GetSrting(pOut);
	C->SetLabel(s);
}

void AddLabel::Undo()
{}

void AddLabel::Redo()
{}

