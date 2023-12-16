#pragma once
#include"setColorAction.h"
#include"ApplicationManager.h"
class Fill :public setColorAction
{
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
			pOut->PrintMessage("Change filling color, Plese choose a color ");
			pManager->setcolorType(FILL); 
			setColorAction::Execute(); 
		}
	}
};