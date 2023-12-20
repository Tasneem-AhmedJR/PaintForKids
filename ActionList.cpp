#include "ActionList.h"
#include "GUI\output.h"
#include"StopRecAction.h"
#include"ApplicationManager.h"

ActionList::ActionList()
{
	LastAction = 0;
	for (int i = 0; i < 5; i++)
		ActList[i] = NULL;
}

Action* ActionList::getList()
{ 
	if (ActList[LastAction - 1] && LastAction != 0)
	{
		return ActList[LastAction - 1];
	}
	else return NULL;
}

void ActionList::TraceAction(Action* p,ActionType t)
{
	switch (t)
	{
	case DRAW_RECT:
	case DRAW_SQUARE:
	case DRAW_CIRCLE:
	case DRAW_TRIANGLE:
	case DRAW_HEXA:
	
		ActList[LastAction] = p;
		IncrementLastAct();

	/*
	case FILL:
	case FIG:
	case ITMDELETE:*/
	default:
		break;
	}
}

void ActionList::Validate()
{
	if (LastAction == 5)
	{
		SortActions();
		LastAction = 4;
	}
}

void ActionList::IncrementLastAct()
{
	if (LastAction <= 4)
		LastAction++;
	Validate();
}

void ActionList::DecrementLastAct()
{
	LastAction--;
}

void ActionList::SortActions()
{
	delete ActList[0];
	for (int i = 0; i < 4; i++)
	{
		swap(ActList[i], ActList[i + 1]);
	}
}

ActionList::~ActionList()
{
	for (int i = 0; i < 5; i++)
	{
		if (ActList[i])
		{
			delete ActList[i];
			ActList[i] = NULL;
		}
	}
}