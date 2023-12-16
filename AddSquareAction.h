#pragma once
#include "Actions\Action.h"
class AddSquareAction:public Action
{
private:
	Point P;
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);
	//Reads Square parameters
	virtual void ReadActionParameters();
	virtual void CancelAction();
	//Add Square to the ApplicationManager
	virtual void Execute();
};

