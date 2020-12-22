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