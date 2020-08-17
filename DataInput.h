#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <fstream>


#include "DataTool.h"
#include "DataSort.h"

using namespace std;

class DataInput
{
public:
		DataInput();
		~DataInput();

		vector<vector<string>> mVectorDates;//データを格納するvector

		inline vector<string> GetPlayerCourseData(const int& inPlayerID) { return mVectorDates.at(inPlayerID); };
		inline string GetPlayIDData (const int& inPlayerId, const int& num) { return mVectorDates.at(inPlayerId).at(num); };

		const void  LoadCSVData(string& ioFile);//CSVデータを読み込み、格納する

		vector<int> GetFileData(const string& filename, vector<string>& ioVectorDatas);//入力したファイルデータから
		
		vector<int> ConvertFileData(vector<string>& ioVectorDatas);
		vector<string> SearchPlayerData(string inPlayerID);

		void Sort();

		bool IsExitPlayerID(string inPlayerID);
protected:
	DataTool data_tool;
	DataSort data_sort;

	string mPlayerId;//PlayerID
	array<int, 10> mData{ 1,2,3,4,5,6,7,8,9,10 };

	int n = 10;

	vector<string> lsl;
	
};

