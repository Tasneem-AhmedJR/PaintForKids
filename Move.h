#pragma once
#include"Figures/CFigure.h"
#include"Actions/Action.h"
class Move : public Action
{
	Point p1;
	CFigure* f;
public:
	Move(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual bool Undoable();
	virtual void CancelAction();
	virtual void RedoAction();
};

