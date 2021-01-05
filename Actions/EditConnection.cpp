#include "EditConnection.h"
#include "..\ApplicationManager.h"
EditConnection::EditConnection(ApplicationManager* pApp, Component* SelComp) :Action(pApp)
{
	C = SelComp;
}

EditConnection::~EditConnection(void)
{
}

void EditConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	while (C == NULL)
	{
		//Print Action Message
		pOut->PrintMsg("Click on a component to move it");

		//Wait for User Input
		pIn->GetPointClicked(Cx, Cy);

		//Ask Application manager if click if on component
		pManager->CheckWhichComponent(Cx, Cy, C);

		//Clear Status Bar
		pOut->ClearStatusBar();

		Connection* conn = dynamic_cast<Connection*>(C);
		if (conn != NULL)
		{
			C = NULL;
		}
	}
	//Print Action Message
	pOut->PrintMsg("Click on The New Location of The Selected Component");
	//Wait for User Input
	bool inside = false;
	do
	{


		pIn->GetPointClicked(Cx2, Cy2);
		if ((Cx2 > 25 && Cx2 < 875) && (Cy2 > (UI.ToolBarHeight + 25) && Cy2 < (UI.height - UI.StatusBarHeight - 25)))
			inside = true;
		else
			pOut->PrintMsg("You Can Only Draw Inside Drawing Area!");

	} while (!inside);
	//Clear Status Bar
	pOut->ClearStatusBar();
}

void EditConnection::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	GraphicsInfo GInfo;
	GInfo.x1 = Cx2 - 50 / 2;
	GInfo.x2 = Cx2 + 50 / 2;
	GInfo.y1 = Cy2 - 50 / 2;
	GInfo.y2 = Cy2 + 50 / 2;
	C->SetLocation(GInfo);
}

void EditConnection::Undo()
{}

void EditConnection::Redo()
{}


