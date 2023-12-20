#include "StartRecAction.h"
#include"ClearAll.h"
#include"GUI\input.h"
#include"GUI\Output.h"
#include"ApplicationManager.h"

StartRecAction::StartRecAction(ApplicationManager* pApp) :Action(pApp) {}

void StartRecAction::ReadActionParameters(){}

bool StartRecAction::isRecorded() { return false; }

void StartRecAction::Execute()
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	if (pManager->getRecorder()->isRecording())
		pOut->PrintMessage("Already recording ");
	else
	{
		if (pManager->getRecorder()->getLastType() == CLEAR_ALL || pManager->getLastAct() == NULL)
		{
			pManager->getRecorder()->setRecording(true);
			pOut->PrintMessage("Recording started");
		}
		else pOut->PrintMessage("Error! please restart the program or clear the drawing area first ");
	}
}
