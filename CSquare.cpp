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
	CFigure::PrintInfo(pOut);
}

void CSquare::DeleteFig()
{
	delete this;
}

void CSquare::Save(ofstream& OutFile)
{
	color DrawColor = FigGfxInfo.DrawClr;
	color FillColor = FigGfxInfo.FillClr;
	OutFile << "SQUARE" << "  " << ID << "   " << Center.x << "   " << Center.y << "   "<<DrawColor.name<<"   "<<FillColor.name << endl;
}
