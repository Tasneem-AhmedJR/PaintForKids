#include "RecorderAct.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

RecorderAct::RecorderAct(ApplicationManager* pApp) :Action(pApp)
{
	lastRec = 0;
	recording = false;
	for (int i = 0; i < 20; i++)
		RecList[i] = NULL;
}
void RecorderAct::LastActType(ActionType t) { lastActType = t; }

ActionType RecorderAct::getLastType() { return lastActType; }

void RecorderAct::ReadActionParameters() {}

void RecorderAct::Execute() {}

void RecorderAct::AddrecList(Action* p, ActionType t)
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	if (t == CLEAR_ALL)
	{
		for (int i = 0; i < 20; i++) RecList[i] = NULL;
		lastRec = 0;
	}
	if (t != START) lastActType = t;
	if (recording)
	{
		if (lastRec < 20 && p->isRecorded()) { RecList[lastRec] = p; lastRec++; }
		if (lastRec >= 20)
		{
			pOut->PrintMessage("Recording has ended ");
			setRecording(false);
		}
	}
}

void RecorderAct::setRecording(bool b) { recording = b; }

bool RecorderAct::isRecording() { return recording; }

Action** RecorderAct::getRecList() { return RecList; }

int RecorderAct::getlastRec() { return lastRec; }

bool RecorderAct::hasRecordes()
{
	if (RecList[0] == NULL) return false;
	return true;
}