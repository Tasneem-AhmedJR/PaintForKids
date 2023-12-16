#pragma once
#include"Actions/Action.h"
class AddHexaAction:public Action
{
private:
	Point P;
	GfxInfo HexaGfxInfo;
public:
	AddHexaAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();
	virtual void CancelAction();
	//Add Hexagon to the ApplicationManager
	virtual void Execute();
};

