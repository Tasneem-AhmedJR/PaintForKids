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

bool CTriangle::validate(Point P1 , Point P2, Point P3)
{
	if (!(P1.y > 50 && P2.y > 50 && P3.y > 50) || !(P1.y < 600 && P2.y < 600 && P3.y < 600))
		return false;
	return true;
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
	pOut->PrintMessage(("ID : ") + to_string(ID) + (" Corner 1: ") + to_string(A.x) + (" , ") + to_string(A.y) + (" Corner 2: ") + to_string(B.x) + (" , ") + to_string(B.y) + (" Corner 3: ") + to_string(C.x) + (" , ") + to_string(C.y));
}

void CTriangle::Movefi(Output* pOut, Point p)
{
	Point o, a, b, c;
	o.x = (A.x + B.x + C.x) / 3;
	o.y = (A.y + B.y + C.y) / 3;

	a.x = A.x + p.x - o.x;
	a.y =A.y + p.y - o.y;

	b.x = B.x + p.x - o.x;
	b.y = B.y + p.y - o.y;

	c.x = C.x + p.x - o.x;
	c.y = C.y + p.y - o.y;

	if (validate(a,b,c))
	{
		A = a; B = b; C = c;
		pOut->PrintMessage("Selected Figure Move");
	}
	else pOut->PrintMessage("Invalid, cannot move figure ");

	//pOut->DrawTria(A, B, C, FigGfxInfo, Selected);
}

int CTriangle::getnum()
{
	return 4;
}

void CTriangle::DeleteFig()
{
	delete this;
}

void CTriangle::Save(ofstream& OutFile)
{
	color DrawColor = FigGfxInfo.DrawClr;
	if (DrawColor == MAGENTA)
		DrawColor = Preclr;
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
