#pragma once
#include"Actions/Action.h"
#include<string.h>
class LoadAction : public Action
{
private:
	string fileName;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

