#include "cut.h"
#include "..\ApplicationManager.h"
#include"..\Components\AND2.h"
#include"..\Components\AND3.h"
#include"..\Components\BUFFER.H"
#include"..\Components\LED.h"
#include"..\Components\NAND2.h"
#include"..\Components\NOR2.h"
#include"..\Components\NOR3.h"
#include"..\Components\NOT.h"
#include"..\Components\OR2.h"
#include"..\Components\Switch.h"
#include"..\Components\XNOR2.h"
#include"..\Components\XOR2.h"
#include"..\Components\XOR3.h"
#include "Delete.h"
void cut::Execute()
{
	if (the_object == NULL)
	{
		ReadActionParameters();
		if (Cancel == 1)
			return;
		pManager->CheckWhichComponent(x, y, the_object);
	}
	Connection* connect = dynamic_cast<Connection*>(the_object);
	if(the_object!=NULL&&connect==NULL)
	{
	AND2* the_saver = dynamic_cast<AND2*>(the_object);
	if (the_saver != NULL)
	{
		AND2* the;
		the = new AND2(*the_saver);
		pManager->set_clipboard(the);
	}
	AND3* t = dynamic_cast<AND3*>(the_object);
	if (t != NULL)
	{
		AND3* the;
		the = new AND3(*t);
		pManager->set_clipboard(the);
	}
	BUFFER* h = dynamic_cast<BUFFER*>(the_object);
	if (h != NULL)
	{
		BUFFER* the;
		the = new BUFFER(*h);
		pManager->set_clipboard(the);
	}
	LED* g = dynamic_cast<LED*>(the_object);
	if (g != NULL)
	{
		LED* the;
		the = new LED(*g);
		pManager->set_clipboard(the);
	}
	NAND2* q = dynamic_cast<NAND2*>(the_object);
	if (q != NULL)
	{
		NAND2* the;
		the = new NAND2(*q);
		pManager->set_clipboard(the);
	}
	NOR2* w = dynamic_cast<NOR2*>(the_object);
	if (w != NULL)
	{
		NOR2* the;
		the = new NOR2(*w);
		pManager->set_clipboard(the);
	}
	NOR3* a = dynamic_cast<NOR3*>(the_object);
	if (a != NULL)
	{
		NOR3* the;
		the = new NOR3(*a);
		pManager->set_clipboard(the);
	}
	OR2* e = dynamic_cast<OR2*>(the_object);
	if (e != NULL)
	{
		OR2* the;
		the = new OR2(*e);
		pManager->set_clipboard(the);
	}
	NOT* d = dynamic_cast<NOT*>(the_object);
	if (d != NULL)
	{
		NOT* the;
		the = new NOT(*d);
		pManager->set_clipboard(the);
	}
	XNOR2* s = dynamic_cast<XNOR2*>(the_object);
	if (s != NULL)
	{
		XNOR2* the;
		the = new XNOR2(*s);
		pManager->set_clipboard(the);
	}
	XOR2* k = dynamic_cast<XOR2*>(the_object);
	if (k != NULL)
	{
		XOR2* the;
		the = new XOR2(*k);
		pManager->set_clipboard(the);
	}
	XOR3* j = dynamic_cast<XOR3*>(the_object);
	if (j != NULL)
	{
		XOR3* the;
		the = new XOR3(*j);
		pManager->set_clipboard(the);
	}
	Switch* f = dynamic_cast<Switch*>(the_object);
	if (f != NULL)
	{
		Switch* the;
		the = new Switch(*f);
		pManager->set_clipboard(the);
	}
	Action* act = new Delete(pManager, the_object);
	act->Execute();
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
}
	
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMsg("Couldn't Cut");
	}
}

void cut::Undo()
{
}

void cut::Redo()
{
}

void cut::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("click on the component that you want to cut it ");
	pIn->GetPointClicked(x, y);
	if (pManager->CheckCancel(x, y) == 0)
	{
		Cancel = 1;
		pOut->ClearStatusBar();
		return;
	}
}

cut::cut(ApplicationManager* pApp,Component* SelComp):Action(pApp)
{
	the_object = SelComp;
	Cancel = 0;
}
