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

bool CSquare::validate(Point P)
{
	if (P.y > 130 && P.y < 520) return true;
	return false;
}

bool CSquare::isInside(Point* p)
{
	if (abs(Center.x - p->x) <= 80 && abs(Center.y - p->y <= 80)) return true;
	return false;
}

void CSquare::PrintInfo(Output* pOut)
{
	pOut->PrintMessage(("ID: ") + to_string(ID) + (" Center: ") + to_string(Center.x) + (" , ") + to_string(Center.y) + (" Area: ") + to_string(160 * 160));
}

void CSquare::DeleteFig()
{
	delete this;
}

void CSquare::Movefi(Output* pOut, Point p)
{
	if (validate(p))
	{
		previous = Center;                          //to store previous point the figure was at
		Center = p; pOut->PrintMessage("Selected Figure Moved");
	}
	else pOut->PrintMessage("Invalid, cannot move figure ");

	//pOut->DrawSquare(Center, FigGfxInfo, 1);
}


int CSquare::getnum()
{
	return 1;
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
	Preclr = FigGfxInfo.DrawClr;
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
