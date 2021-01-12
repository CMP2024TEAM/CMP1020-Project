#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	 int id;
	 static int Countofcomp;
public:
	
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut,bool selected=0) ;	//for each component to Draw itself
	virtual void DrawLabel(Output* pOut);
	void SetId(int);
	int GetId();
	int getid();
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1
	string GetLabel();
	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual int getm_Inputs()=0;
	virtual void save(string& thenameofthecirciut)=0 ;
	virtual void load(int x, int y, string label, int u)=0;
	GraphicsInfo GetLocation();
	void set_Location(GraphicsInfo the_new);
	void Setmlabel(string thereadingname);
	void SetLabel(string);
	void SetLocation(GraphicsInfo);
	string get_mlabel();
	virtual bool IsInsideMe(int, int);
	Component();	
	virtual void ResetPins();
	//Destructor must be virtual
	virtual ~Component();
};

#endif
