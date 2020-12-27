#include "Arrows.h"
Arrows::Arrows(ApplicationManager* pApp, ActionType action) :Action(pApp)
{
	Execute(action);
}
void Arrows::ReadActionParameters()
{
	return;
}

//Execute action (code depends on action type)
void Arrows::Execute(ActionType action)
{
	Output* pOut = pManager->GetOutput();
	if (action == Page_One)
	{
		pOut->CreateDesignToolBar(Page_One);
		UI.PageNumber = 1;
	}
	if (action == Page_Two)
	{
		pOut->CreateDesignToolBar(Page_Two);
		UI.PageNumber = 2;
	}


}
void Arrows::Execute()// not to be virtual
{
	return;

}
//To undo this action (code depends on action type)
void Arrows::Undo()
{
	return;
}
//To redo this action (code depends on action type)
void Arrows::Redo()
{
	return;
}
Arrows:: ~Arrows(void)
{
	return;
}
