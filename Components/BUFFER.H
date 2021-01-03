#include "Gate.h"

class BUFFER :public Gate
{

public:
	BUFFER(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the NOT gate
	virtual void Draw(Output* pOut,bool selected=0);	//Draws NOT gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin  if SWITCH, return -1
	void save(int y);
	virtual void setInputPinStatus(int n ,STATUS s);	//set status of Inputpin , to be used by connection class.
	virtual int getm_Inputs();
};