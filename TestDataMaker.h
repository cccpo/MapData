#pragma once
#include <random>
#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <fstream>

#include "DataTool.h"

using namespace std;

class TestDataMaker
{
public:
	const int mDataSize = 10;
	
	TestDataMaker();
	~TestDataMaker();

	void GeneratePlayerID(char* s, const int len);
	const void GenerateData(const int& ioNumOfData);//�f�[�^�̃����_������
	const void GenerateTestDataCSV(string inFileName,int inNumOfData);//�f�[�^�̃����_������(CSV�t�@�C���ɏ�������)

protected:
	DataTool data_tool;

	string mPlayerId;//PlayerID
	array<int, 10> mData;
	

	char* mPlayerID;
};

