#ifndef _Move_H
#define _Move_H

#include "action.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"
class Move : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int Cx2, Cy2;
	Component* C;
	bool Cancel;
public:
	Move(ApplicationManager* pApp,Component*);
	virtual ~Move(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif