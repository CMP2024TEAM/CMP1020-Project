#include "GetClickedComponent.h"
#include "..\ApplicationManager.h"
GetClickedComponent::GetClickedComponent(ApplicationManager* pApp) :Action(pApp)
{
}

GetClickedComponent::~GetClickedComponent(void)
{
}
void GetClickedComponent::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click On a Component To Select it");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}
void GetClickedComponent::Execute()
{
	Component** AllComponents;
	int ComponentCount;
	pManager->GetComponentList(AllComponents, ComponentCount);
	if (ComponentCount == 0)
	{
		Output* pOut = pManager->GetOutput();

		pOut->PrintMsg("NO Components Added To Select it");

		return;
	}
	while (true)
	{
		ReadActionParameters();
		for (int i = 0; i < ComponentCount; i++)
		{
			GraphicsInfo GfxInfo = AllComponents[i]->GetLocation();
			if (Cx > GfxInfo.x1 && Cx< GfxInfo.x2 && Cy > GfxInfo.y1 && Cy < GfxInfo.y2)
			{
				ClickedComponent = AllComponents[i];
				Gate* gate = dynamic_cast<Gate*>(AllComponents[i]);
				if (gate != NULL)
				{
					IsGate = true;
				}
				else
				{
					IsGate = false;
				}
				return;
			}
		}
	}
}
void GetClickedComponent::GetComponent(Component* &Pcom, bool &isgate)
{
	Pcom = ClickedComponent;
	isgate = IsGate;
}

void GetClickedComponent::Undo()
{}

void GetClickedComponent::Redo()
{}
