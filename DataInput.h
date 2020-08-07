#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <fstream>

using namespace std;

vector<vector<int>> gDataList(1000, vector<int>(11));

class DataInput

{
public:
		DataInput();
		~DataInput();

		void  LoadData(vector<string>& ioVectorDatas);
		vector<string> GetFileData(const string& filename, vector<string>& vstr);
		void AddFileData(vector<string>& ioVectorDatas);

		inline int GetPlayerID() {};
		//int GetPlayerRoute();

		array<int, 10> GetPlayerRoute();
protected:

	string mPlayerId;//PlayerID
	array<int, 10> mData{ 1,2,3,4,5,6,7,8,9,10 };

	/*vector<array<string, 1000>,11> mDataList;*/

	vector<string> lsl;
	
};

