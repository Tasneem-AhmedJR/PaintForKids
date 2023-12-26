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
	ActionType getLastType();               //return the type of the last action before recording
	void AddrecList(Action*, ActionType);   //add actions to the recorded actions array
	void setRecording(bool);                
	bool isRecording();                     //checks if the program is recording
	void setNowPlaying(bool);
	bool isPlayingNow();                    //checks if any recording is now playing
	Action** getRecList();                  //returns the recorded actions array 
	int getlastRec();                       //returns the index of the last recorded action
	bool hasRecordes();                     //checks if any recording history exists
	void ReadActionParameters();
	void Execute();

};

