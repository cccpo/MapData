#pragma once
#include <iostream>
#include <string>

#include <vector>
#include <list>
#include <chrono>


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

	vector<list<int>> mListDates;

	vector<vector<int>> mVectorDates;

	vector<list<int>> mPriorityDates;

	const void GenerateTestData(string& inFileName);//�e�X�g�f�[�^�������s�֐�
	const void LoadTestData(string& inFileName);//CSV�f�[�^�ǎ���s�֐�
	const void ExtractPlayerCourceData(vector<vector<int>>& inDate);

protected:
	DataInput data_input;
	TestDataMaker test_data_maker;
	DataTool data_tool;
	DataSort data_sort;

};

