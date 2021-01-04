#include "Copy.h"
#include "..\ApplicationManager.h"
void Copy::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("click on the component that you want to copy it ");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	
}
void Copy::Execute()
{
	ReadActionParameters();
	pManager->CheckWhichComponent(x, y, the_object);
	pManager->set_clipboard(the_object);

}

void Copy::Undo()
{
}

void Copy::Redo()
{
}



Copy::Copy(ApplicationManager* pApp):Action(pApp)
{
}
