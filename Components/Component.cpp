#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}

void Component::save(int y)
{
}

GraphicsInfo Component::GetLocation()
{
	return m_GfxInfo;
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
{}

Component::~Component()
{}

