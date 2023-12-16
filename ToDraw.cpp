#include "ToDraw.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

ToDraw::ToDraw(ApplicationManager* pApp):Action(pApp)
{
}

void ToDraw::ReadActionParameters()
{
}

void ToDraw::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Switching to Draw Mode, Creating simualtion tool bar");
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
}
