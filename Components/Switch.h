#pragma once
#include "component.h"
#include "OutputPin.h"
class Switch :
    public Component
{
private:
	OutputPin SrcPin;	//The Source pin of this connection (an output pin of certain Component)
public:
	Switch(const GraphicsInfo& r_GfxInfo);
	virtual void Operate();	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut,bool selected);//for each component to Draw itself

	void save();
	void load(int x, int y, string label, int u);
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual int getm_Inputs();
	virtual void setInputPinStatus(int n, STATUS s=LOW);	//set status of Inputpin # n, to be used by connection class.
	OutputPin* Switch::getoutputpin();
};

