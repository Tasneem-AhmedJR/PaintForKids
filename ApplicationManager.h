#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include"ActionList.h"
#include"RecorderAct.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		             // Actual number of figures
	CFigure* FigList[MaxFigCount];	 // List of all figures (Array of pointers)
	CFigure* SelectedFig;            // Pointer to the selected figure
	bool filled;                     // Figure Color Mode (Fill / Drawing)
	ActionList* ActList;
	RecorderAct* Recorder;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	
	ActionType GetUserAction() const;   // Reads the input command from the user and returns the corresponding action type
	void ExecuteAction(ActionType) ;    // Creates an action and executes it
	void SaveAll(ofstream& OutFile);    // Saves all figure in drawing area 
	void WhenLoad();
	RecorderAct* getRecorder();         // Returns a pointer to RecorderAct array to manage recording actions
	ActionList* GetActionList();        // Returns pointer to actlist array

	void Movefig(Point p);
	int getnumcolors( int n);         //this fuction returns a number representing each shape to save the memory of arrofcolor
	int getnumofshape(int n);          //this fuction returns a number representing each shape to save the memory of arroffig
	int insideoffig(Point p, int y);  //this function to know the whether the child pressed into the correct shape or not or anywhere
	int insideofcolor(Point p,int y);  //this function to know the whether the child pressed into the correct color or not or anywhere
	int insideofboth(Point p, int y);    //this function to know the whether the child pressed into the correct (color&fig) or not or anywhere
	void unhide();
	
	// -- Figures Management Functions

	int getfigureCount();                // returns the Actual figure count
	void setfigureCount(int);
	void AddFigure(CFigure* pFig);       // Adds a new figure to the FigList
	CFigure *GetFigure(Point* p) const;  // Search for a figure given a point inside the figure
	void setSelectedFig(CFigure* fig);   // sets the selected figure
	CFigure* getSelectedFig();           // returns the selected Figure
	void ClearingFigures();              // Deletes all figures in figure list
	void DeleteFig(CFigure*);           // Deletes the passed figure
	
	// -- Colours Management Functions 

	bool getcolorType();        // Sets the selected colour mode (Fill colour / Drawing colour)
	void setcolorType(bool);    // Returns the selected colour mode (Fill colour / Drawing colour)
	

	// -- Interface Management Functions

	Input *GetInput() const;          //Return pointer to the input
	Output *GetOutput() const;        //Return pointer to the output
	void UpdateInterface() const;	  //Redraws all the drawing window	
};

#endif