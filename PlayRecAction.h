#pragma once
#include"Actions/Action.h" 

class PlayRecAction:public Action
{
public:
	PlayRecAction(ApplicationManager* pApp);
	bool isRecorded();
	void ReadActionParameters();
	void Execute();
};

