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
	if (FigGfxInfo.isFilled == 0)
		FillColor.name = "NO_FILL";
	OutFile << "RECT" << "  " << ID << "   " << Corner1.x << "   " << Corner1.y << "   " << Corner2.x << "   " << Corner2.y << "   " <<DrawColor.name<<"   "<<FillColor.name << endl;
	
}

void CRectangle::Load(ifstream& Infile)
{
	Selected = 0;
	string C_D;
	string C_F;
	Infile >> ID;
	Infile >> Corner1.x;
	Infile >> Corner1.y;
	Infile >> Corner2.x;
	Infile >> Corner2.y;
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

