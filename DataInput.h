#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <fstream>
#include <list>
#include <iterator>
#include <functional>


#include "DataTool.h"
#include "DataSort.h"

using namespace std;

class DataInput
{
public:
		DataInput();
		~DataInput();

		vector<vector<int>> mVectorDates;//�f�[�^���i�[����vector

		/*inline vector<string> GetPlayerCourseData(const int& inPlayerID) { return mVectorDates.at(inPlayerID); };
		inline string GetPlayIDData (const int& inPlayerId, const int& num) { return mVectorDates.at(inPlayerId).at(num); };*/

		const vector<vector<int>>  LoadCSVData(string& ioFile);//CSV�f�[�^��ǂݍ��ފ֐�
		list<int> ConvertFileData(vector<string>& ioVectorDatas);
		
		bool IsExitPlayerID(string inPlayerID);
protected:
	DataTool data_tool;
	DataSort data_sort;

};

