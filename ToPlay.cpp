#include "ToPlay.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
ToPlay::ToPlay(ApplicationManager* pApp):Action(pApp)
{
}
void ToPlay::ReadActionParameters()
{
}

void ToPlay::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Switching to Play Mode, Creating simualtion tool bar");
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
	

}

bool ToPlay::isRecorded()
{
	return false;
}
