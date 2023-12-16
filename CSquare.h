#pragma once
#include"Figures\CFigure.h"
class CSquare:public CFigure
{
private:
	Point Center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut);
	bool isInside(Point* p);
	void PrintInfo(Output* pOut);
	virtual void DeleteFig();
	void Save(ofstream& OutFile);
	//void Load(ifstream& Infile);

};

