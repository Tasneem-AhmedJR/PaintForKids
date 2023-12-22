#include "SoundAction.h"
#include<string.h>
#include<Windows.h>
#include<MMSystem.h>
#include<iostream>
#include"GUI/Output.h"
#include"ApplicationManager.h"
SoundAction::SoundAction(ApplicationManager* pApp) :Action(pApp)
{
}

void SoundAction::ReadActionParameters()
{
}

void SoundAction::Execute()
{
	ActionType ActType;
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("FUNNY Sound ^^ ");
	ActType = pManager->GetUserAction();
	if (ActType == DRAW_RECT)
	{
		PlaySound(TEXT("bubble.wav"), NULL, SND_SYNC);
		PlaySound(TEXT("rectangle.wav"), NULL, SND_SYNC);
	}
	else if (ActType == DRAW_CIRCLE)
	{

		PlaySound(TEXT("bubble.wav"), NULL, SND_SYNC);
		PlaySound(TEXT("circle.wav"), NULL, SND_SYNC);
	}
	else if (ActType == DRAW_TRIANGLE)
	{

		PlaySound(TEXT("bubble.wav"), NULL, SND_SYNC);
		PlaySound(TEXT("triangle.wav"), NULL, SND_SYNC);
	}
	else if (ActType == DRAW_HEXA)
	{

		PlaySound(TEXT("bubble.wav"), NULL, SND_SYNC);
		PlaySound(TEXT("Hexa.wav"), NULL, SND_SYNC);
	}
	else if (ActType == DRAW_SQUARE)
	{

		PlaySound(TEXT("bubble.wav"), NULL, SND_SYNC);
		PlaySound(TEXT("square.wav"), NULL, SND_SYNC);
	}
}