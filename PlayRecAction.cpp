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

	if (pManager->getRecorder()->isRecording())       //checks if the recording has stopped
		pOut->PrintMessage("Please stop recording first ");

	else if (pManager->getRecorder()->hasRecordes())  //checks if there's recording history
	{
		pManager->getRecorder()->setNowPlaying(true);
		pManager->ClearingFigures();                 //clear all figures and reset the program to default 

		pOut->PrintMessage("Playing recording");
		pOut->ClearDrawArea();
		Sleep(1000);
		for (int i = 0; i < n; i++)
		{
			list[i]->Execute();                      //excute every action in the recorded actions array 
			pManager->GetActionList()->TraceAction(list[i]);
			pManager->UpdateInterface();
			Sleep(1000);                             //delay 1 second after every excution
		}
		pManager->getRecorder()->setNowPlaying(false); 
		pOut->ClearStatusBar();
	}
	else pOut->PrintMessage("No recording to play ");
}
