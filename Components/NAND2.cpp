#include"NAND2.h"


/// ////////////////Constructor///////////////////////////

NAND2::NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}
/// //////////////Operate////////////////////////////
void NAND2::Operate()
{
	m_OutputPin = GetInputPinStatus(1) && GetInputPinStatus(2);
}
/////////////////Draw Function////////////////////////
void NAND2::Draw(Output* pOut)
{
	pOut->DrawNAND2(m_GfxInfo);
}
/////////////////GEToutpinstatus////////////////////////
int NAND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}
/////////////////GETinputStatus/////////////////////
int NAND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}
///////////////setinputpinstatus////////////////////
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

