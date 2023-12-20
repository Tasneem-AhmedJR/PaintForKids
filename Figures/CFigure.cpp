#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID = 0;
	//7clr = FigGfxInfo.DrawClr;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::SetVisibility(bool f)
{
	if (this)
		Visible = f;
}

bool CFigure::GetVisibility()
{
	return Visible;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
	//if (Dclr != UI.HighlightColor) clr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

color CFigure::GetFillclr() { return FigGfxInfo.FillClr; }

bool CFigure::IsFilled()
{
	if (FigGfxInfo.isFilled)
		return true;
	else return false;
}

void CFigure::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("ID : " + ID);
}




