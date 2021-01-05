#include "AddSwitch.h"
#include "..\ApplicationManager.h"
AddSwitch::AddSwitch(ApplicationManager* pApp) :Action(pApp)
{
	Cancel = 0;
}

AddSwitch::~AddSwitch(void)
{
}

void AddSwitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Switch: Click to add the switch");

	//Wait for User Input
	bool inside = false;
	do
	{


		pIn->GetPointClicked(Cx, Cy);
		if (pManager->CheckWhichComponent(Cx, Cy) == 0)
		{
			Cancel = 1;
			pOut->ClearStatusBar();
			return;
		}
		if ((Cx > 25 && Cx < 875) && (Cy > (UI.ToolBarHeight + 25) && Cy < (UI.height - UI.StatusBarHeight - 25)))
			inside = true;
		else
			pOut->PrintMsg("You Can Only Draw Inside Drawing Area! Click Again ");

	} while (!inside);
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddSwitch::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	if (Cancel == 1)
		return;
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	Switch* pA = new Switch(GInfo);
	pManager->AddComponent(pA);
}



void AddSwitch::Undo()
{}

void AddSwitch::Redo()
{}
