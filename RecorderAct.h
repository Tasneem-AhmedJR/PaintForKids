#pragma once
#include"Actions/Action.h"

class RecorderAct:public Action
{
	int lastRec;
	ActionType lastActType;
	Action* RecList[20];
	bool recording;
	bool NowPlaying;
public:
	RecorderAct(ApplicationManager* pApp);
	void LastActType(ActionType);
	ActionType getLastType();
	void AddrecList(Action*, ActionType);
	void setRecording(bool);
	bool isRecording();
	void setNowPlaying(bool);
	bool isPlayingNow();
	Action** getRecList();
	int getlastRec();
	bool hasRecordes();
	void ReadActionParameters();
	void Execute();

};

