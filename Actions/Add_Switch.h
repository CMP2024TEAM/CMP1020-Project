#pragma once
#include "action.h"
#include "..\Components\Switch.h"
class Add_Switch :
    public Action
{
private:
	//Parameters for rectangular area to be occupied by the LED
	int Cx, Cy;	//Center point of the LED
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	Add_Switch(ApplicationManager* pApp);
	virtual ~Add_Switch(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

