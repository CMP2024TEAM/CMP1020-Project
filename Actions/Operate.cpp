#include "Operate.h"
Operate::Operate(ApplicationManager* pApp) :Action(pApp)
{
	
}
void Operate::ReadActionParameters()
{
	if (UI.AppMode == SIMULATION)
	{
		//Get a Pointer to the Input / Output Interfaces
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();


		//Print Action Message
		pOut->PrintMsg("Click on a Switch to Change it");

		//Wait for User Input
		pIn->GetPointClicked(Cx, Cy);

		//Clear Status Bar
		pOut->ClearStatusBar();
	}
	return;
}


void Operate::Execute()// not to be virtual
{
	ReadActionParameters();
	
	pManager->CheckWhichComponent(Cx, Cy, sw);
	sw = dynamic_cast<Switch*>(sw);
	if (sw != NULL)
		sw->Operate();
	
}
//To undo this action (code depends on action type)
void Operate::Undo()
{
	return;
}
//To redo this action (code depends on action type)
void Operate::Redo()
{
	return;
}
Operate :: ~Operate(void)
{
	return;
}