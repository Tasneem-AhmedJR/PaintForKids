#include "pickbyfill.h"
#include "pickbyboth.h"
#include "pickbytype.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
pickbyfill::pickbyfill(ApplicationManager* pApp):Action(pApp)
{
	correct = 0;
	incorrect = 0;
	pAct = NULL;
}

void pickbyfill::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Read one point store in point p
	pIn->GetPointClicked(p1.x, p1.y);
	pOut->ClearStatusBar();
}

void pickbyfill::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string arrofquestions[6] = { "choose the all black color","choose the all yellow color" ,"choose the all orange color" ,"choose the all red color" ,"choose the all green color" ,"choose the all blue color" };  //possible questions in pick by fillcolor
	int arrofcolor[6] = {0,0,0,0,0,0};   //to save all colors of one type in it
	for (int l = 0; l < pManager->getfigureCount(); l++) {

		if (pManager->getnumcolors(l) == 0)
			arrofcolor[0]++;
		else if (pManager->getnumcolors(l) == 1)
			arrofcolor[1]++;
		else if (pManager->getnumcolors(l) == 2)
			arrofcolor[2]++;
		else if (pManager->getnumcolors(l) == 3)
			arrofcolor[3]++;
		else if (pManager->getnumcolors(l) == 4)
			arrofcolor[4]++;
		else if (pManager->getnumcolors(l) == 5)
			arrofcolor[5]++;
	}
	int sum = 0;
	for (int i = 0; i < 6; i++) {
		sum += arrofcolor[i];
	}
 bool flag = true;

 if ((sum)) {
	 int i = 0;
	 for (i; i<sum && flag;) {
		 int random = rand() % 6;
		 if (arrofcolor[random]) {
			 pOut->PrintMessage(arrofquestions[random]);
			 for (int j = 0; arrofcolor[random]; )
			 {
				 ReadActionParameters();
				 if (p1.x <= 4 * (UI.MenuItemWidth) && p1.x >= 138 && p1.y <= UI.ToolBarHeight && p1.y >= 0) {
					 pManager->unhide();
					 pManager->UpdateInterface();
					 pOut->CreateDrawToolBar();
					 flag = false;
					 break;
				 }

				 else if (p1.x <= (UI.MenuItemWidth) && p1.x >= 0 && p1.y <= UI.ToolBarHeight && p1.y >= 0) {
					 pManager->unhide();
					 pManager->UpdateInterface();
					 incorrect = 0;
					 correct = 0;
					 pAct = new pickbytype(pManager);
					 pAct->Execute();
					 flag = false;
					 break;
				 }
				 else if (p1.x <= 2 * (UI.MenuItemWidth) && p1.x >= 46 && p1.y <= UI.ToolBarHeight && p1.y >= 0) {
					 pManager->unhide();
					 pManager->UpdateInterface();
					 pAct = new pickbyfill(pManager);
					 
					 pAct->Execute();
					 flag = false;
					 break;
				 }
				 else if (p1.x <=3* (UI.MenuItemWidth) && p1.x >=92  && p1.y <= UI.ToolBarHeight && p1.y >= 0) {
					 pManager->unhide();
					 pManager->UpdateInterface();
					 pAct = new pickbyboth(pManager);
					 pAct->Execute();
					 flag = false;
					 break;
				 }
				 else if (pManager->insideofcolor(p1, random) == 1) {
					 j++;
					 i++;
					 arrofcolor[random]--;
					 correct++;
					 pManager->UpdateInterface();
					 
						 pOut->PrintMessage("you are right continue the correct is " + to_string(correct) + " the incorrect anwsers " + to_string(incorrect)+ " choose " + (arrofquestions[random]));
					 
				 }
				 else  if (pManager->insideofcolor(p1, random) == 0)
				 {
					 incorrect++;
					 pOut->PrintMessage("this is the false anwser " + (arrofquestions[random]) + " the correct is " + to_string(correct) + " the incorrect anwsers " + to_string(incorrect) + " please choose " + (arrofquestions[random]));
				 }
				 else if (pManager->insideofcolor(p1, random) == -1)
					 pOut->PrintMessage("please click on a fig");
			 }
		 }
	 }
	
	 if (i == sum)
	 {

		 pOut->PrintMessage("please click to get the final score");
		 pIn->GetPointClicked(p1.x, p1.y);
		 pManager->unhide();
		 pManager->UpdateInterface();
		 pOut->PrintMessage("the final correct anwsers " + to_string(correct) + " the final incorrect anwsers " + to_string(incorrect));
	 }

	// pAct = NULL;
 }
 else
	 pOut->PrintMessage("please draw first and fill color to can play with color");
}

bool pickbyfill::isRecorded()
{
	return false;
}

pickbyfill::~pickbyfill()
{
	delete pAct;
}
