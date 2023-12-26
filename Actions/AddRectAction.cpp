#include "AddRectAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int i = 0;
	do
	{
		if (i > 0)
		{
			pOut->PrintMessage("Invalid. Please click another two points :) ");
			Sleep(1000);
		}

		pOut->PrintMessage("New Rectangle: Click at first corner");
		pIn->GetPointClicked(P1.x, P1.y);  //Read 1st corner and store in point P1

		pOut->PrintMessage("New Rectangle: Click at second corner");
		pIn->GetPointClicked(P2.x, P2.y);   //Read 2nd corner and store in point P2

		i++;
	} while (!rect->validate(P1, P2));
	

	RectGfxInfo.isFilled = pOut->isFilled();;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

bool AddRectAction::canUndone() { return true; }

void AddRectAction::CancelAction()
{
	pManager->setfigureCount(pManager->getfigureCount() - 1);
	rect->SetVisibility(false);                     //the figure sets its own visibilty to false in order not to be drawn 
	Output* pOut = pManager->GetOutput();        
	pOut->ClearDrawArea();
}

void AddRectAction::RedoAction()
{
	pManager->setfigureCount(pManager->getfigureCount() + 1);
	rect->SetVisibility(true);
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
}

//Execute the action
void AddRectAction::Execute() 
{
	if (!pManager->getRecorder()->isPlayingNow())

	ReadActionParameters();  //must read Action parameters first
	//Create a rectangle with the parameters read from the user
	rect = new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(rect);
}

