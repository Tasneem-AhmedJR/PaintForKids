#include "Undo.h"
#include"GUI\input.h"
#include"GUI\Output.h"
#include"ApplicationManager.h"

Undo::Undo(ApplicationManager* pApp) :Action(pApp)
{
}

void Undo::ReadActionParameters()
{

}

void Undo::Execute()
{
	int c = pManager->getfigureCount();
	if ((pManager->GetActionList()->getList()) != NULL && c != 0)                      //To ensure that there is an action traced to undo 
	{                                                                                  //and it wasn't preceeded by Clear All 
		pManager->GetActionList()->getList()->CancelAction();                          //Every action is responsible for canceling itself 
		pManager->GetActionList()->DecrementLastAct();                                 //Decrements last Action index only if last traced action was undone

	}
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("No Action to Undo");
	}

}
