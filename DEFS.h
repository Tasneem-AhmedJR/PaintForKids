#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQUARE,    //Draw square
	DRAW_CIRCLE,    //Draw circle
	DRAW_TRIANGLE,  //Draw Triangle
	DRAW_HEXA,      //Draw Hexa
	SELECT,         //Select any Fig
	SOUND,
	FILL,           //To Filled The fig with color
	FIG,            //To Highlite The Fig
	BLCK,           // Black Color
	YELLW,          //Yellow Color
	ORANG,          //Orange Color
	RD,             //Red Color
	GREN,           //Green Color
	BLU,            //Blue Color
	MOVE,           //Move 
	UNDO,           //Undo 
	REDO,           //Redo 
	START,          //Start Recording
	STOP,           //Stop Recording
	PLAY,           //Play Recording
	SAVE,           //Save 
	LOAD,           //Load 
	ITMDELETE,      //Delete
	CLEAR_ALL,      //Clear all
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	TYPE,           //Type the fig
	FILLCOLOR,      //Fillcolor the fig
	TYPE_COLOR,     //Type and Color The Fig
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	PLAYING_AREA,   //A click on playing area
	STATUS,			//A click on the status bar
	NO_ACION

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x,y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders


};

#endif