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
	bool validate(Point);                    // checks if the figure is inside the drawing area
	bool isInside(Point* p);
	void PrintInfo(Output* pOut);
	virtual void DeleteFig();
	virtual void Movefi(Output* pOut, Point p);
	virtual Point getcenter();
	virtual int getconstfig();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

};

