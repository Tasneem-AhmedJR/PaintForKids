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
	} while (!hex->validate(P));          //make sure the hexagon is not drawn outside the drawing area 

	HexaGfxInfo.isFilled = pOut->isFilled();;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddHexaAction::RedoAction()
{
	hex->SetVisibility(true);
	pManager->AddFigure(hex);
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
}

bool AddHexaAction::Undoable()
{
	return true;
}

void AddHexaAction::CancelAction()
{
	hex->SetVisibility(false);                 //the figure sets its own visibilty to false in order not to be drawn
	pManager->DeleteFig(hex);
	Output* pOut = pManager->GetOutput();      //and delete last added figure
	pOut->ClearDrawArea();
}

void AddHexaAction::Execute()
{
	if (!pManager->getRecorder()->isPlayingNow())     //no need to read Action parameters while playing recording

	ReadActionParameters();  //must read Action parameters first in case of not playing recording

	//Create a rectangle with the parameters read from the user
	hex = new CHexagon(P,HexaGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(hex);
}
