#include "AddANDgate3.h"
#include "..\ApplicationManager.h"

AddANDgate3::AddANDgate3(ApplicationManager* pApp) :Action(pApp)
{
	Cancel = 0;
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	Cx = 0;
	Cy = 0;
}

AddANDgate3::~AddANDgate3(void)
{
}

void AddANDgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input AND Gate: Click to Add The Gate");

	//Wait for User Input
	bool inside = false;
	do
	{


		pIn->GetPointClicked(Cx, Cy);
		if ((Cx > 25 && Cx < 875) && (Cy > (UI.ToolBarHeight + 25) && Cy < (UI.height - UI.StatusBarHeight - 25)))
			inside = true;
		else
			pOut->PrintMsg("You Can Only Draw Inside Drawing Area! Click Again ");
		if (pManager->CheckCancel(Cx, Cy) == 0)
		{
			Cancel = 1;
			pOut->ClearStatusBar();
			return;
		}
	} while (!inside);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddANDgate3::Execute()
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
	AND3* pA = new AND3(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}



void AddANDgate3::Undo()
{}

void AddANDgate3::Redo()
{}

