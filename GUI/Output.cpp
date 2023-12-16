#include "Output.h"
#include<cmath>

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 46;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = WHITE;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = PURPLE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\square.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\fillc.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\tri.jpg";
	MenuItemImages[ITM_HEXA] = "images\\MenuItems\\hexa.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_FILLED] = "images\\MenuItems\\fill.jpg";
	MenuItemImages[ITM_FIG] = "images\\MenuItems\\figure.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\orange.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_START] = "images\\MenuItems\\start.jpg";
	MenuItemImages[ITM_STOP] = "images\\MenuItems\\stop.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_CLEAR_ALL] = "images\\MenuItems\\clear.jpg";
	MenuItemImages[ITM_SWITCH_PLAY] = "images\\MenuItems\\switch.jpg";

	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_BY_TYPE] = "images\\MenuItems\\fig.jpg";
	MenuItemImages[ITM_FILL_COLOR] = "images\\MenuItems\\color.jpg";
	MenuItemImages[ITM_TYPE_FILL] = "images\\MenuItems\\both.jpg";
	MenuItemImages[ITM_SWITCH_DRAW] = "images\\MenuItems\\draw.jpg";


	//DRAW PLAY TOOL BAR
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//DRAW A LINE UNDER TOOLBAR
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
void Output::ClearToolBar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point &P1, Point &P2, GfxInfo RectGfxInfo, bool selected) const
{
	while (!(P1.y > 50 && P2.y > 50 && P1.y < 600 && P2.y < 600))
	{
		PrintMessage("Invalid, Please click another two Points :) ");
		Input* I = CreateInput();
		I->GetPointClicked(P1.x, P1.y);
		I->GetPointClicked(P2.x, P2.y);
		ClearStatusBar();
	}
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::DrawSquare(Point &p, GfxInfo SquGfxInfo, bool selected) const

{
	while (!(p.y > 130 && p.y < 520))
	{
		PrintMessage("Invalid, Please click another Point :) ");
		Input* I = CreateInput();
		I->GetPointClicked(p.x, p.y);
		ClearStatusBar();
	}

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SquGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SquGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquGfxInfo.FillClr);
	}
	else
		style = FRAME;
		
	pWind->DrawRectangle((p.x) - 80, (p.y) - 80, (p.x) + 80, (p.y) + 80, style);
}

void Output::DrawCircle(Point &p1,Point &p2, GfxInfo CircGfxInfo, bool selected) const
{
	double r = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
	while (!(p1.y > 50 && p1.y < 600 && p1.y - r > 50 && p1.y + r < 600))
	{
		PrintMessage("Invalid, Please click another two points :) ");
		Input* I = CreateInput();
		I->GetPointClicked(p1.x, p1.y);
		I->GetPointClicked(p2.x, p2.y);
		r = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
		ClearStatusBar();
	}

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(p1.x, p1.y,r, style);
}

void Output::DrawTria(Point &P1, Point &P2, Point &P3, GfxInfo TriaGfxInfo, bool selected) const
{
	while (!(P1.y > 50 && P2.y > 50 && P3.y > 50) || !(P1.y < 600 && P2.y < 600 && P3.y < 600))
	{
		PrintMessage("Invalid ,Please click another three Points :)");
		Input* I = CreateInput();
		I->GetPointClicked(P1.x, P1.y);
		I->GetPointClicked(P2.x, P2.y);
		I->GetPointClicked(P3.x, P3.y);
		ClearStatusBar();
	}
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriaGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriaGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriaGfxInfo.FillClr);
	}
	else
		style = FRAME;
	

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawHexa(Point &P1, GfxInfo HexaInfo, bool selected) const
{
	while (P1.y < 130 || P1.y>530)
	{
		PrintMessage("Invalid ,Please click another Point :)");
		Input* I = CreateInput();
		I->GetPointClicked(P1.x, P1.y);
		ClearStatusBar();
	}
	float a = 0.8660254038;
	int Length = 80; //length of hexagon
	const float X[6] = { P1.x + (Length * 0.5),P1.x - (Length * 0.5),P1.x - Length, P1.x - (Length * 0.5),P1.x + (Length * 0.5),P1.x + Length };
	const float Y[6] = { P1.y - (Length * a),P1.y - (Length * a),P1.y,P1.y + (Length * a),P1.y + (Length * a),P1.y };
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexaInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexaInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexaInfo.FillClr);
	}
	else
		style = FRAME;

	

	pWind->DrawPolygon(X, Y, 6, style);
	
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

