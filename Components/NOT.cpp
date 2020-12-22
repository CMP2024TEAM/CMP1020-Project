#include "NOT.h"
NOT::NOT(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOT::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	if (m_InputPins[0].getStatus() == HIGH)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);

}


// Function Draw
// Draws 2-input AND gate
void NOT::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOT(m_GfxInfo);
}

//returns status of outputpin
int NOT::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOT::GetInputPinStatus()
{
	return m_InputPins[0].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOT::setInputPinStatus( STATUS s)
{
	m_InputPins[0].setStatus(s);
}
