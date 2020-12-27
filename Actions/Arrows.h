#pragma once
#include "..\ApplicationManager.h"
#include "action.h"
class Arrows : public Action
{
public:
	Arrows(ApplicationManager* pApp ,ActionType action);
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
	void Execute(ActionType action);

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
	virtual ~Arrows(void);
};


