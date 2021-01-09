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
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("the circiut is saved");
	ofstream the_added_component;
	the_added_component.open("file format.txt");
	pManager->save();
	the_added_component.close();
}

void Save::Undo()
{
}

void Save::Redo()
{
}






