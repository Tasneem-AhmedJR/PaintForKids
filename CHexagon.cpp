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
	if (FigGfxInfo.isFilled == 0)
		FillColor.name = "NO_FILL";
	OutFile << "HEXA" << "  " << ID << "   " << Center.x << "   " << Center.y << "   " <<DrawColor.name<<"   "<<FillColor.name << endl;
}

void CHexagon::Load(ifstream& Infile)
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
