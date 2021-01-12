#include "load.h"
#include<fstream>
#include<iostream>
#include "..\ApplicationManager.h"
#include"..\Components\AND2.h"
#include"..\Components\AND3.h"
#include"..\Components\BUFFER.H"
#include"..\Components\XOR3.h"
#include"..\Components\XOR2.h"
#include"..\Components\XNOR2.h"
#include"..\Components\Switch.h"
#include"..\Components\OR2.h"
#include"..\Components\NOT.h"
#include"..\Components\NOR3.h"
#include"..\Components\NOR2.h"
#include"..\Components\NAND2.h"
#include"..\Components\LED.h"
#include"..\Components\Connection.h"
load::load(ApplicationManager* pApp) :Action(pApp)
{
}

void load::ReadActionParameters()
{
}

void load::Execute()
{
	int TheRealId, x, y;
	string TheName;
	string the_label = "";
	string label = "";
	string id = "";
	string xin = "";
	string yin = "";
	Output* pOut = pManager->GetOutput();
	ifstream the_added_component;
	string thecircuit, thefile, s;
	Input* thegetter = pManager->GetInput();
	pOut->PrintMsg("Enter the name of the circiut that you want to load it");
	thecircuit = thegetter->GetSrting(pOut);
	s = ".txt";
	thefile = thecircuit + s;
	the_added_component.open(thefile);
	if (!the_added_component.is_open())
	{
		pOut->PrintMsg("the circuit is not found please click on the load and enter the correct name");

	}
	pOut->PrintMsg("the circiut is loaded");
	int thenumofcomp;
	the_added_component >> thenumofcomp;
	getline(the_added_component, TheName);
	getline(the_added_component, TheName);
	Component* TheLoadedComponent[200];
	for (int i = 0; i < thenumofcomp; i++)
	{

		int j = 0;
		for (; j < TheName.length(); j++)
		{
			if (TheName[j] == ' ')
			{
				break;
			}
			the_label += TheName[j];
		}
		j++;
		for (; j < TheName.length(); j++)
		{
			if (TheName[j] == ' ')
				continue;
			else break;
		}
		for (; j < TheName.length(); j++)
		{
			if (TheName[j] == ' ')
			{
				break;
			}
			id += TheName[j];
		}
		j++;
		int r = 0;
		for (; j < TheName.length(); j++)
		{
			if (TheName[j] == ' ' && r < 5)
			{
				r++;
				continue;
			}
			else break;
		}
		for (; j < TheName.length(); j++)
		{
			if (TheName[j] == ' ')
			{
				break;
			}
			label += TheName[j];
		}
		j++;
		for (; j < TheName.length(); j++)
		{
			if (TheName[j] == ' ')
				continue;
			else break;
		}
		for (; j < TheName.length(); j++)
		{
			if (TheName[j] == ' ')
			{
				break;
			}
			xin += TheName[j];
		}
		j++;
		for (; j < TheName.length(); j++)
		{
			if (TheName[j] == ' ')
				continue;
			else break;
		}
		for (; j < TheName.length(); j++)
		{
			if (TheName[j] == ' ')
			{
				break;
			}
			yin += TheName[j];
		}
		TheRealId = stoi(id);
		x = stoi(xin);
		y = stoi(yin);

		GraphicsInfo r_GfxInfo;

		if (the_label == "AND2")
		{
			TheLoadedComponent[i] = new AND2(r_GfxInfo, AND2_FANOUT);
			TheLoadedComponent[i]->load(x, y, label, TheRealId);

		}
		if (the_label == "AND3")
		{
			TheLoadedComponent[i] = new AND3(r_GfxInfo, AND2_FANOUT);
			TheLoadedComponent[i]->load(x, y, label, TheRealId);

		}
		if (the_label == "BUFFER")
		{
			TheLoadedComponent[i] = new BUFFER(r_GfxInfo, BUFFER_FANOUT);
			TheLoadedComponent[i]->load(x, y, label, TheRealId);

		}
		if (the_label == "LED")
		{
			TheLoadedComponent[i] = new LED(r_GfxInfo);
			TheLoadedComponent[i]->load(x, y, label, TheRealId);
			LED* ld = dynamic_cast<LED*>(TheLoadedComponent[i]);
			pManager->AddLeds(ld);
		}
		if (the_label == "NAND2")
		{
			TheLoadedComponent[i] = new NAND2(r_GfxInfo, AND2_FANOUT);
			TheLoadedComponent[i]->load(x, y, label, TheRealId);

		}
		if (the_label == "NOR2")
		{
			TheLoadedComponent[i] = new NOR2(r_GfxInfo, AND2_FANOUT);
			TheLoadedComponent[i]->load(x, y, label, TheRealId);

		}
		if (the_label == "NOR3")
		{
			TheLoadedComponent[i] = new NOR3(r_GfxInfo, AND2_FANOUT);
			TheLoadedComponent[i]->load(x, y, label, TheRealId);

		}
		if (the_label == "NOT")
		{
			TheLoadedComponent[i] = new NOT(r_GfxInfo, AND2_FANOUT);
			TheLoadedComponent[i]->load(x, y, label, TheRealId);

		}
		if (the_label == "OR2")
		{
			TheLoadedComponent[i] = new OR2(r_GfxInfo, AND2_FANOUT);
			TheLoadedComponent[i]->load(x, y, label, TheRealId);

		}
		if (the_label == "Switch")
		{
			TheLoadedComponent[i] = new Switch(r_GfxInfo);
			TheLoadedComponent[i]->load(x, y, label, TheRealId);
			Switch* sw = dynamic_cast<Switch*>(TheLoadedComponent[i]);
			pManager->Addswitch(sw);
		}
		if (the_label == "XNOR2")
		{
			TheLoadedComponent[i] = new XNOR2(r_GfxInfo, AND2_FANOUT);
			TheLoadedComponent[i]->load(x, y, label, TheRealId);
		}
		if (the_label == "XOR2")
		{
			TheLoadedComponent[i] = new XOR2(r_GfxInfo, AND2_FANOUT);
			TheLoadedComponent[i]->load(x, y, label, TheRealId);
		}
		if (the_label == "XOR3")
		{
			TheLoadedComponent[i] = new XOR3(r_GfxInfo, AND2_FANOUT);
			TheLoadedComponent[i]->load(x, y, label, TheRealId);
		}
		pManager->AddComponent(TheLoadedComponent[i]);
		TheName = "";
		the_label = "";
		label = "";
		id = "";
		xin = "";
		yin = "";
		getline(the_added_component, TheName);
	}
	id = "";
	xin = "";
	yin = "";
	if (TheName == "the connections")
	{
		getline(the_added_component, TheName);
		while (!(TheName == "-1"))
		{
			int j = 0;

			for (; j < TheName.length(); j++)
			{
				if (TheName[j] == ' ')
				{
					break;
				}
				xin += TheName[j];
			}
			j++;
			int r = 0;
			for (; j < TheName.length(); j++)
			{
				if (TheName[j] == ' ' && r < 5)
				{
					r++;
					continue;
				}
				else break;
			}
			for (; j < TheName.length(); j++)
			{
				if (TheName[j] == ' ')
				{
					break;
				}
				yin += TheName[j];
			}
			j++;
			r = 0;
			for (; j < TheName.length(); j++)
			{
				if (TheName[j] == ' ' && r < 5)
				{
					r++;
					continue;
				}
				else break;
			}
			for (; j < TheName.length(); j++)
			{
				if (TheName[j] == ' ')
				{
					break;
				}
				id += TheName[j];
			}
			x = stoi(xin);
			y = stoi(yin);
			TheRealId = stoi(id);
			Component* thesource;
			Component* thedissource;
			for (int i = 0; i < thenumofcomp; i++)
			{
				if (x == TheLoadedComponent[i]->getid())
					thesource = TheLoadedComponent[i];
				if (y == TheLoadedComponent[i]->getid())
					thedissource = TheLoadedComponent[i];
			}
			GraphicsInfo TheLocation;
			Connection* theaddedconnection;
			int n = thedissource->getm_Inputs();
			Switch* TheaddedSwitch = dynamic_cast<Switch*>(thesource);
			
				if (TheaddedSwitch != NULL)
				{
					
					LED* thedis = dynamic_cast<LED*>(thedissource);
					if (thedis != NULL)
						theaddedconnection = new Connection(TheLocation, (TheaddedSwitch)->getoutputpin(), (thedis)->getinputpin());
					else
					{
						theaddedconnection = new Connection(TheLocation, (TheaddedSwitch)->getoutputpin(), ((Gate*)thedissource)->getinputpin(TheRealId));
					}
					((TheaddedSwitch)->getoutputpin()->ConnectTo(theaddedconnection));
				}
				else
				{
					LED* thedis = dynamic_cast<LED*>(thedissource);
					if (thedis != NULL)
						theaddedconnection = new Connection(TheLocation, ((Gate*)thesource)->getoutputpin(), (thedis)->getinputpin());
					else
						theaddedconnection = new Connection(TheLocation, ((Gate*)thesource)->getoutputpin(), ((Gate*)thedissource)->getinputpin(TheRealId));
					(((Gate*)thesource)->getoutputpin()->ConnectTo(theaddedconnection));
				}

			
			
			
			theaddedconnection->setDestCmpnt(thedissource, n /*number of inputs*/, TheRealId /*pin number*/);
			theaddedconnection->setSourceCmpnt(thesource);


			theaddedconnection->load(thesource, thedissource, pManager->GetOutput(), TheRealId, TheLocation);
			pManager->AddComponent(theaddedconnection);
			id = "";
			xin = "";
			yin = "";
			getline(the_added_component, TheName);
		}

	}
	the_added_component.close();
}

void load::Undo()
{
}

void load::Redo()
{
}
