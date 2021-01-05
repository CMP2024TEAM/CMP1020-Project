#ifndef _DELETE_H
#define _DELETE_H

#include "action.h"
#include "..\Components\Component.h"
#include "..\Components\Switch.h"
#include "..\Components\LED.h"
#include "..\Components\Gate.h"
#include "..\Components\Connection.h"
class Delete : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int ID;
	Component* C;
public:
	Delete(ApplicationManager* pApp,Component*);
	virtual ~Delete(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif