#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <map>

#include "DataInput.h"
#include "TestDataMaker.h"
#include "DataTool.h"
#include "DataSort.h"

using namespace std;

//���o�����f�[�^���i�[�A�e�N���X�֖��߂��o���N���X
class Data
{
public:

	Data();
	~Data();

	map<string, vector<vector<string>>> user_datas;

	vector<vector<string>> mVectorDates;
	vector<vector<string>> mSortVectorDates;
	vector<vector<string>> mPriorityDates;

	const void GenerateTestData(string& inFileName);//�e�X�g�f�[�^�������s�֐�
	const void LoadTestData(string& inFileName);//CSV�f�[�^�ǎ���s�֐�
	const void ExtractPlayerCourceData(vector<vector<string>>& inDate);

protected:
	DataInput data_input;
	TestDataMaker test_data_maker;
	DataTool data_tool;
	DataSort data_sort;

};

