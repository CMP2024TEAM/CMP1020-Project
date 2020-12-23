#include "XOR2.h"

XOR2::XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
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
	if (input[0] != input[1])
		m_OutputPin.setStatus(HIGH);
	else 
		m_OutputPin.setStatus(LOW);
}

void XOR2::Draw(Output* pOut)
{//Call output class and pass gate drawing info to it.
	pOut->Draw_XOR2(m_GfxInfo);
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
