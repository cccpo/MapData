#pragma once
#include <vector>
#include <list>
#include <iterator>
#include <string>

#include "DataTool.h"

using namespace std;

class DataSort{
public:
	DataSort();
	~DataSort();

	const vector<vector<string>> DeleteKeyCategory(vector<vector<string>>& inDataList);
	const vector<list<int>> IntDeleteKeyCategory(vector<vector<string>>& inDataList);


	const vector<list<int>> ExtractData(vector<vector<int>>& inDataList);//データの抽出を行う
protected:
	DataTool data_tool;
};

