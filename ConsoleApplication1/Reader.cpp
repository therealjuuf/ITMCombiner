#include "ITMStructure.h"



_FileITM* ReadITM(string filepath,string filename) {


	ifstream rf(filepath + filename, ios::binary);
	if (!rf) {
		cout << "file cannot be opened." << endl;
		return NULL;
	}
	char temp[500];

	_FileITM* itm = new _FileITM();
	rf.read((char*)&itm->sign, sizeof(itm->sign));


	// read 3DO count
	rf.read((char*)&itm->count3DO, sizeof(itm->count3DO));

	// read 3DO names
	for (int i = 0; i < itm->count3DO; i++) {
		xString* _3dcName = new xString();
		rf.read((char*)&_3dcName->length, sizeof(_3dcName->length));

		rf.read((char*)&temp, _3dcName->length);

		_3dcName->chars = temp;

		itm->names3DO.push_back(_3dcName);

	}


	// read DDS count
	rf.read((char*)&itm->countDDS, sizeof(itm->countDDS));

	// read DDS names
	for (int i = 0; i < itm->countDDS; i++) {
		xString* _ddsName = new xString();
		rf.read((char*)&_ddsName->length, sizeof(_ddsName->length));

		rf.read((char*)&temp, _ddsName->length);

		_ddsName->chars = temp;

		itm->namesDDS.push_back(_ddsName);

	}

	// read record count
	rf.read((char*)&itm->countRec, sizeof(itm->countRec));

	// read records
	for (int i = 0; i < itm->countRec; i++) {
		_RecordITM* itmrecord = new _RecordITM();

		rf.read((char*)&itmrecord->index3DO, sizeof(itmrecord->index3DO));
		rf.read((char*)&itmrecord->indexDDS, sizeof(itmrecord->indexDDS));
		rf.read((char*)&itmrecord->glow, sizeof(itmrecord->glow));
		rf.read((char*)&itmrecord->unk2, sizeof(itmrecord->unk2));
		rf.read((char*)&itmrecord->format, sizeof(itmrecord->format));
		rf.read((char*)&itmrecord->unk3, sizeof(itmrecord->unk3));

		if (itmrecord->format == 1) {
			rf.read((char*)&itmrecord->rgba, sizeof(itmrecord->rgba));
			rf.read((char*)&itmrecord->unk4, sizeof(itmrecord->unk4));
			rf.read((char*)&itmrecord->scale, sizeof(itmrecord->scale));
			rf.read((char*)&itmrecord->unk5, sizeof(itmrecord->unk5));
		}

		itm->records.push_back(itmrecord);

	}

	rf.close();

	return itm;
}