#include"Select.h"
#include "..\ApplicationManager.h"
Select::Select(Component* p, ApplicationManager* pApp) :Action(pApp)
{
	Comp = p;
}
void Select::Execute()
{
	ActionType Act;
	Act = pManager->GetUserAction();
	switch (Act)
	{

	case ADD_CONNECTION:
		break;
	case ADD_Label:
		break;
	case EDIT_Label:
		break;
	case DEL:
		pManager->DeleteComponent(Comp);
		break;
	case MOVE:
		break;
	default:
		break;
	}
}
void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}
void Select::Redo()
{}
void Select::Undo()
{}
Select::~Select() {}