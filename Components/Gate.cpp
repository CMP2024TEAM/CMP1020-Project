#include "Gate.h"
#include<fstream>
//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
int Gate::NotAssignedGates = 0;
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
	//increases NotAssigned Gates
	NotAssignedGates++;
	AssignCheck = 0;
}
int Gate::getm_Inputs()
{
	return 0;
}
InputPin* Gate::getinputpin(int n)
{
	return (&m_InputPins[n]);
}
OutputPin* Gate::getoutputpin()
{
	return (&m_OutputPin);
}
void Gate::save()
{
	
}
 void Gate::load(int x, int y, string label, int u)
{
	
}

 int Gate::getNotAssignedGates()
 {
	 return NotAssignedGates;
 }

 Gate::~Gate()
 {
	 //Decreases NotAssigned Gates
	 NotAssignedGates--;
	 delete[] m_InputPins;
 }
