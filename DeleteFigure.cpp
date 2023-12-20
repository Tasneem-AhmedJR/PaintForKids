#include "DeleteFigure.h"
#include"Figures/CFigure.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

DeleteFigure::DeleteFigure(ApplicationManager* pApp):Action(pApp)
{
}

void DeleteFigure::ReadActionParameters()
{  
}

void DeleteFigure::CancelAction()
{
	f->SetVisibility(true);
	//pManager->AddFigure(f); planA
	//pManager->AddFigure(pManager->deleted fig);
}

void DeleteFigure::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getSelectedFig())                    //to only be called if there is a selected fig
	{
		f = pManager->getSelectedFig();
		pManager->DeleteFig(false);                    //calls delete func. in applicationManager to access figlist
		pOut->PrintMessage("Selected Figure Deleted");
		pOut->ClearDrawArea();
		pManager->setSelectedFig(NULL);
	}
	else
		pOut->PrintMessage("Select a Figure to Delete");
}
