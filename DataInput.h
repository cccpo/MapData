#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <fstream>


#include "DataTool.h"

using namespace std;

 static vector<int> gDataList;
 //static vector<vector<string>> gVectorDates(10001, vector<string>(11));


class DataInput

{
public:
		DataInput();
		~DataInput();

		vector<vector<string>> mVectorDates;

		
		inline vector<int> GetDataList() const { return gDataList;};
		inline vector<string> GetPlayerCourseData(int inPlayerID) { return mVectorDates.at(inPlayerID); };
		inline string GetPlayIDData (int inPlayerId, int num) { return mVectorDates.at(inPlayerId).at(num); };

		void  LoadCSVData(string& ioVectorDatas);

		vector<int> GetFileData(const string& filename, vector<string>& ioVectorDatas);//入力したファイルデータから
		
		vector<int> ConvertFileData(vector<string>& ioVectorDatas);
		vector<string> SearchPlayerData(string inPlayerName);


		void SaveData();

		inline int GetPlayerID() {};
		//int GetPlayerRoute();
protected:
	DataTool data_tool;

	int n = 10;

	string mPlayerId;//PlayerID
	array<int, 10> mData{ 1,2,3,4,5,6,7,8,9,10 };

	//vector<int> mDataList(*n);



	
	//vector<string> mDataList(string,11);
	

	vector<string> lsl;
	
};

