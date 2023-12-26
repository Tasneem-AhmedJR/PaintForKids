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

Action* ActionList::GetToDelete()
{
	if (ActList[0])
		return ActList[0];
}

void ActionList::TraceAction(Action* p)
{
	if (p->Undoable())
	{
		Validate();
		ActList[LastAction] = p;
		IncrementLastAct();
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
	ActList[0] = NULL;
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

bool ActionList::IsTraced(Action* a)
{
	bool found = false;
	int i = 0;
	while (!found && i < 5)
	{
		if (ActList[i] == a)
			found = true;
		i++;
	}
	return found;
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