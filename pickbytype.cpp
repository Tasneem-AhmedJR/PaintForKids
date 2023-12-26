#include "pickbytype.h"
#include "pickbyboth.h"
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

	string arrofquestions[5] = { "choose the Rectangle","choose the Square" ,"choose the Circle" ,"choose the Hexa" ,"choose the Triangle" };  //possible questions in pick by type
	int arroffig[5] = { 0,0,0,0,0 };  //to save all shapes of one type in it
	bool flag = true;
	for (int l = 0; l < pManager->getfigureCount(); l++) {

		if (pManager->getnumofshape(l) == 0)
			arroffig[0]++;
		else if (pManager->getnumofshape(l) == 1)
			arroffig[1]++;
		else if (pManager->getnumofshape(l) == 2)
			arroffig[2]++;
		else if (pManager->getnumofshape(l) == 3)
			arroffig[3]++;
		else if (pManager->getnumofshape(l) == 4)
			arroffig[4]++;
	}
	int sum = 0;   ///the sum all shapes
	for (int i = 0; i < 5; i++) {
		sum += arroffig[i];
	}
	int i = 0;
	if ((arroffig[0] + arroffig[1] + arroffig[2] + arroffig[3] + arroffig[4])) {
		for (i; i<sum && flag;) {
			int random = rand() % 5;
			if (arroffig[random]) {
				pOut->PrintMessage(arrofquestions[random]);
				for (int j = 0; arroffig[random]; )
				{
					
					ReadActionParameters();
					if (p1.x <= 4*(UI.MenuItemWidth) && p1.x >= 138 && p1.y <= UI.ToolBarHeight && p1.y >= 0) {
						pManager->unhide();
						pManager->UpdateInterface();
						pManager->unhide();
						pManager->UpdateInterface();
						pOut->CreateDrawToolBar();
						flag = false;
						break;
						

					}
					else if(p1.x <= 2 * (UI.MenuItemWidth) && p1.x >= 46 && p1.y <= UI.ToolBarHeight && p1.y >= 0) {
						pManager->unhide();
						pManager->UpdateInterface();
						incorrect = 0;
						correct = 0;
						pManager->unhide();
						pManager->UpdateInterface();
					pAct=new pickbyfill(pManager);
					pAct->Execute();
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
					else if (p1.x <= 3 * (UI.MenuItemWidth) && p1.x >= 92 && p1.y <= UI.ToolBarHeight && p1.y >= 0) {
						pManager->unhide();
						pManager->UpdateInterface();
						pAct = new pickbyboth(pManager);
						pAct->Execute();
						flag = false;
						break;
					}
					else if (pManager->insideoffig(p1, random) == 5) {
						j++;
						i++;
						arroffig[random]--;
						correct++;
						pManager->UpdateInterface();
						
							pOut->PrintMessage("you are right continue the correct is " + to_string(correct) + " the incorrect anwsers " + to_string(incorrect)+ " choose " + (arrofquestions[random]));
						}
						
					
					else  if (pManager->insideoffig(p1, random) == 0) {
						
						incorrect++;
						pOut->PrintMessage("this is the false anwser "+(arrofquestions[random])+" the correct is " + to_string(correct) + " the incorrect anwsers " + to_string(incorrect) + " please choose " + (arrofquestions[random]));
					
					}
					else if (pManager->insideoffig(p1, random) == -1)
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
		
	//	pAct = NULL;
	}
	else
		pOut->PrintMessage("please draw first to can play with type");

		}

		pickbytype::~pickbytype()
		{
			delete pAct;
		}

		