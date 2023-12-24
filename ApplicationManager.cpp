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
#include "Move.h"
#include"StopRecAction.h"
#include"PlayRecAction.h"
#include"RecorderAct.h"
#include"LoadAction.h"
<<<<<<< HEAD
#include"ToPlay.h"
#include "pickbyfill.h"
#include "pickbytype.h"
=======
#include"SoundAction.h"
>>>>>>> 509b57b18b676642a70f66a2c5f1035fae7946fd

#include"Redo.h"
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
	filled = false;
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
<<<<<<< HEAD
		
=======
		case REDO:
			pAct = new Redo(this);
			break;
>>>>>>> 509b57b18b676642a70f66a2c5f1035fae7946fd
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case LOAD:
			pAct = new LoadAction(this);
			break;
<<<<<<< HEAD
		case MOVE:
			pAct = new Move(this);
		
=======
		case SOUND:
			pAct = new SoundAction(this);
			break;
>>>>>>> 509b57b18b676642a70f66a2c5f1035fae7946fd
		case EXIT:
			///create ExitAction here
			break;
		case TO_DRAW:
			pAct = new ToDraw(this);
			break;
		case FILLCOLOR:
			pAct = new pickbyfill(this);
			break;
		case TYPE:
			pAct = new pickbytype(this);
			break;
		case TO_PLAY:
			pAct = new ToPlay(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		if (!Recorder->isPlayingNow())
			pAct->Execute();                            //Execute
		ActList->TraceAction(pAct);
		Recorder->AddrecList(pAct, ActType);
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
		if(FigList[i]->GetVisibility())
			if(FigList[i])
		FigList[i]->Save(OutFile);
}

void ApplicationManager::WhenLoad()
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i] = NULL;
		delete FigList[i];
	}
	FigCount = 0;
}

Action* ApplicationManager::GetRedoAction()
{
	return ActList->getRedo();
}

Action* ApplicationManager::getLastAct() { return ActList->getList(); }

RecorderAct* ApplicationManager::getRecorder() { return Recorder; }

ActionList* ApplicationManager::GetActionList()
{
	return ActList;
}

void ApplicationManager::Movefig(Point p)
{
	bool notfound = true;
	for (int i = 0; i < FigCount && notfound; i++)                         //loops on figlist 
	{
		if (FigList[i]->IsSelected())                          //Checks which fig has selected as true
		{
			FigList[i]->Movefi(pOut, p);
			notfound = false;

		}
	}
}

int ApplicationManager::getn( int n)
{
//	for (int i = 0; i < FigCount; i++)
	//{
		/*	if (FigList[i]->GetFillclr() == BLACK && FigList[i]->IsFilled() && FigList[i]->GetVisibility())
				a[0]++;
			else if (FigList[i]->GetFillclr() == YELLOW && FigList[i]->IsFilled() && FigList[i]->GetVisibility())
				a[1]++;
			else if (FigList[i]->GetFillclr() == ORANGE && FigList[i]->IsFilled() && FigList[i]->GetVisibility())
				a[2]++;
			else if (FigList[i]->GetFillclr() == RED && FigList[i]->IsFilled() && FigList[i]->GetVisibility())
				a[3]++;
			else if (FigList[i]->GetFillclr() == GREEN && FigList[i]->IsFilled() && FigList[i]->GetVisibility())
				a[4]++;
			else if (FigList[i]->GetFillclr() == BLUE && FigList[i]->IsFilled() && FigList[i]->GetVisibility())
				a[5]++;
		}
		*/
		if (FigList[n]->GetFillclr() == BLACK && FigList[n]->IsFilled() && FigList[n]->GetVisibility())
			return 0;
		else if (FigList[n]->GetFillclr() == YELLOW && FigList[n]->IsFilled() && FigList[n]->GetVisibility())
			return 1;
		else if (FigList[n]->GetFillclr() == ORANGE && FigList[n]->IsFilled() && FigList[n]->GetVisibility())
			return 2;
		else if (FigList[n]->GetFillclr() == RED && FigList[n]->IsFilled() && FigList[n]->GetVisibility())
			return 3;
		else if (FigList[n]->GetFillclr() == GREEN && FigList[n]->IsFilled() && FigList[n]->GetVisibility())
			return 4;
		else if (FigList[n]->GetFillclr() == BLUE && FigList[n]->IsFilled() && FigList[n]->GetVisibility())
			return 5;
		else
			return -1;
	
}

