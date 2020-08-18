#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <string>

#include "DataInput.h"
#include "TestDataMaker.h"
#include "DataSort.h"

using namespace std;

class Data
{
public:

	Data();
	~Data();

	vector<vector<string>> mVectorDates;
	vector<vector<string>> mSortVectorDates;
	vector<vector<string>> mPriorityDates;

	const void GenerateTestData(string& inFileName);//�e�X�g�f�[�^�������s�֐�
	const void LoadTestData(string& inFileName);//CSV�f�[�^�ǎ���s�֐�

protected:
	DataInput data_input;
	TestDataMaker test_data_maker;
	DataSort data_sort;

};

