#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <chrono>


#include "DataInput.h"
#include "TestDataMaker.h"
#include "DataTool.h"
#include "DataSort.h"

using namespace std;

//抽出したデータを格納、各クラスへ命令を出すクラス
class Data
{
public:

	Data();
	~Data();

	map<string, vector<vector<string>>> user_datas;

	vector<list<int>> mLos;

	vector<list<int>> mListDates;

	vector<vector<int>> mVectorDates;
	vector<vector<string>> mSortVectorDates;
	vector<list<int>> mPriorityDates;

	const void GenerateTestData(string& inFileName);//テストデータ生成実行関数
	const void LoadTestData(string& inFileName);//CSVデータ読取実行関数
	const void ExtractPlayerCourceData(vector<list<int>>& inDate);

protected:
	DataInput data_input;
	TestDataMaker test_data_maker;
	DataTool data_tool;
	DataSort data_sort;

};

