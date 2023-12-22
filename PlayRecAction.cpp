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
		pManager->getRecorder()->setNowPlaying(true);
		pManager->reset();

		pOut->ClearDrawArea();
		Sleep(1000);
		for (int i = 0; i < n; i++)
		{
			list[i]->PlayAct();
			Sleep(1000);
		}
		pManager->getRecorder()->setNowPlaying(false);
	}
	else pOut->PrintMessage("No recording to play ");
}
