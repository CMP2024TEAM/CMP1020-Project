#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Switch.h"
#include "..\Components\LED.h"
#include"..\Components\Connection.h"
#include "..\Components\Gate.h"
class CircuitProping :
	public Action
{
private:
	int Cx11, Cy11;
	Component* Comp;
	STATUS PropStatus;
public:
	CircuitProping(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();


	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
	virtual ~CircuitProping(void);
};

