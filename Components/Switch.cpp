#include "Switch.h"
#include<fstream>
Switch::Switch(const GraphicsInfo& r_GfxInfo) :SrcPin(AND2_FANOUT)
{

	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	SrcPin.setStatus(NOTASSIGNED);
}


void Switch::Operate()
{
	//Not the original Functuanality but added here to decrease the appmanger logic 

	if (UI.AppMode == SIMULATION && SrcPin.getStatus() == NOTASSIGNED)
		SrcPin.setStatus(LOW);
}



// Function Draw
// Draws 2-input AND gate
void Switch::Draw(Output* pOut, bool selected)
{
	//Call output class and pass gate drawing info to it.
	if (SrcPin.getStatus() == LOW || SrcPin.getStatus() == NOTASSIGNED)
	{
		pOut->DrawSWITCHON(m_GfxInfo, selected);
	}
	if (SrcPin.getStatus() == HIGH)
	{
		pOut->DrawSWITCHOFF(m_GfxInfo, selected);
	}
	DrawLabel(pOut);
}

void Switch::save(string& thenameofthecirciut)
{

	ofstream the_added_component;
	the_added_component.open(thenameofthecirciut, ios::app);
	the_added_component << "Switch" << "     " << id << "     " << get_mlabel() << "     " << m_GfxInfo.x1 << "     " << m_GfxInfo.y1 << "     " << endl;
	the_added_component.close();
}

void Switch::load(int x, int y, string label, int u)
{
	m_GfxInfo.x1 = x;
	m_GfxInfo.x2 = x + 50;
	m_GfxInfo.y1 = y;
	m_GfxInfo.y2 = y + 50;
	Setmlabel(label);
	id = u;
}

//returns status of outputpin
int Switch::GetOutPinStatus()
{
	return SrcPin.getStatus();
}
void Switch::DrawLabel(Output* pOut)
{
	if (this->GetLabel() != "")
	{
		GraphicsInfo GI;
		GI.x1 = m_GfxInfo.x1 + 5;
		GI.y1 = m_GfxInfo.y2 - 5;
		pOut->Print(this->GetLabel(), GI);
	}
}

//returns status of Inputpin #n
int Switch::GetInputPinStatus(int n)
{
	return -1;	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Switch::setInputPinStatus(int n, STATUS s)
{
	return;
}
int Switch::getm_Inputs()
{
	return  0;
}
OutputPin* Switch::getoutputpin()
{
	return (&SrcPin);
}

void Switch::OperateSwitch()
{
	//The Functuanality of th e Switch
	//a Click on a switch is Execute

	if (SrcPin.getStatus() == LOW)
		SrcPin.setStatus(HIGH);
	else
		SrcPin.setStatus(LOW);
	return;
}

void Switch::SetStatus(STATUS s)
{
	SrcPin.setStatus(s);
}
void Switch::ResetPins()
{
	SrcPin.setStatus(NOTASSIGNED);
}