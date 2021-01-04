#pragma once
#include "component.h"
#include "InputPin.h"
#include "OutputPin.h"
#include"Gate.h"
class Connection :	public Component
{
	Component*	SrcCmpnt;	//Connection source component
	Component*	DstCmpnt;	//Connection Destination component
	int		DstPinNum;		//The Input pin to which this connection is linked
	int		DstPins;		//the number of inputpins  of dstination
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
	int static TheNumberOfconnection;
public:
	//Connection(const GraphicsInfo &r_GfxInfo, Component *pS=NULL,Component *pD=NULL, int Pin=0);
	Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin);
	~Connection();
	virtual void Operate() ;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut,bool selected);	//for each component to Draw itself
	int GetTheNumberOfconnection();
	
	void setSourcePin(OutputPin *pSrcPin);
	void setSourceCmpnt(Component* pSrcCmpnt);
	void setDestPin(InputPin *pDstPin);
	void setDestCmpnt(Component* pDstCmpnt,int n,int j);
	OutputPin* getSourcePin();
	InputPin* getDestPin();
	virtual int getm_Inputs();
	void save();

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	//virtual bool IsInsideMe(int, int);

};
