#pragma once
#include"Actions/Action.h"
class AddTriangleAction:public Action
{
private:
	Point P1;
	Point P2;
	Point P3;
	GfxInfo TriangleGfxInfo;
public:
	AddTriangleAction( ApplicationManager* pApp);
	//Reads Triangle parameters
	virtual void ReadActionParameters();
	virtual void CancelAction();
	//Add Triangle to the ApplicationManager
	virtual void Execute();
};

