#include "XOR2.h"
#include<fstream>
XOR2::XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void XOR2::Operate()
{
	int input[2];
	input[0] = GetInputPinStatus(1);
	input[1] = GetInputPinStatus(2);
	if ((m_InputPins[0].getStatus() != NOTASSIGNED) && (m_InputPins[1].getStatus() != NOTASSIGNED))
	{
		if (input[0] != input[1])
			m_OutputPin.setStatus(HIGH);
		else
			m_OutputPin.setStatus(LOW);
		AssignCheck++;
		//Decreases NotAssigned Gates
		if (AssignCheck == 1)
			NotAssignedGates--;
	}
}

void XOR2::Draw(Output* pOut, bool selected)
{//Call output class and pass gate drawing info to it.
	pOut->Draw_XOR2(m_GfxInfo, selected);
	DrawLabel(pOut);
}

void XOR2::save()
{

	ofstream the_added_component;
	the_added_component.open("file format.txt", ios::app);
	the_added_component << "XOR2  " << "     " << id << "     " << get_mlabel() << "     " << m_GfxInfo.x1 << "     " << m_GfxInfo.y1 << endl;
	the_added_component.close();
}

void XOR2::load(int x, int y, string label, int u)
{
	m_GfxInfo.x1 = x;
	m_GfxInfo.y1 = y;
	Setmlabel(label);
	id = u;
}

int XOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
int XOR2::getm_Inputs()
{
	return  m_Inputs;
}