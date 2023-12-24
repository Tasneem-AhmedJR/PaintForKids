#pragma once
#include"Actions/Action.h"
#include "pickbyfill.h"
class pickbytype :public Action
{
	int incorrect;
	int correct;
	Point p1;
	Action* pAct;
	//pickbyfill* ptr1;
public:
	pickbytype(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

