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
}

int LED::GetOutPinStatus()
{
	return 0;
}
