#pragma once
#include <random>
#include <string>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

class TestDataMaker
{
public:
	const int mDataSize = 10;
	
	TestDataMaker();
	~TestDataMaker();

	void GeneratePlayerID(char* s, const int len);;
	const void GenerateData(const int& ioNumOfData);
	const void GenerateTestDataCSV(string inFileName,int inNumOfData);

protected:
	string mPlayerId;//PlayerID
	array<int, 10> mData;
	

	char* mPlayerID;
};

