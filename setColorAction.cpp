#include "setColorAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include"SelectAction.h"

setColorAction::setColorAction(ApplicationManager* pApp) :Action(pApp) {}

void setColorAction::ReadActionParameters() {}

void setColorAction::changecolorAct(bool b, CFigure* fig, color c)
{
	Output* pOut = pManager->GetOutput();

	if(b)
	{
		fig->ChngFillClr(c);
		pOut->setCurrentFillColor(c);
	}
	else
	{
		fig->ChngDrawClr(c);
		pOut->setCurrentDrawColor(c);
	}
}

void setColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure* fig = pManager->getSelectedFig();
	bool typ = pManager->getcolorType();

	ActionType clr = pManager->GetUserAction();

	switch (clr)
	{
	case BLCK: Clr = BLACK; break;
	case YELLW: Clr = YELLOW; break;
	case ORANG: Clr = ORANGE; break;
	case RD: Clr = RED; break;
	case GREN: Clr = GREEN; break;
	case BLU: Clr = BLUE; break;
	default: break;
	}

	changecolorAct(typ, fig, Clr);

	pOut->ClearStatusBar();
}