#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
#include <fstream>
#include <list>

#include "DataTool.h"

using namespace std;


class DataSort{
public:
	DataSort();
	~DataSort();

	const vector<vector<string>> DeleteKeyCategory(vector<vector<string>>& inDataList);
	const vector<list<int>> IntDeleteKeyCategory(vector<vector<string>>& inDataList);


	const vector<list<int>> ExtractData(vector<vector<int>>& inDataList);//�f�[�^�̒��o���s��
protected:
	DataTool data_tool;
};

