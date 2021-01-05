#include "Add_Switch.h"
#include "..\ApplicationManager.h"
Add_Switch::Add_Switch(ApplicationManager* pApp) :Action(pApp)
{
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
	pOut->PrintMsg("the switch: Click to add the switch");

	//Wait for User Input
	bool inside = false;
	do
	{


		pIn->GetPointClicked(Cx, Cy);
		if ((Cx > 25 && Cx < 875) && (Cy > (UI.ToolBarHeight + 25) && Cy < (UI.height - UI.StatusBarHeight - 25)))
			inside = true;
		else
			pOut->PrintMsg("You Can Only Draw Inside Drawing Area! Click Again ");

	} while (!inside);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Add_Switch::Execute()
{//Get Center point of the switch
	ReadActionParameters();

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
}



void Add_Switch::Undo()
{
}

void Add_Switch::Redo()
{
}
