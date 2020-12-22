#include"NOR2.h"

/*class NOR2
represent the 2 input NOR2 gate
*/
/// ////////////////Constructor///////////////////////////

NOR2::NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}
/// //////////////Operate////////////////////////////
void NOR2::Operate()
{

}
/////////////////Draw Function////////////////////////
void NOR2::Draw(Output* pOut)
{
	pOut->DrawNAND2(m_GfxInfo);
}
/////////////////GEToutpinstatus////////////////////////
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}
/////////////////GETinputStatus/////////////////////
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}
///////////////setinputpinstatus////////////////////
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

