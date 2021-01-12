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
	ofstream the_added_file;
	string thecircuit,thefile,s;
	Input* thegetter= pManager->GetInput();
	pOut->PrintMsg("Enter the name of the circiut");
	thecircuit =thegetter->GetSrting(pOut);
	s = ".txt";
	thefile = thecircuit + s;
		the_added_file.open("\save\\"+thefile);
	pManager->save("\save\\" + thefile);
	pOut->PrintMsg("the circiut is saved");
	the_added_file.close();
}

void Save::Undo()
{
}

void Save::Redo()
{
}






