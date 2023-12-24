#pragma once
#include "pickbytype.h"
#include"Actions/Action.h"

class pickbyfill :public Action
{
//	pickbytype* ptr;
	Action* pAct;
	int incorrect;
	int correct;
	Point p1;
public:
	pickbyfill(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

