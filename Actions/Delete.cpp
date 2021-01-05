#include "Delete.h"
#include "..\ApplicationManager.h"
Delete::Delete(ApplicationManager* pApp,Component* SelComp) :Action(pApp)
{
	C = SelComp;
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
		pManager->CheckWhichComponent(Cx, Cy, C);

		//Clear Status Bar
		pOut->ClearStatusBar();
	} 
}

void Delete::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
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
		pManager->DeleteAllConnnectionsWithThisInputPin(P);
	}
	else if (type == "Switch")
	{
		OutputPin* O = s->getoutputpin();
		pManager->DeleteAllConnnectionsWithThisOutputPin(O);
	}
	else if (type == "Gate")
	{
		OutputPin* O = g->getoutputpin();
		pManager->DeleteAllConnnectionsWithThisOutputPin(O);
		int inputcount = g->getm_Inputs();
		for (int j = 1;j <= inputcount;j++)
		{
			InputPin* P = g->getinputpin(j);
			pManager->DeleteAllConnnectionsWithThisInputPin(P);
		}
	}
	pManager->DeleteComponent(C);
}

void Delete::Undo()
{}

void Delete::Redo()
{}

