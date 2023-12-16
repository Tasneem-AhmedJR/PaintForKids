#include "AddSquareAction.h"
#include "CSquare.h"
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

	pOut->PrintMessage("New Square: Click at One Point");

	//Read one point store in point P
	pIn->GetPointClicked(P.x, P.y);

	SquareGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddSquareAction::CancelAction()
{
	pManager->DeleteFig(true);                     //calls delete func. in applicationManager to access figlist
	Output* pOut = pManager->GetOutput();          //and delete last added figure
	pOut->ClearDrawArea();
}

void AddSquareAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Square with the parameters read from the user
	CSquare* S = new CSquare(P, SquareGfxInfo);

	//Add the Square to the list of figures
	pManager->AddFigure(S);
}
