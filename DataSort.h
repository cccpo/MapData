#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
#include <fstream>

#include "DataTool.h"

using namespace std;


class DataSort{
public:
	DataSort();
	~DataSort();

	//vector<vector<string>> mSortVectorDates;//�f�[�^���i�[����vector

	const vector<vector<string>> DeleteKeyCategory(vector<vector<string>>& inDataList);
	const vector<vector<string>> ExtractData(vector<vector<string>>& inDataList);//�f�[�^�̒��o���s��
protected:
	DataTool data_tool;
};

