#include "AddCircleAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at first Point");

	//Read 1st Point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at second Point");

	//Read 2nd Point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	CircleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddCircleAction::CancelAction()
{
	pManager->DeleteFig(true);                     //calls delete func. in applicationManager to access figlist
	Output* pOut = pManager->GetOutput();      //and delete last added figure
	pOut->ClearDrawArea();
}

void AddCircleAction::Execute()
{
	//Create a Circle with the parameters read from the user
	circ = new CCircle(P1, P2, CircleGfxInfo);

	//Add the Circle to the list of figures
	pManager->AddFigure(circ);
}
