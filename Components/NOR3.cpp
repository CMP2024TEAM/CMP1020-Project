#include "NOR3.h"
#include<fstream>
NOR3::NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOR3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	//Add you code here
	int Inputs[3];
	Inputs[0] = GetInputPinStatus(1);
	Inputs[1] = GetInputPinStatus(2);
	Inputs[2] = GetInputPinStatus(3);
	if ((Inputs[0] != NOTASSIGNED) && ((Inputs[1] != NOTASSIGNED)&& (Inputs[2] != NOTASSIGNED)))
	{
		if (!Inputs[0] && !Inputs[1] && !Inputs[2])
		{
			m_OutputPin.setStatus(HIGH);
		}
		else
		{
			m_OutputPin.setStatus(LOW);
		}
		AssignCheck++;
		//Decreases NotAssigned Gates
		if (AssignCheck == 1)
			NotAssignedGates--;
	}
}


// Function Draw
// Draws 3-input NOR gate
void NOR3::Draw(Output* pOut,bool selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR3(m_GfxInfo, selected);
	DrawLabel(pOut);
}

//returns status of outputpin
int NOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void NOR3::save()
{
	
	ofstream the_added_component;
	the_added_component.open("file format.txt", ios::app);
	the_added_component << "NOR3  " << "     " << id << "     " << get_mlabel() << "     " << m_GfxInfo.x1 << "     " << m_GfxInfo.y1 << endl;
	the_added_component.close();
}

void NOR3::load(int x, int y, string label, int u)
{
	m_GfxInfo.x1 = x;
	m_GfxInfo.y1 = y;
	Setmlabel(label);
	id = u;
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
int NOR3:: getm_Inputs() { return  m_Inputs; }