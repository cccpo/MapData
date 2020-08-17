#pragma once
#include <iostream>
#include <array>

//#include "DataInput.h"
#include "TestDataMaker.h"
#include "DataTool.h"
#include "DataSort.h"

using namespace std;

class Data
{
public:

	Data();
	~Data();

	const void GenerateTestData(string& inFileName);

protected:
	//DataInput data_input;
	TestDataMaker test_data_maker;
	DataTool data_tool;
	DataSort data_sort;

};

