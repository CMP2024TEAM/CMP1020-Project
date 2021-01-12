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
	if ((m_InputPins[0].getStatus() != NOTASSIGNED) && (m_InputPins[1].getStatus() != NOTASSIGNED))
	{
		if (GetInputPinStatus(1) == LOW && GetInputPinStatus(2) == LOW)
			m_OutputPin.setStatus(HIGH);
		else
			m_OutputPin.setStatus(LOW);
		AssignCheck++;
		//Decreases NotAssigned Gates
		if (AssignCheck == 1)
			NotAssignedGates--;
	}
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
void NOR2::save(string& thenameofthecirciut)
{
	
	ofstream the_added_component;
	the_added_component.open(thenameofthecirciut, ios::app);
	the_added_component << "NOR2  " << "     " << id << "     " << get_mlabel() << "     " << m_GfxInfo.x1 << "     " << m_GfxInfo.y1 << endl;
	the_added_component.close();
}
void NOR2::load(int x, int y, string label, int u)
{
	m_GfxInfo.x1 = x;
	m_GfxInfo.x2 = x + 50;
	m_GfxInfo.y1 = y;
	m_GfxInfo.y2 = y + 50;
	Setmlabel(label);
	id = u;
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
void NOR2::ResetPins()
{
	if (m_OutputPin.getStatus() != NOTASSIGNED)
	{
		NotAssignedGates++;
		AssignCheck = 0;
	}
	m_InputPins[0].setStatus(NOTASSIGNED);
	m_InputPins[1].setStatus(NOTASSIGNED);
	m_OutputPin.setStatus(NOTASSIGNED);
}