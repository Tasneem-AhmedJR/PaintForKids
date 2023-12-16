#include "CHexagon.h"
#include<cmath>
#include<fstream>

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P;
	
}

void CHexagon::Draw(Output* pOut)
{
	//Call Output::DrawHexa to draw a Hexagon on the screen	
	pOut->DrawHexa(Center, FigGfxInfo, Selected);
}

double CHexagon::CalcArea(Point* p)
{
	double a = sqrt(pow(Center.x-p->x,2) + pow(Center.y-p->y,2));
	return a * a * 3 * sqrt(3) / 2;
}

bool CHexagon::isInside(Point* p)
{
	if (CalcArea(p) <= 3200 * sqrt(3)) return true;
	return false;
}

void CHexagon::PrintInfo(Output* pOut)
{
	CFigure::PrintInfo(pOut);
}

void CHexagon::DeleteFig()
{
	delete this;
}

void CHexagon::Save(ofstream& OutFile)
{
	color DrawColor = FigGfxInfo.DrawClr;
	color FillColor = FigGfxInfo.FillClr;
	OutFile << "HEXA" << "  " << ID << "   " << Center.x << "   " << Center.y << "   " <<DrawColor.name<<"   "<<FillColor.name << endl;
}
