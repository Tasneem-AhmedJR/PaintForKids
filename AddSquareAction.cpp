#include "AddSquareAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int i = 0;

	do
	{
		if (i > 0)
		{
			pOut->PrintMessage("Invalid. Please click another point :) ");
			Sleep(1000);
		}
		pOut->PrintMessage("New Square: Click at One Point");
		pIn->GetPointClicked(P.x, P.y);      //Read one point store in point P

		i++;
	} while (!(P.y > 130 && P.y < 520));

	SquareGfxInfo.isFilled = pOut->isFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

bool AddSquareAction::canUndone() { return true; }

void AddSquareAction::RedoAction()
{
	pManager->setfigureCount(pManager->getfigureCount() + 1);
	sq->SetVisibility(true);
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
}

void AddSquareAction::CancelAction()
{
	pManager->setfigureCount(pManager->getfigureCount() - 1);
	sq->SetVisibility(false);                       //the figure sets its own visibilty to false in order not to be drawn
	Output* pOut = pManager->GetOutput();          //and delete last added figure
	pOut->ClearDrawArea();
}

void AddSquareAction::Execute()
{
	if (!pManager->getRecorder()->isPlayingNow())

	ReadActionParameters();  //must read Action parameters first
	//Create a Square with the parameters read from the user
	sq = new CSquare(P, SquareGfxInfo);

	//Add the Square to the list of figures
	pManager->AddFigure(sq);
}
