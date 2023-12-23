#pragma once
#include "Actions\Action.h"
#include "CSquare.h"

class AddSquareAction:public Action
{
private:
	Point P;
	GfxInfo SquareGfxInfo;
	CSquare* sq;
public:
	AddSquareAction(ApplicationManager* pApp);
	//Reads Square parameters
	virtual void ReadActionParameters();
	bool canUndone();
	virtual void RedoAction();
	virtual void CancelAction();
	//Add Square to the ApplicationManager
	virtual void Execute();
};

