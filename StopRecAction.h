#pragma once
#include"Actions/Action.h"

class StopRecAction:public Action
{	
public:
	StopRecAction(ApplicationManager* pApp);
	bool isRecorded();
	void ReadActionParameters();
	void Execute();
};

