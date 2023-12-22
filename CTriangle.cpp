#include "CTriangle.h"
#include<fstream>
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	A = P1;
	B = P2;
	C = P3;
	
}

void CTriangle::Draw(Output* pOut)
{
	//Call Output::DrawTria to draw a Triangle on the screen	
	pOut->DrawTria(A, B,C, FigGfxInfo, Selected);
}

double CTriangle::CalcArea(Point* a, Point* b, Point* c)
{
	return abs(a->x * (b->y - c->y) + b->x * (c->y - a->y) + c->x * (a->y - b->y)) * .5;
}

bool CTriangle::isInside(Point* p)
{
	if (CalcArea(&A, &B, &C) == CalcArea(&A, &B, p) + CalcArea(&A, p, &C) + CalcArea(p, &B, &C))
		return true;
	return false;
}

void CTriangle::PrintInfo(Output* pOut)
{
	CFigure::PrintInfo(pOut);
}

void CTriangle::DeleteFig()
{
	delete this;
}

void CTriangle::Save(ofstream& OutFile)
{
	color DrawColor = FigGfxInfo.DrawClr;
	color FillColor = FigGfxInfo.FillClr;
	if (FigGfxInfo.isFilled == 0)
		FillColor.name = "NO_FILL";
	OutFile << "TRIANG" << "  " << ID << "   " << A.x << "   " << A.y << "   " << B.x << "   " << B.y << "   " <<C.x<<"   " <<C.y<<"   "<<DrawColor.name<<"   " <<FillColor.name<< endl;
}

void CTriangle::Load(ifstream& Infile)
{
	Selected = 0;
	string C_D;
	string C_F;
	Infile >> ID;
	Infile >> A.x;
	Infile >> A.y;
	Infile >> B.x;
	Infile >> B.y;
	Infile >> C.x;
	Infile >> C.y;
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
