#pragma once
#include "Actions/Action.h"
class SoundAction :public Action
{
public:
	SoundAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};


