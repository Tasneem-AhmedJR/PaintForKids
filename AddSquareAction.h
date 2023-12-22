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
	virtual void CancelAction();
	void PlayAct();
	//Add Square to the ApplicationManager
	virtual void Execute();
};

