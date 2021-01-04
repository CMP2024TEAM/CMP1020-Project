#include "LED.h"
#include<fstream>
LED::LED(const GraphicsInfo& r_GfxInfo)
{
	the_output.setStatus(LOW);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void LED::Operate()
{
	if (the_output.getStatus() == 1)
		the_status->DrawLEDON(m_GfxInfo);
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

void LED::Draw(Output* pOut,bool selected)
{
	if (the_output.getStatus() == 1)
		pOut->DrawLEDON(m_GfxInfo,selected);
	else
		pOut->DrawLEDOFF(m_GfxInfo,selected);
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
	double cx, cy;
	cx = (m_GfxInfo.x1 + m_GfxInfo.x2) / 2.0;
	cy = (m_GfxInfo.y1 + m_GfxInfo.y2) / 2.0;
	ofstream the_added_component;
	the_added_component.open("file format.txt", ios::app);
	the_added_component << endl << "LED   " << "     " << id << "     " << get_mlabel() << "     " << cx << "     " << cy << endl;
	the_added_component.close();
}
InputPin* LED::getinputpin()
{
	return (&the_output);
}