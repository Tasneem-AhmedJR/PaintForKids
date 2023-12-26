#include "RecorderAct.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

RecorderAct::RecorderAct(ApplicationManager* pApp) :Action(pApp)
{
	lastRec = 0;
	lastActType = EMPTY;
	recording = false; 
	NowPlaying = false;
	for (int i = 0; i < 20; i++)
		RecList[i] = NULL;
}

ActionType RecorderAct::getLastType() { return lastActType; }

void RecorderAct::ReadActionParameters() {}

void RecorderAct::Execute() {}

RecorderAct::~RecorderAct()
{
	for (int i = 0; i < 20; i++)
		if (RecList[i] != NULL)
		{
			delete RecList[i]; RecList[i] = NULL;
		}
}

void RecorderAct::AddrecList(Action* p, ActionType t)
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	//reset recording history after clear all action 
	if (t == CLEAR_ALL)
	{
		for (int i = 0; i < 20; i++) { delete RecList[i]; RecList[i] = NULL; }
		lastRec = 0;
	}
	//delete actions that cannot be recorded/undone
	if (!p->isRecorded() || (!recording && !pManager->GetActionList()->IsTraced(p))) 
	{ 
		if (p != NULL)
		{ delete p; p = NULL; }
	}

	if (t != START) lastActType = t;  

	if (recording && p)       //record actions if the program is currently recording
	{
		if (lastRec < 20 && p->isRecorded()) { RecList[lastRec] = p; lastRec++; }

		//stops recording when the actions reach 20 
		if (lastRec >= 20)
		{
			pOut->PrintMessage("Recording has ended ");
			setRecording(false);
		}
	}
}

void RecorderAct::setRecording(bool b) { recording = b; }

bool RecorderAct::isRecording() { return recording; }

void RecorderAct::setNowPlaying(bool b) { NowPlaying = b; }

bool RecorderAct::isPlayingNow() { return NowPlaying; }

Action** RecorderAct::getRecList() { return RecList; }

int RecorderAct::getlastRec() { return lastRec; }

bool RecorderAct::hasRecordes()
{
	if (RecList[0] == NULL) return false;
	return true;
}