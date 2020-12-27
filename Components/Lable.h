#pragma once
#include<string>
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
using namespace std;
class Lable
{
private:
	string freelable;
public:
	Lable(string);
	void	setLable(string);//setting and editing
	string  getlable() const;
	virtual int getm_Inputs();

	~Lable();


};

