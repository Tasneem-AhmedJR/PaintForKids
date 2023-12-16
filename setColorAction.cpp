#include "setColorAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include"SelectAction.h"

setColorAction::setColorAction(ApplicationManager* pApp) :Action(pApp) {}

void setColorAction::ReadActionParameters() {}

void setColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getcolorType() == NO_ACION)
		pOut->PrintMessage("Please choose color mode first ");
	else
	{
		CFigure* fig = pManager->getSelectedFig();
		ActionType typ = pManager->getcolorType();
		ActionType clr = pManager->GetUserAction();

		if (clr == BLCK)
		{
			if (typ == FIG) fig->ChngDrawClr(BLACK);
			else if (typ == FILL) fig->ChngFillClr(BLACK);
		}
		else if (clr == YELLW)
		{
			if (typ == FIG) fig->ChngDrawClr(YELLOW);
			else if (typ == FILL) fig->ChngFillClr(YELLOW);
		}
		 if (clr == ORANG)
		{
			if (typ == FIG) fig->ChngDrawClr(ORANGE);
			else if (typ == FILL) fig->ChngFillClr(ORANGE);
		}
		else if (clr == RD)
		{
			if (typ == FIG) fig->ChngDrawClr(RED);
			else if (typ == FILL) fig->ChngFillClr(RED);
		}
		else if (clr == GREN)
		{
			if (typ == FIG) fig->ChngDrawClr(GREEN);
			else if (typ == FILL) fig->ChngFillClr(GREEN);
		}
		else if (clr == BLU)
		{
			if (typ == FIG) fig->ChngDrawClr(BLUE);
			else if (typ == FILL) fig->ChngFillClr(BLUE);
		}
		pOut->ClearStatusBar();
	}
}