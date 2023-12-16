#pragma once
#include"Figures/CFigure.h"
class CCircle:public CFigure
{
private:
	Point F_P;
	Point S_P;
	Point Cent_P;
	Point gen_P;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut);
	virtual void DeleteFig();
	int CalcRadius(Point* p);              //Calculate radius of the circle between the center and any point
	double CalcArea(Point* p);            // Calculate Area of the circle between the center and any point
	bool isInside(Point* p);              // checks if a given point is inside or on the circle
	void PrintInfo(Output* pOut);
    void Save(ofstream& OutFile);
	//void Load(ifstream& Infile);
};

