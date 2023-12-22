#pragma once
#include"Actions/Action.h"
#include"Figures/CFigure.h"
class setColorAction :public Action
{
	color Clr;
	ActionType act;
	CFigure* fig;
	bool typ;
public:
	setColorAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void changecolorAct(bool, CFigure*, color);
	void PlayAct();
	void Execute();
};