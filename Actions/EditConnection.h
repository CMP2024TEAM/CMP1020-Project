#pragma once
#include "Action.h"
#include "AddConnection.h"
class EditConnection :
    public Action
{

private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int Cx2, Cy2;
	Component* C;
public:
	EditConnection(ApplicationManager* pApp, Component*);
	virtual ~EditConnection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

