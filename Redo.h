#pragma once
#include"Actions/Action.h"
class Redo:public Action
{
public:
	Redo(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

