#ifndef _ADD_LABEL_H
#define _ADD_LABEL_H

#include "action.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"
class AddLabel : public Action
{
private:
	int Cx, Cy;	
	Component* C;
	bool Cancel;
public:
	AddLabel(ApplicationManager* pApp,Component*);
	virtual ~AddLabel(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif