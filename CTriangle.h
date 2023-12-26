#pragma once
#include"Figures/CFigure.h"
class CTriangle:public CFigure
{
private:
	Point F_P;
	Point S_P;
	Point T_P;
	Point A;
	Point B;
	Point C;
public:
	CTriangle(){}
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut);
	double CalcArea(Point* a, Point* b, Point* c);
	bool isInside(Point*);
	void PrintInfo(Output* pOut);
	virtual void Movefi(Output* pOut, Point p);
	virtual int getconstfig();
	virtual void DeleteFig();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	

};

