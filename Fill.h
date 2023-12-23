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
		Output* pOut = pManager->GetOutput();

		if (pManager->getSelectedFig() == NULL) { pOut->PrintMessage("Please select a figure first "); }
		else
		{
			f = pManager->getSelectedFig();
			if (f->IsFilled())
				PreClr = f->GetFillclr();
			else PreClr = BEIGE;
			pOut->PrintMessage("Change filling color, Plese choose a color ");
			pManager->setcolorType(true);
			pOut->setStyle(true);
			setColorAction::Execute();
			CurrentClr = pOut->getCrntFillColor();
		}
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
	}
	bool canUndone() { return true; }
};