#pragma once
#include"Actions/Action.h"
#include"Figures/CFigure.h"
class setColorAction :public Action
{
	color Clr;
public:
	setColorAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void changecolorAct(bool, CFigure*, color);
	void Execute();
};