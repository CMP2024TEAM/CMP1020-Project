#include "Operate.h"
Operate::Operate(ApplicationManager* pApp, ActionType action) :Action(pApp)
{
	Execute(action);
}
void Operate::ReadActionParameters()
{
	return;
}

//Execute action (code depends on action type)
void Operate::Execute(ActionType action)
{
	return;

}
void Operate::Execute()// not to be virtual
{
	bool test = true;
	int n;
	Switch* sw;
	Connection** co;
	n = sw->getoutputpin()->getNumConnections();
	co = sw->getoutputpin()->getConnections();
	Component** p = new Component * [n];
	do
	{
		for (int i = 0; i < n; i++)
		{
			co[i]->Operate();
			p[i] = co[i]->getDestPin()->getComponent();

		}
		for (int i = 0; i < n; i++)
		{
			p[i]->Operate();
			Gate* g = dynamic_cast<Gate*>(p[i]);

			if (g == NULL)
			{
				test = 0; break;
			}

			co = g->getoutputpin()->getConnections();
			n = g->getoutputpin()->getNumConnections();
			for (int i = 0; i < n; i++)
			{
				co[i]->Operate();
				p[i] = co[i]->getDestPin()->getComponent();

			}
		}
	} while (test);

}
//To undo this action (code depends on action type)
void Operate::Undo()
{
	return;
}
//To redo this action (code depends on action type)
void Operate::Redo()
{
	return;
}
Operate :: ~Operate(void)
{
	return;
}