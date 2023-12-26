#include "CSquare.h"
#include<cmath>
#include<fstream>
CSquare::CSquare(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P;
	
}

void CSquare::Draw(Output* pOut)
{
	//Call Output::DrawSquare to draw a Square on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

bool CSquare::isInside(Point* p)
{
	if (abs(Center.x - p->x) <= 80 && abs(Center.y - p->y <= 80)) return true;
	return false;
}

void CSquare::PrintInfo(Output* pOut)
{
	pOut->PrintMessage(("ID: ") + to_string(ID) + (" Center: ") + to_string(Center.x) + (" , ") + to_string(Center.y));
}

void CSquare::DeleteFig()
{
	delete this;
}

void CSquare::Movefi(Output* pOut, Point p)
{
	Center = p;
	pOut->DrawSquare(Center, FigGfxInfo, 1);
}

int CSquare::getconstfig()
{
	return 1;                 //the const of the square is considerd 1
}

void CSquare::Save(ofstream& OutFile)
{
	color DrawColor = FigGfxInfo.DrawClr;
	if (DrawColor == MAGENTA)
		DrawColor = Preclr;
	color FillColor = FigGfxInfo.FillClr;
	if (FigGfxInfo.isFilled == 0)
		FillColor.name = "NO_FILL";
	OutFile << "SQUARE" << "  " << ID << "   " << Center.x << "   " << Center.y << "   "<<DrawColor.name<<"   "<<FillColor.name << endl;
}

void CSquare::Load(ifstream& Infile)
{
	Selected = 0;
	string C_D;
	string C_F;
	Infile >> ID;
	Infile >> Center.x;
	Infile >> Center.y;
	Infile >> C_D;
	if (C_D == "BLUE")
		FigGfxInfo.DrawClr = BLUE;
	else if (C_D == "BLACK")
		FigGfxInfo.DrawClr = BLACK;
	else if (C_D == "GREEN")
		FigGfxInfo.DrawClr = GREEN;
	else if (C_D == "YELLOW")
		FigGfxInfo.DrawClr = YELLOW;
	else if (C_D == "ORANGE")
		FigGfxInfo.DrawClr = ORANGE;
	else if (C_D == "RED")
		FigGfxInfo.DrawClr = RED;
	Infile >> C_F;
	if (C_F == "NO_FILL")
		FigGfxInfo.isFilled = 0;
	else FigGfxInfo.isFilled = 1;
	if (C_F == "BLUE")
		FigGfxInfo.FillClr = BLUE;
	else if (C_F == "BLACK")
		FigGfxInfo.FillClr = BLACK;
	else if (C_F == "GREEN")
		FigGfxInfo.FillClr = GREEN;
	else if (C_F == "YELLOW")
		FigGfxInfo.FillClr = YELLOW;
	else if (C_F == "ORANGE")
		FigGfxInfo.FillClr = ORANGE;
	else if (C_F == "RED")
		FigGfxInfo.FillClr = RED;
}
