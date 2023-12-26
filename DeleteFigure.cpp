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

void DeleteFigure::RedoAction()
{
	f->SetVisibility(false);
	pManager->DeleteFig(f);
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
}

bool DeleteFigure::Undoable()
{
	return true;
}


void DeleteFigure::CancelAction()
{
	f->SetVisibility(true);
	pManager->AddFigure(f);
}

void DeleteFigure::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getSelectedFig())                    //to only be called if there is a selected fig
	{
		f = pManager->getSelectedFig();
		pManager->DeleteFig(f);                       //calls delete func. in applicationManager to access figlist
		pOut->PrintMessage("Selected Figure Deleted");
		pManager->setSelectedFig(NULL);
		f->SetSelected(false);
		f->ChngDrawClr(f->GetDrawClr());
		pOut->ClearDrawArea();
	}
	else
		pOut->PrintMessage("Select a Figure to Delete");
}

DeleteFigure::~DeleteFigure()
{
	if (!f->GetVisibility())
		delete f;
}
