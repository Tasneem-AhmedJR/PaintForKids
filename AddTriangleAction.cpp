#include "AddTriangleAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

AddTriangleAction::AddTriangleAction( ApplicationManager* pApp):Action(pApp)
{
	
}

void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int i = 0;

	do {
		if (i > 0)
		{
			pOut->PrintMessage("Invalid. Please click another three points :) ");
			Sleep(1000);
		}
		pOut->PrintMessage("New Triangle: Click at first Point");
		pIn->GetPointClicked(P1.x, P1.y);    //Read 1st Point and store in point P1

		pOut->PrintMessage("New Triangle: Click at second Point");
		pIn->GetPointClicked(P2.x, P2.y);    //Read 2nd Point and store in point P2

		pOut->PrintMessage("New Triangle: Click at Third Point");
		pIn->GetPointClicked(P3.x, P3.y);    //Read 3th Point and store in Point P3

		i++;
	} while (!(P1.y > 50 && P2.y > 50 && P3.y > 50) || !(P1.y < 600 && P2.y < 600 && P3.y < 600));

	TriangleGfxInfo.isFilled = pOut->isFilled();;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddTriangleAction::RedoAction()
{
	pManager->setfigureCount(pManager->getfigureCount() + 1);
	tri->SetVisibility(true);
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
}

void AddTriangleAction::CancelAction()
{
	pManager->setfigureCount(pManager->getfigureCount() - 1);
	tri->SetVisibility(false);                  //the figure sets its own visibilty to false in order not to be drawn
	Output* pOut = pManager->GetOutput();      //and delete last added figure
	pOut->ClearDrawArea();
}

bool AddTriangleAction::Undoable() { return true; }

void AddTriangleAction::Execute()
{	
	if (!pManager->getRecorder()->isPlayingNow())

	ReadActionParameters();  //must read Action parameters first
	//Create a Triangle with the parameters read from the user
	tri = new CTriangle(P1, P2,P3, TriangleGfxInfo);

	//Add the Triangle to the list of figures
	pManager->AddFigure(tri);
}
