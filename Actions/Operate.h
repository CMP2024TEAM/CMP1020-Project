#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Switch.h"
#include "..\Components\LED.h"
#include "..\Components\Gate.h"
#include "..\Components\Connection.h"
class Operate :
    public Action
{
private:
	int Cx, Cy;
	Component* sw;
public:
	Operate(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();


	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
	virtual ~Operate(void);
};

