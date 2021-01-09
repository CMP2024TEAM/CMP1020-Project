#include"BUFFER.H"
#include<fstream>
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

void BUFFER::Draw(Output* pOut,bool selected)
{
	pOut->Draw_BUFFER(m_GfxInfo,selected);
	DrawLabel(pOut);
}

int BUFFER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();

}

int BUFFER::GetInputPinStatus(int n)
{
	return m_InputPins->getStatus();	//n starts from 1 but array index starts from 0.
}

void BUFFER::save()
{
	
	ofstream the_added_component;
	the_added_component.open("file format.txt", ios::app);
	the_added_component << "BUFFER" << "     " << id << "     " << get_mlabel() << "     " << m_GfxInfo.x1 << "     " << m_GfxInfo.y1 << endl;
	the_added_component.close();
}



void BUFFER::setInputPinStatus(int n ,STATUS s)
{
	m_InputPins->setStatus(s);
}
int BUFFER::getm_Inputs()
{
	return  m_Inputs;
}

void BUFFER::load(int x, int y, string label, int u)
{
	m_GfxInfo.x1 = x;
	m_GfxInfo.y1 = y;
	Setmlabel(label);
	id = u;
}
