#include "DataInput.h"

DataInput::DataInput() :mVectorDates(10001, vector<string>(11)){
	
}

DataInput::~DataInput() {

}

//CSVデータを読み込む関数
const vector<vector<string>> DataInput:: LoadCSVData(string& ioFile) {
	string file_path = data_tool.SetFilePath(ioFile);
	
	ifstream input_file(file_path);
	string line;
	int data_column = 0;

	//全行読み込む
	while (getline(input_file, line)) {
		vector<string> data_set = data_tool.Split(line, ',');
		
		//データを格納
		for (int data_row = 0; data_row < data_set.size(); data_row++) {
			mVectorDates.at(data_column).at(data_row)= data_set.at(data_row);

			//cout << mVectorDates.at(data_column).at(data_row);
		}

		//cout << endl;
		++data_column;
	}
	
	//cout << data_column << endl;

	return mVectorDates;
}

//入力したファイルデータから
vector<int> DataInput::GetFileData(const string& inFileName, vector<string>& ioVectorDatas) {
	ifstream ifs(inFileName);
	vector<string> player_route,player_id, player_route2;
	vector<int> pls_in;

	if (!ifs)
	{
		//cout << "Error"<< endl;
	}

	string tmp;
	while (getline(ifs, tmp)) {
		ioVectorDatas.emplace_back(tmp);
	}

	/*cout << tmp << endl;*/

	player_id = data_tool.Split(ioVectorDatas[0], ':');//分割
	player_id.erase(player_id.begin());
	
	player_route = data_tool.Split(ioVectorDatas[1],':');
	player_route.erase(player_route.begin());

	player_route = data_tool.Split(player_route[0], '.');

	pls_in=ConvertFileData(player_route);

	return pls_in;



}

vector<int> DataInput::ConvertFileData(vector<string>& ioVectorDatas) {
	string tesu_a;
	vector<int> lisya;
	
	for (int i = 0; i < ioVectorDatas.size(); i++) {
		//cout << "PlayerRoutePOS:" << i << endl;
		//cout << ioVectorDatas[i][1]<<"," << ioVectorDatas[i][3] <<endl;
		//cout << "DataSize:" << ioVectorDatas[i].size() << endl;
		
		int test_number2 = ioVectorDatas[i][3] - '0';
		
		lisya.emplace_back(test_number2);
		//cout << test_number << endl;
		//for (int j = 0; j < ioVectorDatas[i].size(); j++) {
		//	//int test_number = ctoi(ioVectorDatas[i][1]);
		//	cout << ioVectorDatas[i][j] << endl;
		//	}
	}
	//cout << mDataList.size() << endl;

	//データをリストに格納する
	for (int i = 0; i < lisya.size(); i++) {
		tesu_a = to_string(lisya[i]);
		//cout << tesu_a << endl;
	}

	return lisya;
}

vector<string> DataInput::SearchPlayerData(string inPlayerID) {

	for (int i = 0; i < mVectorDates.size(); i++) {
		if (mVectorDates.at(i).at(0) == inPlayerID) {
			return mVectorDates.at(i);
		}
	}

}

bool DataInput::IsExitPlayerID(string inPlayerID) {
	for (int i = 0; i < mVectorDates.size(); i++) {
		if (mVectorDates.at(i).at(0) == inPlayerID) {
			
			return true;
		}
	}

	cout << "Can't find" << inPlayerID << endl;
	return false;

}

void DataInput::Sort() {
	data_sort.DeleteKeyCategory(mVectorDates);
}
