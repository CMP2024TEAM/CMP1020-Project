#include "ApplicationManager.h"
#include "Actions/AddANDgate2.h"
#include "Actions/AddBUFFERgate.h"
#include "Actions/AddNANDgate2.h"
#include "Actions/AddNORgate2.h"
#include "Actions/AddORgate2.h"
#include "Actions/AddXNORgate2.h"
#include "Actions/AddXORgate2.h"
#include "Actions/AddNOTgate.h"
#include "Actions/AddANDgate3.h"
#include "Actions/AddNORgate3.h"
#include "Actions/AddXORgate3.h"
#include "Actions/StartStopSimulation.h"
#include "Actions/Arrows.h"
#include "Actions/AddConnection.h"
#include "Actions/AddLED.h"
#include "Actions/Add_Switch.h"
#include "Actions/Select.h"
#include "Actions/Delete.h"
#include "Actions/Copy.h"
#include "Actions/Cut.h"
#include "Actions/Move.h"
#include "Actions/AddLabel.h"
#include "Actions/load.h"
#include <string>
#include "Actions/Edit.h"
#include "Actions/EditConnection.h"
#include <iostream>
#include <fstream>
#include "Actions/Operate.h"
#include "Actions/TruthTable.h"
#include "Actions/CircuitProping.h"
using namespace std;
ApplicationManager::ApplicationManager()
{
	Clipboard = NULL;
	CompCount = 0;
	RemCompCount = 0;
	for (int i = 0; i < MaxCompCount; i++)
		RemComp[i] = NULL;

	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
	Selected_Comp = NULL;
	NumSwitches = 0;
	NumLeds = 0;
}
void ApplicationManager::set_clipboard(Component* object)
{
	Clipboard = object;
}
Component* ApplicationManager::get_clipboard()
{
	return Clipboard;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
	Selected_Comp = pComp;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction();
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;
	case ADD_AND_GATE_3:
		pAct = new AddANDgate3(this);
		break;
	case ADD_NOR_GATE_3:
		pAct = new AddNORgate3(this);
		break;
	case ADD_XOR_GATE_3:
		pAct = new AddXORgate3(this);
		break;
	case ADD_NAND_GATE_2:
		pAct = new AddNANDgate2(this);
		break;
	case ADD_OR_GATE_2:
		pAct = new AddORgate2(this);
		break;
	case ADD_XNOR_GATE_2:
		pAct = new AddXNORgate2(this);
		break;
	case ADD_XOR_GATE_2:
		pAct = new AddXORgate2(this);
		break;
	case ADD_NOR_GATE_2:
		pAct = new AddNORgate2(this);
		break;
	case ADD_Buff:
		pAct = new AddBUFFERgate(this);
		break;
	case ADD_INV:
		pAct = new AddNOTgate(this);
		break;
	case ADD_LED:
		pAct = new AddLED(this);
		break;
	case ADD_Switch:
		pAct = new Add_Switch(this);
		break;
	case DSN_MODE:
		pAct = new StartStopSimulation(this, DSN_MODE);
		break;
	case SIM_MODE:
		pAct = new StartStopSimulation(this, SIM_MODE);
		break;
	case DEL:
		pAct = new Delete(this, Selected_Comp);
		break;
	case Page_One:
		pAct = new Arrows(this, Page_One);
		break;
	case Page_Two:
		pAct = new Arrows(this, Page_Two);
		break;
	case ADD_CONNECTION:
		pAct = new AddConnection(this);
		break;
	case SELECT:
		if (UI.AppMode == DESIGN)
		{
			pAct = new Select(this);
			break;
		}
		else if (UI.AppMode == SIMULATION)
		{
			pAct = new Operate(this);
			break;
		}
	case Create_TruthTable:
		if (UI.AppMode == DESIGN)
			OutputInterface->PrintMsg("Activate The simulation Mode to create the truth table");
		else if (UI.AppMode == SIMULATION)
		{
			pAct = new TruthTable(NumLeds, NumSwitches, ListOfSwitches, ListOfLeds,this);
		}
		break;
	case START_SELECT:
		OutputInterface->PrintMsg("Start Select");
		break;
	case MOVE:
		pAct = new Move(this, Selected_Comp);
		break;
	case ADD_Label:
		pAct = new AddLabel(this, Selected_Comp);
		break;
	case UNDO:
		this->Undo();
		break;
	case SAVE:
		pAct = new Save(this);
		break;
	case LOAD:
		pAct = new load(this);
		break;
	case REDO:
		this->Redo();
		break;
	case COPY:
		pAct = new Copy(this, Selected_Comp);
		break;
	case PASTE:
		pAct = new Past(this);
		break;
	case CUT:
		pAct = new cut(this, Selected_Comp);
		break;
	case EDIT:
		pAct = new Edit(this, Selected_Comp);
		break;
	case EDITCONNECTION:
		pAct = new EditConnection(this, Selected_Comp);
		break;
	case Circuit_Proping:
		pAct = new CircuitProping(this);
		break;
	case DELETEALL:
		DeleteAll();
		break;
	case EXIT:
		///TODO: create ExitAction here
		break;
	}
	if (pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}

}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AppOperate() 
{
	for (int i = 0; i < CompCount; i++)
	{
		for (int i = 0; i < CompCount; i++)
		{
			CompList[i]->Operate();
		}
	}
}
void ApplicationManager::UpdateInterface()
{
	/*delete OutputInterface;
OutputInterface = new Output;*/
	OutputInterface->ClearDrawingArea();
//SIMULATION
	if (UI.AppMode == SIMULATION)
	{
		AppOperate();
		if ((LED::getNotAssignedLeds() != 0 || Gate::getNotAssignedGates() != 0))
			OutputInterface->PrintMsg("Please Check your Connections!");
	}
	for (int i = 0; i < CompCount; i++)
	{
		bool selected = 0;
		if (CompList[i] == Selected_Comp)
			selected = 1;
		CompList[i]->Draw(OutputInterface, selected);
	}
}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteComponent(Component* pComp)
{
	
	for (int j = 0; j < CompCount; j++)
	{
		if (pComp == CompList[j])
		{
			Switch* sw = dynamic_cast<Switch*>(CompList[j]);
			if (sw)
			{
				for(int i=0;i<NumSwitches;i++)
					if (sw == ListOfSwitches[i])
					{
						ListOfSwitches[i] = ListOfSwitches[NumSwitches-1];
						ListOfSwitches[NumSwitches--] = NULL;
					}
			}
			LED* ld = dynamic_cast<LED*>(CompList[j]);
			if (ld)
			{
				for (int i = 0; i < NumLeds; i++)
					if (ld == ListOfLeds[i])
					{
						ListOfLeds[i] = ListOfLeds[NumLeds-1];
						ListOfSwitches[NumLeds--] = NULL;
					}
			}
			//RemComp[RemCompCount++] = CompList[j];
			CompList[j] = NULL;
			CompList[j] = CompList[CompCount - 1];
			delete pComp;
			CompList[CompCount - 1] = NULL;
			CompCount--;

		}
	}
	UpdateInterface();
}
void ApplicationManager::Undo()
{
	this->DeleteComponent(CompList[CompCount - 1]);

}
void ApplicationManager::Redo()
{
	this->AddComponent(RemComp[RemCompCount - 1]);
	RemComp[RemCompCount--] = NULL;
}
int ApplicationManager::get_compcount()
{
	return CompCount;
}

