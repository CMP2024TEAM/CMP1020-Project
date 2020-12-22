#pragma once
#include "..\Defs.h"
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output(); // Performs the Window Initialization
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;
	void CreateCommonToolBar()const;        // tool bar
	void CreateDesignToolBar(ActionType= Page_One) const;	//Tool bar of the design mode
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar
	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area

	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window

	

	// Draws 2-input AND gate
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	///TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc
	void DrawNAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Draw_BUFFER(GraphicsInfo r_GfxInfo, bool selected = false)const;
	void Draw_XOR2(GraphicsInfo r_GfxInfo, bool selected = false)const;
	void Draw_XNOR2(GraphicsInfo r_GfxInfo, bool selected = false)const;
	void DrawOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawLEDOFF(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawLEDON(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawSWITCHON(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawSWITCHOFF(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOT(GraphicsInfo r_GfxInfo, bool selected=false) const;
	
	// Draws Connection
	void DrawConnection(GraphicsInfo r_GfxInfo, bool selected = false) const;
	
	void PrintMsg(string msg) const;	//Print a message on Status bar
	void Print(string msg, GraphicsInfo r_GfxInfo) const; //Print a message on a certain place in window

	~Output();
};
