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

	if (the_output.getStatus() != NOTASSIGNED)
	{
		AssignCheck++;
		
		if (the_output.getStatus() == 1)
			the_status->DrawLEDON(m_GfxInfo);
		else
			the_status->DrawLEDOFF(m_GfxInfo);
		if (AssignCheck == 1)
			NotAssigendLeds--;
	}
	else
		the_status->DrawLEDOFF(m_GfxInfo);


}

int LED::GetInputPinStatus(int n)
{
	if (the_output.getStatus() == HIGH)
		return 1;
	else
		return 0;
}

void LED::setInputPinStatus(int n, STATUS s)
{
	the_output.setStatus(s);
}

void LED::Draw(Output* pOut, bool selected)
{
	the_status = pOut;
	if (the_output.getStatus() == 1)
		pOut->DrawLEDON(m_GfxInfo,selected);
	else
		pOut->DrawLEDOFF(m_GfxInfo,selected);
	
	DrawLabel(pOut);

}

int LED::GetOutPinStatus()
{
	return 0;
}
int LED::getm_Inputs()
{
	return  0;
}
void LED::save()
{

	ofstream the_added_component;
	the_added_component.open("file format.txt", ios::app);
	the_added_component << "LED   " << "     " << id << "     " << get_mlabel() << "     " << m_GfxInfo.x1 << "     " << m_GfxInfo.y1 << endl;
	the_added_component.close();
}
void LED::load(int x, int y, string label, int u)
{
	m_GfxInfo.x1 = x;
	m_GfxInfo.y1 = y;
	Setmlabel(label);
	id = u;
}
InputPin* LED::getinputpin()
{
	return (&the_output);
}

int LED::getNotAssignedLeds()
{
	return NotAssigendLeds;
}

LED::~LED()
{
	NotAssigendLeds--;
}
