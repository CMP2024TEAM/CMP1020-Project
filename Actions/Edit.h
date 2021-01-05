#ifndef _EDIT_H
#define _EDIT_H

#include "action.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"
class Edit : public Action
{
private:
	int Cx, Cy;
	Component* C;
public:
	Edit(ApplicationManager* pApp);
	virtual ~Edit(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif