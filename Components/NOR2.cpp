#include"NOR2.h"
#include<fstream>
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
	if (GetInputPinStatus(1) == LOW && GetInputPinStatus(2) == LOW)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}
/////////////////Draw Function////////////////////////
void NOR2::Draw(Output* pOut,bool selected)
{
	pOut->DrawNOR2(m_GfxInfo,selected);
	DrawLabel(pOut);
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
void NOR2::save()
{
	
	ofstream the_added_component;
	the_added_component.open("file format.txt", ios::app);
	the_added_component << endl << "NOR2  " << "     " << id << "     " << get_mlabel() << "     " << m_GfxInfo.x1 << "     " << m_GfxInfo.y1 << endl;
	the_added_component.close();
}
///////////////setinputpinstatus////////////////////
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

int NOR2::getm_Inputs()
{
	return  m_Inputs;
}