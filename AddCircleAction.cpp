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
	double r; int i = 0;

	do
	{
		if (i > 0)
		{
			pOut->PrintMessage("Invalid. Please click another two points :) ");
			Sleep(1000);
		}

		pOut->PrintMessage("New Circle: Click at first Point");
		pIn->GetPointClicked(P1.x, P1.y);              //Read 1st Point and store in point P1

		pOut->PrintMessage("New Circle: Click at second Point");
		pIn->GetPointClicked(P2.x, P2.y);              //Read 2nd Point and store in point P2

		r = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));    //calculate radius of the circle
		i++;
		 
	} while (!circ->validate(P1, P2));   //make sure the figure is not drawn outside drawing area
	
	CircleGfxInfo.isFilled = pOut->isFilled();;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddCircleAction::RedoAction()
{
	pManager->setfigureCount(pManager->getfigureCount() + 1);
	circ->SetVisibility(true);
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
}

void AddCircleAction::CancelAction()
{
	pManager->setfigureCount(pManager->getfigureCount() - 1);
	circ->SetVisibility(false);                 //the figure sets its own visibilty to false in order not to be drawn
	Output* pOut = pManager->GetOutput();      //and delete last added figure
	pOut->ClearDrawArea();
}

bool AddCircleAction::canUndone() { return true; }

void AddCircleAction::Execute()
{
	if (!pManager->getRecorder()->isPlayingNow())

	ReadActionParameters();  //must read Action parameters first
	//Create a Circle with the parameters read from the user
	circ = new CCircle(P1, P2, CircleGfxInfo);

	//Add the Circle to the list of figures
	pManager->AddFigure(circ);
}