#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Actions\Save.h"
#include ".\Components\OutputPin.h"
#include ".\Components\InputPin.h"
#include"Components/Switch.h"
#include"Components/LED.h"
//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	int RemCompCount;
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Component* RemComp[MaxCompCount];   //List of recently removed Components
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Component* Clipboard;
	Component* Selected_Comp;
	Switch* ListOfSwitches[200];
	LED* ListOfLeds[200];
	int NumSwitches;
	int NumLeds;
public:


public:	
	ApplicationManager(); //constructor
	void set_clipboard(Component* object);
	Component* get_clipboard();
	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	void DeleteComponent(Component* pComp);
	bool CheckWhichComponent(int, int, Component*&);
	bool CheckWhichComponent(int, int);
	void SetSelectedComponent(Component*);
	//void DeleteAllConnnectionsWithThisInputPin(InputPin* P);
	//void DeleteAllConnnectionsWithThisOutputPin(OutputPin* P);
	void Undo();
	void Redo();
	int get_compcount();
	void save(string& thenameofthecirciut);
	void AppOperate();
	void Addswitch(Switch*);
	void AddLeds(LED*);
	

	//destructor
	~ApplicationManager();
};

#endif