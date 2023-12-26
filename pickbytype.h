#pragma once
#include"Actions/Action.h"
#include "pickbyfill.h"
class pickbytype :public Action
{
	int incorrect;
	int correct;
	Point p1;
	Action* pAct;
	public:
	pickbytype(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual bool isRecorded();

	~pickbytype();
};

