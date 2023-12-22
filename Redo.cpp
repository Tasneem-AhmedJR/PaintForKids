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
	if (pManager->Redoable())
	{
		pManager->GetRedoAction()->RedoAction();   //Every action is responsible for redoing itself 
		pManager->IncrRedo();                       //
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("No Action to Redo");
	}

}
