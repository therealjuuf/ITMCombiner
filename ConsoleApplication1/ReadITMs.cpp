#include <fstream>
#include <iostream>
#include <filesystem>
#include "ITMStructure.h"
namespace fs = std::filesystem;


int readITMsFromFolder(std::string path, std::vector<ITMListMember*>& ITMList) {

	std::string ext(".ITM");
	std::string ext2(".itm");
	for (auto& p : fs::recursive_directory_iterator(path))
	{
		if (p.path().extension() == ext || p.path().extension() == ext2) {

			ITMListMember* itmfile = new ITMListMember();

			itmfile->FileName = p.path().stem().string();
			itmfile->FileName += ".ITM";
			
			itmfile->itm = ReadITM(path, itmfile->FileName);
			
			ITMList.push_back(itmfile);

		}
	}
	return 0;
}
