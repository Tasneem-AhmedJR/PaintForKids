#pragma once

#include"Actions/Action.h"
class Move : public Action
{
	Point p1;
public:
	Move(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

