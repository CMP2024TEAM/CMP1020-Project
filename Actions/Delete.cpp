#include "Delete.h"
#include "..\ApplicationManager.h"
Delete::Delete(ApplicationManager* pApp,Component* SelComp) :Action(pApp)
{
	C = SelComp;
	Cancel = 0;
}

Delete::~Delete(void)
{
}

void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	while(C==NULL)
	{
		//Print Action Message
		pOut->PrintMsg("Click on a component to delete it");

		//Wait for User Input
		pIn->GetPointClicked(Cx, Cy);

		//Ask Application manager if click if on component
		if (pManager->CheckWhichComponent(Cx, Cy, C) == 0)
		{
			Cancel = 1;
			pOut->ClearStatusBar();
			return;
		}

		//Clear Status Bar
		pOut->ClearStatusBar();
	} 
}

void Delete::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	if (Cancel == 1)
		return;
	string type;
	Switch* s = dynamic_cast<Switch*>(C);
	if (s != NULL)
	{
		type = "Switch";
	}
	LED* l = dynamic_cast<LED*>(C);
	if (l != NULL)
	{
		type = "LED";
	}
	Connection* conn = dynamic_cast<Connection *>(C);
	if (conn != NULL)
	{
		type = "Connection";
	}
	Gate* g = dynamic_cast<Gate*>(C);
	if (g != NULL)
	{
		type = "Gate";
	}
	if (type == "LED")
	{
		InputPin* P = l->getinputpin();
		pManager->DeleteComponent((Component*)P->GetConnection());
	}
	else if (type == "Switch")
	{
		OutputPin* O = s->getoutputpin();
		Connection** Connections = O->getConnections();
		for (int i = 0;i <= O->getNumConnections();i++)
		{
			if (Connections[i]!=NULL)
			{
				pManager->DeleteComponent((Component*)Connections[i]);
			}
		}
	}
	else if (type == "Gate")
	{
		OutputPin* O = g->getoutputpin();
		Connection** Connections = O->getConnections();
		for (int i = 0;i <= O->getNumConnections();i++)
		{
			if (Connections[i] != NULL)
			{
				pManager->DeleteComponent((Component*)Connections[i]);
			}
		}
		int inputcount = g->getm_Inputs();
		for (int j = 0;j < inputcount;j++)
		{
			InputPin* P = g->getinputpin(j);
			pManager->DeleteComponent((Component*)P->GetConnection());
		}
	}
	pManager->DeleteComponent(C);
}

void Delete::Undo()
{}

void Delete::Redo()
{}

