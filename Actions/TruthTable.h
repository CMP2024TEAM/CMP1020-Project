#pragma once
#include"Action.h"
#include<string>
#include"..\Components/LED.h"
#include"..\Components/Switch.h"
class TruthTable:public Action
{
public:
	TruthTable(int, int,Switch**,LED**,ApplicationManager*);
	void FillTheTable();
	void Execute();
	~TruthTable();
	Switch** ListSwitches;
	LED** ListLeds;
	void ReadActionParameters();
	void Redo();
	void Undo();
private:
	STATUS** Table;
	int Leds;
	int Switches;
	STATUS** Results;
	char* N_Leds;
	window* tWind;
};