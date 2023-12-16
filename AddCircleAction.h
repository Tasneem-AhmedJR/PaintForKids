#pragma once
#include"Actions/Action.h"
class AddCircleAction:public Action
{
private:
	Point P1;
	Point P2;
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);
	//Reads Circle parameters
	virtual void ReadActionParameters();
	virtual void CancelAction();
	//Add Circle to the ApplicationManager
	virtual void Execute();
};

