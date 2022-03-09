// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "ITMStructure.h"

std::vector<ITMListMember*> srcITMList;
std::vector<ITMListMember*> destITMList;
std::vector<ITMListMember*> outITMList;

int main()
{

    readITMsFromFolder("./src/", srcITMList);
    readITMsFromFolder("./dest/", destITMList);

    CombineITMs();
    cout << srcITMList[0]->itm->countRec << endl;
    

    for (int i = 0; i < destITMList.size(); i++) {
        WriteITM(destITMList[i]->FileName, destITMList[i]->itm);
    }

    cout << "program has ended." << endl;

    getchar();
}
