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
	string arrofquestions[30] = { "choose the all rectangle black color","choose the all rectangle yellow color" ,"choose the all rectangle orange color" ,"choose the all rectangle red color" ,"choose the all rectangle green color" ,"choose the all rectangle blue color","choose the all square black color","choose the all square yellow color" ,"choose the all square orange color" ,"choose the all square red color" ,"choose the all square green color" ,"choose the all square blue color"
	,"choose the all circle black color","choose the all circle yellow color" ,"choose the all circle orange color" ,"choose the all circle red color" ,"choose the all circle green color" ,"choose the all circle blue color"
	,"choose the all hexa black color","choose the all hexa yellow color" ,"choose the all hexa orange color" ,"choose the all hexa red color" ,"choose the all hexa green color" ,"choose the all hexa blue color" 
	,"choose the all triangle black color","choose the all triangle yellow color" ,"choose the all triangle orange color" ,"choose the all triangle red color" ,"choose the all triangle green color" ,"choose the all triangle blue color" };  ///the ques
	int arrofboth[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int l = 0; l < pManager->getfigureCount(); l++) {

		if (pManager->getnumcolors(l) == 0&& pManager->getnumofshape(l) == 0)
			arrofboth[0]++;
		else if (pManager->getnumcolors(l) == 1 && pManager->getnumofshape(l) == 0)
			arrofboth[1]++;
		else if (pManager->getnumcolors(l) == 2 && pManager->getnumofshape(l) == 0)
			arrofboth[2]++;
		else if (pManager->getnumcolors(l) == 3 && pManager->getnumofshape(l) == 0)
			arrofboth[3]++;
		else if (pManager->getnumcolors(l) == 4 && pManager->getnumofshape(l) == 0)
			arrofboth[4]++;
		else if (pManager->getnumcolors(l) == 5 && pManager->getnumofshape(l) == 0)
			arrofboth[5]++;
		else if (pManager->getnumcolors(l) == 0 && pManager->getnumofshape(l) == 1)
			arrofboth[6]++;
		else if (pManager->getnumcolors(l) == 1 && pManager->getnumofshape(l) == 1)
			arrofboth[7]++;
		else if (pManager->getnumcolors(l) == 2 && pManager->getnumofshape(l) == 1)
			arrofboth[8]++;
		else if (pManager->getnumcolors(l) == 3 && pManager->getnumofshape(l) == 1)
			arrofboth[9]++;
		else if (pManager->getnumcolors(l) == 4 && pManager->getnumofshape(l) == 1)
			arrofboth[10]++;
		else if (pManager->getnumcolors(l) == 5 && pManager->getnumofshape(l) == 1)
			arrofboth[11]++;
		else if (pManager->getnumcolors(l) == 0 && pManager->getnumofshape(l) == 2)
			arrofboth[12]++;
		else if (pManager->getnumcolors(l) == 1 && pManager->getnumofshape(l) == 2)
			arrofboth[13]++;
		else if (pManager->getnumcolors(l) == 2 && pManager->getnumofshape(l) == 2)
			arrofboth[14]++;
		else if (pManager->getnumcolors(l) == 3 && pManager->getnumofshape(l) == 2)
			arrofboth[15]++;
		else if (pManager->getnumcolors(l) == 4 && pManager->getnumofshape(l) == 2)
			arrofboth[16]++;
		else if (pManager->getnumcolors(l) == 5 && pManager->getnumofshape(l) == 2)
			arrofboth[17]++;
		else if (pManager->getnumcolors(l) == 0 && pManager->getnumofshape(l) == 3)
			arrofboth[18]++;
		else if (pManager->getnumcolors(l) == 1 && pManager->getnumofshape(l) == 3)
			arrofboth[19]++;
		else if (pManager->getnumcolors(l) == 2 && pManager->getnumofshape(l) == 3)
			arrofboth[20]++;
		else if (pManager->getnumcolors(l) == 3 && pManager->getnumofshape(l) == 3)
			arrofboth[21]++;
		else if (pManager->getnumcolors(l) == 4 && pManager->getnumofshape(l) == 3)
			arrofboth[22]++;
		else if (pManager->getnumcolors(l) == 5 && pManager->getnumofshape(l) == 3)
			arrofboth[23]++;
		else if (pManager->getnumcolors(l) == 0 && pManager->getnumofshape(l) == 4)
			arrofboth[24]++;
		else if (pManager->getnumcolors(l) == 1 && pManager->getnumofshape(l) == 4)
			arrofboth[25]++;
		else if (pManager->getnumcolors(l) == 2 && pManager->getnumofshape(l) == 4)
			arrofboth[26]++;
		else if (pManager->getnumcolors(l) == 3 && pManager->getnumofshape(l) == 4)
			arrofboth[27]++;
		else if (pManager->getnumcolors(l) == 4 && pManager->getnumofshape(l) == 4)
			arrofboth[28]++;
		else if (pManager->getnumcolors(l) == 5 && pManager->getnumofshape(l) == 4)
			arrofboth[29]++;
	}
	int sum = 0;
	bool flag = true;
	for (int i = 0; i < 30; i++) {
		sum += arrofboth[i];
	}
	int i = 0;
	if (sum) {
		
		for (i ; i<sum && flag;) {
			int random = rand() % 30;
			if (arrofboth[random]) {
				pOut->PrintMessage(arrofquestions[random]);
				for (int j = 0; arrofboth[random]; )
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
					else if (pManager->insideofboth(p1, random)==1 ) {
						j++;
						i++;
						arrofboth[random]--;
						correct++;
						pManager->UpdateInterface();
				
						pOut->PrintMessage("you are right continue is " + to_string(correct) + "the incorrect anwsers" + to_string(incorrect)+ " choose "+(arrofquestions[random]) );
					
						
					}
					else  if (pManager->insideofboth(p1, random) == 0)
					{
						incorrect++;
						pOut->PrintMessage("this is the false anwser " + (arrofquestions[random]) + " the correct is " + to_string(correct) + "the incorrect anwsers" + to_string(incorrect)+" please choose "+(arrofquestions[random]));
					}
					else if (pManager->insideofboth(p1, random) == -1)
						pOut->PrintMessage("please click on a fig");
				}

			}

			
		}
		
		if (i == sum)
		{
			pOut->PrintMessage("please click toget the final score");
			pIn->GetPointClicked(p1.x, p1.y);
			pManager->unhide();
			pManager->UpdateInterface();
			pOut->PrintMessage("the final correct anwsers" + to_string(correct) + "the final incorrect anwsers" + to_string(incorrect));
		}
	//	pAct = NULL;

	}
	
 else
	 pOut->PrintMessage("please draw and fill color first to play with fig & color");


}
pickbyboth::~pickbyboth()
{
	delete pAct;
}
;



