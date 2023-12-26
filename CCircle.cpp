#include "CCircle.h"
#include<cmath>
#include<fstream>
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Cent_P = P1;
	gen_P = P2;
	
}

void CCircle::Draw(Output* pOut)
{
	//Call Output::DrawCircle to draw a Circle on the screen	
	pOut->DrawCircle(Cent_P, gen_P, FigGfxInfo, Selected);
}

bool CCircle::validate(Point P1, Point P2)
{
	double r = CalcRadius(&P1, &P2);
	if (!(P1.y > 50 && P1.y < 600 && P1.y - r > 50 && P1.y + r < 600) || (P1.x == P2.x && P1.y == P2.y))
		return false;
	return true;
}

int CCircle::CalcRadius(Point*p,Point*pcent)
{
	double r = sqrt(pow((pcent->x - p->x), 2) + pow((pcent->y - p->y), 2));
	return r;
}

double CCircle::CalcArea(Point* p)
{
	return 3.14 * pow(CalcRadius(p,&Cent_P), 2);
}

bool CCircle::isInside(Point* p)
{
	if (CalcArea(p) <= CalcArea(&gen_P)) return true;
	return false;
}

void CCircle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage(("ID : ") + to_string(ID) + (" Radius : ") + to_string(CalcRadius(&gen_P, &Cent_P)) + ("Center : ") + to_string(Cent_P.x) + (", ") + to_string(Cent_P.y));
}

int CCircle::getnum()
{
	return 2;
}

void CCircle::Save(ofstream& OutFile)
{
	color DrawColor = FigGfxInfo.DrawClr;
	if (DrawColor == MAGENTA)
		DrawColor = Preclr;
	color FillColor = FigGfxInfo.FillClr;
	if (FigGfxInfo.isFilled == 0)
		FillColor.name = "NO_FILL";
	OutFile << "Circle" << "  " << ID << "   " << Cent_P.x << "   " << Cent_P.y << "   " << gen_P.x << "   " << gen_P.y <<"   "<<DrawColor.name<<"   " <<FillColor.name<< endl;
}

void CCircle::Load(ifstream& Infile)
{
	Selected = 0;
	string C_D;
	string C_F;
	Infile >> ID;
	Infile >> Cent_P.x;
	Infile >> Cent_P.y;
	Infile >> gen_P.x;
	Infile >> gen_P.y;
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

void CCircle::DeleteFig()
{
	delete this;
}

void CCircle::Movefi(Output* pOut, Point p)
{
	Point p1, p2;
	p1.x = gen_P.x + p.x - Cent_P.x;
	p1.y = gen_P.y + p.y - Cent_P.y;
	p2 = p;
	if (validate(p1, p2))
	{
		gen_P = p1;
		Cent_P = p2;
		pOut->PrintMessage("Selected Figure Move");
	}
	else pOut->PrintMessage("Invalid, cannot move figure ");

	//pOut->DrawCircle(Cent_P, gen_P, FigGfxInfo, Selected);
}
