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
#include"Actions/Select.h"
#include"Actions/Delete.h"
#include"Actions/Copy.h"
#include"Actions/Cut.h"
#include"Actions/Move.h"
#include"Actions/AddLabel.h"
#include"Actions/load.h"
#include<string>
#include"Actions/Edit.h"
#include"Actions/EditConnection.h"
#include<iostream>
#include<fstream>
#include"Actions/Operate.h"
using namespace std;
ApplicationManager::ApplicationManager()
{
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
	}
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

void ApplicationManager::UpdateInterface()
{
	/*delete OutputInterface;
OutputInterface = new Output;*/
	OutputInterface->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++)
	{
		bool selected = 0;
		if (CompList[i] == Selected_Comp)
			selected = 1;
		CompList[i]->Draw(OutputInterface, selected);
	}
	//SIMULATION
	if(UI.AppMode==SIMULATION)
		for (int i = 0; i < CompCount; i++)
			for (int i = 0; i < CompCount; i++)
			{
				Switch* sw = dynamic_cast<Switch*>(CompList[i]);
				if (sw == NULL)
					CompList[i]->Operate();
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
//Delete Component
void ApplicationManager::DeleteComponent(Component* pComp)
{
	/*
	for (int j = 0; j < CompCount; j++)
	{
		if (pComp == CompList[j])
		{
			Component* Temp;
			RemComp[RemCompCount++] = CompList[j];
			CompList[j] = NULL;
			Temp = CompList[j];
			CompList[j] = CompList[CompCount - 1];
			CompList[CompCount - 1] = Temp;
			CompCount--;
		}
	}
	*/
	for (int i = 0; i < CompCount; i++)
	{
		if (pComp == CompList[i])
		{
			delete CompList[i];
			CompList[i] = NULL;
			CompList[i] = CompList[CompCount - 1];
			CompList[CompCount - 1] = NULL;
			CompCount--;

		}
	}
	UpdateInterface();
}
//void ApplicationManager::DeleteAllConnnectionsWithThisInputPin(InputPin* P)
//{
//	for (int i = 0; i < CompCount; i++)
//	{
//		Connection* conn = dynamic_cast<Connection*>(CompList[i]);
//		if (conn != NULL)
//		{
//			if (conn->getDestPin() == P)
//			{
//				delete CompList[i];
//				CompList[i] = NULL;
//				CompList[i] = CompList[CompCount - 1];
//				CompList[CompCount - 1] = NULL;
//				CompCount--;
//				i--;
//			}
//		}
//	}
//}
//void ApplicationManager::DeleteAllConnnectionsWithThisOutputPin(OutputPin* P)
//{
//	for (int i = 0; i < CompCount; i++)
//	{
//		Connection* conn = dynamic_cast<Connection*>(CompList[i]);
//		if (conn != NULL)
//		{
//			if (conn->getSourcePin() == P)
//			{
//				delete CompList[i];
//				CompList[i] = NULL;
//				CompList[i] = CompList[CompCount - 1];
//				CompList[CompCount - 1] = NULL;
//				CompCount--;
//				i--;
//			}
//		}
//	}
//}
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

void ApplicationManager::save()
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
	ofstream the_added_component;
	the_added_component.open("file format.txt",ios::app);
	the_added_component << TheNumberOfcomponents << endl ;
	the_added_component.close();
	for (int i = 0; i < CompCount; i++)
	{
		Connection* Theconnector = dynamic_cast<Connection*>(CompList[i]);
		if (Theconnector == NULL)
			if (CompList[i] != NULL)
				CompList[i]->save();
	}
	the_added_component.open("file format.txt", ios::app);
	the_added_component << endl << "the connections";
	the_added_component.close();
	for (int i = 0; i < CompCount; i++)
	{
		Connection* Theconnector = dynamic_cast<Connection*>(CompList[i]);
		if (Theconnector != NULL)
			Theconnector->save();

	}
	the_added_component.open("file format.txt", ios::app);
	the_added_component << endl << -1;
	the_added_component.close();


}


}
bool ApplicationManager::CheckWhichComponent(int x, int y)
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
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];
	for (int i = 0; i < RemCompCount; i++)
		delete RemComp[i];
	delete OutputInterface;
	delete InputInterface;

}