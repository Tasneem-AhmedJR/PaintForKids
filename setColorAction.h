#pragma once
#include"Actions/Action.h"
#include"Figures/CFigure.h"
class setColorAction :public Action
{
	color Clr;
public:
	setColorAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};