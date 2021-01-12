#include"Select.h"
#include "..\ApplicationManager.h"
Select::Select( ApplicationManager* pApp) :Action(pApp)
{
}
void Select::Execute()
{
	if (UI.AppMode == DESIGN)
	{
		ReadActionParameters();
		Component* SelComp;
		pManager->CheckWhichComponent(Cx, Cy, SelComp);
		pManager->SetSelectedComponent(SelComp);
	}
}
void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	
		//Print Action Message
		pOut->PrintMsg("Click on Component to select it or click anywhere to cancel");

		//Wait for User Input
		pIn->GetPointClicked(Cx, Cy);

		//Clear Status Bar
		pOut->ClearStatusBar();
	
	

}
void Select::Redo()
{}
void Select::Undo()
{}
Select::~Select() {}