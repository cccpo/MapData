#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <fstream>


#include "DataTool.h"

using namespace std;

 static vector<int> gDataList;

class DataInput

{
public:
		DataInput();
		~DataInput();

		inline vector<int> GetDataList() const { return gDataList;};

		void  LoadData(vector<string>& ioVectorDatas);

		vector<int> GetFileData(const string& filename, vector<string>& ioVectorDatas);//入力したファイルデータから
		
		vector<int> ConvertFileData(vector<string>& ioVectorDatas);

		void SaveData();

		inline int GetPlayerID() {};
		//int GetPlayerRoute();
protected:
	DataTool data_tool;

	int n = 10;

	string mPlayerId;//PlayerID
	array<int, 10> mData{ 1,2,3,4,5,6,7,8,9,10 };

	//vector<string>& mVectorDates;
	//vector<int> mDataList(*n);




	//vector<string> mDataList(string,11);
	

	vector<string> lsl;
	
};

