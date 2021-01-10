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
	if ((m_InputPins[0].getStatus() != NOTASSIGNED) && (m_InputPins[1].getStatus() != NOTASSIGNED))
	{
		if (GetInputPinStatus(1) == HIGH && GetInputPinStatus(2) == HIGH)
			m_OutputPin.setStatus(LOW);
		else
			m_OutputPin.setStatus(HIGH);
		AssignCheck++;
		//Decreases NotAssigned Gates
		if (AssignCheck == 1)
			NotAssignedGates--;
	}
}
/////////////////Draw Function////////////////////////
void NAND2::Draw(Output* pOut,bool selected)
{
	pOut->DrawNAND2(m_GfxInfo,selected);
	DrawLabel(pOut);
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
	
	ofstream the_added_component;
	the_added_component.open("file format.txt", ios::app);
	the_added_component<< "NAND2 " << "     " << id << "     " << get_mlabel() << "     " << m_GfxInfo.x1 << "     " << m_GfxInfo.y1 << endl;
	the_added_component.close();
}
void NAND2::load(int x, int y, string label, int u)
{
	m_GfxInfo.x1 = x;
	m_GfxInfo.x2 = x + 50;
	m_GfxInfo.y1 = y;
	m_GfxInfo.y2 = y + 50;
	Setmlabel(label);
	id = u;
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