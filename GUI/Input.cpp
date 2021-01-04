//#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pOut)
{
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar
	char ch;
	string s = "";
	//pWind->GetKeyPress(escape);
	while (true)
	{
		pWind->WaitKeyPress(ch);
		if (ch == '\r')
		{
			break;
		}
		else if (ch == 8)
		{
			if (s.length() != 0)
			{
				s.erase(s.begin() + s.length() - 1);
			}
		}
		else if (ch == 27)
		{
			return "";
		}
		else {
			s += ch;
		}
		pOut->PrintMsg("You Entered : " + s);
	}
	return s;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction(int Page) const
{
	Page = UI.PageNumber;
	// 0 to 40
	// 45 + 40 to 45 + 40 * 2				//Kotb
	// 45 * 2 + 40 * 2 to 45 * 2 + 40 * 3
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	// User Click on the common toolbar 
	if (x > 900 && y > UI.ToolBarHeight)
	{
		y -= 80;
		int ClickedItemOrder = -1;
		for (int i = 0; i <= 8; i++) {
			if (y > (i * 45 + 40 * i) && y < (i * 45 + 40 * (i + 1))) {
				ClickedItemOrder = i;
				break;
			}
		}
		// Items on the right
		if (x > 940)
		{
			ClickedItemOrder += 7;
			switch (ClickedItemOrder)
			{
			case ITM_STOP: return DSN_MODE;
			case ITM_Redo: return REDO;
			case ITM_Load: return LOAD;
			case ITM_Move: return MOVE;
			case ITM_Label: return ADD_Label;
			case ITM_Paste: return PASTE;
			case ITM_Edit: return EDIT;
			default: return COMMON_BAR;
			}
		}
		// Items on the left
		else
		{
			switch (ClickedItemOrder)
			{
			case ITM_START: return SIM_MODE;
			case ITM_Undo: return UNDO;
			case ITM_Save: return SAVE;
			case ITM_Select: return START_SELECT;
			case ITM_Delete: return DEL;
			case ITM_Copy:return COPY;
			case ITM_Cut:return CUT;
			default: return COMMON_BAR;
			}
		}
	}
	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			if (Page == 1)
			{
				switch (ClickedItemOrder)
				{
				case ITM_AND2: return ADD_AND_GATE_2;
				case ITM_NAND2: return ADD_NAND_GATE_2;
				case ITM_OR2: return ADD_OR_GATE_2;
				case ITM_NOR2: return ADD_NOR_GATE_2;
				case ITM_XOR2: return ADD_XOR_GATE_2;
				case ITM_XNOR2: return ADD_XNOR_GATE_2;
				case ITM_Buffer: return ADD_Buff;
				case ITM_NOT: return ADD_INV;
				case ITM_AND3: return ADD_AND_GATE_3;
				case ITM_NOR3: return ADD_NOR_GATE_3;
				case 10:
					if (y < 40) return Page_One;// arrow up
					if (y > 40) return Page_Two;// arrow down
				case 11: return EXIT;
				default: return DSN_TOOL;	//A click on empty place in desgin toolbar
				}
			}
			else
			{
				switch (ClickedItemOrder)
				{
				case 0: return ADD_XOR_GATE_3;
				case 1: return ADD_Switch;
				case 2: return ADD_LED;
				case 3: return ADD_CONNECTION;
				case 10:
					if (y < 40) return Page_One;// arrow up
					if (y > 40) return Page_Two;// arrow down
				case 11: return EXIT;
				default: return DSN_TOOL;	//A click on empty place in desgin toolbar
				}
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select / unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on


			switch (ClickedItemOrder)
			{
			case ITM_TRUTH: return Create_TruthTable;

			
			case 11: return EXIT;
			default: return SIM_BAR;	//A click on empty place in Simulation toolbar
			}


		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select / unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;

		//This should be changed after creating the compelete simulation bar 
	}

}


Input::~Input()
{
}
