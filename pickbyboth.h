#pragma once
#include"Actions/Action.h"
class pickbyboth :public Action
{
	Action* pAct;
	int incorrect;
	int correct;
	Point p1;
public:
	pickbyboth(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~pickbyboth();
};


