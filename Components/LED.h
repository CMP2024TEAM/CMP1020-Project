#ifndef _LED_H_
#define _LED_H_

#include"Component.h"
#include "InputPin.h"
class LED :public Component
{
	InputPin Inputpin;  //the Input pin  
	Output* the_status; //that make me able to use the drawing functions 
	static int NotAssigendLeds;
	int AssignCheck;
public:
	LED(const GraphicsInfo& r_GfxInfo);
	void Operate();
	int GetInputPinStatus(int n);
	void setInputPinStatus(int n, STATUS s);
	void Draw(Output* pOut,bool selected);
	int GetOutPinStatus();
	virtual int getm_Inputs();
	void save(string& thenameofthecirciut);
	void load(int x, int y, string label, int u);
	InputPin* getinputpin();
	int static getNotAssignedLeds();
	~LED();
	virtual void ResetPins();
};
#endif