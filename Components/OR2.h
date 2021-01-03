#pragma once
#include"Gate.h"
/*class OR2
represent the 2 input OR2 gate
*/
class OR2:public Gate
{
public:
	OR2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the OR gate
	virtual void Draw(Output* pOut,bool selected);	//Draws 2-input gate
	void save(int y);
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual int getm_Inputs();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
};