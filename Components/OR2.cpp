#include"OR2.h"
#include<fstream>
/*class OR2
represent the 2 input OR2 gate
*/
/// ////////////////Constructor///////////////////////////

OR2::OR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}
/// //////////////Operate////////////////////////////
void OR2::Operate()
{
	if ((m_InputPins[0].getStatus() != NOTASSIGNED) && (m_InputPins[1].getStatus() != NOTASSIGNED))
	{
		if (GetInputPinStatus(1) == LOW && GetInputPinStatus(2) == LOW)
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
void OR2::Draw(Output* pOut, bool selected)
{
	pOut->DrawOR2(m_GfxInfo, selected);
	DrawLabel(pOut);
}
void OR2::save(string& thenameofthecirciut)
{


	ofstream the_added_component;
	the_added_component.open(thenameofthecirciut, ios::app);
	the_added_component << "OR2   " << "     " << id << "     " << get_mlabel() << "     " << m_GfxInfo.x1 << "     " << m_GfxInfo.y1 << endl;
	the_added_component.close();
}
void OR2::load(int x, int y, string label, int u)
{
	m_GfxInfo.x1 = x;
	m_GfxInfo.x2 = x+50;
	m_GfxInfo.y1 = y;
	m_GfxInfo.y2 = y+50;
	Setmlabel(label);
	id = u;
}
/////////////////GEToutpinstatus////////////////////////
int OR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}
/////////////////GETinputStatus/////////////////////
int OR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}
///////////////setinputpinstatus////////////////////
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
int OR2::getm_Inputs()
{
	return  m_Inputs;
}
void OR2::ResetPins()
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