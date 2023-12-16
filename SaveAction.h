#pragma once
#include"Actions/Action.h"
#include<string.h>
class SaveAction:public Action
{
private:
	string fileName;

public:
	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

