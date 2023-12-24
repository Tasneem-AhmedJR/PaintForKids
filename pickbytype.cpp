#include "pickbytype.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include<cstdlib>
pickbytype::pickbytype(ApplicationManager* pApp) :Action(pApp)
{
	correct = 0;
	incorrect = 0;
	pAct = NULL;
}

void pickbytype::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Read one point store in point p
	pIn->GetPointClicked(p1.x, p1.y);
	pOut->ClearStatusBar();
}

void pickbytype::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	string arr[5] = { "choose the Rectangle","choose the Square" ,"choose the Circle" ,"choose the Hexa" ,"choose the Triangle" };
	int arr2[5] = { 0,0,0,0,0 };
	bool flag = true;
	for (int l = 0; l < pManager->getfigureCount(); l++) {

		if (pManager->getm(l) == 0)
			arr2[0]++;
		else if (pManager->getm(l) == 1)
			arr2[1]++;
		else if (pManager->getm(l) == 2)
			arr2[2]++;
		else if (pManager->getm(l) == 3)
			arr2[3]++;
		else if (pManager->getm(l) == 4)
			arr2[4]++;
	}
	
	if ((arr2[0] + arr2[1] + arr2[2] + arr2[3] + arr2[4])) {
		for (int i = 0; (arr2[0] + arr2[1] + arr2[2] + arr2[3] + arr2[4]) && flag;) {
			int x = rand() % 5;
			if (arr2[x]) {
				pOut->PrintMessage(arr[x]);
				for (int j = 0; arr2[x]; )
				{
					
					ReadActionParameters();
					if (p1.x <= 4*(UI.MenuItemWidth) && p1.x >= 138 && p1.y <= UI.ToolBarHeight && p1.y >= 0) {
						pManager->unhide();
						pManager->UpdateInterface();
						pOut->CreateDrawToolBar();
						flag = false;
						break;
						

					}
					else if(p1.x <= 2 * (UI.MenuItemWidth) && p1.x >= 46 && p1.y <= UI.ToolBarHeight && p1.y >= 0) {
						pManager->unhide();
						pManager->UpdateInterface();
					pAct=new pickbyfill(pManager);
					pAct->Execute();
						flag = false;
						break;


					}
					else if (pManager->inside2(p1, x) == 1) {
						j++;
						i++;
						arr2[x]--;
						correct++;
						pManager->UpdateInterface();
					}
					else  if (pManager->inside2(p1, x) == 0)

						incorrect++;
					else if (pManager->inside2(p1, x) == -1)
						pOut->PrintMessage("please click on a fig");
				}

			}


		}
		pOut->PrintMessage("please click to get the final score");
		pIn->GetPointClicked(p1.x, p1.y);
		
		pManager->unhide();
		pManager->UpdateInterface();
		pOut->PrintMessage("the correct anwsers" + to_string(correct) + "the incorrect anwsers" + to_string(incorrect));
		//ptr1 = NULL;
		pAct = NULL;
	}
	else
		pOut->PrintMessage("please draw first");

		}
	