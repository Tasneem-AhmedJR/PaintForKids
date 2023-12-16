#include "SaveAction.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"
#include<fstream>
#include"CMUgraphicsLib/colors.h"
using namespace std;
SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Enter the File name To Save Your figures on");
	fileName=pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	GfxInfo gfxInfo;
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	ofstream outfile;
	outfile.open(fileName);
    color DrawColor= pOut->getCrntDrawColor();
    color FillColor=pOut->getCrntFillColor();
    outfile << DrawColor.name << "   " << FillColor.name << endl;
	outfile << pManager->getfigureCount()<<endl;
	pManager->SaveAll(outfile);
	outfile.close();

}
