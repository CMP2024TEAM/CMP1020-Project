#include"TruthTable.h"
#include"..\ApplicationManager.h"
#include<sstream>
#include<iostream>
using namespace std;
TruthTable::TruthTable(int leds, int switches, Switch** s, LED** l, ApplicationManager* pApp) :Action(pApp)
{
	ListLeds = l;
	ListSwitches = s;
	Leds = leds;
	Switches = switches;
	Results = new STATUS * [Leds];
	Table = new STATUS * [Switches];
	for (int i = 0; i < Switches; i++)
		Table[i] = new STATUS[int(pow(2, Switches))];
	for (int i = 0; i < Leds; i++)
		Results[i] = new STATUS[int(pow(2, Switches))];
	tWind = new window((Leds + Switches) * 72, (int(pow(2, Switches)) + 1) * 32, UI.wx, UI.wy);
}
TruthTable::~TruthTable()
{
	for (int i = 0; i < Switches; i++)
		delete Table[i];
	for (int i = 0; i < int(pow(2, Switches)); i++)
		delete Results[i];
	delete[] Results;
	delete[]Table;
	delete tWind;
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
		pManager->AppOperate();
		for (int j = 0; j < Leds; j++)
		{
			Results[j][i] = STATUS(ListLeds[j]->GetOutPinStatus());
		}
	}
	tWind->ChangeTitle("TruthTable");
	tWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	for (int i = 0; i < Switches; i++)
	{
		if (ListSwitches[i]->GetLabel() == "")
		{
			stringstream num;
			num << i;
			string Num;
			num >> Num;
			Num = "Switch" + Num;
			tWind->DrawString(i * 70, 10, Num);
		}
		else
		{
			tWind->DrawString(i * 70, 10, ListSwitches[i]->GetLabel());
		}
	}
	for (int i = 0; i < Leds; i++)
	{
		if (ListLeds[i]->GetLabel() == "")
		{
			stringstream num;
			num << i;
			string Num;
			num >> Num;
			Num = "Led" + Num;
			tWind->DrawString((i+Switches) * 70, 10, Num);
		}
		else
			tWind->DrawString((i + Switches) * 70, 10, ListLeds[i]->GetLabel());
	}
	for (int j = 0; j<int(pow(2, Switches)); j++)
	{

		for (int i = 0; i < Switches; i++)
		{
			stringstream ss;
			string s;
			ss << Table[i][j];
			ss >> s;
			tWind->DrawString(i * 70, (j + 1) * 30, s);
		}
	}
	for (int i = 0; i < Leds; i++)
	{
		for (int j = 0; j<int(pow(2, Switches)); j++)
		{
			stringstream ss;
			string s;
			ss << Results[i][j];
			ss >> s;
			tWind->DrawString((i + Switches) * 70, (j + 1) * 30, s);
		}
	}
	/*for (int j = 0; j<int(pow(2, Switches)); j++)
	{
		for (int i = 0; i < Switches; i++)
		{
			cout << Table[i][j] << "     ";
		}
		cout << Results[0][j];
		cout << endl;
	}*/
}
void TruthTable::ReadActionParameters()
{}
void TruthTable::Redo()
{}
void TruthTable::Undo()
{}
