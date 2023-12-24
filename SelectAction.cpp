#include"SelectAction.h"
#include"GUI\input.h"
#include"GUI\Output.h"
#include"ApplicationManager.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp) {}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on a figure to select");
	pIn->GetPointClicked(P.x, P.y);
			
	pOut->ClearStatusBar();
}

void SelectAction::Select(CFigure* f)
{
	Output* pOut = pManager->GetOutput();
	pManager->setSelectedFig(Fig);
	f->SetSelected(true);
	f->ChngDrawClr(UI.HighlightColor);
//	f->PrintInfo(pOut);
}

void SelectAction::Unselect(CFigure* f)
{
	Output* pOut = pManager->GetOutput();
	pManager->setSelectedFig(NULL);
	f->SetSelected(false);
	f->ChngDrawClr(f->GetDrawClr());
	pOut->ClearStatusBar();
}

void SelectAction::Execute()
{
	if(!pManager->getRecorder()->isPlayingNow())
	ReadActionParameters(); // must read action parameters first

	Fig = pManager->GetFigure(&P);

	if (Fig)  // if the kid clickes on or inside the figure there will be three cases:         
	{
		//if no figure was previousely selected, select the current figure right away
		if (pManager->getSelectedFig() == NULL)	Select(Fig);

		//if the current figure was alresdy selected , unselect current figure
		else if (pManager->getSelectedFig() == Fig) Unselect(Fig);

		// if there was an already selected figure , first unselect it then select the current figure  
		else 
		{ Unselect(pManager->getSelectedFig());	Select(Fig); }
	}
}

