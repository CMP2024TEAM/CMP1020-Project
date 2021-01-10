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
	int Cx, Cy;
	while (C == NULL)
	{
		//Print Action Message
		pOut->PrintMsg("Click on a connection to edit it");

		//Wait for User Input
		pIn->GetPointClicked(Cx, Cy);

		//Ask Application manager if click if on component
		pManager->CheckWhichComponent(Cx, Cy, C);

		//Clear Status Bar
		pOut->ClearStatusBar();

		Conn = dynamic_cast<Connection*>(C);
		C = Conn;
	}
	pOut->PrintMsg("Edit Connection: Enter 1 to Edit Input Pin or 2 to Edit Output Pin Then Press Enter Key");
	string s;
	pIn->GetSrting(pOut,s);
	while (true) {
		if (s == "1")
		{
			pOut->ClearStatusBar();
			pOut->PrintMsg("Connection: Click on the new input Pin to the Connection");
			bool Inpin = false;
			do
			{
				pIn->GetPointClicked(Cx22, Cy22);
				if (pManager->CheckWhichComponent(Cx22, Cy22, p2) == 0)
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
			type = 1;
			break;
		}
		else if (s == "2")
		{
			pOut->ClearStatusBar();
			pOut->PrintMsg("Connection: Click on the new output Pin to the Connection");
			bool Outpin = false;
			do
			{
				pIn->GetPointClicked(Cx11, Cy11);
				if (pManager->CheckWhichComponent(Cx11, Cy11, p1) == 0)
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
			type = 2;
			break;
		}
		else
		{
			pOut->PrintMsg("Edit Connection: Enter 1 to edit Input Pin or 2 to edit Output Pin");
			s = "";
			pIn->GetSrting(pOut, s);
		}
	}

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void EditConnection::Execute()
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
	if (type == 1)
	{

	}
	else if (type == 2)
	{

	}
	else
	{

	}
	int n, j;
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
		DstPin = gate2->getinputpin(j - 1);
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
		pManager->DeleteComponent(C);
		pManager->AddComponent(pA);
		pA->setDestCmpnt(p2, n /*number of inputs*/, j /*pin number*/);
		pA->setSourceCmpnt(p1);
	}
	else
	{
		delete pA;
		Output* pOut = pManager->GetOutput();
		pOut->PrintMsg("Connection: Can't add any more due to FANOUT");
	}
}

void EditConnection::Undo()
{}

void EditConnection::Redo()
{}


