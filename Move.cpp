#include "Move.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

#include"Figures/CFigure.h"

Move::Move(ApplicationManager* pApp) :Action(pApp)
{
	Output* pOut = pManager->GetOutput();
	//w = pOut;
}

void Move::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click at One Point That You Want To Move");

	//Read one point store in point p
	pIn->GetPointClicked(p1.x, p1.y);
	pOut->PrintMessage("the point was entered");

	pOut->ClearStatusBar();
}

void Move::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getSelectedFig())                //to only be called if there is a selected fig
	{
		ReadActionParameters();
		pOut->PrintMessage("aclick on move");

		pManager->Movefig(p1);                    //calls delete func. in applicationManager to access figlist
		pOut->PrintMessage("Selected Figure Move");
		pOut->ClearDrawArea();

	}
}
