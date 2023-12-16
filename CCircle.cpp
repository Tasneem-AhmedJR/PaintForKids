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

int CCircle::CalcRadius(Point*p)
{
	double r = sqrt(pow((Cent_P.x - p->x), 2) + pow((Cent_P.y - p->y), 2));
	return r;
}

double CCircle::CalcArea(Point* p)
{
	return 3.14 * pow(CalcRadius(p), 2);
}

bool CCircle::isInside(Point* p)
{
	if (CalcArea(p) <= CalcArea(&gen_P)) return true;
	return false;
}

void CCircle::PrintInfo(Output* pOut)
{
	CFigure::PrintInfo(pOut);
	pOut->PrintMessage("Redius : " + CalcRadius(&gen_P));
}

void CCircle::Save(ofstream& OutFile)
{
	color DrawColor = FigGfxInfo.DrawClr;
	color FillColor = FigGfxInfo.FillClr;
	OutFile << "Circle" << "  " << ID << "   " << Cent_P.x << "   " << Cent_P.y << "   " << gen_P.x << "   " << gen_P.y <<"   "<<DrawColor.name<<"   " <<FillColor.name<< endl;
}

void CCircle::DeleteFig()
{
	delete this;
}
