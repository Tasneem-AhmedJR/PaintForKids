#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	static int count;
	int ID;		        //Each figure has an ID
	bool Selected;	    //true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	color Preclr;       //figure drawing color without highlighting  
	bool Visible;
	bool hide;
	Point previous;
	/// Add more parameters if needed.

public:
	CFigure() { }
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	                //select/unselect the figure
	bool IsSelected() const;	                //check whether fig is selected
	virtual void Draw(Output* pOut)   = 0 ;		//Draw the figure
	static void resetcount();                      //resets ID to zero
	void SetVisibility(bool f);                 //Sets visibilty status for a figure
	bool GetVisibility();                       //Returns visibility for a figure
	void ChngDrawClr(color Dclr);	            //changes the figure's drawing color
	void ChngFillClr(color Fclr);	            //changes the figure's filling color
	virtual void Movefi(Output* pOut, Point p)=0;
	Point PrePoint();
	void sethide(bool l);
	bool gethide();
	virtual int getconstfig() =0;              //this function considered that any shape of fig has a const number
	int filledcolor();                         //this function considered that any color has a const number
	color GetFillclr();                         //returns the current figure's fill color
	color GetDrawClr();                         //returns the current figure's drawing color   
	bool IsFilled();                            //checks if the figure is filled

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	virtual	bool isInside(Point* p) = 0;        //checks if a given point is inside or on the figure

	virtual void DeleteFig() = 0;               //Each shape is responsible of deleting itself
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif