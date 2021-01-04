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
	Component* object=pManager->get_clipboard();
	pOut->PrintMsg("click to any point to add the component");
	ReadActionParameters();
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
		the = new AND2( *the_saver);
		the->set_Location(GInfo);
		pManager->AddComponent(the);
		the->Draw(pOut);
	}
	AND3* t = dynamic_cast<AND3*>(object);
	if (t != NULL)
	{
		AND3* the;
		the = new AND3(*t);
		the->set_Location(GInfo);
		pManager->AddComponent(the);
		the->Draw(pOut);
	}
	BUFFER* h = dynamic_cast<BUFFER*>(object);
	if (h != NULL)
	{
		BUFFER* the;
		the = new BUFFER(*h);
		the->set_Location(GInfo);
		pManager->AddComponent(the);
		the->Draw(pOut);
	}
	LED* g = dynamic_cast<LED*>(object);
	if (g != NULL)
	{
		LED* the;
		the = new LED(*g);
		the->set_Location(GInfo);
		pManager->AddComponent(the);
		the->Draw(pOut,true);
	}
	NAND2* q = dynamic_cast<NAND2*>(object);
	if (q != NULL)
	{
		NAND2* the;
		the = new NAND2(*q);
		the->set_Location(GInfo);
		pManager->AddComponent(the);
		the->Draw(pOut, true);
	}
	NOR2* w = dynamic_cast<NOR2*>(object);
	if (w != NULL)
	{
		NOR2* the;
		the = new NOR2(*w);
		the->set_Location(GInfo);
		pManager->AddComponent(the);
		the->Draw(pOut, true);
	}
	NOR3* a = dynamic_cast<NOR3*>(object);
	if (a != NULL)
	{
		NOR3* the;
		the = new NOR3(*a);
		the->set_Location(GInfo);
		pManager->AddComponent(the);
		the->Draw(pOut, true);
	}
	OR2* e = dynamic_cast<OR2*>(object);
	if (e != NULL)
	{
		OR2* the;
		the = new OR2(*e);
		the->set_Location(GInfo);
		pManager->AddComponent(the);
		the->Draw(pOut, true);
	}
	NOT* d = dynamic_cast<NOT*>(object);
	if (d != NULL)
	{
		NOT* the;
		the = new NOT(*d);
		the->set_Location(GInfo);
		pManager->AddComponent(the);
		the->Draw(pOut, true);
	}
	XNOR2* s = dynamic_cast<XNOR2*>(object);
	if (s != NULL)
	{
		XNOR2* the;
		the = new XNOR2(*s);
		the->set_Location(GInfo);
		pManager->AddComponent(the);
		the->Draw(pOut, true);
	}
	XOR2* k = dynamic_cast<XOR2*>(object);
	if (k != NULL)
	{
		XOR2* the;
		the = new XOR2(*k);
		the->set_Location(GInfo);
		pManager->AddComponent(the);
		the->Draw(pOut, true);
	}
	XOR3* j = dynamic_cast<XOR3*>(object);
	if (j != NULL)
	{
		XOR3* the;
		the = new XOR3(*j);
		the->set_Location(GInfo);
		pManager->AddComponent(the);
		the->Draw(pOut, true);
	}
	Switch* f = dynamic_cast<Switch*>(object);
	if (f != NULL)
	{
		Switch* the;
		the = new Switch(*f);
		the->set_Location(GInfo);
		pManager->AddComponent(the);
		the->Draw(pOut, true);
	}
	pOut->PrintMsg("the component is added");
	pOut->ClearStatusBar();
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
	
	pIn->GetPointClicked(x, y);
}

Past::Past(ApplicationManager* pApp):Action(pApp)
{
}
