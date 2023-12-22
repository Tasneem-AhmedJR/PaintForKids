#include "CFigure.h"
int CFigure::count = 0;
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	count++;
	ID = count;
	Preclr = UI.DrawColor;
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
	if(this)
	return Visible;
}

void CFigure::ChngDrawClr (color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
	if (Dclr != UI.HighlightColor) Preclr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{
	if (Fclr == LIGHTGOLDENRODYELLOW)
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = Fclr;
	}
}

color CFigure::GetFillclr() { return FigGfxInfo.FillClr; }

color CFigure::GetDrawClr() { return Preclr; }

bool CFigure::IsFilled()
{
	if (FigGfxInfo.isFilled)
		return true;
	else return false;
}