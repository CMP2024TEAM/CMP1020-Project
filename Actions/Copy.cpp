#include "Copy.h"
#include "..\ApplicationManager.h"
#include"..\Components\Connection.h"
void Copy::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("click on the component that you want to copy it ");
	pIn->GetPointClicked(x, y);
	if (pManager->CheckCancel(x,y) == 0)
	{
		Cancel = 1;
		pOut->ClearStatusBar();
		return;
	}
	pOut->ClearStatusBar();
	
}
void Copy::Execute()
{
	Connection* connect = dynamic_cast<Connection*>(the_object);
	if (the_object == NULL&&connect==NULL)
	{
		ReadActionParameters();
		if (Cancel == 1)
			return;
		pManager->CheckWhichComponent(x, y, the_object);
	}
	pManager->set_clipboard(the_object);

}

void Copy::Undo()
{
}

void Copy::Redo()
{
}



Copy::Copy(ApplicationManager* pApp,Component* Selcomp):Action(pApp)
{
	the_object = Selcomp;
	Cancel = 0;
}
