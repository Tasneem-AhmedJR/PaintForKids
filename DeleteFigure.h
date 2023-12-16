#pragma once
#include"Actions/Action.h"
#include"Figures/CFigure.h"
class DeleteFigure:public Action
{
	CFigure* f;
public:
	DeleteFigure(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void CancelAction();
	virtual void Execute();
};

