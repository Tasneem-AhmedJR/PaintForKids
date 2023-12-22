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
	double CalcArea(Point* p);
	bool isInside(Point* p);
	void PrintInfo(Output* pOut);
	virtual void DeleteFig();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};

