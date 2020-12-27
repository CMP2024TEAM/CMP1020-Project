#pragma once
#include "action.h"
#include "..\Components\Connection.h"
#include "..\Components\Gate.h"
#include "GetClickedComponent.h"
class AddConnection : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	GetClickedComponent* GCC;
	Component* p1;
	bool isp1Gate;
	Component* p2;
	bool isp2Gate;
	OutputPin SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin DstPin;	//The Destination pin of this connection (an input pin of certain Component)
	int Cx1, Cy1,Cx2,Cy2;	//Center point of the srcgate dstgate
	int Cx11, Cy11, Cx22, Cy22;
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

