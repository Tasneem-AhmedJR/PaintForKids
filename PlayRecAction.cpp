#include "PlayRecAction.h"
#include"ApplicationManager.h"

PlayRecAction::PlayRecAction(ApplicationManager* pApp) :Action(pApp) {}

bool PlayRecAction::isRecorded() { return false; }

void PlayRecAction::ReadActionParameters() {}

void PlayRecAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Action** list = pManager->getRecorder()->getRecList();
	int n = pManager->getRecorder()->getlastRec();

	if (pManager->getRecorder()->isRecording())
		pOut->PrintMessage("Please stop recording first ");

	else if (pManager->getRecorder()->hasRecordes())
	{
		pOut->ClearDrawArea();
		for (int i = 0; i < n; i++)
		{
			list[i]->Execute();
			Sleep(1000);
		}
		pOut->PrintMessage("playsquare called");
	}
	else pOut->PrintMessage("No recording to play ");
}
