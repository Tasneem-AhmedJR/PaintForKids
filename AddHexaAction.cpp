#include "AddHexaAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

AddHexaAction::AddHexaAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddHexaAction::ReadActionParameters()
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
		pOut->PrintMessage("New Hexagon: Click at One Point ");
		pIn->GetPointClicked(P.x, P.y);   //Read point and store in point P1

		i++;
	} while (P.y < 130 || P.y>530);

	HexaGfxInfo.isFilled = pOut->isFilled();;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddHexaAction::RedoAction()
{
	pManager->setfigureCount(pManager->getfigureCount() + 1);
	hex->SetVisibility(true);
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
}

bool AddHexaAction::Undoable() { return true; }

void AddHexaAction::CancelAction()
{
	pManager->setfigureCount(pManager->getfigureCount() - 1);
	hex->SetVisibility(false);                 //the figure sets its own visibilty to false in order not to be drawn
	Output* pOut = pManager->GetOutput();      //and delete last added figure
	pOut->ClearDrawArea();
}

void AddHexaAction::Execute()
{
	if (!pManager->getRecorder()->isPlayingNow())

	ReadActionParameters();  //must read Action parameters first
	//Create a rectangle with the parameters read from the user
	hex = new CHexagon(P,HexaGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(hex);
}
