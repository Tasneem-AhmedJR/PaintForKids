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
	OutFile << "TRIANG" << "  " << ID << "   " << A.x << "   " << A.y << "   " << B.x << "   " << B.y << "   " <<C.x<<"   " <<C.y<<"   "<<DrawColor.name<<"   " <<FillColor.name<< endl;
}