int ApplicationManager::getm( int n)
{
	/*for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->getnum() == 1 && FigList[i]->GetVisibility() )
			a[1]++;
		else if (FigList[i]->getnum() == 2 && FigList[i]->GetVisibility() )
			a[2]++;
		else if (FigList[i]->getnum() == 3 && FigList[i]->GetVisibility() )
			a[3]++;
		else if (FigList[i]->getnum() == 4 && FigList[i]->GetVisibility() )
			a[4]++;
		else if (FigList[i]->getnum() == 0 && FigList[i]->GetVisibility())
			a[0]++;
	}
	*/
	if (FigList[n]->getnum() == 1 && FigList[n]->GetVisibility())
		return 1;
	else if (FigList[n]->getnum() == 2 && FigList[n]->GetVisibility())
		return 2;
	else if (FigList[n]->getnum() == 3 && FigList[n]->GetVisibility())
		return 3;
	else if (FigList[n]->getnum() == 4 && FigList[n]->GetVisibility())
		return 4;
	else if (FigList[n]->getnum() == 0 && FigList[n]->GetVisibility())
		return 0;

}
int ApplicationManager::inside2(Point p, int y)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->isInside(&p) && FigList[i]->getnum() == y) {
			FigList[i]->sethide(false);
			return 1;
		}
		else if (FigList[i]->isInside(&p) && FigList[i]->getnum() != y)
		{
			return 0;
		}


	}
	return -1;
	
}
int ApplicationManager::inside(Point p, int y)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->isInside(&p) && FigList[i]->filledcolor() == y && FigList[i]->IsFilled()) {
			FigList[i]->sethide(false);
			return 1;
		}
		else if (FigList[i]->isInside(&p) && FigList[i]->filledcolor() !=y&&FigList[i]->IsFilled())
			{
			return 0;
		}
		else if (FigList[i]->isInside(&p) &&!(FigList[i]->IsFilled()))
		{
			return 0;
		}
		

	}
	return -1;

}
void ApplicationManager::unhide()
{
	for (int i = 0; i < FigCount; i++)
	{

		FigList[i]->sethide(true);
	}
}

void ApplicationManager::decrease()
{
	ActList->DecrementLastAct();
}

void ApplicationManager::IncrRedo()
{
	ActList->IncrementRedo();
}

bool ApplicationManager::Redoable()
{
	return ActList->canredo();
}

int ApplicationManager::getfigureCount() { return FigCount; }
void ApplicationManager::setfigureCount(int x)
{
	FigCount = x;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(Point* p) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for (int i = 0; i < FigCount; i++)
	{
	    if(FigList[i])
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
	pOut->reset();
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
void ApplicationManager::reset()
{
	pOut->setCurrentDrawColor(BLUE);
	pOut->setCurrentFillColor(GREEN);
	pOut->setStyle(false);
}
void ApplicationManager::setSelectedFig(CFigure* fig) { SelectedFig = fig; }

CFigure* ApplicationManager::getSelectedFig() { return SelectedFig; }

//==================================================================================//
//						Colours Management Functions								//
//==================================================================================//

bool ApplicationManager::getcolorType() { return filled; }

void ApplicationManager::setcolorType(bool b) { filled = b; }

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]) {
			if (FigList[i]->gethide())
				if (FigList[i]->GetVisibility()  )        //To Only Draw Visible figures to the user
				   FigList[i]->Draw(pOut);
		}	          //Call Draw function (virtual member fn)
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
