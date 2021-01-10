#include"TruthTable.h"
#include"..\ApplicationManager.h"
#include<sstream>
#include<iostream>
using namespace std;
TruthTable::TruthTable(int leds, int switches,Switch** s,LED** l,ApplicationManager*pApp):Action(pApp)
{
	ListLeds = l;
	ListSwitches = s;
	Leds = leds;
	Switches = switches;
	Results = new STATUS*[Leds];
	N_Leds = new char[Switches];
	Table = new STATUS*[Switches];
	for (int i = 0; i < Switches; i++)
		Table[i] = new STATUS[int(pow(2, Switches))];
	for (int i = 0; i < Leds; i++)
		Results[i] = new STATUS[int(pow(2, Switches))];
	tWind = new window(640, 480, UI.wx, UI.wy);
}
TruthTable::~TruthTable()
{
	for (int i = 0; i < Switches; i++)
		delete Table[i];
	delete Table;
}
void TruthTable::FillTheTable()
{

	for (int i = 0; i < Switches; i++)
	{
		int l = 0;
		for (int j = 0; j < (int(pow(2, Switches)) / int(pow(2, (i + 1)))); j++)
		{
			for (int k = 0; k<int(pow(2, i)); k++)
			{
				Table[i][l] = HIGH;
				l++;
			}
			for (int k = 0; k<int(pow(2, i)); k++)
			{
				Table[i][l] = LOW;
				l++;
			}
		}
	}
}
void TruthTable::Execute()
{
	FillTheTable();
	tWind->SetPen(BLACK, 5);
	for (int i = 0; i<int(pow(2, Switches)); i++)
	{
		for (int j = 0; j < Switches; j++)
		{
			ListSwitches[j]->SetStatus(Table[j][i]);
		}
		pManager->UpdateInterface();
		for (int j = 0; j < Leds; j++)
		{
			Results[j][i] = STATUS(ListLeds[j]->GetOutPinStatus());
		}
	}
	tWind->ChangeTitle("TruthTable");
	for (int i = 0; i < Switches; i++)
		tWind->DrawString(i * 10,10, "Switch");
	for (int i = 0; i < Leds; i++)
		tWind->DrawString((i + Switches) * 10, 10, "Led");
	for (int i = 0; i < Leds; i++)
	{
		stringstream ss;
		string s;
		for (int j = 0; j<int(pow(2, Switches)); j++)
		{
			ss << Results[i][j];
			ss >> s;
			tWind->DrawString((i + 1) * 10, i * 10, s);
		}
	}
	for (int j = 0; j<int(pow(2, Switches)); j++)
	{
		for (int i = 0; i < Switches; i++)
		{
			cout << Table[i][j] << "     ";
		}
		cout << Results[0][j];
		cout << endl;
	}
}
void TruthTable :: ReadActionParameters()
{}
void TruthTable::Redo()
{}
void TruthTable::Undo()
{}
