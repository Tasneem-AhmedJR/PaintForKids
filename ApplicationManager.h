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
	Action* GetRedoAction();            // Calls getredo in actionlist class 
	Action* getLastAct();               // Returns last traced Action 
	RecorderAct* getRecorder();
	ActionList* GetActionList();        // Returns pointer to actlist array
<<<<<<< HEAD
	void Movefig(Point p);
	int getn( int n);
	int getm(int n);
	int inside2(Point p, int y);
	int inside(Point p,int y);
	void unhide();
=======
	void decrease();                    // Calls decrement Function of action list class
	void IncrRedo();                    // Calls Increment function of action list
	bool Redoable();                    // Validates RedoIndex
>>>>>>> 509b57b18b676642a70f66a2c5f1035fae7946fd
	// -- Figures Management Functions
	int getfigureCount();                // returns the Actual figure count
	void setfigureCount(int);
	void AddFigure(CFigure* pFig);       // Adds a new figure to the FigList
	CFigure *GetFigure(Point* p) const;  // Search for a figure given a point inside the figure
	void setSelectedFig(CFigure* fig);   // sets the selected figure
	CFigure* getSelectedFig();           // returns the selected Figure
	void ClearingFigures();              // Deletes all figures in figure list
	void DeleteFig(bool ToUndo);         // Deletes the selected figure
	void reset();

	// -- Colours Management Functions 

	bool getcolorType();        // Sets the selected colour mode (Fill colour / Drawing colour)
	void setcolorType(bool);    // Returns the selected colour mode (Fill colour / Drawing colour)
	

	// -- Interface Management Functions

	Input *GetInput() const;          //Return pointer to the input
	Output *GetOutput() const;        //Return pointer to the output
	void UpdateInterface() const;	  //Redraws all the drawing window	
};

#endif