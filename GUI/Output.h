#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void  ClearToolBar() const; //Clears tool bar when switching modes 
	// -- Figures Drawing functions
	void DrawRect(Point &P1, Point &P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawSquare(Point &p, GfxInfo SquGfxInfo, bool selected = false) const;  //Draw a square  
	void DrawCircle(Point &p1, Point &p2, GfxInfo CircGfxInfo, bool selected = false)const; //Draw a circle
	void DrawTria(Point &P1, Point &P2, Point &P3, GfxInfo TriaInfo, bool selected = false)const; //Draw a triangle
	void DrawHexa(Point &P1, GfxInfo HexaInfo,  bool selected = false)const; //Draw a Hexagon
	
	///Make similar functions for drawing all other figure types.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	  //get current drwawing color
	void setCurrentDrawColor(color);  //set a given color as the current drawing color 
	color getCrntFillColor() const;	  //get current filling color
	bool isClicked(int& x, int& y);
	void setCurrentFillColor(color);  //set a given color as the current filling color 
	bool isFilled();                  //checks if the figure drawing style is filled
	void setStyle(bool);              //sets the current drawing style of the figures (filled/frame)      
	void reset();                     //resets the programm to the default settings 
	int getCrntPenWidth() const;	  //get current pen width
	window* getwindo();

	
	~Output();
};

#endif