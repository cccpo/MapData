#include "DataInput.h"

DataInput::DataInput() {
	
}

DataInput::~DataInput() {

}

//int DataInput::GetPlayerRoute() {
//	return mPlayerRoute.size();
//}

void DataInput:: LoadData(vector<string>& ioVectorDatas) {

}

//Œo˜Hƒ‰ƒ“ƒ_ƒ€¶¬‚Ì‚½‚ß‚Éì¬AŒ»İ‚ÍTestDataMaker‚É’u‚¢‚Ä‚¢‚é
array<int,10> DataInput::GetPlayerRoute() {
	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<int> first_number(0, 9);//0`9‚Ì”ÍˆÍ‚Å—””­¶
	uniform_int_distribution<int> second_number(2, 4);//2`4‚Ì”ÍˆÍ‚Å—””­¶


	for (int i = 0; i < 10; ++i) {
		if (i == 0) {
			mData[i] = first_number(mt);
		}else{
			mData[i] = mData[i-1] + second_number(mt) - 3;
		}
	}
	
	return mData;
}

vector<string> DataInput::GetFileData(const string& inFileName, vector<string>& ioVectorDatas) {
	ifstream ifs(inFileName);
	vector<string> player_route,player_id,test3;

	if (!ifs)
	{
		cout << "Error"<< endl;
	}

	string tmp;
	while (getline(ifs, tmp)) {

		ioVectorDatas.emplace_back(tmp);
	}

	/*cout << tmp << endl;*/

	player_id = data_tool.split(ioVectorDatas[0], ':');
	player_id.erase(player_id.begin());
	

	player_route = data_tool.split(ioVectorDatas[1],':');
	player_route.erase(player_route.begin());

	AddFileData(ioVectorDatas);

	return player_route;

}

void DataInput::AddFileData(vector<string>& ioVectorDatas) {
	//cout << ioVectorDatas.size() << endl;
	
	//gDataList.emplace_back(ioVectorDatas);
	//
	//for (int i = 0; i < ioVectorDatas.size(); i++)
	//	for(int j=0;j < 11; j++)
	//	cout << gDataList[i][j] << endl;
}

