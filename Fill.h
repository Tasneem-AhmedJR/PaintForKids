#pragma once
#include"setColorAction.h"
#include"ApplicationManager.h"
class Fill :public setColorAction
{
	CFigure* f;
	color PreClr;
	color CurrentClr;
public:
	Fill(ApplicationManager* pApp) :setColorAction(pApp) {}
	void Execute()
	{
		//a pointer to the output interface
		Output* pOut = pManager->GetOutput();

		//checks if any figure is selectd

		if (pManager->getSelectedFig() == NULL) { pOut->PrintMessage("Please select a figure first "); }
		else
		{
			f = pManager->getSelectedFig();     //a pointer to the selected figure 
			if (f->IsFilled())
				PreClr = f->GetFillclr();
			else PreClr = BEIGE;

			pOut->PrintMessage("Change filling color, Plese choose a color ");
			pManager->setcolorType(true);       //Fill the selectd figure
			pOut->setStyle(true);               //set drawing style FILLED

			setColorAction::Execute();          //change filling color   
			CurrentClr = pOut->getCrntFillColor();
		}
		pManager->UpdateInterface();
	}
	virtual void RedoAction()
	{
		Output* pOut = pManager->GetOutput();
		if (CurrentClr != LIGHTGOLDENRODYELLOW)
			pOut->setStyle(true);
		f->ChngFillClr(CurrentClr);
		pOut->setCurrentFillColor(CurrentClr);
	}

	virtual void CancelAction()
	{
		Output* pOut = pManager->GetOutput();
		if (PreClr != BEIGE)
		{
			f->ChngFillClr(PreClr);
			pOut->setStyle(true);
			pOut->setCurrentFillColor(PreClr);
			
			pOut->ClearDrawArea();
		}
		else
		{
			f->ChngFillClr(LIGHTGOLDENRODYELLOW);
			pOut->setStyle(false);
			pOut->ClearDrawArea();

		}
		pManager->UpdateInterface();
	}

	virtual bool Undoable()
	{
		return true;
	}
};