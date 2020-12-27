#ifndef _Get_Clicked_Component_H
#define _Get_Clicked_Component_H

#include "action.h"
#include"../Components/Component.h"
#include"../Components/Gate.h"
class GetClickedComponent : public Action
{
	int Cx, Cy;
	Component* ClickedComponent;
	bool IsGate;
public:
	GetClickedComponent(ApplicationManager* pApp);
	virtual ~GetClickedComponent(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	void GetComponent(Component*&,bool&);
	void GetPoint(int& x, int& y);
};

#endif