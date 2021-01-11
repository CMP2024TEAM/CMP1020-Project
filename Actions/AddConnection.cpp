#include "AddConnection.h"
#include "..\ApplicationManager.h"
#include "..\Components\Switch.h"
#include "..\Components\LED.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{
	Cancel = 0;
}

AddConnection::~AddConnection(void)
{

}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Connection: Click on an output Pin to add the Connection");
	bool Outpin = false;
	do
	{
		pIn->GetPointClicked(Cx11, Cy11);
		if (pManager->CheckWhichComponent(Cx11, Cy11,p1) == 0)
		{
			Cancel = 1;
			pOut->ClearStatusBar();
			return;
		}
		LED* L = dynamic_cast<LED*>(p1);

		if (p1 != NULL)
			if (L == NULL)
			{
				if (Cx11 > (p1->GetLocation().x1 + p1->GetLocation().x2) / 2)
					Outpin = true;
				else
				{
					pOut->ClearStatusBar();
					pOut->PrintMsg("Connection: You Can Only Click on an output Pin, Click Again!");
				}
			}
			else
			{
				pOut->ClearStatusBar();
				pOut->PrintMsg("Connection: You Can Only Click on an output Pin, Click Again!");
			}

	} while (p1 == NULL || !Outpin);
	pOut->ClearStatusBar();
	pOut->PrintMsg("Connection: Click on an input Pin to add the Connection");
	bool Inpin = false;
	do
	{

		pIn->GetPointClicked(Cx22, Cy22);
		if (pManager->CheckWhichComponent(Cx22, Cy22,p2) == 0)
		{
			Cancel = 1;
			pOut->ClearStatusBar();
			return;
		}
		LED* L = dynamic_cast<LED*>(p2);
		Switch* S = dynamic_cast<Switch*>(p2);
		if (L != NULL)
			if (Cy22 < (p2->GetLocation().y1 + p2->GetLocation().y2) / 2)
			{
				Inpin = true;
				break;
			}
			else
			{
				pOut->ClearStatusBar();
				pOut->PrintMsg("Connection: You Can Only Click on an Input Pin, Click Again!");
			}
		if (S == NULL)
			if (p2 != NULL)
				if (Cx22 < (p2->GetLocation().x1 + p2->GetLocation().x2) / 2)
					Inpin = true;
				else
				{
					pOut->ClearStatusBar();
					pOut->PrintMsg("Connection: You Can Only Click on an Input Pin, Click Again!");
				}
			else
			{
				pOut->ClearStatusBar();
				pOut->PrintMsg("Connection: You Can Only Click on an Input Pin, Click Again!");
			}
	} while (p2 == NULL || !Inpin);

	//Wait for User Input

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnection::Execute()
{

	GraphicsInfo GInfo;
	//Get Center point of the Gate
	ReadActionParameters();
	if (Cancel == 1)
		return;
	GInfo = p1->GetLocation();//get gfxinfo
	Cx1 = (GInfo.x1 + GInfo.x2) / 2;
	Cy1 = (GInfo.y1 + GInfo.y2) / 2;
	GInfo = p2->GetLocation();//get gfxinfo
	Cx2 = (GInfo.x1 + GInfo.x2) / 2;
	Cy2 = (GInfo.y1 + GInfo.y2) / 2;
	//Calculate the rectangle Corners
	int n, j= 1;
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
		if ((Cx22 < Cx2) && (Cy22 < Cy2 - 4))// pin 1
		{
			GInfo.y2 = Cy2 - 5;
			j = 1;
		}
		else if ((Cx22 < Cx2) && (Cy22 < Cy2 + 4))// pin 2
		{

			GInfo.y2 = Cy2;
			j = 2;
		}
		else if ((Cx22 < Cx2))// pin 3
		{

			GInfo.y2 = Cy2 + 4;
			j = 3;
		}
	}
	if (n == 2)
	{
		if ((Cx22 < Cx2) && (Cy22 < Cy2)) //pin 1
		{
			GInfo.y2 = Cy2 - 4.5;
			j = 1;
		}
		else if ((Cx22 < Cx2) && (Cy22 > Cy2)) // pin 2
		{
			GInfo.y2 = Cy2 + 4.5;
			j = 2;
		}
	}
	if (n == 1)
	{
		GInfo.y2 = Cy2;
		j = 1;
	}
	if (n == 0)
	{
		GInfo.y2 = Cy2 + 25;
		Cx2 += 10;
		j = 1;
	}
	Gate* gate2 = dynamic_cast<Gate*>(p2);
	if (gate2 != NULL)
	{
		DstPin = gate2->getinputpin(j-1);
	}
	LED* Led = dynamic_cast<LED*>(p2);
	if (Led != NULL)
	{
		DstPin = Led->getinputpin();
	}
	GInfo.x2 = Cx2 - 20;
	GInfo.x1 = Cx1 + 20;
	GInfo.y1 = Cy1 - 0.5;
	Connection* pA = new Connection(GInfo, SrcPin, DstPin);
	if (SrcPin->ConnectTo(pA))
	{
		pManager->AddComponent(pA);
		pA->setDestCmpnt(p2, n /*number of inputs*/, j /*pin number*/);
		pA->setSourceCmpnt(p1);
		DstPin->SetConnection(pA);
	}
	else
	{
		delete pA;
		Output* pOut = pManager->GetOutput();
		pOut->PrintMsg("Connection: Can't add any more due to FANOUT");
	}
}


void AddConnection::Undo()
{}

void AddConnection::Redo()
{}

