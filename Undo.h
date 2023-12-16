#pragma once
#include"Actions/Action.h"

class Undo:public Action
{
public:
	Undo(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

