#pragma once
#include"setColorAction.h"
#include"ApplicationManager.h"
class Draw :public setColorAction
{
public:
	Draw(ApplicationManager* pApp) :setColorAction(pApp) {}

	void Execute()
	{
		Output* pOut = pManager->GetOutput();

		if (pManager->getSelectedFig() == NULL) { pOut->PrintMessage("Please select a figure first "); }
		else 
		{
			pOut->PrintMessage("changing drawing color, Please choose a color");
			pManager->setcolorType(false);
			setColorAction::Execute(); 
		}
	}

	void PlayAct() { setColorAction::PlayAct(); }
};