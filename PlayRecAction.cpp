#include "PlayRecAction.h"
#include"ApplicationManager.h"

PlayRecAction::PlayRecAction(ApplicationManager* pApp) :Action(pApp) {}

bool PlayRecAction::isRecorded() { return false; }

void PlayRecAction::ReadActionParameters() {}

void PlayRecAction::Execute()
{

}
