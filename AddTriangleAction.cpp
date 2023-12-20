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

	pOut->PrintMessage("New Triangle: Click at first Point");

	//Read 1st Point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second Point");

	//Read 2nd Point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at Third Point");

	//Read 3th Point and store in Point P3
	pIn->GetPointClicked(P3.x, P3.y);
	TriangleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddTriangleAction::CancelAction()
{
	tri->SetVisibility(false);                  //the figure sets its own visibilty to false in order not to be drawn
	Output* pOut = pManager->GetOutput();      //and delete last added figure
	pOut->ClearDrawArea();
}

void AddTriangleAction::Execute()
{	
	//Create a Triangle with the parameters read from the user
	tri = new CTriangle(P1, P2,P3, TriangleGfxInfo);

	//Add the Triangle to the list of figures
	pManager->AddFigure(tri);
}
