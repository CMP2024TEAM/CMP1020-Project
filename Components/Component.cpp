#include "Component.h"
int Component::Countofcomp = 0;
Component::Component(const GraphicsInfo &r_GfxInfo)
{
	Countofcomp++;
	id = 0;
	id = Countofcomp;
	m_GfxInfo = r_GfxInfo;
	m_Label = "";
}
GraphicsInfo Component::GetLocation()
{
	return m_GfxInfo;
}
void Component::set_Location(GraphicsInfo the_new)
{
	m_GfxInfo = the_new;
}

void Component::Setmlabel(string thereadingname)
{
	m_Label = thereadingname;
}

string Component::get_mlabel()
{
	return m_Label;
}
bool Component::IsInsideMe(int x, int y)
{
	if (m_GfxInfo.x1 < x && m_GfxInfo.x2 > x && m_GfxInfo.y1 < y && m_GfxInfo.y2 > y)
	{
		return true;
	}
	return false;
}
Component::Component()
{
	Countofcomp++;
	id = 0;
	id = Countofcomp;
}

void Component::ResetPins()
{
}


void Component::Draw(Output* pOut, bool selected)
{
}

void Component::DrawLabel(Output* pOut)
{
	if (m_Label != "") 
	{
		GraphicsInfo GI;
		GI.x1 = m_GfxInfo.x1 + 5;
		GI.y1 = m_GfxInfo.y2;
		pOut->Print(m_Label, GI);
	}
}

void Component::SetId(int TheIdOFThecopy)
{
	id = TheIdOFThecopy;
}

int Component::GetId()
{
	return ++Countofcomp;
}

int Component::getid()
{
	return id;
}

Component::~Component()
{
	Countofcomp--;
}

