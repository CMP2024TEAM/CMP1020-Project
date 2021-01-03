#include "Copy.h"
#include "..\ApplicationManager.h"
void Copy::Execute()
{
	//Component* the_object = pManager->get_clipboard();
	the_message->PrintMsg("click on the component that you want to copy it ");
	Component* the_object;
}

void Copy::Undo()
{
}

void Copy::Redo()
{
}

void Copy::ReadActionParameters()
{
}

Copy::Copy(ApplicationManager* pApp):Action(pApp)
{
}
