#pragma once
#include"Figures\CFigure.h"
class CSquare:public CFigure
{
private:
	Point Center;
public:
	CSquare(){}
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut);
	bool isInside(Point* p);
	void PrintInfo(Output* pOut);
	virtual void DeleteFig();
	virtual void Movefi(Output* pOut, Point p);
	virtual int getnum();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

};

