#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
		
public:

	Action(ApplicationManager* pApp) { pManager = pApp; }	//constructor

	virtual void ReadActionParameters() = 0;     // Reads parameters required for action to execute (code depends on action type)
	virtual void Execute() = 0;                  //Execute action (code depends on action type)
	virtual void CancelAction(){}
	virtual void RedoAction(){}
	virtual bool isRecorded() { return true; }  //returns false for actions that are required not to be recorded otherwise true 
	virtual bool canUndone() { return false; }  //returns true for actions that can be undone otherwise false
};

#endif