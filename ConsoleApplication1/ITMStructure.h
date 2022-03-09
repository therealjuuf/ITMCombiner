#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;





struct xString {
	long		length;		// number of characters to follow
	//char* chars;		// characters (usually zero terminated)
	std::string chars;
};


struct _RecordITM {
	long		index3DO;	// index of a .3DO filename
	long		indexDDS;	// index of a .DDS filename
	long		glow;		// glow mode
	long		unk2;
	long		format;		//	0 or 1
	long		unk3;
	long		rgba;		//	present if format == 1
	long		unk4;		//	present if format == 1
	long		scale;		//	present if format == 1
	long		unk5;		//	present if format == 1
	long		unk6[1024];	//	present in struct "IT2" (32 block of 8 int32)
};

struct _FileITM {
	char		sign[3];	// format: 'I','T','M' or 'I','T','2'
	long		count3DO;	// number of .3DO filenames to follow
	std::vector<xString*> names3DO;	// array of filenames
	long		countDDS;	// number of .DDS filenames to follow
	std::vector<xString*> namesDDS;	// array of filenames
	long		countRec;	// number of records to follow
	std::vector<_RecordITM*> records;	// array of the RecordITM
};

struct ITMListMember {
	std::string FileName;
	_FileITM* itm;
};


extern _FileITM* ReadITM(string filepath, string filename);
extern _FileITM* WriteITM(string filename, _FileITM* itm);
extern void CombineITMs();

extern int readITMsFromFolder(std::string path, std::vector<ITMListMember*>& ITMList);

extern std::vector<ITMListMember*> srcITMList;
extern std::vector<ITMListMember*> destITMList;
extern std::vector<ITMListMember*> outITMList;