#include "Lable.h"
Lable::Lable(string lb)
{
	setLable(lb);
}
void Lable::setLable(string lb)		//setting and editing
{
	freelable = lb;
}

string Lable ::getlable() const
{
	return freelable;
}
Lable ::~Lable()
{}
int Lable::getm_Inputs()
{
	return  -1;
}