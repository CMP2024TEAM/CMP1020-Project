#include "InputPin.h"
#include"Connection.h"
InputPin::InputPin()
{
	Conn = NULL;
}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}
void InputPin::SetConnection(Connection* C)
{
	Conn = C;
}
Connection* InputPin::GetConnection()
{
	return Conn;
}