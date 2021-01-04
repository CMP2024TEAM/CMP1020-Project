#include "Save.h"
#include<fstream>
#include "..\ApplicationManager.h"
Save::Save(ApplicationManager* pApp):Action(pApp)
{
}
void Save::ReadActionParameters()
{
}

void Save::Execute()
{
	ofstream the_added_component;
	the_added_component.open("file format.txt");
	pManager->save();
}

void Save::Undo()
{
}

void Save::Redo()
{
}






