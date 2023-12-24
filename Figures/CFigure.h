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
	color Preclr;
	bool Visible;
	bool hide;
	/// Add more parameters if needed.

public:
	CFigure() { }
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	                //select/unselect the figure
	bool IsSelected() const;	                //check whether fig is selected
	virtual void Draw(Output* pOut)   = 0 ;		//Draw the figure
	void SetVisibility(bool f);                 //Sets visibilty status for a figure
	bool GetVisibility();                       //Returns visibility for a figure
	void ChngDrawClr(color Dclr);	            //changes the figure's drawing color
	void ChngFillClr(color Fclr);	            //changes the figure's filling color
	virtual void Movefi(Output* pOut, Point p);
	void sethide(bool l);
	bool gethide();
	virtual int getnum() =0;
	int filledcolor();
	color GetFillclr();                         //returns the current figure's fill color
	color GetDrawClr();
	bool IsFilled();
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	virtual	bool isInside(Point* p) = 0; // checks if a given point is inside or on the inside

	virtual void DeleteFig() = 0;     //Each shape is responsible of deleting itself
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif