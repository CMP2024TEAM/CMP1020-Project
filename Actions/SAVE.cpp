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
	string thecircuit,thefile,s;
	Input* thegetter= pManager->GetInput();
	pOut->PrintMsg("Enter the name of the circiut");
	thecircuit =thegetter->GetSrting(pOut);
	s = ".txt";
	thefile = thecircuit + s;
		the_added_component.open(thefile);
	pManager->save(thefile);
	the_added_component.close();
}

void Save::Undo()
{
}

void Save::Redo()
{
}






