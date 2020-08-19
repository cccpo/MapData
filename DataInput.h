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

		vector<vector<string>> mVectorDates;//�f�[�^���i�[����vector

		inline vector<string> GetPlayerCourseData(const int& inPlayerID) { return mVectorDates.at(inPlayerID); };
		inline string GetPlayIDData (const int& inPlayerId, const int& num) { return mVectorDates.at(inPlayerId).at(num); };

		const vector<vector<string>>  LoadCSVData(string& ioFile);//CSV�f�[�^��ǂݍ��ފ֐�

		vector<int> GetFileData(const string& filename, vector<string>& ioVectorDatas);//���͂����t�@�C���f�[�^����
		
		vector<int> ConvertFileData(vector<string>& ioVectorDatas);
		vector<string> SearchPlayerData(string inPlayerID);

		void Sort();

		bool IsExitPlayerID(string inPlayerID);
protected:
	DataTool data_tool;
	DataSort data_sort;

};

