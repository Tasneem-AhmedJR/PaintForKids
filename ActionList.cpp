#include "ActionList.h"
#include "GUI\output.h"
#include"ApplicationManager.h"

ActionList::ActionList()
{
	RedoIndex = -1;
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

Action* ActionList::getRedo()
{
	if (ActList[RedoIndex] && RedoIndex != -1)
		return ActList[RedoIndex];
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
	case FILL:
	case ITMDELETE:
	case FIG:
		Validate();
		ActList[LastAction] = p;
		IncrementLastAct();
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
}

void ActionList::DecrementLastAct()
{
	RedoIndex = LastAction-- - 1;
	//RedoIndex = LastAction--;
}

void ActionList::IncrementRedo()
{
	RedoIndex++;
	LastAction++;
}

void ActionList::DecrementRedo()
{
	RedoIndex--;
}

void ActionList::SortActions()
{
	delete ActList[0];
	for (int i = 0; i < 4; i++)
	{
		swap(ActList[i], ActList[i + 1]);
	}
}

bool ActionList::canredo()
{
	if (RedoIndex == -1 || RedoIndex >= 5 || ActList[RedoIndex] == NULL)
		return false;
	else return true;
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