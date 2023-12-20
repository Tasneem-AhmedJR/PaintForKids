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

	pOut->PrintMessage("New Hexagon: Click at One Point ");

	//Read point and store in point P1
	pIn->GetPointClicked(P.x, P.y);

	HexaGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddHexaAction::CancelAction()
{
	pManager->DeleteFig(true);                     //calls delete func. in applicationManager to access figlist
	Output* pOut = pManager->GetOutput();      //and delete last added figure
	pOut->ClearDrawArea();
}

void AddHexaAction::Execute()
{
	//Create a rectangle with the parameters read from the user
	hex = new CHexagon(P,HexaGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(hex);
}
