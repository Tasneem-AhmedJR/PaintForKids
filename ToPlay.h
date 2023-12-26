#pragma once
#include"Actions/Action.h"
class ToPlay :  public Action
{
public:
	ToPlay(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	void Execute();
	virtual bool isRecorded();

};

