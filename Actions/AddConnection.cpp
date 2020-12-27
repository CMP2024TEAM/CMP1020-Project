#include "AddConnection.h"
#include "..\ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp), SrcPin(5)
{
	GCC = new GetClickedComponent(pManager);
}

AddConnection::~AddConnection(void)
{
	delete GCC;
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Connection: Click on a Pin to add the Connection");
	GCC->GetComponent(p1, isp1Gate);//source
	pIn->GetPointClicked(Cx11, Cy11);
	GCC->GetComponent(p2, isp2Gate);//distanition
	pIn->GetPointClicked(Cx22, Cy22);

	//Wait for User Input
	

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnection::Execute()
{
	GraphicsInfo GInfo;
	//Get Center point of the Gate
	ReadActionParameters();
	GInfo = p1->GetLocation();//get gfxinfo
	Cx1 = (GInfo.x1 + GInfo.x2) / 2;
	Cy1 = (GInfo.y1 + GInfo.y2) / 2;
	GInfo = p2->GetLocation();//get gfxinfo
	Cx2 = (GInfo.x1 + GInfo.x2) / 2;
	Cy2 = (GInfo.y1 + GInfo.y2) / 2;
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	//Gfx info to be used to construct the AND2 gate
	int n;
	if (isp2Gate)
		n = p2->getm_Inputs();
	SrcPin.setStatus ((STATUS)p1->GetOutPinStatus());
	
	if (n == 3)
	{
		if ((Cx22 < Cx1) && (Cy22 < Cy2 - 9))//pin 1
		{
			GInfo.x2 = Cx2 - 25;
			GInfo.y2 = Cy2 - 9;
			DstPin.setStatus((STATUS)p2->GetInputPinStatus(1));
		}
		else if ((Cx22 < Cx2) && (Cy22 < Cy2 + 7))//pin 2
		{
			GInfo.x2 = Cx2 - 25;
			GInfo.y2 = Cy2 +7;
			DstPin.setStatus((STATUS)p2->GetInputPinStatus(2));
		}
		else if ((Cx22 < Cx2) && (Cy22 < Cy2 + 23))//pin 3
		{
			GInfo.x2 = Cx2 - 25;
			GInfo.y2 = Cy2 +23;
			DstPin.setStatus((STATUS)p2->GetInputPinStatus(3));
		}
	}
	if (n == 2)
	{
		if ((Cx22 < Cx2) && (Cy22 < Cy2 - 25))//pin 1
		{
			GInfo.x2 = Cx2 - 25;
			GInfo.y2 = Cy2 -12;
			DstPin.setStatus((STATUS)p2->GetInputPinStatus(1));
		}
		else if ((Cx22 < Cx2) && (Cy22 < Cy2 + 25))//pin 2
		{
			GInfo.x2 = Cx2 - 25;
			GInfo.y2 = Cy2 +12;
			DstPin.setStatus((STATUS)p2->GetInputPinStatus(2));
		}
	}
	GInfo.x1 = Cx2 + 25;
	GInfo.y1 = Cy2 + 12;
	Connection* pA = new Connection(GInfo,&SrcPin,&DstPin);
	pManager->AddComponent(pA);
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}

