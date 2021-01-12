#include "Add_Switch.h"
#include "..\ApplicationManager.h"
Add_Switch::Add_Switch(ApplicationManager* pApp) :Action(pApp)
{
	Cancel = 0;
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	Cx = 0;
	Cy = 0;
}

Add_Switch::~Add_Switch(void)
{
}

void Add_Switch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("The Switch: Click to Add a Switch");

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

void Add_Switch::Execute()
{//Get Center point of the switch
	ReadActionParameters();
	if (Cancel == 1)
		return;
	//Calculate the rectangle Corners
	int Len = UI.Swtich_Width;
	int Wdth = UI.Swtich_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the the swtich

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	Switch* pA = new Switch(GInfo);
	pManager->AddComponent(pA);
	pManager->Addswitch(pA);
}



void Add_Switch::Undo()
{
}

void Add_Switch::Redo()
{
}
