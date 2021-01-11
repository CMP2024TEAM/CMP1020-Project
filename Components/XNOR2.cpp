#include "XNOR2.h"
#include<fstream>
XNOR2::XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void XNOR2::Operate()
{
	int input[2];
	input[0] = GetInputPinStatus(1);
	input[1] = GetInputPinStatus(2);
	if ((m_InputPins[0].getStatus() != NOTASSIGNED) && (m_InputPins[1].getStatus() != NOTASSIGNED))
	{
		if (input[0] == input[1])
			m_OutputPin.setStatus(HIGH);
		else
			m_OutputPin.setStatus(LOW);
		AssignCheck++;
		//Decreases NotAssigned Gates
		if (AssignCheck == 1)
			NotAssignedGates--;
	}
}

void XNOR2::Draw(Output* pOut,bool selected)
{//Call output class and pass gate drawing info to it.
	pOut->Draw_XNOR2(m_GfxInfo, selected);
	DrawLabel(pOut);
}

int XNOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int XNOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void XNOR2::save(string& thenameofthecirciut)
{
	
	ofstream the_added_component;
	the_added_component.open(thenameofthecirciut, ios::app);
	the_added_component << "XNOR2 " << "     " << id << "     " << get_mlabel() << "     " << m_GfxInfo.x1 << "     " << m_GfxInfo.y1 << endl;
	the_added_component.close();
}

void XNOR2::load(int x, int y, string label, int u)
{
	m_GfxInfo.x1 = x;
	m_GfxInfo.y1 = y;
	m_GfxInfo.x2 = x+50;
	m_GfxInfo.y2 = y+50;
	Setmlabel(label);
	id = u;
}

void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
int XNOR2:: getm_Inputs()
{
	return  m_Inputs;
}