#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(){}
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) ;
	double CalcArea(Point* p);
	bool validate(Point,Point);
	bool isInside(Point* p);
	void PrintInfo(Output* pOut);
	virtual void DeleteFig();
	virtual int getnum();
	virtual void Movefi(Output* pOut, Point p);
	//virtual CFigure* GetDeletedFig();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	
};

#endif