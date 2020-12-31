#include "AddConnection.h"
#include "..\ApplicationManager.h"
#include "..\Components\Switch.h"
#include "..\Components\LED.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
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
	pOut->PrintMsg("Connection: Click on an output Pin to add the Connection");
	GCC->Execute();
	GCC->GetComponent(p1, isp1Gate);//source
	GCC->GetPoint(Cx11, Cy11);
	pOut->ClearStatusBar();
	pOut->PrintMsg("Connection: Click on an input Pin to add the Connection");
	GCC->Execute();
	GCC->GetComponent(p2, isp2Gate);//distanition
	GCC->GetPoint(Cx22, Cy22);

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
	int n,j;
	//if (isp2Gate)
	n = p2->getm_Inputs();
	Gate* gate1 = dynamic_cast<Gate*>(p1);
	if (gate1 != NULL)
	{
		SrcPin = gate1->getoutputpin();
	}
	Switch* SWITCH = dynamic_cast<Switch*>(p1);
	if (SWITCH != NULL)
	{
		SrcPin = SWITCH->getoutputpin();
	}


	if (n == 3)
	{
		if ((Cx22 < Cx2) && (Cy22 < Cy2 - 4))//pin 1
		{

			GInfo.y1 = Cy2 - 5;
			j = 1;
		}
		else if ((Cx22 < Cx2) && (Cy22 < Cy2 + 4))//pin 2
		{

			GInfo.y1 = Cy2;
			j = 2;
		}
		else if ((Cx22 < Cx2))//pin 3
		{

			GInfo.y1 = Cy2 + 5;
			j = 3;
		}
	}
	if (n == 2)
	{
		if ((Cx22 < Cx2) && (Cy22 < Cy2))//pin 1
		{

			GInfo.y1 = Cy2 - 4;
			j = 1;
		}
		else if ((Cx22 < Cx2) && (Cy22 > Cy2))//pin 2
		{
			GInfo.y1 = Cy2 + 4;
			j = 2;
		}
	}
	if (n == 1)
	{
		GInfo.y1 = Cy2;
		j = 1;
	}
	if (n == 0)
	{
		GInfo.y1 = Cy2 + 25;
		Cx2 += 10;
		

	}
	Gate* gate2 = dynamic_cast<Gate*>(p2);
	if (gate2 != NULL)
	{
		DstPin = gate2->getinputpin(j);
	}
	LED* Led = dynamic_cast<LED*>(p2);
	if (Led != NULL)
	{
		DstPin = Led->getinputpin(1);
	}
	GInfo.x1 = Cx2 - 20;

	GInfo.x2 = Cx1 + 20;
	GInfo.y2 = Cy1;
	Connection* pA = new Connection(GInfo, SrcPin, DstPin);
	pManager->AddComponent(pA);
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}

