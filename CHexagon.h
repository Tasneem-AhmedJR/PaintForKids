#pragma once
#include"Figures/CFigure.h"
class CHexagon:public CFigure
{
private:
	Point Center;
public:
	CHexagon(){}
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut);
	bool validate(Point);                // checks if the figure is inside the drawing area
	double CalcArea(Point* p);           //calculate area of the hexagon
	bool isInside(Point* p);             
	void PrintInfo(Output* pOut);        
	virtual void DeleteFig();
	virtual void Movefi(Output* pOut, Point p);
	virtual int getnum();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};

