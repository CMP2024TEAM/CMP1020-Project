#pragma once
#pragma once
#include"Action.h"
#include "..\Components\Component.h"
class Select :public Action
{
private:
	Component* Comp;
	int Cx=0, Cy=0;
public:
	Select(ApplicationManager*);
	~Select();
	virtual void Execute();
	virtual void ReadActionParameters();
	virtual void Undo();
	virtual void Redo();
};