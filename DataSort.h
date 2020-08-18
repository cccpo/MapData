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



	vector<vector<string>> mSortVectorDates;//ÉfÅ[É^Çäiî[Ç∑ÇÈvector

	vector<vector<string>> DeleteKeyCategory(vector<vector<string>> inDataList);
	vector<vector<string>> ExtractData(vector<vector<string>> inDataList);
protected:
	//DataInput data_input;
	DataTool data_tool;
};

