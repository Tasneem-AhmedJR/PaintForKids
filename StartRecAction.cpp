#include "StartRecAction.h"
#include"GUI\input.h"
#include"GUI\Output.h"
#include"ApplicationManager.h"

StartRecAction::StartRecAction(ApplicationManager* pApp) :Action(pApp) {}

void StartRecAction::ReadActionParameters(){}

bool StartRecAction::isRecorded() { return false; }

void StartRecAction::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	
	if (pManager->getLastAct() == NULL)
	{
		pManager->setrecording(true);
		pOut->PrintMessage("Recording started");
	}
	else pOut->PrintMessage("Error! please restart the program or clear the drawing area first ");
}
