#include "StopRecAction.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"

StopRecAction::StopRecAction(ApplicationManager* pApp) :Action(pApp) {}

bool StopRecAction::isRecorded() { return false; }

void StopRecAction::ReadActionParameters() {}

void StopRecAction::Execute()
{
	//Get a Pointer to the Output Interfaces
		Output* pOut = pManager->GetOutput();

		if (pManager->getRecorder()->isRecording())
		{
			pManager->getRecorder()->setRecording(false);
			pOut->PrintMessage("Recording has ended ");
		}

		else pOut->PrintMessage("Error, nothing is being recorded ");
}
