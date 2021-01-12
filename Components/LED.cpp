#include "LED.h"
#include<fstream>
int LED::NotAssigendLeds = 0;
LED::LED(const GraphicsInfo& r_GfxInfo)
{
	//the_output.setStatus(LOW);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	NotAssigendLeds++;
	AssignCheck = 0;
}

void LED::Operate()
{

	if (Inputpin.getStatus() != NOTASSIGNED)
	{
		AssignCheck++;
		if (AssignCheck == 1)
			NotAssigendLeds--;
	}
	
}

int LED::GetInputPinStatus(int n)
{
	if (Inputpin.getStatus() == HIGH)
		return 1;
	else
		return 0;
}

void LED::setInputPinStatus(int n, STATUS s)
{
	Inputpin.setStatus(s);
}

void LED::Draw(Output* pOut, bool selected)
{
	the_status = pOut;
	if (Inputpin.getStatus() == 1)
		pOut->DrawLEDON(m_GfxInfo,selected);
	else
		pOut->DrawLEDOFF(m_GfxInfo,selected);
	
	DrawLabel(pOut);

}

int LED::GetOutPinStatus()
{
	return Inputpin.getStatus();
}
int LED::getm_Inputs()
{
	return  0;
}
void LED::save(string& thenameofthecirciut)
{

	ofstream the_added_component;
	the_added_component.open(thenameofthecirciut, ios::app);
	the_added_component << "LED   " << "     " << id << "     " << get_mlabel() << "     " << m_GfxInfo.x1 << "     " << m_GfxInfo.y1 << endl;
	the_added_component.close();
}
void LED::load(int x, int y, string label, int u)
{
	m_GfxInfo.x1 = x;
	m_GfxInfo.x2 = x + 50;
	m_GfxInfo.y1 = y;
	m_GfxInfo.y2 = y + 50;
	Setmlabel(label);
	id = u;
}
InputPin* LED::getinputpin()
{
	return (&Inputpin);
}

int LED::getNotAssignedLeds()
{
	return NotAssigendLeds;
}

LED::~LED()
{
	NotAssigendLeds--;
}
void LED::ResetPins()
{
	if (Inputpin.getStatus() != NOTASSIGNED)
	{
		NotAssigendLeds++;
		AssignCheck = 0;
	}
	Inputpin.setStatus(NOTASSIGNED);

}