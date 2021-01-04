#include"NAND2.h"
#include<fstream>


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
void NAND2::Draw(Output* pOut,bool selected)
{
	pOut->DrawNAND2(m_GfxInfo,selected);
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
void NAND2::save()
{
	double cx, cy;
	cx = (m_GfxInfo.x1 + m_GfxInfo.x2) / 2.0;
	cy = (m_GfxInfo.y1 + m_GfxInfo.y2) / 2.0;
	ofstream the_added_component;
	the_added_component.open("file format.txt", ios::app);
	the_added_component << endl << "NAND2 " << "     " << id << "     " << get_mlabel() << "     " << cx << "     " << cy << endl;
	the_added_component.close();
}
///////////////setinputpinstatus////////////////////
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

int NAND2::getm_Inputs()
{
	return  m_Inputs;
}