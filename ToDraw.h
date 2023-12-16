#pragma once
#include"Actions/Action.h"
class ToDraw:public Action
{
public:
	ToDraw(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	void Execute();

};

