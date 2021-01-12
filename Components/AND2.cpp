#include "AND2.h"
#include<fstream>
AND2::AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND2::Operate()
{
	if ((m_InputPins[0].getStatus() != NOTASSIGNED) && (m_InputPins[1].getStatus() != NOTASSIGNED))
	{
		if ((m_InputPins[0].getStatus() == HIGH) && (m_InputPins[1].getStatus() == HIGH))
			m_OutputPin.setStatus(HIGH);
		else
			m_OutputPin.setStatus(LOW);
		AssignCheck++;
		if (AssignCheck == 1)
		NotAssignedGates--;
	}
}
void AND2::Draw(Output* pOut,bool selected)
{
	pOut->DrawAND2(m_GfxInfo,selected);
	DrawLabel(pOut);
}

int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}

int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

void AND2::save(string& thenameofthecirciut)
{
	
	ofstream the_added_component;
	the_added_component.open( thenameofthecirciut, ios::app);
	the_added_component << "AND2  " << "     " << id << "     " << get_mlabel() << "     " << m_GfxInfo.x1 << "     " << m_GfxInfo.y1 << endl;
	the_added_component.close();
	
}

void AND2::load(int x,int y, string label,int u)
{
	m_GfxInfo.x1 = x;
	m_GfxInfo.x2 = x + 50;
	m_GfxInfo.y1 = y;
	m_GfxInfo.y2 = y + 50;
	Setmlabel(label);
	id = u;
}

int AND2::getm_Inputs()

{
	return  m_Inputs;
}
void AND2::ResetPins()
{
	if (m_OutputPin.getStatus() != NOTASSIGNED)
	{
		NotAssignedGates++;
		AssignCheck = 0;
	}
	m_InputPins[0].setStatus(NOTASSIGNED);
	m_InputPins[1].setStatus(NOTASSIGNED);
	m_OutputPin.setStatus(NOTASSIGNED);
}

AND2::~AND2()
{
	
}
