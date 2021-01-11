#include "AND3.h"
#include <fstream>
AND3::AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	//Add you code here
	int Inputs[3];
	Inputs[0] = GetInputPinStatus(1);
	Inputs[1] = GetInputPinStatus(2);
	Inputs[2] = GetInputPinStatus(3);
	if ((Inputs[0] != NOTASSIGNED) && (Inputs[1] != NOTASSIGNED) && (Inputs[2] != NOTASSIGNED)) {
		if (Inputs[0] && Inputs[1] && Inputs[2])
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
// Draws 3-input AND gate
void AND3::Draw(Output* pOut, bool selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND3(m_GfxInfo, selected);
	DrawLabel(pOut);
}

//returns status of outputpin
int AND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}



//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
int AND3::getm_Inputs()
{
	return  m_Inputs;
}

void AND3::save(string& thenameofthecirciut)
{

	ofstream the_added_component;
	the_added_component.open( thenameofthecirciut, ios::app);
	the_added_component << "AND3  " << "     " << id << "     " << get_mlabel() << "     " << m_GfxInfo.x1 << "     " << m_GfxInfo.y1 << endl;
	the_added_component.close();
	//Gate::save(y);
}

void AND3::load(int x, int y, string label, int u)
{
	m_GfxInfo.x1 = x;
	m_GfxInfo.x2 = x + 50;
	m_GfxInfo.y1 = y;
	m_GfxInfo.y2 = y + 50;
	Setmlabel(label);
	id = u;
}
