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

	vector<vector<string>> mSortVectorDates;//ÉfÅ[É^Çäiî[Ç∑ÇÈvector

	void NumOfSame(vector<vector<string>> inKSA);
protected:
	//DataInput data_input;
};

