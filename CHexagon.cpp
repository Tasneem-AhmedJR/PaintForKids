#include "CHexagon.h"
#include"CTriangle.h"
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

bool CHexagon::validate(Point P)
{
	if (P.y < 130 || P.y>530) return false;
	return true;
}

bool CHexagon::isInside(Point* p)
{
	//devide the hexagon into small triangle and check if the given point is inside any of them  
	Point p1, p2, p3, p4, p5, p6;
	float a = 0.8660254038 * 80;
	p1.x = Center.x + 40;      p1.y = Center.y;
	p2.x = Center.x + 20;      p2.y = Center.y + a;
	p3.x = Center.x - 20;      p3.y = Center.y + a;
	p4.x = Center.x - 40;      p4.y = Center.y;
	p5.x = p3.x;               p5.y = Center.y - a;
	p6.x = p2.x;               p6.y = p5.y;
	CTriangle t1(p1, p2, Center, FigGfxInfo), t2(p2, p3, Center, FigGfxInfo), t3(p3, p4, Center, FigGfxInfo), t4(p4, p5, Center, FigGfxInfo), t5(p5, p6, Center, FigGfxInfo), t6(p6, p1, Center, FigGfxInfo);
	if (t1.isInside(p) || t2.isInside(p) || t3.isInside(p) || t4.isInside(p) || t5.isInside(p) || t6.isInside(p))
		return true;
	return false;

}

void CHexagon::PrintInfo(Output* pOut)
{
	pOut->PrintMessage(("ID : ") + to_string(ID) + (" Center : ") + to_string(Center.x) + (", ") + to_string(Center.y));

}

void CHexagon::DeleteFig()
{
	delete this;
}

void CHexagon::Movefi(Output* pOut, Point p)
{
	if(validate(p))
	{
		previous = Center;                          //to store previous point the figure was at
		Center = p;
		pOut->PrintMessage("Selected Figure Move");
	}
	else pOut->PrintMessage("Invalid, cannot move figure ");
		
	//pOut->DrawHexa(Center, FigGfxInfo, Selected);
}

int CHexagon::getconstfig()
{
	return 3;      //the const of the hexa is considerd 3
}

void CHexagon::Save(ofstream& OutFile)
{
	color DrawColor = FigGfxInfo.DrawClr;
	if (DrawColor == MAGENTA)
		DrawColor = Preclr;
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
