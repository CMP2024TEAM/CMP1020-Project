#pragma once
#include "Action.h"
#include "AddConnection.h"
#include "..\Components\Gate.h"
#include "..\Components\Switch.h"
#include "..\Components\LED.h"
class EditConnection :
    public Action
{

private:
	//Parameters for rectangular area to be occupied by the gate

	Component* p1, *p2, *C;
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
	int Cx1, Cy1, Cx2, Cy2;	//Center point of the srcgate dstgate
	int Cx11, Cy11, Cx22, Cy22;
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	bool Cancel;
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

