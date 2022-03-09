#include "ITMStructure.h"


void CombineRecords(_FileITM* src, _FileITM* dest) {
	for (int i = 0; i < src->countDDS; i++) {
		int found = 0;
		for (int j = 0; j < dest->countDDS; j++) {
			if (dest->namesDDS[j]->chars == src->namesDDS[i]->chars) {
				found = 1;
			}
		}
		if (found == 0) {

			dest->names3DO.push_back(src->names3DO[i]);
			dest->count3DO += 1;
			dest->namesDDS.push_back(src->namesDDS[i]);
			dest->countDDS += 1;
			_RecordITM* itm = new _RecordITM();
			itm->index3DO = dest->count3DO-1;
			itm->indexDDS = dest->countDDS-1;
			itm->glow = src->records[i]->glow;
			itm->unk2 = src->records[i]->unk2;
			itm->format = src->records[i]->format;
			itm->unk3 = src->records[i]->unk3;
			if (itm->format == 1) {
				itm->rgba = src->records[i]->rgba;
				itm->unk4 = src->records[i]->unk4;
				itm->scale = src->records[i]->scale;
				itm->unk5 = src->records[i]->unk5;
			}
			dest->records.push_back(itm);
			dest->countRec += 1;
		}
	}
}



void CombineITMs() {

	for (int i = 0; i < srcITMList.size(); i++) {
		for (int j = 0; j < destITMList.size(); j++) {
			if (srcITMList[i]->FileName == destITMList[j]->FileName) {
				CombineRecords(srcITMList[i]->itm, destITMList[j]->itm);
			}
		}
	}

	return;
}