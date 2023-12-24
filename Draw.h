#pragma once
#include"setColorAction.h"
#include"ApplicationManager.h"
class Draw :public setColorAction
{
	CFigure* f;
	color PreClr;
	color CurrentClr;
public:
	Draw(ApplicationManager* pApp) :setColorAction(pApp) {}

	void Execute()
	{
		Output* pOut = pManager->GetOutput();

		if (pManager->getSelectedFig() == NULL) { pOut->PrintMessage("Please select a figure first "); }
		else 
		{
			f = pManager->getSelectedFig();
			PreClr = pOut->getCrntDrawColor();
			pOut->PrintMessage("changing drawing color, Please choose a color");
			pManager->setcolorType(false);
			setColorAction::Execute(); 
<<<<<<< HEAD
			pManager->UpdateInterface();
=======
			CurrentClr = pOut->getCrntDrawColor();
>>>>>>> 509b57b18b676642a70f66a2c5f1035fae7946fd
		}
	}
	virtual void RedoAction()
	{
		Output* pOut = pManager->GetOutput();
		f->ChngDrawClr(CurrentClr);
		pOut->setCurrentDrawColor(CurrentClr);

	}
	virtual void CancelAction()
	{
		Output* pOut = pManager->GetOutput();
		f->ChngDrawClr(PreClr);
		pOut->setCurrentDrawColor(PreClr);
		pManager->UpdateInterface();
	}
	bool canUndone() { return true; }
};