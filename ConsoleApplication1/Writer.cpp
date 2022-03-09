
#include "ITMStructure.h"



_FileITM* WriteITM(string filename, _FileITM* itm) {


	if (remove(("./output/" + filename).c_str()) != 0)
		perror(("" + filename + " doesn't exist, it will be created automatically.").c_str());
	else
		puts(("./output/" + filename + " deleted, remaking the new one.").c_str());

	cout<< endl;
	ofstream of;
	of.open("./output/" + filename, ios::out | ios::binary);

	of.write((char*)&itm->sign, sizeof(itm->sign));


	of.write((char*)&itm->count3DO, sizeof(itm->count3DO));

	for (int i = 0; i < itm->count3DO; i++) {
		of.write((char*)&itm->names3DO[i]->length, sizeof(itm->names3DO[i]->length));

		of.write((char*)itm->names3DO[i]->chars.c_str(), itm->names3DO[i]->length);
	}

	of.write((char*)&itm->countDDS, sizeof(itm->countDDS));

	for (int i = 0; i < itm->countDDS; i++) {
		of.write((char*)&itm->namesDDS[i]->length, sizeof(itm->namesDDS[i]->length));
		of.write((char*)itm->namesDDS[i]->chars.c_str(), itm->namesDDS[i]->length);
	}


	of.write((char*)&itm->countRec, sizeof(itm->countRec));

	cout << itm->countRec <<endl;
	for (int i = 0; i < itm->countRec; i++) {
		of.write((char*)&itm->records[i]->index3DO, sizeof(itm->records[i]->index3DO));
		of.write((char*)&itm->records[i]->indexDDS, sizeof(itm->records[i]->indexDDS));
		of.write((char*)&itm->records[i]->glow, sizeof(itm->records[i]->glow));
		of.write((char*)&itm->records[i]->unk2, sizeof(itm->records[i]->unk2));
		of.write((char*)&itm->records[i]->format, sizeof(itm->records[i]->format));
		of.write((char*)&itm->records[i]->unk3, sizeof(itm->records[i]->unk3));

		if (itm->records[i]->format == 1) {
			of.write((char*)&itm->records[i]->rgba, sizeof(itm->records[i]->rgba));
			of.write((char*)&itm->records[i]->unk4, sizeof(itm->records[i]->unk4));
			of.write((char*)&itm->records[i]->scale, sizeof(itm->records[i]->scale));
			of.write((char*)&itm->records[i]->unk5, sizeof(itm->records[i]->unk5));
		}

	}

	return itm;
}