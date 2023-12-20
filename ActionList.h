#pragma once
#include"Actions/Action.h"

Action;
class ActionList
{
	Action* ActList[5];                        //array of last 5 executed actions 
	int LastAction;                            //has the location of last traced action 
	
public:
	ActionList();
	Action* getList();
	void TraceAction(Action*,ActionType);       // traces actions to be undone
	void Validate();                            //makes sure LastAction index never exceeds scope size
	void IncrementLastAct();                    //increments LastAction index
	void DecrementLastAct();                    //decrements LastAction index
	void SortActions();                         //deletes oldest traced action then sorts the array to overwrite in actlist[4]
	~ActionList();
};

