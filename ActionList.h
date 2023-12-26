#pragma once
#include"Actions/Action.h"

Action;
class ActionList
{
	Action* ActList[5];                        //array of last 5 executed actions 
	int LastAction;                            //has the location of last traced action 
	int RedoIndex;
	bool IsRecord;
public:
	ActionList();
	Action* getList();                          //returns last traced action  
	Action* getRedo();                          //Returns action to be redoed 
	void TraceAction(Action*);                  //traces last 5 actions done by the kid
	void Validate();                            //makes sure LastAction index never exceeds scope size
	void IncrementLastAct();                    //increments LastAction index
	void DecrementLastAct();                    //decrements LastAction index
	void IncrementRedo();                       //increments LastAction index
	void DecrementRedo();                       //decrements LastAction index
	void SetRecord(bool x);                     //Sets record true if recording
	void SortActions();                         //sorts the array to overwrite in actlist[4]
	bool canredo();                             //checks position of redo index in actlist
	bool IsTraced(Action*);
	~ActionList();
};

