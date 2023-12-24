#include "CFigure.h"
int CFigure::count = 0;
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	count++;
	ID = count;
<<<<<<< HEAD
	Visible = true;
	hide = true;
=======
	Preclr = UI.DrawColor;
>>>>>>> 509b57b18b676642a70f66a2c5f1035fae7946fd
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
<<<<<<< HEAD
{	if(Fclr== LIGHTGOLDENRODYELLOW)
FigGfxInfo.isFilled = false;
else {
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
=======
{
	if (Fclr == LIGHTGOLDENRODYELLOW)
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = Fclr;
	}
>>>>>>> 509b57b18b676642a70f66a2c5f1035fae7946fd
}

}

void CFigure::Movefi(Output* pOut, Point p)
{
}

void CFigure::sethide(bool l)
{
	hide = l;
}

bool CFigure::gethide()
{
	return hide;
}



int CFigure::filledcolor() 
{
	if(FigGfxInfo.FillClr==BLACK)
	    return 0;
	else if (FigGfxInfo.FillClr == YELLOW)
		return 1;
	else if (FigGfxInfo.FillClr == ORANGE)
		return 2;
	else if (FigGfxInfo.FillClr == RED)
		return 3;
	else if (FigGfxInfo.FillClr == GREEN)
		return 4;
	else if (FigGfxInfo.FillClr == BLUE)
		return 5;
	else if (FigGfxInfo.FillClr == LIGHTGOLDENRODYELLOW)
		return 6;
}

color CFigure::GetFillclr() {return FigGfxInfo.FillClr; }

color CFigure::GetDrawClr() { return Preclr; }

bool CFigure::IsFilled()
{
	if (FigGfxInfo.isFilled)
		return true;
	else return false;
}