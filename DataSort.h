#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;


class DataSort{
public:
	DataSort();
	~DataSort();

	vector<vector<string>> mSortVectorDates;//�f�[�^���i�[����vector

	void NumOfSame(vector<vector<string>> inKSA);
protected:
	//DataInput data_input;
};

