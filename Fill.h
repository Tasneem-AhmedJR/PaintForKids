#pragma once
#include"setColorAction.h"
#include"ApplicationManager.h"
class Fill :public setColorAction
{
	CFigure* f;
	color PreClr;
public:
	Fill(ApplicationManager* pApp) :setColorAction(pApp) {}
	void Execute()
	{
		Output* pOut = pManager->GetOutput();

		if (pManager->getSelectedFig() == NULL)
		{
			pManager->setcolorType(NO_ACION);
			pOut->PrintMessage("Please select a figure first ");
		}
		else 
		{ 
			f = pManager->getSelectedFig();
			PreClr = f->getclr();
			pOut->PrintMessage("Change filling color, Plese choose a color ");
			pManager->setcolorType(FILL); 
			setColorAction::Execute(); 
		}
	}
	virtual void CancelAction()
	{
		f->ChngFillClr(PreClr);
	}
};