#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType 
{
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	Create_TruthTable,	//Create Truth Table of the Circuit

	Change_Switch,		//Change Switch Status in Simulation Mode
	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	START_SELECT,
	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode

	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar
	COMMON_BAR,		//A click on an empty place in the Common tool bar
	SIM_BAR,		//A click on an empty place in the Simulation tool bar
	Page_One,
	Page_Two
};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION,
};


enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_AND2,		//AND gate item in menu
	ITM_NAND2,      //NAND gate item in menu
	ITM_OR2,        //OR gate item in menu
	ITM_NOR2,       //NOR gate item in menu
	ITM_XOR2,       //XOR gate item in menu
	ITM_XNOR2,      //XNOR gate item in menu
	ITM_Buffer,     //Buffer gate item in menu
	ITM_NOT,        //Not gate item in menu
	ITM_AND3,       //and3 gate item in menu
	ITM_NOR3,       //NOR3 gate item in menu
	ITM_XOR3,       //XOR3 gate item in menu
	ITM_Switch,     //Switch item in menu
	ITM_Led,        //Led item in menu
	ITM_Connection,//Connection
	ITM_Arrows,     //Arrow up down
	ITM_EXIT,       //Exit item
	
	//TODO: Add more items names here
	
	ITM_DSN_CNT,		//no. of design menu items ==> This should be the last line in this enum

};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
				//Simulate menu item
	ITM_TRUTH,	//Truth table menu item
	
	//TODO:Add more items names here
	
	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
};
enum toolbarmenu
{
	ITM_START,		//start simulation		
	ITM_Undo,		//Undo item in menu
	ITM_Save,       //save item in menu
	ITM_Select,		 //select item in men
	ITM_Delete,		//delete item in menu


	ITM_STOP,		//stop simulation
	ITM_Redo,		//Redo item in menu
	ITM_Load,       //load item in menu
	ITM_Move,     //move item in menu
	ITM_Label,      //label item in menu
	
	

    ITM_TB_CNT
};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5,	//Default fan out of 2-input AND gate
	XOR2_FANOUT = 5,
	XNOR2_FANOUT = 5,
	BUFFER_FANOUT=5
};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1,y1, x2, y2;
};

#ifndef NULL
#define NULL 0
#endif

#endif