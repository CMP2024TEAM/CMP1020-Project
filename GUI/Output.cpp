#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");
	CreateCommonToolBar();	
	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
	
}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//
window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}

void Output::Print(string msg , GraphicsInfo r_GfxInfo) const
{
	int MsgX = r_GfxInfo.x1;
	int MsgY = r_GfxInfo.y1;

	// Print the Message
	pWind->SetFont(50, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.DrawColor);
	pWind->DrawString(MsgX, MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight,900, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode

void Output::CreateDesignToolBar(ActionType Item) const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	
	//TODO: Prepare image for each menu item and add it to the list
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_NAND2.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_NOR2.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\Menu_XOR2.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\Menu_XNOR2.jpg";
	MenuItemImages[ITM_Buffer] = "images\\Menu\\Menu_Buffer.jpg";
	MenuItemImages[ITM_NOT] = "images\\Menu\\Menu_NOT.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\Menu_AND3.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\Menu_NOR3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\Menu_XOR3.jpg";
	MenuItemImages[ITM_Switch] = "images\\Menu\\Menu_Switch_On.jpg";
	MenuItemImages[ITM_Led] = "images\\Menu\\Menu_Light_Off.jpg";
	MenuItemImages[ITM_Connection] = "images\\Menu\\Menu_Connection.jpg";
	MenuItemImages[ITM_Arrows] = "images\\Menu\\Menu_Arrows.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	//Draw menu item one image at a time
	switch (Item)
	{
	case Page_One:
		for (int i = 0; i < 10; i++)
		{
			pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
		}
		UI.PageNumber = 1;
		break;
	case Page_Two:
		for (int i = 10; i < 14; i++)
		{
			pWind->DrawImage(MenuItemImages[i], (i - 10) * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
		}
		UI.PageNumber = 2;
		pWind->SetPen(WHITE, 1);
		pWind->SetBrush(WHITE);			//Draw white rectangle
		pWind->DrawRectangle(320, 0, 800, UI.ToolBarHeight);
		break;
	}
	pWind->DrawImage(MenuItemImages[ITM_Arrows], 10 * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	pWind->DrawImage(MenuItemImages[ITM_EXIT], 11 * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	string SimulationItemImages[ITM_SIM_CNT];
	
	SimulationItemImages[ITM_TRUTH] = "images\\Simulation\\frequency.jpg";
	
	
	for (int i = 0; i < ITM_SIM_CNT; i++)
	{
		pWind->DrawImage(SimulationItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	}
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);			//Draw white rectangle
	pWind->DrawRectangle(80, 0, 880, UI.ToolBarHeight);
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)

}

void Output::CreateCommonToolBar() const
{
	
	string TOOLBAR[ITM_TB_CNT];
	TOOLBAR[ITM_START] = "images\\Simulation\\simulator.jpg";
	TOOLBAR[ITM_STOP] = "images\\Simulation\\stop.jpg";
	TOOLBAR[ITM_Undo] = "images\\Menu\\Menu_Undo.jpg";
	TOOLBAR[ITM_Redo] = "images\\Menu\\Menu_Redo.jpg";
	TOOLBAR[ITM_Label]= "images\\Menu\\Menu_Label.jpg";
	TOOLBAR[ITM_Save] = "images\\Menu\\Menu_Save.jpg";
	TOOLBAR[ITM_Load] = "images\\Menu\\Menu_Load.jpg";
	TOOLBAR[ITM_Select] = "images\\Menu\\Menu_Select.jpg";
	TOOLBAR[ITM_Move] = "images\\Menu\\Menu_Move.jpg";
	TOOLBAR[ITM_Delete] = "images\\Menu\\Menu_Delete.jpg";
	TOOLBAR[ITM_Copy] = "images\\Menu\\Menu_Copy.jpg";
	TOOLBAR[ITM_Paste] = "images\\Menu\\Menu_Paste.jpg";

	
	for (int i = 0; i < 6; i++)
	{
		pWind->DrawImage(TOOLBAR[i], 900, (i + 1) * (85), UI.ToolItemWidth / 2, UI.ToolBarHeight / 2);
	}
	for (int i = 6; i < ITM_TB_CNT; i++)
	{
		pWind->DrawImage(TOOLBAR[i], 940, (i - 5) * (85), UI.ToolItemWidth / 2, UI.ToolBarHeight / 2);
	}

	pWind->SetPen(RED, 3);
	pWind->DrawLine(900, UI.ToolBarHeight, 900, 700);
}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

#pragma region Drawing Functions

//The drawing function of AND2
void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

//The drawing function of XOR2
void Output::Draw_XOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highligahted
		GateImage = "Images\\Gates\\Gate_XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, 50, 50);
}

//The drawing function of BUFFER
void Output::Draw_BUFFER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_BUFFER_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_BUFFER.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, 50, 50);
}

//The drawing function of XNOR2
void Output::Draw_XNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, 50, 50);
}

//The drawing function of NAND2
void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND2_hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1,50, 50);
}

//The drawing function of OR2
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1,50, 50);
}

//The drawing function of NOR2
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, 50, 50);
}

//The drawing function of NOT
void Output::DrawNOT(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOT_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOT.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, 50, 50);
}

//The drawing function of AND3
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, 50, 50);
}

//The drawing function of NOR3
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, 50, 50);
}

//The drawing function of XOR3
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, 50, 50);
}

//The drawing function of LED ON
void Output::DrawLEDON(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Light_On_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Light_On.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, 50, 50);
}

//The drawing function of LED OFF
void Output::DrawLEDOFF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Light_Off_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Light_Off.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, 50, 50);
}

//The drawing function of SWITCH ON
void Output::DrawSWITCHON(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Switch_On_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Switch_On.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, 50,50);
}

//The drawing function of SWITCH OFF
void Output::DrawSWITCHOFF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Switch_Off_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Switch_Off.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, 50,50);
}

//The drawing function of Conection
void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{

	int ix= r_GfxInfo.x1, iy= r_GfxInfo.y1, fx= r_GfxInfo.x2, fy= r_GfxInfo.y2,y=0,x=0;
	
	if (selected==true) pWind->SetPen(RED,3);
	else pWind->SetPen(BLUE,2);
	x = (fx - ix) / 2;
	if (iy != fy)
	{
		y = fy - iy;
		if (y > 0);
		else y = (-1) * y;
		pWind->DrawLine(ix, iy, ix + x, iy);
		pWind->DrawLine(ix + x, iy, ix + x, fy);
		pWind->DrawLine(ix + x, fy, fx, fy);

	}
	else pWind->DrawLine(ix, iy, fx, fy);
	
	//TODO: Add code to draw connection
}

#pragma endregion

Output::~Output()
{
	delete pWind;
}
