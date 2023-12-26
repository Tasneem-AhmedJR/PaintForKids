#include "pickbyboth.h"
#include "pickbyfill.h"
#include "pickbytype.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
pickbyboth::pickbyboth(ApplicationManager* pApp):Action(pApp)
	{
		correct = 0;
		incorrect = 0;
		pAct = NULL;
	}

void pickbyboth::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Read one point store in point p
	pIn->GetPointClicked(p1.x, p1.y);
	pOut->ClearStatusBar();
}

void pickbyboth::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string arr5[30] = { "choose the all rectangle black color","choose the all rectangle yellow color" ,"choose the all rectangle orange color" ,"choose the all rectangle red color" ,"choose the all rectangle green color" ,"choose the all rectangle blue color","choose the all square black color","choose the all square yellow color" ,"choose the all square orange color" ,"choose the all square red color" ,"choose the all square green color" ,"choose the all square blue color"
	,"choose the all circle black color","choose the all circle yellow color" ,"choose the all circle orange color" ,"choose the all circle red color" ,"choose the all circle green color" ,"choose the all circle blue color"
	,"choose the all hexa black color","choose the all hexa yellow color" ,"choose the all hexa orange color" ,"choose the all hexa red color" ,"choose the all hexa green color" ,"choose the all hexa blue color" 
	,"choose the all triangle black color","choose the all triangle yellow color" ,"choose the all triangle orange color" ,"choose the all triangle red color" ,"choose the all triangle green color" ,"choose the all triangle blue color" };  ///the ques
	int arr4[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int l = 0; l < pManager->getfigureCount(); l++) {

		if (pManager->getn(l) == 0&& pManager->getm(l) == 0)
			arr4[0]++;
		else if (pManager->getn(l) == 1 && pManager->getm(l) == 0)
			arr4[1]++;
		else if (pManager->getn(l) == 2 && pManager->getm(l) == 0)
			arr4[2]++;
		else if (pManager->getn(l) == 3 && pManager->getm(l) == 0)
			arr4[3]++;
		else if (pManager->getn(l) == 4 && pManager->getm(l) == 0)
			arr4[4]++;
		else if (pManager->getn(l) == 5 && pManager->getm(l) == 0)
			arr4[5]++;
		else if (pManager->getn(l) == 0 && pManager->getm(l) == 1)
			arr4[6]++;
		else if (pManager->getn(l) == 1 && pManager->getm(l) == 1)
			arr4[7]++;
		else if (pManager->getn(l) == 2 && pManager->getm(l) == 1)
			arr4[8]++;
		else if (pManager->getn(l) == 3 && pManager->getm(l) == 1)
			arr4[9]++;
		else if (pManager->getn(l) == 4 && pManager->getm(l) == 1)
			arr4[10]++;
		else if (pManager->getn(l) == 5 && pManager->getm(l) == 1)
			arr4[11]++;
		else if (pManager->getn(l) == 0 && pManager->getm(l) == 2)
			arr4[12]++;
		else if (pManager->getn(l) == 1 && pManager->getm(l) == 2)
			arr4[13]++;
		else if (pManager->getn(l) == 2 && pManager->getm(l) == 2)
			arr4[14]++;
		else if (pManager->getn(l) == 3 && pManager->getm(l) == 2)
			arr4[15]++;
		else if (pManager->getn(l) == 4 && pManager->getm(l) == 2)
			arr4[16]++;
		else if (pManager->getn(l) == 5 && pManager->getm(l) == 2)
			arr4[17]++;
		else if (pManager->getn(l) == 0 && pManager->getm(l) == 3)
			arr4[18]++;
		else if (pManager->getn(l) == 1 && pManager->getm(l) == 3)
			arr4[19]++;
		else if (pManager->getn(l) == 2 && pManager->getm(l) == 3)
			arr4[20]++;
		else if (pManager->getn(l) == 3 && pManager->getm(l) == 3)
			arr4[21]++;
		else if (pManager->getn(l) == 4 && pManager->getm(l) == 3)
			arr4[22]++;
		else if (pManager->getn(l) == 5 && pManager->getm(l) == 3)
			arr4[23]++;
		else if (pManager->getn(l) == 0 && pManager->getm(l) == 4)
			arr4[24]++;
		else if (pManager->getn(l) == 1 && pManager->getm(l) == 4)
			arr4[25]++;
		else if (pManager->getn(l) == 2 && pManager->getm(l) == 4)
			arr4[26]++;
		else if (pManager->getn(l) == 3 && pManager->getm(l) == 4)
			arr4[27]++;
		else if (pManager->getn(l) == 4 && pManager->getm(l) == 4)
			arr4[28]++;
		else if (pManager->getn(l) == 5 && pManager->getm(l) == 4)
			arr4[29]++;
	}
	int o = 0;
	bool flag = true;
	for (int i = 0; i < 30; i++) {
		o += arr4[i];
	}
	int i = 0;
	if (o) {
		
		for (i ; i<o && flag;) {
			int x = rand() % 30;
			if (arr4[x]) {
				pOut->PrintMessage(arr5[x]);
				for (int j = 0; arr4[x]; )
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
						pAct = new pickbytype(pManager);
						pAct->Execute();
						flag = false;
						break;
					}
					else if (p1.x <= 2*(UI.MenuItemWidth) && p1.x >= 46 && p1.y <= UI.ToolBarHeight && p1.y >= 0) {
						pManager->unhide();
						pManager->UpdateInterface();
						pAct = new pickbyfill(pManager);
						
						pAct->Execute();
						flag = false;
						break;
					}
					else if (p1.x <= 3 * (UI.MenuItemWidth) && p1.x >= 92 && p1.y <= UI.ToolBarHeight && p1.y >= 0) {   //restart game
						pManager->unhide();
						pManager->UpdateInterface();
						pAct = new pickbyboth(pManager);
						pAct->Execute();
						flag = false;
						break;
					}
					else if (pManager->inside3(p1, x)==1 ) {
						j++;
						i++;
						arr4[x]--;
						correct++;
						pOut->PrintMessage("you are right continue");
						pManager->UpdateInterface();
					}
					else  if (pManager->inside3(p1, x) == 0)
					{
						incorrect++;
						pOut->PrintMessage("this is the false anwser " + (arr5[x]));
					}
					else if (pManager->inside3(p1, x) == -1)
						pOut->PrintMessage("please click on a fig");
				}

			}

			
		}
		
		if (i == o)
		{
			pOut->PrintMessage("please click toget the final score");
			pIn->GetPointClicked(p1.x, p1.y);
			pManager->unhide();
			pManager->UpdateInterface();
			pOut->PrintMessage("the correct anwsers" + to_string(correct) + "the incorrect anwsers" + to_string(incorrect));
		}
		pAct = NULL;

	}
	
 else
	 pOut->PrintMessage("please draw and fill color first");


};



