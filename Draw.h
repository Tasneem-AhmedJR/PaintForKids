#pragma once
#include"setColorAction.h"
#include"ApplicationManager.h"
class Draw :public setColorAction
{
	CFigure* f;
	color PreClr;
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
		}
	}
	virtual void CancelAction()
	{
		Output* pOut = pManager->GetOutput();
		f->ChngDrawClr(PreClr);
		pOut->setCurrentDrawColor(PreClr);
	}
	//void PlayAct() { setColorAction::PlayAct(); }
};