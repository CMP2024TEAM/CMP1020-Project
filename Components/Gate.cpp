#include "Gate.h"
#include<fstream>
//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}
InputPin* Gate::getinputpin(int n)
{
	return (&m_InputPins[n]);
}
OutputPin* Gate::getoutputpin()
{
	return (&m_OutputPin);
}
void Gate::save(int y)
{
	/*ofstream the_added_component;
	double Cx, Cy;
	//Cx = (m_GfxInfo.x1 + m_GfxInfo.x2) / 2.0;
	//Cy = (m_GfxInfo.y1 + m_GfxInfo.y2) / 2.0;
	the_added_component.open("file format.txt");
	the_added_component<<y<<"     "<<get_mlabel()<<"     " << m_GfxInfo.x1 << "     " << m_GfxInfo.y1 << "     " << endl;
	the_added_component.close();*/
}
int Gate::getm_Inputs()
{
	return m_Inputs;
}