void ApplicationManager::save(string& thenameofthecirciut)
{
	int thenumofconnections = 0;
	for (int i = 0; i < CompCount; i++)
	{
		Connection* theconnector = dynamic_cast<Connection*>(CompList[i]);
		if (theconnector != NULL)
		{
			thenumofconnections = theconnector->GetTheNumberOfconnection();
			break;
		}
	}
	int TheNumberOfcomponents = (CompCount - thenumofconnections);
	ofstream file;
	file.open(thenameofthecirciut,ios::app);
	file << TheNumberOfcomponents << endl ;
	file.close();
	for (int i = 0; i < CompCount; i++)
	{
		Connection* Theconnector = dynamic_cast<Connection*>(CompList[i]);
		if (Theconnector == NULL)
			if (CompList[i] != NULL)
				CompList[i]->save(thenameofthecirciut);
	}
	file.open(thenameofthecirciut, ios::app);
	file << "the connections"<<endl;
	file.close();
	for (int i = 0; i < CompCount; i++)
	{
		Connection* Theconnector = dynamic_cast<Connection*>(CompList[i]);
		if (Theconnector != NULL)
			Theconnector->save(thenameofthecirciut);

	}
	file.open(thenameofthecirciut, ios::app);
	file << -1;
	file.close();
}

bool ApplicationManager::CheckCancel(int x, int y)
{
	if (x < 940 && x>900 && y < 380 && y>340)
		return false;
	return true;
}

bool ApplicationManager::CheckWhichComponent(int x, int y, Component*& c)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->IsInsideMe(x, y))
		{
			c = CompList[i];
			return true;
		}
	}
	if (x < 940 && x>900 && y < 380 && y>340)
	{
		return false;

	}
	c = NULL;
	return true;
}
void ApplicationManager::SetSelectedComponent(Component* comp)
{
	Selected_Comp = comp;
}
ApplicationManager::~ApplicationManager()
{
	DeleteAll();
	for (int i = 0; i < RemCompCount; i++)
		delete RemComp[i];
	delete OutputInterface;
	delete InputInterface;

}
void ApplicationManager::Addswitch(Switch* s)
{
	ListOfSwitches[NumSwitches] = s;
	NumSwitches++;
}
void ApplicationManager::AddLeds(LED* l)
{
	ListOfLeds[NumLeds] = l;
	NumLeds++;
}

void ApplicationManager::DeleteAll()
{
	OutputInterface->PrintMsg("Deleted All Components Sucssesfully!");
	for (int i = 0; i < CompCount; i++)
		DeleteComponent(CompList[i]);
	CompCount = 0;
}

void ApplicationManager::ResetAllComponents()
{
	for (int i = 0; i < CompCount; i++)
		CompList[i]->ResetPins();
}
