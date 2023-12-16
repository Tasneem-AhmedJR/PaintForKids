#include "CRectangle.h"
#include<fstream>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	
}
	

void CRectangle::Draw(Output* pOut) 
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

double CRectangle::CalcArea(Point* p)
{
	return abs(Corner1.x - Corner2.x) * abs(Corner1.y - Corner2.y);
}

bool CRectangle::isInside(Point* p)
{
	int maxy = Corner1.y;  int miny = Corner2.y;
	if (Corner2.y > Corner1.y) { maxy = Corner2.y; miny = Corner1.y; }
	int maxx = Corner1.x;  int minx = Corner2.x;
	if (Corner2.x > Corner1.x) { maxx = Corner2.x; minx = Corner1.x; }
	if (p->y <= maxy && p->y >= miny && p->x <= maxx && p->x >= minx) return true;
	return false;
}

void CRectangle::PrintInfo(Output* pOut)
{ 
	CFigure::PrintInfo(pOut);
}


void CRectangle::DeleteFig()
{
	//DeletedFig = this;
	delete this;
}
/*
CFigure* CRectangle::GetDeletedFig()
{
	return DeletedFig;
}
*/
void CRectangle::Save(ofstream& OutFile)
{
	color DrawColor = FigGfxInfo.DrawClr;
	color FillColor = FigGfxInfo.FillClr;
	OutFile << "RECT" << "  " << ID << "   " << Corner1.x << "   " << Corner1.y << "   " << Corner2.x << "   " << Corner2.y << "   " <<DrawColor.name<<"   "<<FillColor.name << endl;
	
}

