#include "pickbyfill.h"
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
	string arr[6] = { "choose the all black color","choose the all yellow color" ,"choose the all orange color" ,"choose the all red color" ,"choose the all green color" ,"choose the all blue color" };
	int arr3[6] = {0,0,0,0,0,0};
	for (int l = 0; l < pManager->getfigureCount(); l++) {

		if (pManager->getn(l) == 0)
			arr3[0]++;
		else if (pManager->getn(l) == 1)
			arr3[1]++;
		else if (pManager->getn(l) == 2)
			arr3[2]++;
		else if (pManager->getn(l) == 3)
			arr3[3]++;
		else if (pManager->getn(l) == 4)
			arr3[4]++;
		else if (pManager->getn(l) == 5)
			arr3[5]++;
	}

 bool flag = true;
 if ((arr3[0] + arr3[1] + arr3[2] + arr3[3] + arr3[4] + arr3[5])) {
	 for (int i = 0; (arr3[0] + arr3[1] + arr3[2] + arr3[3] + arr3[4] + arr3[5])&&flag;) {
		 int x = rand() % 6;
		 if (arr3[x]) {
			 pOut->PrintMessage(arr[x]);
			 for (int j = 0; arr3[x]; )
			 {
				 ReadActionParameters();
				 if (p1.x <= 4 * (UI.MenuItemWidth) && p1.x >= 138 && p1.y <= UI.ToolBarHeight && p1.y >= 0) {
					 pManager->unhide();
					 pManager->UpdateInterface();
					 pOut->CreateDrawToolBar();
					 flag = false;
					 break;
				 }
				 
				 else if (p1.x <=  (UI.MenuItemWidth) && p1.x >= 0 && p1.y <= UI.ToolBarHeight && p1.y >= 0) {
					 pManager->unhide();
					 pManager->UpdateInterface();
					 pAct = new pickbytype(pManager);
					 pAct->Execute();
					 flag = false;
					 break;
				 }
				 else if (pManager->inside(p1, x)==1) {
					 j++;
					 i++;
					 arr3[x]--;
					 correct++;
					 pManager->UpdateInterface();
				 }
				 else  if(pManager->inside(p1, x) == 0)

					 incorrect++;
				 else if(pManager->inside(p1, x) == -1)
					 pOut->PrintMessage("please click on a fig");
			 }

		 }


	 }
	 pOut->PrintMessage("please click to get the final score");
	 pIn->GetPointClicked(p1.x, p1.y);

	 pManager->unhide();
	 pManager->UpdateInterface();
	 pOut->PrintMessage("the correct anwsers" + to_string(correct) + "the incorrect anwsers" + to_string(incorrect));
	 pAct = NULL;
 }
 else
	 pOut->PrintMessage("please draw first");
	
}
