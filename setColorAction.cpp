#include "setColorAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include"SelectAction.h"

setColorAction::setColorAction(ApplicationManager* pApp) :Action(pApp) {}

void setColorAction::changecolorAct(bool b, CFigure* fig, color c)
{
	Output* pOut = pManager->GetOutput();
	if (c == WHITE) pOut->PrintMessage("no colour was chosen ");
	else
	{
		if (b)
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
}
void setColorAction::ReadActionParameters()
{
	act = pManager->GetUserAction();   //need one extra click to determine the color
	switch (act)
	{
	case BLCK: Clr = BLACK; break;
	case YELLW: Clr = YELLOW; break;
	case ORANG: Clr = ORANGE; break;
	case RD: Clr = RED; break;
	case GREN: Clr = GREEN; break;
	case BLU: Clr = BLUE; break;
	default: Clr = LIGHTGOLDENRODYELLOW; break;
	}
}
void setColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	fig = pManager->getSelectedFig();               //a pointer to the selected figure 
	typ = pManager->getcolorType();                 //selected figure color type

	if (!pManager->getRecorder()->isPlayingNow())  //no need to read action parameters while playing recording
		ReadActionParameters();

	changecolorAct(typ, fig, Clr);

	pOut->ClearStatusBar();
}

