#pragma once
#include"Actions/Action.h"
#include"Figures/CFigure.h"
class SelectAction:public Action
{
	Point P; CFigure* Fig; 
public:
	SelectAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Select(CFigure*);
	void Unselect(CFigure*);
	void PlayAct();
	void Execute();
};