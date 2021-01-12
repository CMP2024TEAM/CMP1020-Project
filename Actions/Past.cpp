#include "Past.h"
#include "..\ApplicationManager.h"
#include "..\Components\AND2.h"
#include "..\Components\AND3.h"
#include "..\Components\BUFFER.H"
#include "..\Components\LED.h"
#include "..\Components\NAND2.h"
#include "..\Components\NOR2.h"
#include "..\Components\NOR3.h"
#include "..\Components\NOT.h"
#include "..\Components\OR2.h"
#include "..\Components\Switch.h"
#include "..\Components\XNOR2.h"
#include "..\Components\XOR2.h"
#include "..\Components\XOR3.h"
void Past::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->get_clipboard() != NULL)
	{
	Component* object=pManager->get_clipboard();
	pOut->PrintMsg("click on any point to add the component");
	ReadActionParameters();
	if (Cancel == 1)
		return;
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	int len = 50;
	int width = 50;
	GInfo.x1 = x - len / 2;
	GInfo.x2 = x + len / 2;
	GInfo.y1 = y - width / 2;
	GInfo.y2 = y + width / 2;
	
		AND2* the_saver = dynamic_cast<AND2*>(object);
		if (the_saver != NULL)
		{
			AND2* the;
			the = new AND2(GInfo,AND2_FANOUT);
			the->SetId(the->GetId());
			pManager->AddComponent(the);
		}
		AND3* the1 = dynamic_cast<AND3*>(object);
		if (the1 != NULL)
		{
			AND3* the;
			the = new AND3(GInfo, AND2_FANOUT);
			the->SetId(the->GetId());
			pManager->AddComponent(the);
		}
		BUFFER* the2 = dynamic_cast<BUFFER*>(object);
		if (the2 != NULL)
		{
			BUFFER* the;
			the = new BUFFER(GInfo, AND2_FANOUT);
			the->SetId(the->GetId());
			pManager->AddComponent(the);
		}
		LED* the3 = dynamic_cast<LED*>(object);
		if (the3 != NULL)
		{
			LED* the;
			the = new LED(GInfo);
			the->SetId(the->GetId());
			pManager->AddComponent(the);
		}
		NAND2* the4 = dynamic_cast<NAND2*>(object);
		if (the4 != NULL)
		{
			NAND2* the;
			the = new NAND2(GInfo, AND2_FANOUT);
			the->SetId(the->GetId());
			pManager->AddComponent(the);
		}
		NOR2* the5 = dynamic_cast<NOR2*>(object);
		if (the5 != NULL)
		{
			NOR2* the;
			the = new NOR2(GInfo, AND2_FANOUT);
			the->SetId(the->GetId());
			pManager->AddComponent(the);
		}
		NOR3* the6 = dynamic_cast<NOR3*>(object);
		if (the6 != NULL)
		{
			NOR3* the;
			the = new NOR3(GInfo, AND2_FANOUT);
			the->SetId(the->GetId());
			pManager->AddComponent(the);
		}
		OR2* the7 = dynamic_cast<OR2*>(object);
		if (the7 != NULL)
		{
			OR2* the;
			the = new OR2(GInfo, AND2_FANOUT);
			the->SetId(the->GetId());
			pManager->AddComponent(the);
		}
		NOT* the8 = dynamic_cast<NOT*>(object);
		if (the8 != NULL)
		{
			NOT* the;
			the = new NOT(GInfo, AND2_FANOUT);
			the->SetId(the->GetId());
			pManager->AddComponent(the);
		}
		XNOR2* the9 = dynamic_cast<XNOR2*>(object);
		if (the9 != NULL)
		{
			XNOR2* the;
			the = new XNOR2(GInfo, AND2_FANOUT);
			the->SetId(the->GetId());
			pManager->AddComponent(the);
		}
		XOR2* the10 = dynamic_cast<XOR2*>(object);
		if (the10 != NULL)
		{
			XOR2* the;
			the = new XOR2(GInfo, AND2_FANOUT);
			the->SetId(the->GetId());
			pManager->AddComponent(the);
		}
		XOR3* the11 = dynamic_cast<XOR3*>(object);
		if (the11 != NULL)
		{
			XOR3* the;
			the = new XOR3(GInfo, AND2_FANOUT);
			the->SetId(the->GetId());
			pManager->AddComponent(the);
		}
		Switch* the12 = dynamic_cast<Switch*>(object);
		if (the12 != NULL)
		{
			Switch* the;
			the = new Switch(GInfo);
			the->SetId(the->GetId());
			pManager->AddComponent(the);
		}
		pOut->PrintMsg("the component is added");
		pOut->ClearStatusBar();
	}
	pOut->PrintMsg("there is no component to paste it");
}

void Past::Undo()
{
}

void Past::Redo()
{
}

void Past::ReadActionParameters()
{
	
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	bool inside = false;
	do
	{


		pIn->GetPointClicked(x, y);
		if (pManager->CheckCancel(x, y) == 0)
		{
			Cancel = 1;
			pOut->ClearStatusBar();
			return;
		}
		if ((x > 25 && x < 875) && (y > (UI.ToolBarHeight + 25) && y < (UI.height - UI.StatusBarHeight - 25)))
			inside = true;
		else
			pOut->PrintMsg("You Can Only Draw Inside Drawing Area!");

	} while (!inside);
}

Past::Past(ApplicationManager* pApp):Action(pApp)
{	
	Cancel = 0;
}
