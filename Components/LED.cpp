#include "LED.h"

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

void LED::Draw(Output* pOut)
{
	if (the_output.getStatus() == 1)
		pOut->DrawLEDON(m_GfxInfo);
	else
		pOut->DrawLEDOFF(m_GfxInfo);
}

int LED::GetOutPinStatus()
{
	return 0;
}
int LED::getm_Inputs()
{
	return  0;
}
InputPin* LED::getinputpin(int n)
{
	return (&the_output);
}