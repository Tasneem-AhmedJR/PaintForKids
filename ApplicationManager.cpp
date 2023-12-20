#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"AddSquareAction.h"
#include"AddCircleAction.h"
#include"AddTriangleAction.h"
#include"AddHexaAction.h"
#include"SelectAction.h"
#include"ToDraw.h"
#include"ClearAll.h"
#include"DeleteFigure.h"
#include"SaveAction.h"
#include"StartRecAction.h" 
#include"Fill.h"
#include"Draw.h" 
#include<fstream>
#include"Undo.h"
#include"StopRecAction.h"
#include"PlayRecAction.h"
#include"RecorderAct.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	SelectedFig = NULL;
	FigCount = 0;
	Recorder = new RecorderAct(this);
	ActList = new ActionList();
	//DrwClr = UI.DrawColor;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_SQUARE:
			pAct = new AddSquareAction(this);
			break;
		case DRAW_CIRCLE:
			pAct = new AddCircleAction(this);
			break;
		case DRAW_TRIANGLE:
			pAct = new AddTriangleAction(this);
			break;
		case DRAW_HEXA:
			pAct = new AddHexaAction(this);
			break;
		case ITMDELETE:
			pAct = new DeleteFigure(this);
			break;
		case CLEAR_ALL:
			pAct = new ClearAll(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case START:
			pAct = new StartRecAction(this);
			break;
		case STOP:
			pAct = new StopRecAction(this);
			break;
		case PLAY:
			pAct = new PlayRecAction(this);
			break;
		case FIG:
			pAct = new Draw(this);
			break;
		case FILL:
			pAct = new Fill(this);
			break;
		case UNDO:
			pAct = new Undo(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case EXIT:
			///create ExitAction here
			break;
		case TO_DRAW:
			pAct = new ToDraw(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		Recorder->AddrecList(pAct, ActType);
		pAct->ReadActionParameters();
		pAct->Execute();                            //Execute
		ActList->TraceAction(pAct, ActType);
		pAct = NULL;
	}
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}

void ApplicationManager::SaveAll(ofstream& OutFile)
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile);
}

Action* ApplicationManager::getLastAct() { return ActList->getList(); }

RecorderAct* ApplicationManager::getRecorder() { return Recorder; }

ActionList* ApplicationManager::GetActionList()
{
	return ActList;
}

void ApplicationManager::decrease()
{
	ActList->DecrementLastAct();
}

int ApplicationManager::getfigureCount() { return FigCount; }
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(Point* p) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->isInside(p)) return FigList[i];
		else continue;
	}
	return false;

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::ClearingFigures()       //loops on fig list and calls clearfig of each class
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i])
			delete FigList[i];
	}
	FigCount = 0;
	setSelectedFig(NULL);
}
void ApplicationManager::DeleteFig(bool ToUndo)
{
	if (ToUndo)
	{
		if (FigList[FigCount - 1])
		{
			FigList[FigCount - 1]->SetVisibility(false);
			pOut->ClearDrawArea();
		}
	}
	else
	{
		bool notfound = true;
		for (int i = 0; i < FigCount && notfound; i++)    //loops on figlist 
		{
			if (FigList[i]->IsSelected())                 //Checks which fig has selected as true
			{
				swap(FigList[i], FigList[FigCount - 1]);  //swaps selected fig with last fig in order not to leave emptiness between fig ptrs when deleted
				//FigList[FigCount - 1]->DeleteFig();     //TODO: Does the order matter??
				FigList[FigCount - 1]->SetVisibility(false);
				notfound = false;
			}
		}
	}
}
void ApplicationManager::setSelectedFig(CFigure* fig) { SelectedFig = fig; }

CFigure* ApplicationManager::getSelectedFig() { return SelectedFig; }

//==================================================================================//
//						Colours Management Functions								//
//==================================================================================//

ActionType ApplicationManager::getcolorType() { return ClrType; }

void ApplicationManager::setcolorType(ActionType act) { ClrType = act; }


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetVisibility())          //To Only Draw Visible figures to the user
			FigList[i]->Draw(pOut);		          //Call Draw function (virtual member fn)
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	delete ActList;
}
