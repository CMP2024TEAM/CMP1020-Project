#include "Gate.h"

class BUFFER :public Gate
{

public:
	BUFFER(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the NOT gate
	virtual void Draw(Output* pOut);	//Draws NOT gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus();	//returns status of Inputpin  if SWITCH, return -1

	virtual void setInputPinStatus(STATUS s);	//set status of Inputpin , to be used by connection class.





};