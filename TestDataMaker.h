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
	TestDataMaker();
	~TestDataMaker();

	void GenerateData();
protected:
	string mPlayerId;//PlayerID
	array<int, 10> mData;
};

