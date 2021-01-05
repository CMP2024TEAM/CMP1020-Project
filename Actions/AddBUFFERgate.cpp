#include "AddBUFFERgate.h"
#include "..\ApplicationManager.h"
AddBUFFERgate::AddBUFFERgate(ApplicationManager* pApp) :Action(pApp)
{
	Cancel = 0;
}

AddBUFFERgate::~AddBUFFERgate(void)
{
}

void AddBUFFERgate::ReadActionParameters()
{//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input BUFFER Gate: Click to add the gate");

	//Wait for User Input
	bool inside = false;
	do
	{


		pIn->GetPointClicked(Cx, Cy);
		if ((Cx > 25 && Cx < 875) && (Cy > (UI.ToolBarHeight + 25) && Cy < (UI.height - UI.StatusBarHeight - 25)))
			inside = true;
		else
			pOut->PrintMsg("You Can Only Draw Inside Drawing Area! Click Again ");
		if (pManager->CheckWhichComponent(Cx, Cy) == 0)
		{
			Cancel = 1;
			pOut->ClearStatusBar();
			return;
		}
	} while (!inside);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddBUFFERgate::Execute()
{//Get Center point of the Gate
	ReadActionParameters();
	if (Cancel == 1)
		return;
	//Calculate the rectangle Corners
	int Len = UI.BUFFER_Width;
	int Wdth = UI.BUFFER_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	BUFFER* pA = new BUFFER(GInfo, BUFFER_FANOUT);
	pManager->AddComponent(pA);
}

void AddBUFFERgate::save()
{

}

void AddBUFFERgate::Undo()
{
}

void AddBUFFERgate::Redo()
{
}
