#include "LoadAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include<fstream>
#include"CMUgraphicsLib/colors.h"
#include"GUI/UI_Info.h"
#include"CCircle.h"
#include"CHexagon.h"
#include"CSquare.h"
#include"CTriangle.h"
#include"Figures/CRectangle.h"


LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Enter the File name To Load Your figures from");
	fileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->WhenLoad();
	string C_D;
	string C_F;
	string FigureType;
	int num_fig;
	CFigure* MyFig = NULL;
	//This action needs to read some parameters first
	ReadActionParameters();
	ifstream infile;
	infile.open(fileName);
	if (infile.is_open())
	{
		infile >> C_D;
		if (C_D == "BLUE")
			UI.DrawColor = BLUE;
		else if (C_D == "BLACK")
			UI.DrawColor = BLACK;
		else if (C_D == "GREEN")
			UI.DrawColor = GREEN;
		else if (C_D == "YELLOW")
			UI.DrawColor = YELLOW;
		else if (C_D == "ORANGE")
			UI.DrawColor = ORANGE;
		else if (C_D == "RED")
			UI.DrawColor = RED;
		infile >> C_F;
		if (C_F == "BLUE")
			UI.FillColor = BLUE;
		else if (C_F == "BLACK")
			UI.FillColor = BLACK;
		else if (C_F == "GREEN")
			UI.FillColor = GREEN;
		else if (C_F == "YELLOW")
			UI.FillColor = YELLOW;
		else if (C_F == "ORANGE")
			UI.FillColor = ORANGE;
		else if (C_F == "RED")
			UI.FillColor = RED;
		infile >> num_fig;
		pManager->setfigureCount(num_fig);
		for (int i = 0; i < num_fig; i++)
		{
			infile >> FigureType;
			if (FigureType == "RECT")
				MyFig = new CRectangle;
			else if (FigureType == "TRIANG")
				MyFig = new CTriangle;
			else if (FigureType == "HEXA")
				MyFig = new CHexagon;
			else if (FigureType == "Circle")
				MyFig = new CCircle;
			else if (FigureType == "SQUARE")
				MyFig = new CSquare;
			if (MyFig != NULL)
			{
				MyFig->Load(infile);
				pManager->AddFigure(MyFig);
			}
		}
		infile.close();
	}
	else pOut->PrintMessage("Couldn't open the file");
}
