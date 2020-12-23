#include"BUFFER.H"

BUFFER::BUFFER(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void BUFFER::Operate()
{//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	if (m_InputPins->getStatus() == HIGH)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);

}

void BUFFER::Draw(Output* pOut)
{
	pOut->Draw_BUFFER(m_GfxInfo);
}

int BUFFER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();

}

int BUFFER::GetInputPinStatus()
{
	return m_InputPins->getStatus();	//n starts from 1 but array index starts from 0.
}

void BUFFER::setInputPinStatus(STATUS s)
{
	m_InputPins->setStatus(s);
}
