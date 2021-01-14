#include "StartStopSimulation.h"
StartStopSimulation::StartStopSimulation(ApplicationManager* pApp, ActionType action) :Action(pApp)
{
	Execute(action);
}
void StartStopSimulation::ReadActionParameters()
{
	return;
}

//Execute action (code depends on action type)
void StartStopSimulation::Execute(ActionType action)
{
	Output* pOut = pManager->GetOutput();
	if (action == SIM_MODE)
	{
		pOut->CreateSimulationToolBar();
		pOut->PrintMsg("Switching to Simulation Mode");
		pManager->SetSelectedComponent(NULL);
	}
	if (action == DSN_MODE)
	{
		pOut->CreateDesignToolBar();
		pOut->PrintMsg("Switching to Design Mode");
		pManager->ResetAllComponents();
	}


}
void StartStopSimulation::Execute()// not to be virtual
{
	return;

}
//To undo this action (code depends on action type)
void StartStopSimulation::Undo()
{
	return;
}
//To redo this action (code depends on action type)
void StartStopSimulation::Redo()
{
	return;
}
StartStopSimulation:: ~StartStopSimulation(void)
{
	return;
}