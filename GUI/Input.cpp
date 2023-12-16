#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	int i = 0;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
		{
			pWind->FlushMouseQueue();
			pWind->FlushKeyQueue();
			return "";	//returns nothing as user has cancelled label
		}
		if (Key == 13)	//ENTER key is pressed
		{
			pWind->FlushMouseQueue();
			pWind->FlushKeyQueue();
			//Two above functions used to clear the memory of mouse click
			if (i == 0)
				return " ";
			else
			return Label;
		}
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO) 
		{
			i = 1;
			pO->PrintMessage(Label);

		}
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE:return DRAW_SQUARE;
			case ITM_CIRC:return DRAW_CIRCLE;
			case ITM_TRI:return DRAW_TRIANGLE;
			case ITM_HEXA:return DRAW_HEXA;
			case SELECT:return SELECT;
			case FILL:return FILL;
			case FIG:return FIG;
			case BLCK:return BLCK;
			case YELLW:return YELLW;
			case ORANG:return ORANG;
			case RD: return RD;
			case GREN:return GREN;
			case BLU:return BLU;
			case MOVE:return MOVE;
			case UNDO:return UNDO;
			case REDO:return REDO;
			case START:return START;
			case STOP:return STOP;
			case PLAY:return PLAY;
			case SAVE:return SAVE;
			case LOAD:return LOAD;
			case ITMDELETE:return ITMDELETE;
			case CLEAR_ALL:return CLEAR_ALL;
			case ITM_SWITCH_PLAY: return TO_PLAY;
			case ITM_EXIT: return EXIT;	
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_BY_TYPE:return TYPE;
			case ITM_FILL_COLOR:return FILLCOLOR;
			case ITM_TYPE_FILL:return TYPE_COLOR;
			case ITM_SWITCH_DRAW: return TO_DRAW;
			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return PLAYING_AREA;
		}

		return STATUS;
		
		//return TO_PLAY;	//just for now. This should be updated
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
