#include "AddXORgate2.h"
#include "..\ApplicationManager.h"
AddXORgate2::AddXORgate2(ApplicationManager* pApp) :Action(pApp)
{
	Cancel = 0;
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	Cx = 0;
	Cy = 0;
}

AddXORgate2::~AddXORgate2(void)
{
}

void AddXORgate2::ReadActionParameters()
{//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input XOR Gate: Click to Add The Gate");

	//Wait for User Input
	bool inside = false;
	do
	{


		pIn->GetPointClicked(Cx, Cy);
		if (pManager->CheckCancel(Cx, Cy) == 0)
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

void AddXORgate2::Execute()
{//Get Center point of the Gate
	ReadActionParameters();
	if (Cancel == 1)
		return;
	//Calculate the rectangle Corners
	int Len = UI.XOR2_Width;
	int Wdth = UI.XOR2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	XOR2* pA = new XOR2(GInfo, XOR2_FANOUT);
	pManager->AddComponent(pA);
}



void AddXORgate2::Undo()
{
}

void AddXORgate2::Redo()
{
}
