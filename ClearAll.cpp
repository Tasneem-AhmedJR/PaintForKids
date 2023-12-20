#include "ClearAll.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

ClearAll::ClearAll(ApplicationManager* pApp) :Action(pApp)
{
}

void ClearAll::ReadActionParameters()
{
	
}

void ClearAll::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Cleared All Figures");
	pOut->ClearDrawArea();
	pManager->ClearingFigures();           //calls a function in Application Manager to get access to figlist
}

bool ClearAll::isRecorded() { return false; }
