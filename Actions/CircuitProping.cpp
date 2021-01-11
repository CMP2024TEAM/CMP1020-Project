#include "CircuitProping.h"
CircuitProping::CircuitProping(ApplicationManager* pApp) :Action(pApp)
{
	PropStatus = NOTASSIGNED;
}
void CircuitProping::ReadActionParameters()
{
	if (UI.AppMode == SIMULATION)
	{
		//Get a Pointer to the Input / Output Interfaces
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();


		//Print Action Message
		pOut->PrintMsg("Click on a Component to Prob it");

		//Wait for User Input
		pIn->GetPointClicked(Cx11, Cy11);

		pManager->CheckWhichComponent(Cx11, Cy11, Comp);
		if (Comp == NULL)
		{
			pOut->PrintMsg("Circuit Probing Tool: Please Select A Valid Pin!");
		}

		//Clear Status Bar
		pOut->ClearStatusBar();
	}
	return;
}


void CircuitProping::Execute()// not to be virtual
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	//Deticting the pin
	GraphicsInfo MInfo = Comp->GetLocation();
	int Cx2 = MInfo.x1;
	int Cy2 = MInfo.y1;
	int Cx1 = MInfo.x2;
	int Cy1 = MInfo.y2;
	Cx2 = (Cx1 + Cx2) / 2;
	Cy2 = (Cy1 + Cy2) / 2;
	int n, j = 1;
	//if (isp2Gate)
	n = Comp->getm_Inputs();
	if (n == 3)
	{
		if ((Cx11 < Cx2) && (Cy11 < Cy2 - 4))// pin 1
		{
			j = 1;
		}
		else if ((Cx11 < Cx2) && (Cy11 < Cy2 + 4))// pin 2
		{

			j = 2;
		}
		else if ((Cx11 < Cx2))// pin 3
		{
			j = 3;
		}
	}
	if (n == 2)
	{
		if ((Cx11 < Cx2) && (Cy11 < Cy2)) //pin 1
		{
			j = 1;
		}
		else if ((Cx11 < Cx2) && (Cy11 > Cy2)) // pin 2
		{
			j = 2;
		}
	}

	Gate* gate2 = dynamic_cast<Gate*>(Comp);
	if (gate2 != NULL)
	{
		PropStatus = (STATUS)gate2->GetInputPinStatus(j);
	}
	LED* Led = dynamic_cast<LED*>(Comp);
	if (Led != NULL)
	{
		PropStatus = Led->getinputpin()->getStatus();
	}

	if ((Cx11 > Cx2))
	{
		Gate* gate2 = dynamic_cast<Gate*>(Comp);
		if (gate2 != NULL)
		{
			PropStatus = gate2->getoutputpin()->getStatus();
		}
	}
	Switch* Sw2 = dynamic_cast<Switch*>(Comp);
	if (Sw2 != NULL)
	{
		PropStatus = Sw2->getoutputpin()->getStatus();
	}
	Connection* Conn = dynamic_cast<Connection*>(Comp);
	if (Conn != NULL)
	{
		PropStatus = Conn->getDestPin()->getStatus();
	}
	if (PropStatus == HIGH)
		pOut->PrintMsg("The Status of The Pin = HIGH");
	else if (PropStatus == LOW)
		pOut->PrintMsg("The Status of The Pin = LOW");
	else
		pOut->PrintMsg("The Status of The Pin = NOT ASSIGNED");

}
//To undo this action (code depends on action type)
void CircuitProping::Undo()
{
	return;
}
//To redo this action (code depends on action type)
void CircuitProping::Redo()
{
	return;
}
CircuitProping :: ~CircuitProping(void)
{
	return;
}