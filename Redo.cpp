#include "Redo.h"
#include"ApplicationManager.h"
#include"GUI\input.h"
#include"GUI\Output.h"
Redo::Redo(ApplicationManager* pApp) :Action(pApp)
{
}

void Redo::ReadActionParameters()
{
}

void Redo::Execute()
{
	if (pManager->GetActionList()->canredo())
	{
		pManager->GetActionList()->getList();   //Every action is responsible for redoing itself 
		pManager->GetActionList()->IncrementRedo();    
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("No Action to Redo");
	}

}
