#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate:public Component
{
protected:
	
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
	static int NotAssignedGates;
	int AssignCheck;
public:
	Gate(int r_Inputs, int r_FanOut);
	virtual int getm_Inputs();
	InputPin* getinputpin(int n);
	OutputPin* getoutputpin();
	 virtual void save();
	 virtual void load(int x, int y, string label, int u);
	static  int getNotAssignedGates();
	virtual ~Gate();//delete dynamic Allocation
	 
};

#endif
