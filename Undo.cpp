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
	if ((pManager->GetActionList()->getList()) != NULL)
	{
		pManager->GetActionList()->getList()->CancelAction();   //Every action is responsible for canceling itself 
		pManager->GetActionList()->DecrementLastAct();          //Decrements last Action index only if last traced action was undone

	}
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("No Action to Undo");
	}

}
